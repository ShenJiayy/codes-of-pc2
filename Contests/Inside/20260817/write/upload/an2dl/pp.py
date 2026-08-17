from os import system
problem = "an2dl"
system(f"g++ {problem}.cpp -std=c++14 -static -g3 -o {problem}")
for i in range(1, 4):
    system(f"ren {problem}{i}.in {problem}.in")
    system(f"ren {problem}{i}.ans {problem}.ans")
    system(f"ConsolePauser {problem}")
    system(f"fc /w {problem}.out {problem}.ans")
    system(f"ren {problem}.in {problem}{i}.in")
    system(f"ren {problem}.ans {problem}{i}.ans")
    system(f"del {problem}.out")