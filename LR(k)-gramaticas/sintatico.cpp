#include "sintatico.h"
#include <stack>

Sintatico::Sintatico(){
        indice[0] = ID; 
        indice[1] = ABREPAR; 
        indice[2] = COCHETE; 
        indice[3] = FECHAPAR; 
        indice[4] = VIRGULA; 
        indice[5] = DOLAR; 
        indice[6] = NTS; 
        indice[7] = NTB; 
        indice[8] = NTP; 
        indice[9] = NTE; 
}

LR Sintatico::InitLr(int _action, int _value, pLR _pmethod){
        LR nova;
        nova.action = _action;
        nova.value = _value;
        nova.pmethod = _pmethod;
        return nova;
}

LR Sintatico::InitLr(int _action, int _value){
        LR nova;
        nova.action = _action;
        nova.value = _value;
        nova.pmethod = &Sintatico::error;
        return nova;
}

void Sintatico::InitLalr1(){
        for (int i = 0; i < 17; i++){
                for (int j = 0; j < 10; j++){
                        LR_tab[i][j].pmethod = &Sintatico::error;
                }
        }

        LR_tab[1][0] = InitLr(SHIFT, 3);
        LR_tab[1][7] = InitLr(GOTO, 2);

        LR_tab[2][5] = InitLr(ACCEPT, NULL);

        LR_tab[3][1] = InitLr(SHIFT, 5);
        LR_tab[3][2] = InitLr(REDUCE, 3, &Sintatico::P3);
        LR_tab[3][3] = InitLr(REDUCE, 3, &Sintatico::P3);
        LR_tab[3][4] = InitLr(REDUCE, 3, &Sintatico::P3);
        LR_tab[3][5] = InitLr(REDUCE, 3, &Sintatico::P3);
        LR_tab[3][8] = InitLr(GOTO, 4);
       
        LR_tab[4][2] = InitLr(REDUCE, 1, &Sintatico::B1);
        LR_tab[4][3] = InitLr(REDUCE, 1, &Sintatico::B1);
        LR_tab[4][4] = InitLr(REDUCE, 1, &Sintatico::B1);
        LR_tab[4][5] = InitLr(REDUCE, 1, &Sintatico::B1);
      
        LR_tab[5][0] = InitLr(SHIFT, 3);
        LR_tab[5][7] = InitLr(GOTO, 9);
        LR_tab[5][9] = InitLr(GOTO, 6);

        LR_tab[6][2] = InitLr(SHIFT, 7);
        LR_tab[6][3] = InitLr(SHIFT, 8);
     
        LR_tab[7][2] = InitLr(REDUCE, 2, &Sintatico::B2);
        LR_tab[7][3] = InitLr(REDUCE, 2, &Sintatico::B2);
        LR_tab[7][4] = InitLr(REDUCE, 2, &Sintatico::B2);
        LR_tab[7][5] = InitLr(REDUCE, 2, &Sintatico::B2);
      
        LR_tab[8][2] = InitLr(REDUCE, 4, &Sintatico::P4);
        LR_tab[8][3] = InitLr(REDUCE, 4, &Sintatico::P4);
        LR_tab[8][4] = InitLr(REDUCE, 4, &Sintatico::P4);
        LR_tab[8][5] = InitLr(REDUCE, 4, &Sintatico::P4);

        LR_tab[9][2] = InitLr(REDUCE, 5, &Sintatico::E5);
        LR_tab[9][3] = InitLr(REDUCE, 5, &Sintatico::E5);
        LR_tab[9][4] = InitLr(SHIFT, 10);
      
        LR_tab[10][0] = InitLr(SHIFT, 3);
        LR_tab[10][7] = InitLr(GOTO, 9);
        LR_tab[10][9] = InitLr(GOTO, 11);
 
        LR_tab[11][2] = InitLr(REDUCE, 6, &Sintatico::E6);
        LR_tab[11][3] = InitLr(REDUCE, 6, &Sintatico::E6);
}


