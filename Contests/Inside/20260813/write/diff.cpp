#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
    while (1) {
        string cmd = "fc ";
        cmd += argv[1];
        cmd += " ";
        cmd += argv[2];
        system(cmd.data());
    }
}