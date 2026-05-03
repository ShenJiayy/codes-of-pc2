from os import system
for i in range(101):
    system(f"echo {i} > data/{i + 1}.out")
    system(f"cat /dev/null > data/{i + 1}.in")