void Sintatico::InitLr1(){
        for (int i = 0; i < 17; i++){
                for (int j = 0; j < 10; j++){
                        LR_tab[i][j].pmethod = &Sintatico::error;
                }
        }

        LR_tab[1][0] = InitLr(SHIFT, 3);
        LR_tab[1][7] = InitLr(GOTO, 2);

        LR_tab[2][5] = InitLr(ACCEPT, NULL);

        LR_tab[3][1] = InitLr(SHIFT, 5);
        LR_tab[3][5] = InitLr(REDUCE, 3, &Sintatico::P3);
        LR_tab[3][8] = InitLr(GOTO, 4);
       
        LR_tab[4][5] = InitLr(REDUCE, 1, &Sintatico::B1);
      
        LR_tab[5][0] = InitLr(SHIFT, 9);
        LR_tab[5][7] = InitLr(GOTO, 15);
        LR_tab[5][9] = InitLr(GOTO, 6);

        LR_tab[6][2] = InitLr(SHIFT, 7);
        LR_tab[6][3] = InitLr(SHIFT, 8);

        LR_tab[7][5] = InitLr(REDUCE, 2, &Sintatico::B2);
      
        LR_tab[8][5] = InitLr(REDUCE, 4, &Sintatico::P4);
      
        LR_tab[9][1] = InitLr(SHIFT, 11);
        LR_tab[9][2] = InitLr(REDUCE, 3, &Sintatico::P3);
        LR_tab[9][3] = InitLr(REDUCE, 3, &Sintatico::P3);
        LR_tab[9][4] = InitLr(REDUCE, 3, &Sintatico::P3);
        LR_tab[9][8] = InitLr(GOTO, 10);
      
        LR_tab[10][2] = InitLr(REDUCE, 1, &Sintatico::B1);
        LR_tab[10][3] = InitLr(REDUCE, 1, &Sintatico::B1);
        LR_tab[10][4] = InitLr(REDUCE, 1, &Sintatico::B1);
 
        LR_tab[11][0] = InitLr(SHIFT, 9);
        LR_tab[11][7] = InitLr(GOTO, 15);
        LR_tab[11][9] = InitLr(GOTO, 12);

        LR_tab[12][2] = InitLr(SHIFT, 13);
        LR_tab[12][3] = InitLr(SHIFT, 14);

        LR_tab[13][2] = InitLr(REDUCE, 2, &Sintatico::B2);
        LR_tab[13][3] = InitLr(REDUCE, 2, &Sintatico::B2);
        LR_tab[13][4] = InitLr(REDUCE, 2, &Sintatico::B2);

        LR_tab[14][2] = InitLr(REDUCE, 1, &Sintatico::B1);
        LR_tab[14][3] = InitLr(REDUCE, 1, &Sintatico::B1);
        LR_tab[14][4] = InitLr(REDUCE, 1, &Sintatico::B1);

        LR_tab[15][2] = InitLr(REDUCE, 5, &Sintatico::E5);
        LR_tab[15][3] = InitLr(REDUCE, 5, &Sintatico::E5);
        LR_tab[15][4] = InitLr(SHIFT, 16);

        LR_tab[16][0] = InitLr(SHIFT, 9);
        LR_tab[16][7] = InitLr(GOTO, 15);
        LR_tab[16][9] = InitLr(GOTO, 17);

        LR_tab[17][2] = InitLr(REDUCE, 6, &Sintatico::E6);
        LR_tab[17][3] = InitLr(REDUCE, 6, &Sintatico::E6);
}


void Sintatico::InitSlr(){
        for (int i = 0; i < 17; i++){
                for (int j = 0; j < 10; j++){
                        LR_tab[i][j].pmethod = &Sintatico::error;
                }
        }

        LR_tab[1][0] = InitLr(SHIFT, 3);
        LR_tab[1][7] = InitLr(GOTO, 2);

        LR_tab[2][5] = InitLr(ACCEPT, NULL);

        LR_tab[3][1] = InitLr(SHIFT, 5);
        LR_tab[3][2] = InitLr(REDUCE, 3, &Sintatico::P3);
        LR_tab[3][3] = InitLr(REDUCE, 3, &Sintatico::P3);
        LR_tab[3][4] = InitLr(REDUCE, 3, &Sintatico::P3);
        LR_tab[3][5] = InitLr(REDUCE, 3, &Sintatico::P3);
        LR_tab[3][8] = InitLr(GOTO, 4);
       
        LR_tab[4][2] = InitLr(REDUCE, 1, &Sintatico::B1);
        LR_tab[4][3] = InitLr(REDUCE, 1, &Sintatico::B1);
        LR_tab[4][4] = InitLr(REDUCE, 1, &Sintatico::B1);
        LR_tab[4][5] = InitLr(REDUCE, 1, &Sintatico::B1);
      
        LR_tab[5][0] = InitLr(SHIFT, 3);
        LR_tab[5][7] = InitLr(GOTO, 7);
        LR_tab[5][9] = InitLr(GOTO, 6);

        LR_tab[6][2] = InitLr(SHIFT, 8);
        LR_tab[6][3] = InitLr(SHIFT, 9);

        LR_tab[7][2] = InitLr(REDUCE, 5, &Sintatico::E5);
        LR_tab[7][3] = InitLr(REDUCE, 5, &Sintatico::E5);
        LR_tab[7][4] = InitLr(SHIFT, 10);
      
        LR_tab[8][2] = InitLr(REDUCE, 2, &Sintatico::B2);
        LR_tab[8][3] = InitLr(REDUCE, 2, &Sintatico::B2);
        LR_tab[8][4] = InitLr(REDUCE, 2, &Sintatico::B2);
        LR_tab[8][5] = InitLr(REDUCE, 2, &Sintatico::B2);
      
        LR_tab[9][2] = InitLr(REDUCE, 4, &Sintatico::P4);
        LR_tab[9][3] = InitLr(REDUCE, 4, &Sintatico::P4);
        LR_tab[9][4] = InitLr(REDUCE, 4, &Sintatico::P4);
        LR_tab[9][5] = InitLr(REDUCE, 4, &Sintatico::P4);
      
        LR_tab[10][0] = InitLr(SHIFT, 5);
        LR_tab[10][9] = InitLr(GOTO, 11);
 
        LR_tab[11][2] = InitLr(REDUCE, 6, &Sintatico::E6);
        LR_tab[11][3] = InitLr(REDUCE, 6, &Sintatico::E6);
}

