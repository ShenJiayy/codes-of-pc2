from os import system
from random import randint
system("rm -rd ./data/*")
system("mkdir data")
system("g++ ans.cpp -std=c++14 -O2 -o ans")
st = [1, 1e3 + 1, 1e6 + 1]
ed = [1e3, 1e6, 1e9]
nme = ['small', 'medium', 'large']
for c in range(3):
    system(f"mkdir data/{nme[c]}")
    for i in range(1, 201):
    # with open('/Users/michael/test.txt', 'w') as f:
    # 	f.write('Hello, world!')
        with open(f"./data/{nme[c]}/{i}.in", "w") as f:
            n = randint(st[c], ed[c])
            f.write(str(n))
        system(f"./ans < ./data/{nme[c]}/{i}.in > ./data/{nme[c]}/{i}.ans")