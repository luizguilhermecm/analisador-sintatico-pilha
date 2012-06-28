#include <iostream>
#include <string.h>
#include "sintatico.cpp"
using namespace std;

int main (int argc, char *argv[]){
        int tecla = 4;
        Sintatico novo;
        string cadeia;
        while (tecla != 0){
                cout << "Entre com a cadeia" << endl;
                cin >> cadeia;
                novo.AnalisadorLexico(cadeia);

                cout << "\nEscolha uma opcao\n\n\t(1) SLR\n\t(2) LR(1)\n\t(3) LALR(1)\n\t(0) Sair\n" << endl; 
                cin >> tecla;
                system("clear");

                switch (tecla){
                        case 1:
                                novo.InitSlr();
                                novo.analiseLR();
                                break;
                        case 2:
                                novo.InitLr1();
                                novo.analiseLR();
                                break;
                        case 3:
                                novo.InitLalr1();
                                novo.analiseLR();
                                break;
                        default:
                                break;
                }
                tecla = 4;
        }
        return 0;
}