void Sintatico::error(){
        cout << "ERRO" << endl;
        exit(0);
}

int Sintatico::getIndice(){
        int i = 0;
        while (i < 10){
                if (entrada.top() == indice[i]) return i;
                else i++;
        }
}

void Sintatico::analiseLR(){
        while(SizeToken() != 0){
                entrada.push(getToken());
                EraseToken();
        }


        indice_atual = getIndice();
        estado_atual = 1;
        acao_atual = NULL;
        celula._state = 1;
        pilha.push(celula);

        while (acao_atual != ACCEPT){
                if (LR_tab[estado_atual][indice_atual].action == SHIFT){
                        estado_atual = LR_tab[estado_atual][indice_atual].value;
                        celula._tok = entrada.top();
                        celula._state = estado_atual;
                        pilha.push(celula);
                        entrada.pop();
                }
                else if (LR_tab[estado_atual][indice_atual].action == GOTO){
                        estado_atual = LR_tab[estado_atual][indice_atual].value;
                }
                else if (LR_tab[estado_atual][indice_atual].action == REDUCE){
                        (*this.*LR_tab[estado_atual][indice_atual].pmethod)();
                        //fazer reducao, ainda nao sei como.
                        //fazer uma funcao para cada regra e chamar essa regra para reduzir
                }
                else if (LR_tab[estado_atual][indice_atual].action == ACCEPT){
                        cout << "Cadeia aceita" << endl;
                        break;
                        //aceitou cadeia, ainda nao sei como fazer.
                        //condicao de saida do while ...
                }
                else error();

                estado_atual = pilha.top()._state;
                indice_atual = getIndice();
                // acredito que tenho que atualizar o indice, porem ainda nao sei ao certo
                // sera apenas um getI]dice()?
        }
}

int Sintatico::goToState(int state, int nt){
        if (nt == NTS){
                return LR_tab[state][6].value;
        }
        else if (nt == NTB){
                return LR_tab[state][7].value;
        }
        else if (nt == NTP){
                return LR_tab[state][8].value;
        }
        else if (nt == NTE){
                return LR_tab[state][9].value;
        }
        else error();
}

void Sintatico::S0(){
        //acredito que na tabela nunca tera um reduce 0
}

void Sintatico::B1(){
        if (pilha.top()._tok == NTP){
                pilha.pop();
        } else error();

        if (pilha.top()._tok == ID){
                pilha.pop();
        } else error();

        celula._tok = NTB;
        celula._state = goToState(pilha.top()._state, NTB); 
        pilha.push(celula); //nesse ponto precisa atualizar o estado_atual.
}

void Sintatico::B2(){
        if (pilha.top()._tok == COCHETE){
                pilha.pop();
        } else error();
        if(pilha.top()._tok == NTE){
                pilha.pop();
        } else error();
        if (pilha.top()._tok == ABREPAR){
                pilha.pop();  
        } else error();
        if (pilha.top()._tok == ID){
                pilha.pop();
        } else error();

        celula._tok = NTE;
        celula._state = goToState(pilha.top()._state, NTE); 
        pilha.push(celula); //nesse ponto precisa atualizar o estado_atual.
}

void Sintatico::P3(){
        celula._tok = NTP;
        celula._state = goToState(pilha.top()._state, NTP); 
        pilha.push(celula); //nesse ponto precisa atualizar o estado_atual.
}

void Sintatico::P4(){
        if (pilha.top()._tok == FECHAPAR){
                pilha.pop();
        } else error();
        if (pilha.top()._tok == NTE){
                pilha.pop();
        } else error();
        if (pilha.top()._tok == ABREPAR){
                pilha.pop();
        } else error();

        celula._tok = NTP;
        celula._state = goToState(pilha.top()._state, NTP); 
        pilha.push(celula); //nesse ponto precisa atualizar o estado_atual.
}

void Sintatico::E5(){
        if (pilha.top()._tok == NTB){
                pilha.pop();
        } else error();

        celula._tok = NTE;
        celula._state = goToState(pilha.top()._state, NTE); 
        pilha.push(celula); //nesse ponto precisa atualizar o estado_atual.
}

void Sintatico::E6(){
        if (pilha.top()._tok == NTE){
                pilha.pop();
        } else error();
        if (pilha.top()._tok == VIRGULA){
                pilha.pop();
        } else error();
        if (pilha.top()._tok == NTB){
                pilha.pop();
        } else error();

        celula._tok = NTE;
        celula._state = goToState(pilha.top()._state, NTE); 
        pilha.push(celula); //nesse ponto precisa atualizar o estado_atual.
}
