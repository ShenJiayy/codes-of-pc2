@echo off
g++ ans.cpp -std=c++14 -o2 -o ans
g++ upload.cpp -std=c++14 -o2 -o run
g++ checker.cpp -std=c++11 -o checker
g++ random.cpp -std=c++14 -o random
:mark
random > data.in
run < data.in > data.out
ans < data.in > data.ans
checker data.in data.out data.ans
if not errorlevel 1 goto mark
pause
goto mark