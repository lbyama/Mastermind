#include <iostream>
#include <string>
#include <vector>
#include "Implement.h"
using namespace std;

int main(){
    Definicoes def;
    Title();
    def.setAll();   //recebe input de usuário das definições desejadas
    Tabuleiro tab(def); //cria o tabuleiro baseado nas definicoes
    Jogo *partida =nullptr;
    if(def.getN_jog() == 2){
        partida = new Jogo;
    }else {
        partida = new Jogo_solo;
    }
    partida->play(def,tab);
    delete partida;
    return 0;
}
