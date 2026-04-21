import random
import sys
ls = sys.argv
try:
    exit(random.randint(int(ls[1]), int(ls[2])))
except Exception as e:
    print(f"Error: {e}")