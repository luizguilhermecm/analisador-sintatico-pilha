#include "lexico.cpp"
#include <stack>
class Sintatico : public Lexico {
  public:
    void avancar();
    void analise();
    void eat(int token_consumir);
    void error();
    void error(int erro, int queria);

    void S();
    void E();
    void E_();
    void T();
    void T_();
    void F();
    void F_();

  private:
    int tok;
    int linha;
    stack<int> pilha;
};
