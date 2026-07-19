from os import system

item = ['a1', 'a2', 'a3', 'a4', 'a5', 'a6', 'a7', 'a8', 'a9', 'a10', 'ex_1', 'ex_2', 'ex_3', 'ex_4', 'ex_5']
folder = '6285data'

cnt = 0

for each in item:
    system(f"bash -c 'cp {folder}/{each}.in data.in'")
    system(f"bash -c 'cp {folder}/{each}.out data.ans'")
    ret = system("bash test")
    system(f"bash -c 'rm data.in data.out data.ans'")
    cnt += not ret

print("15 Datas,", cnt, "ACs")