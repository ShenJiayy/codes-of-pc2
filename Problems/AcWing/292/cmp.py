import os
import hashlib

def get_file_hash(file_path):
    hash_md5 = hashlib.md5()
    try:
        with open(file_path, "rb") as f:
            for chunk in iter(lambda: f.read(4096), b""):
                hash_md5.update(chunk)
        return hash_md5.hexdigest()
    except:
        return None

def compare_dirs(dir1, dir2):
    # 遍历 dir1 所有文件
    for root, _, files in os.walk(dir1):
        rel_path = os.path.relpath(root, dir1)
        target_root = os.path.join(dir2, rel_path)

        for file in files:
            f1 = os.path.join(root, file)
            f2 = os.path.join(target_root, file)

            # 文件不存在于第二个目录
            if not os.path.exists(f2):
                print(f"[Exist only A] {f1}")
                continue

            # 对比内容 MD5
            h1 = get_file_hash(f1)
            h2 = get_file_hash(f2)
            if h1 is None or h2 is None or h1 != h2:
                print(f"[Content neq] {f1} VS {f2}")

    # 遍历 dir2 找只在 B 存在的文件
    for root, _, files in os.walk(dir2):
        rel_path = os.path.relpath(root, dir2)
        source_root = os.path.join(dir1, rel_path)

        for file in files:
            f1 = os.path.join(source_root, file)
            f2 = os.path.join(root, file)
            if not os.path.exists(f1):
                print(f"[Exist only B] {f2}")

if __name__ == "__main__":
    DIR_A = r"answer"
    DIR_B = r"debug"
    print("Compare Dictory A:", DIR_A)
    print("Compare Dictory B:", DIR_B)
    compare_dirs(DIR_A, DIR_B)