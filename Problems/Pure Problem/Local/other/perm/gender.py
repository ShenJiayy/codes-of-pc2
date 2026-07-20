from os import system
from random import randint
system("mkdir data")
system("g++ ans.cpp -std=c++14 -O2 -o ans")
cnt = 0
for i in range(1, 11):
	for j in range(1, i + 1):
# with open('/Users/michael/test.txt', 'w') as f:
# 	f.write('Hello, world!')
		cnt += 1
		with open(f"./data/{cnt}.in", "w") as f:
			f.write(str(i) + ' ' + str(j))
		system(f"./ans < ./data/{cnt}.in > ./data/{cnt}.ans")