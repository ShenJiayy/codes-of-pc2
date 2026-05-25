from os import system
from random import randint
system("rm -rd ./data/*")
system("mkdir data")
system("g++ ans.cpp -std=c++14 -O2 -o ans")
for i in range(1, 41):
# with open('/Users/michael/test.txt', 'w') as f:
# 	f.write('Hello, world!')
    with open(f"./data/{i}.in", "w") as f:
        f.write(str(i))
    system(f"./ans < ./data/{i}.in > ./data/{i}.ans")