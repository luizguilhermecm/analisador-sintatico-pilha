#include <iostream>
#include <string.h>
#include "sintatico.cpp"
using namespace std;

int main (int argc, char *argv[]){
        Sintatico novo;
//        novo.AnalisadorLexico(argv[1]);
        string cadeia;
        cout << "Entre com a cadeia" << endl;
        cin >> cadeia;
        novo.AnalisadorLexico(cadeia);
        //novo.analiseSLR();
        int tecla = 4;
        system("clear");
        while (tecla != 0){
                cout << "\nEscolha uma opcao\n\n\t(1) SLR\n\t(2) LR(1)\n\t(3) LALR(1)\n\t(0) Sair\n" << endl; 
                cin >> tecla;
                system("clear");
                switch (tecla){
                        case 1:
                                novo.InitSlr();
                                novo.analiseLR();
                                break;
                        default:
                                break;
                }
        }
        return 0;
}
