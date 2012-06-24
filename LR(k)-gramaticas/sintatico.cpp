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

        for (int i = 0; i < 12; i++){
                for (int j = 0; j < 10; j++){
                        SLR_tab[i][j].pmethod = &Sintatico::error;
                }
        }

        SLR_tab[1][0].value = 3;
        SLR_tab[1][0].action = SHIFT;

        SLR_tab[1][7].value = 2;
        SLR_tab[1][7].action = GOTO;

        SLR_tab[2][5].value = NULL;
        SLR_tab[2][5].action = ACCEPT;

        SLR_tab[3][1].value = 5;
        SLR_tab[3][1].action = SHIFT;
         
        SLR_tab[3][2].value = 3;
        SLR_tab[3][2].action = REDUCE;
        SLR_tab[3][2].pmethod = &Sintatico::P3;
        
        SLR_tab[3][3].value = 3;
        SLR_tab[3][3].action = REDUCE;
        SLR_tab[3][3].pmethod = &Sintatico::P3;
        
        SLR_tab[3][4].value = 3;
        SLR_tab[3][4].action = REDUCE;
        SLR_tab[3][4].pmethod = &Sintatico::P3;
       
        SLR_tab[3][5].value = 3;
        SLR_tab[3][5].action = REDUCE;
        SLR_tab[3][5].pmethod = &Sintatico::P3;
       
        SLR_tab[3][8].value = 4;
        SLR_tab[3][8].action = GOTO;
         
        SLR_tab[4][2].value = 1;
        SLR_tab[4][2].action = REDUCE;
        SLR_tab[4][2].pmethod = &Sintatico::B1;
        
        SLR_tab[4][3].value = 1;
        SLR_tab[4][3].action = REDUCE;
        SLR_tab[4][3].pmethod = &Sintatico::B1;
        
        SLR_tab[4][4].value = 1;
        SLR_tab[4][4].action = REDUCE;
        SLR_tab[4][4].pmethod = &Sintatico::B1;
       
        SLR_tab[4][5].value = 1;
        SLR_tab[4][5].action = REDUCE;
        SLR_tab[4][5].pmethod = &Sintatico::B1;
        
        SLR_tab[5][0].value = 3;
        SLR_tab[5][0].action = SHIFT;
         
        SLR_tab[5][7].value = 7;
        SLR_tab[5][7].action = GOTO;
         
        SLR_tab[5][9].value = 6;
        SLR_tab[5][9].action = GOTO;
         
        SLR_tab[6][2].value = 8;
        SLR_tab[6][2].action = SHIFT;
         
        SLR_tab[6][3].value = 9;
        SLR_tab[6][3].action = SHIFT;
          
        SLR_tab[7][2].value = 5;
        SLR_tab[7][2].action = REDUCE;
        SLR_tab[7][2].pmethod = &Sintatico::E5;
          
        SLR_tab[7][3].value = 5;
        SLR_tab[7][3].action = REDUCE;
        SLR_tab[7][3].pmethod = &Sintatico::E5;
          
        SLR_tab[7][4].value = 10;
        SLR_tab[7][4].action = SHIFT;
         
        SLR_tab[8][2].value = 2;
        SLR_tab[8][2].action = REDUCE;
        SLR_tab[8][2].pmethod = &Sintatico::B2;
        
        SLR_tab[8][3].value = 2;
        SLR_tab[8][3].action = REDUCE;
        SLR_tab[8][3].pmethod = &Sintatico::B2;
        
        SLR_tab[8][4].value = 2;
        SLR_tab[8][4].action = REDUCE;
        SLR_tab[8][4].pmethod = &Sintatico::B2;
       
        SLR_tab[8][5].value = 2;
        SLR_tab[8][5].action = REDUCE;
        SLR_tab[8][5].pmethod = &Sintatico::B2;
          
        SLR_tab[9][2].value = 4;
        SLR_tab[9][2].action = REDUCE;
        SLR_tab[9][2].pmethod = &Sintatico::P4;
        
        SLR_tab[9][3].value = 4;
        SLR_tab[9][3].action = REDUCE;
        SLR_tab[9][3].pmethod = &Sintatico::P4;
        
        SLR_tab[9][4].value = 4;
        SLR_tab[9][4].action = REDUCE;
        SLR_tab[9][4].pmethod = &Sintatico::P4;
       
        SLR_tab[9][5].value = 4;
        SLR_tab[9][5].action = REDUCE;
        SLR_tab[9][5].pmethod = &Sintatico::P4;
        
        SLR_tab[10][0].value = 5;
        SLR_tab[10][0].action = SHIFT;
        
        SLR_tab[10][9].value = 11;
        SLR_tab[10][9].action = GOTO;
 
        SLR_tab[11][2].value = 6;
        SLR_tab[11][2].action = REDUCE;
        SLR_tab[11][2].pmethod = &Sintatico::E6;
       
        SLR_tab[11][3].value = 6;
        SLR_tab[11][3].action = REDUCE;
        SLR_tab[11][3].pmethod = &Sintatico::E6;
 

}

