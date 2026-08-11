@echo off
g++ upload.cpp -std=c++14 -o2 -static -o run
run < data.in 1>data.out 2>data.ans
fc data.out data.ans