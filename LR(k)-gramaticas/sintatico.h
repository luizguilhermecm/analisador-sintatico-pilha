#include "lexico.cpp"
#include <stack>
class Sintatico;

typedef void (Sintatico::*pSLR)();

class Sintatico : public Lexico {
        public:
                enum Actions{
                        SHIFT,
                        GOTO,
                        REDUCE,
                        ACCEPT
                };
                enum NaoTerminais{
                        NTB = 99,
                        NTP,
                        NTS,
                        NTE
                };
                Sintatico();
                void imprime();

                void avancar();
                void analise();
                void eat(int token_consumir);
                void error();
                void error(int erro, int queria);

                int goToState(int state, int nt);
                void Shift();
                int getIndice();
                void analiseSLR();

                void S0();
                void B1();
                void B2();
                void P3();
                void P4();
                void E5();
                void E6();

        private:
                struct cell{
                        int _tok;
                        int _state;
                };
                struct SLR{
                        pSLR pmethod;
                        int action;
                        int value;
                };
                SLR SLR_tab[12][10];

                int indice[11];
                int estado_atual;
                int acao_atual;
                int indice_atual;
                int tok;
                int linha;
                stack<int> entrada;
                stack<cell> pilha;
                cell celula;
                //stack<int> pilha;
};
