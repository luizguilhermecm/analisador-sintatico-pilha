#include "sintatico.h"
#include <stack>

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
  tok = getToken(); 
  EraseToken(); 
  pilha.pop();
}

void Sintatico::eat(int token_consumir){ 
  if (Lexico::IsEqual(tok,token_consumir)){
    avancar();
  } 
}
void Sintatico::analise(){
  if (pilha.top() == DOLAR){
  cout << "sucess";
  printTokens();
  exit(0);
  }
  if (pilha.top() > 6){
    if (tok == pilha.top()) avancar();
    else error();
  }
  else {
    cout << pilha.top() <<  " - " << tok <<endl;
    if (pilha.top() == 2) E();
    else if (pilha.top() == 3) E_();
    else if (pilha.top() == 4) T();
    else if (pilha.top() == 5) T_();
    else if (pilha.top() == 6) F();
  }
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
