from os import system
system("g++ answer.cpp -std=c++14 -O2 -o answer")
system("g++ upload.cpp -std=c++14 -O2 -o upload")
system("g++ random.cpp -std=c++14 -O2 -o random")
while True:
    system("./random > data.in")
    system("./upload < data.in > data.out")
    system("./answer < data.in > data.ans")
    if system("diff -w data.out data.ans 1>/dev/null 2>/dev/null") != 0:
        print("Oops!\nWrong Answer!")
        input("Press Enter To Continue.")