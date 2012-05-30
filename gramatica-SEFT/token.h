#include <iostream>
#include <vector>

using namespace std;

class Tokens{
  protected:
    int getToken ();
    void setToken (int new_token);
    void printTokens ();
    void Inverter ();
    bool IsEqual (int tok_, int need);
    bool NextIsEqual (int t);
    bool IsReservada (string palavra);
    void setToken (int new_token, int qnt);
    void EraseToken ();
    int SizeToken ();
    enum automato_reservadas {ID = 7,
      PLUS,
      ASTERISCO,
      ABREPAR,
      FECHAPAR,
      DOLAR 
    }; 
  private:
    vector<int> Token;
};
