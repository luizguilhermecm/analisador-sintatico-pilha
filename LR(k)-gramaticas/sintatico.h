#include "lexico.cpp"
#include <stack>

class Sintatico;

typedef void (Sintatico::*pLR)();

struct LR{
        pLR pmethod;
        int action;
        int value;
};

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

                void InitLr1();
                void InitLalr1();
                void InitSlr();

                LR InitLr(int _action, int _value, pLR _pmethod);
                LR InitLr(int _action, int _value);

                int goToState(int state, int nt);
                int getIndice();

                void analiseLR();
                void error();

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
                LR LR_tab[17][10];

                int indice[11];
                int estado_atual;
                int acao_atual;
                int indice_atual;
                int tok;
                int linha;
                stack<int> entrada;
                stack<cell> pilha;
                cell celula;
};
