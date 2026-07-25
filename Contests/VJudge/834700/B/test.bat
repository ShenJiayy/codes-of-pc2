@echo off
g++ upload.cpp -std=c++14 -o2 -static -o run
if errorlevel 1 (
    echo - Complete Error.
    exit 1
)

echo Max CPU rate:               20%
echo Maximum committed memory:   256 MiB
echo Clock-time execution limit: 2s

procgov --quiet --maxmem 256M --cpurate 20 --timeout 2000 --recursive run < data.in 1>data.out 2>run.log
set exc=%errorlevel%
if %exc%==2 (
    echo - Time Limit Exceeted.
    exit 2
)
if %exc%==3 (
    echo - Memory Limit Exceeted.
    exit 3
)
fc /w data.out data.ans 1>nul 2>&1
set exc=%errorlevel%
if %exc%==1 (
    echo - Wrong Answer.
    exit 4
)
echo - Answer Correct.
exit 0