void Sintatico::imprime(){
        cout << pilha.top()._tok << endl;
}

void Sintatico::error(){
        cout << "ERRO" << entrada.top() << endl;
        exit(0);
}

int Sintatico::getIndice(){
        int i = 0;
        while (i < 10){
                if (entrada.top() == indice[i]) return i;
                else i++;
        }
}

void Sintatico::Shift(){
}

void Sintatico::analiseSLR(){
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
                if (SLR_tab[estado_atual][indice_atual].action == SHIFT){
                        estado_atual = SLR_tab[estado_atual][indice_atual].value;
                        celula._tok = entrada.top();
                        celula._state = estado_atual;
                        pilha.push(celula);
                        entrada.pop();
                }
                else if (SLR_tab[estado_atual][indice_atual].action == GOTO){
                        estado_atual = SLR_tab[estado_atual][indice_atual].value;
                }
                else if (SLR_tab[estado_atual][indice_atual].action == REDUCE){
                        (*this.*SLR_tab[estado_atual][indice_atual].pmethod)();
                        //fazer reducao, ainda nao sei como.
                        //fazer uma funcao para cada regra e chamar essa regra para reduzir
                }
                else if (SLR_tab[estado_atual][indice_atual].action == ACCEPT){
                        cout << "Cadeia aceita" << endl;
                        exit (0);
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
                return SLR_tab[state][6].value;
        }
        else if (nt == NTB){
                return SLR_tab[state][7].value;
        }
        else if (nt == NTP){
                return SLR_tab[state][8].value;
        }
        else if (nt == NTE){
                return SLR_tab[state][9].value;
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

/*
   void Sintatico::error(){
   cout << "ERRO " << tok << endl;
   exit(0);
   }

   void Sintatico::error(int erro, int queria){
//  cout << "ERRO " << erro << "--" << queria << "linha " << linha << endl;
cout << "ERRO " << "linha " << linha << endl;
//  avancar();
exit (0);
}
void Sintatico::avancar(){ 
EraseToken();   tok = getToken(); 
pilha.pop();
analise();
}

void Sintatico::eat(int token_consumir){ 
if (Lexico::IsEqual(tok,token_consumir)){
avancar();
} 
}

void Sintatico::analise(){
cout << "ANALISE FOR - "<< pilha.top() << endl;
if (pilha.top() == DOLAR && SizeToken() == 0 ){
cout << "sucess";
printTokens();
exit(0);
}
else if (pilha.empty())
cout << "VAZIA DAMMIT";

else if (pilha.top() == DOLAR && SizeToken() != 0)
error();

else if (pilha.top() == DOLAR) cout << "IUPI" << endl;

else if (pilha.top() > 6){
if (tok == pilha.top()) avancar();
else error();
}
else if (pilha.top() <= 6){
cout << pilha.top() << " - " << SizeToken() <<  " - " << tok <<endl;
if (pilha.top() == 2) E();
else if (pilha.top() == 3) E_();
else if (pilha.top() == 4) T();
else if (pilha.top() == 5) T_();
else if (pilha.top() == 6) F();
}
else error();
}

void Sintatico::S(){
tok = getToken();
cout << tok << endl;
pilha.push(DOLAR);
pilha.push(2);
analise();
}

void Sintatico::E(){
pilha.pop();
pilha.push(3);
pilha.push(4);

analise();
} 
void Sintatico::E_(){
pilha.pop();
if (tok == PLUS){
        pilha.push(3);
        pilha.push(4);
        pilha.push(PLUS);
}

analise();
}

void Sintatico::T(){
        pilha.pop();
        pilha.push(5);
        pilha.push(6);

        analise();
}

void Sintatico::T_(){
        pilha.pop();
        if (tok == ASTERISCO){
                pilha.push(5);
                pilha.push(6);
                pilha.push(ASTERISCO);
        }

        analise();
}

void Sintatico::F(){
        pilha.pop();
        if (tok == ID){
                pilha.push(ID);
        }
        else if (tok == ABREPAR){
                pilha.push(FECHAPAR);
                pilha.push(2);
                pilha.push(ABREPAR);
        }

        analise();
}
*/
