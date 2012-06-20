#include "token.cpp"

#define estados 9 
#define alfabeto 7
#define estado_erro 9 

class Lexico : public Tokens{
  public:
    void AnalisadorLexico (char * argumento);
    int PosicaoIndice (char ch);
    bool IsFinal (int estado);
    void print ();    
    void iniciar();
    Lexico();
    void Token (int final);
  private:
    int automato [estados][alfabeto];
    char indice [alfabeto];
};
