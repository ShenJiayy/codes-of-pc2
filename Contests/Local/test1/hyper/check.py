from os import system
from time import time_ns
system("del /f /q /s tmp 1>nul 2>nul")
system("rmdir tmp 1>nul 2>nul")
system("mkdir tmp")
system("g++ checker.cpp -std=c++14 -o tmp/checker")
system("g++ hyper.cpp -std=c++14 -O2 -o tmp/hyper")
for i in range(1, 201):
    system(f"copy data\\random-{i}.in tmp\\data.in 1>nul 2>nul")
    system(f"copy data\\random-{i}.ans tmp\\data.ans 1>nul 2>nul")
    st = int(time_ns() // 1000000)
    system("start /wait tmp\\hyper")
    ed = int(time_ns() // 1000000)
    if st - ed > 3050:
        printf(f"Time Too Long On Case {i}")
    ext = system("tmp\\checker tmp\\data.in tmp\\data.out tmp\\data.ans")
    if ext != 1:
        print(f"Error On Case {i}")
    system("del tmp/data.* 1>nul 2>nul")