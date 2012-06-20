#include "lexico.h"
#include <fstream>
using namespace std;


Lexico::Lexico(){
  for (int i = 0; i < estados; i++){
    for (int j = 0; j < alfabeto; j++){
      automato[i][j] = 0;
    }
  }
  automato[1][0] = 2;
  automato[1][2] = 4;
  automato[1][3] = 5;
  automato[1][4] = 6;
  automato[1][5] = 7;
  automato[1][6] = 8;
  automato[2][1] = 3;

  indice[0]  = 'i';
  indice[1]  = 'd';
  indice[2]  = '+';
  indice[3]  = '*';
  indice[4]  = '(';
  indice[5]  = ')';
  indice[6]  = '$';
}

int Lexico::PosicaoIndice (char ch){
  int i = 0;
  while (i < alfabeto){
    if (ch == indice [i])
      return i;
    i++;
  }
  return -1;
}

bool Lexico::IsFinal (int estado){
  if (estado != 1 && 
      estado != 2 &&
      estado != 0)
    return true;
  else return false;
}

void Lexico::print () {
  for (int i = 0; i < estados; i++){
    cout << "\n";
    for (int j = 0; j < alfabeto; j++){
      cout << automato[i][j] << "  ";  
    }
  }
}


void Lexico::AnalisadorLexico(char * argumento){
  ifstream fin (argumento);
  vector<char> caracter;
  char ch;
  int i;
  while (fin.get(ch)) caracter.push_back(ch); 
  fin.clear();
  fin.close();
  int current_state = 1;
  int final_state = 0;
  int indice_caracter;
  string palavra;
  i = 0;
  while (i < caracter.size()) {
    indice_caracter = PosicaoIndice(caracter[i]);
    if (indice_caracter == -1 && current_state != 1) current_state = 0;
    if (indice_caracter == -1 && current_state == 1) current_state = estado_erro;
    if (current_state == estado_erro){
      cout << "ERRO SINTATICO";
      exit(0);
    }      
    if (indice_caracter != -1) current_state = automato[current_state][indice_caracter];

    if (IsFinal(current_state)) final_state = current_state;

    if (current_state != 0) {
      if (current_state == 2) palavra.push_back(caracter[i]);
      i++; 
    }
    if (current_state == estado_erro) exit(0);
    if (current_state == 0) {
      if (final_state == 2 || final_state == 40){
        if (IsReservada(palavra));
        else setToken(2,palavra.size());
        palavra.clear();
      }
      else Token (final_state);
      current_state = 1;
      final_state = 0;
    }
  }
  Token (final_state);
  printTokens();
  Inverter();
}

void Lexico::Token (int final) {
	switch (final) {
    case 3 : setToken (ID) ; cout << "ID \n"; break;
		case 4 : setToken (PLUS) ; cout << "Plus" << endl; break;
    case 5 : setToken (ASTERISCO) ; cout << "ASTERISCO" << endl; break;
    case 6 : setToken (ABREPAR) ; cout << "ABREPAR" << endl; break;
    case 7 : setToken (FECHAPAR) ; cout << "FECHAPAR" << endl;break;
    case 8 : setToken (DOLAR) ; cout << "DOLAR" << endl; break;
  }
}
