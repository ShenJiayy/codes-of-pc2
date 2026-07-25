@echo off
g++ upload.cpp -std=c++14 -O2 -static -o run
run < data.in > data.out
fc data.out data.ans