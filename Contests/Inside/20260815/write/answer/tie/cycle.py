from os import system
from random import randint
# rand.exe [Nmax] [LenMax] [datafile] [seed]
system("g++ base.cpp -std=c++14 -static -O2 -o base")
system("g++ rand.cpp -std=c++14 -static -O2 -o rand")
system("g++ tie.cpp -std=c++14 -static -O2 -o tie")
while (True):
    seed = randint(1, 1048576)
    system(f"rand 10 1000000000 tie.in {seed}")
    system("tie")
    system("base")
    ret = system("fc /w tie.out tie.ans")
    if ret != 0:
        break