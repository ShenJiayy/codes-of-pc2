from os import system
problem = "zlagalica"
for i in range(1, 5):
    system(f"ren {problem}{i}.out {problem}{i}.ans")
for i in range(1, 5):
    system(f"ren {problem}{i}.in {problem}.in")
    system(f"g++ {problem}.cpp -std=c++14 -static -o run -g3 && run && fc /w {problem}.out {problem}{i}.ans")
    system(f"ren {problem}.in {problem}{i}.in")