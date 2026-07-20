from os import system
system("g++ base.cpp -std=c++14 -O2 -o base")
system("g++ rand.cpp -std=c++14 -O2 -o rand")
system("mkdir data")
for i in range(1, 11):
    system("bash -c \"./rand $(head -20 /dev/random | cksum | cut -c 1-10) > data.in\"")
    system("base < data.in > data.ans")
    system(f"bash -c \"cp data.in data/{i}.in\"")
    system(f"bash -c \"cp data.ans data/{i}.ans\"")