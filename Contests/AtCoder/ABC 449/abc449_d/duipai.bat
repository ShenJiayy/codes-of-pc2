@echo off
:a
    cls
    random %random% %random% %random% %random% > data.in
    baoli < data.in > data.ans
    upload < data.in > data.out
    fc data.out data.ans
if not errorlevel 1 goto a
pause
goto a