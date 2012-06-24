#include <iostream>

#include "sintatico.cpp"
using namespace std;

int main (int argc, char *argv[]){
        Sintatico novo;
        novo.AnalisadorLexico(argv[1]);
        novo.analiseSLR();

        return 0;
}
