#include <vector>
#include <iostream>
#include <string>
#include <cstring>

#include "token.h"

using namespace std;

void Tokens::setToken (int new_token, int qnt){
  int i = 0;
  while (i < qnt){
    Token.push_back(new_token);
    i++;
  }
}

bool Tokens::IsReservada (string palavra){
  if (palavra == "id") {
    setToken (ID);
    return true;
  }
  return false;
}

void Tokens::setToken (int new_token) {
  Token.push_back(new_token);
}

int Tokens::getToken () {
  return Token.back();
}

void Tokens::EraseToken () {
  Token.pop_back();
}

void Tokens::Inverter (){
  vector<int>aux;
  aux = Token;
  Token.clear();
  while (!aux.empty()){
    Token.push_back(aux.back());
    aux.pop_back();
  }
  aux.clear();
}

void Tokens::printTokens(){
  int i = 0;
  while (i < Token.size()){
    cout << Token[i] << " ";
    i++;
  }
}

bool Tokens::IsEqual (int tok_, int need) {
  if (tok_ == need) return true;
  else return false;
}

bool Tokens::NextIsEqual(int t){
  int next = getToken();
  if (next == t){
  return true;
  } else return false;

}
