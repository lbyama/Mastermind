#ifndef IMPLEMENT_H
#define IMPLEMENT_H

#include <iostream>
#include <string>
using namespace std;


void Title();

class Definicoes{
    bool rep;
    int qte_cor, tam_cod , tentativas , n_jog;
public:
    void setAll();
    int getQte_cor();
    int getTam_cod ();
    int getTentativas ();
    int getN_jog ();
    bool getRep();
};

class Pino{
    string cor;
    string cores[13] = {"vermelho", "laranja", "amarelo", "verde", "azul","ciano","rosa","roxo", "cinza","branco","resp_nada","resp_branco","resp_preto"};
    string cores_print[13] ={"\033[21;31m\U000023FA\033[0m ","\033[21;33m\U000023FA\033[0m ","\033[1;33m\U000023FA\033[0m ","\033[21;32m\U000023FA\033[0m ","\033[21;34m\U000023FA\033[0m ","\033[1;36m\U000023FA\033[0m ", "\033[1;35m\U000023FA\033[0m ","\033[21;35m\U000023FA\033[0m ", "\033[1;30m\U000023FA\033[0m ", "\033[1;37m\U000023FA\033[0m ","\U00002219 ","\033[1;37m\U000025CF\033[0m ","\033[1;37m\U000025CB\033[0m "};
public:
    bool igual(Pino &outro);
    void display();
    void setCor(int i);
    void setCor(string c);
    string getCor();
};

class Tabuleiro{
    Pino **matriz;
    int tentativas;
    vector<Pino> codigo;
    string cores_print[12] ={"\033[21;31m\U000023FA\033[0m ","\033[21;33m\U000023FA\033[0m ","\033[1;33m\U000023FA\033[0m ","\033[21;32m\U000023FA\033[0m ","\033[21;34m\U000023FA\033[0m ","\033[1;36m\U000023FA\033[0m ", "\033[1;35m\U000023FA\033[0m ","\033[21;35m\U000023FA\033[0m ", "\033[1;30m\U000023FA\033[0m ", "\033[1;37m\U000023FA\033[0m ","\033[1;37m\U000025CB\033[0m ","\033[1;37m\U000025CF\033[0m "};
        
public:
    Tabuleiro(Definicoes &def);
    void setCodigo(vector<Pino> &cod);
    void displayTentativa(int tent);
    void displayTentativas(int tent);
    vector<int> setTentativa(int tent,vector<int> chute);
    void displayCodigo();
    ~Tabuleiro();
};
    
class Jogo{
public:
    virtual void play(Definicoes &def,Tabuleiro &tab);
    void codemaker_resp(vector<int> &resp,Definicoes &def, Tabuleiro &tab, int &tent_atual);
    void codemaker_jog(Definicoes &def, Tabuleiro &tab);
    vector<int> codebreaker(Definicoes &def, Tabuleiro &tab, int &tent_atual);
};

class Jogo_solo : public Jogo{
public:
    virtual void play(Definicoes &def,Tabuleiro &tab)override;
    void codemaker_comp(Definicoes &def, Tabuleiro &tab);
};

#endif
