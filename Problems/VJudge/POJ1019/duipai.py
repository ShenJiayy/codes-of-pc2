from os import system
from random import randint
system("g++ answer.cpp -std=c++14 -O2 -o ans")
system("g++ upload.cpp -std=c++14 -O2 -o my")

def FileCmp(path1, path2):
    with open(path1, "r", encoding='utf-8') as f1, open(path2, "r", encoding='utf-8') as f2:
        return f1.read() == f2.read()

while True:
    T = randint(1, 10)
    with open("data.in", "w", encoding="utf-8") as f:
        f.write(str(T))
        f.write("\n")
        for _ in range(T):
            f.write(str(randint(1, 100)))
            f.write('\n')
    system("ans < data.in > data.ans")
    system("my < data.in > data.out")
    if not FileCmp('data.out', 'data.ans'):
        print("Findout a testcase!\nPress Any Key......")
        system("pause 1>nul 2>nul")