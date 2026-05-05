from os import system
from random import randint
system("mkdir data")
system("g++ ans.cpp -std=c++14 -O2 -o ans")
for i in range(1, 200):
# with open('/Users/michael/test.txt', 'w') as f:
# 	f.write('Hello, world!')
	with open(f"./data/{i}.in", "w") as f:
		f.write(str(randint(1, 1e6)) + ' ' + str(randint(1, 1e6)))
	system(f"./ans < ./data/{i}.in > ./data/{i}.ans")