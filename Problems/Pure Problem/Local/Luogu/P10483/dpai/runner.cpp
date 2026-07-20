#include <windows.h>

int main() {
    system("g++ base.cpp -std=c++14 -O2 -o base");
    system("g++ rand.cpp -std=c++14 -O2 -o rand");
    system("g++ source.cpp -std=c++14 -O2 -o source");
    while (1) {
        system("bash -c \"./rand $(head -20 /dev/random | cksum | cut -c 1-10) > data.in\"");
        system("base < data.in > data.ans");
        system("source < data.in > data.out");
        int ret = system("bash -c 'diff data.out data.ans -w'");
        if (!ret) continue;
        system("pause");
    }
}