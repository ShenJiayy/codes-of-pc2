import socket
import os
import struct

def receive_file(host='0.0.0.0', port=9999, save_dir='received_files'):
    # 创建保存目录
    if not os.path.exists(save_dir):
        os.makedirs(save_dir)
    
    # 创建TCP套接字
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    server_socket.bind((host, port))
    server_socket.listen(5)
    
    print(f"Server Started, Listening {host}:{port}")
    print(f"File Save to {save_dir}")
    print("Waiting......")

    while True:
        client_socket, addr = server_socket.accept()
        print(f"\nClient Connected: {addr}")

        try:
            # 1. 接收文件名长度 + 文件名
            file_name_len = struct.unpack('128s', client_socket.recv(128))[0].decode().strip('\x00')
            file_name = client_socket.recv(int(file_name_len)).decode()

            # 2. 接收文件大小
            file_size = struct.unpack('Q', client_socket.recv(8))[0]
            print(f"Reciving Files{file_name} | Size: {file_size} bytes")

            # 3. 接收文件数据
            save_path = os.path.join(save_dir, file_name)
            received_size = 0
            with open(save_path, 'wb') as f:
                while received_size < file_size:
                    data = client_socket.recv(4096)
                    if not data:
                        break
                    f.write(data)
                    received_size += len(data)
                    # 打印进度
                    progress = received_size / file_size * 100
                    print(f"\rProcess {progress:.2f}%", end='')

            print(f"\nSaved Compelete, Path: {save_path}")

        except Exception as e:
            print(f"\nRecived Error: {str(e)}")
        finally:
            client_socket.close()

if __name__ == '__main__':
    # 可自定义端口和保存目录
    receive_file(port=9999, save_dir='Saved Files')