import socket
import os
import struct

def send_file(server_ip, server_port=9999, file_path=''):
    # 检查文件是否存在
    if not os.path.isfile(file_path):
        print(f"❌ 错误：文件 {file_path} 不存在")
        return

    # 创建套接字并连接服务端
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        client_socket.connect((server_ip, server_port))
        print(f"✅ 成功连接服务端 {server_ip}:{server_port}")
    except Exception as e:
        print(f"❌ 连接服务端失败：{str(e)}")
        return

    try:
        file_name = os.path.basename(file_path)
        file_size = os.path.getsize(file_path)

        # 1. 发送文件名长度（固定128字节）
        client_socket.send(struct.pack('128s', str(len(file_name)).encode()))
        # 2. 发送文件名
        client_socket.send(file_name.encode())
        # 3. 发送文件大小
        client_socket.send(struct.pack('Q', file_size))

        print(f"📤 开始发送文件：{file_name} | 大小：{file_size} 字节")

        # 4. 发送文件数据
        sent_size = 0
        with open(file_path, 'rb') as f:
            while sent_size < file_size:
                data = f.read(4096)
                client_socket.send(data)
                sent_size += len(data)
                progress = sent_size / file_size * 100
                print(f"\r📊 传输进度：{progress:.2f}%", end='')

        print(f"\n🎉 文件发送完成！")

    except Exception as e:
        print(f"\n❌ 发送失败：{str(e)}")
    finally:
        client_socket.close()

if __name__ == '__main__':
    # ========== 请在这里修改配置 ==========
    SERVER_IP = "127.0.0.1"  # 服务端IP地址
    FILE_PATH = "test.txt"   # 要发送的文件路径
    # ======================================
    send_file(SERVER_IP, 9999, FILE_PATH)