from os import system
from random import randint
system("del /f random.exe 1>nul 2>nul")
system("del /f answer.exe 1>nul 2>nul")
system("g++ random.cpp -std=c++14 -o2 -o random")
system("g++ answer.cpp -std=c++14 -o2 -o answer")
system("del /f /q /s data 1>nul 2>nul")
system("rmdir data 1>nul 2>nul")
system("mkdir data")
for i in range(1, 201):
    num = randint(1, 20000)
    with open(f"./data/random-{i}.in", "w", encoding="utf-8") as f:
        f.write(str(num))
    system(f"answer < data/random-{i}.in > data/random-{i}.ans")