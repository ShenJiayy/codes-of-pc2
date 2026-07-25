import time
import os
os.system("cls")
os.system("title Timer")
while True:
    print(time.ctime(), end="")
    time.sleep(0.2)
    print("\r", end="")