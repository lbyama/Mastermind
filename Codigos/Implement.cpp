#include <iostream>
#include <string>
#include <vector>
#include "Implement.h"
using namespace std;


    void Title(){   //dá clear na tela e imprime o título do jogo
        cout<< "\033[2J\033[1;1H" << endl << endl;
        cout<< "\t\t███╗   ███╗ █████╗ ███████╗████████╗███████╗██████╗ ███╗   ███╗██╗███╗   ██╗██████╗ " << endl;
        cout<< "\t\t████╗ ████║██╔══██╗██╔════╝╚══██╔══╝██╔════╝██╔══██╗████╗ ████║██║████╗  ██║██╔══██╗" << endl;
        cout<< "\t\t██╔████╔██║███████║███████╗   ██║   █████╗  ██████╔╝██╔████╔██║██║██╔██╗ ██║██║  ██║" << endl;
        cout<< "\t\t██║╚██╔╝██║██╔══██║╚════██║   ██║   ██╔══╝  ██╔══██╗██║╚██╔╝██║██║██║╚██╗██║██║  ██║" << endl;
        cout<< "\t\t██║ ╚═╝ ██║██║  ██║███████║   ██║   ███████╗██║  ██║██║ ╚═╝ ██║██║██║ ╚████║██████╔╝" << endl;
        cout<< "\t\t╚═╝     ╚═╝╚═╝  ╚═╝╚══════╝   ╚═╝   ╚══════╝╚═╝  ╚═╝╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═════╝ " << endl<<endl<<endl;
    }

    void Definicoes::setAll(){
        char rept;
        cout << "\e[1mInsira o numero de cores a ser utilizado no jogo:\e[0m (4-10)" << endl;
        cin >> qte_cor;
        while(qte_cor <4 || qte_cor > 10){  //mantem o valor no intervalo desejado
            Title();
            cout << "\e[1mResposta invalida!\e[0m" << endl;
            cout << "\e[1mInsira o numero de cores a ser utilizado no jogo:\e[0m (4-10)" << endl;
            cin >> qte_cor;
        }
        Title();
        
        
        cout <<"\e[1mInsira o tamanho do codigo a ser quebrado:\e[0m (4-6)" << endl;
        cin >>tam_cod; 
        while(tam_cod <4 || tam_cod >6){
            Title();
            cout <<"\e[1mResposta invalida!\e[0m"  << endl;
            cout << "\e[1mInsira o tamanho do codigo a ser quebrado:\e[0m (4-6)" << endl;
            cin >> tam_cod;
        }
        Title();
        
        
        cout << "\e[1mInsira a quantidade de tentativas permitidas:\e[0m (4-10)" << endl;
        cin >>tentativas;
        while(tentativas <4 || tentativas > 10){
            Title();
            cout << "\e[1mResposta invalida!\e[0m"  << endl;
            cout << "\e[1mInsira a quantidade de tentativas permitidas:\e[0m (4-10)" << endl;
            cin >> tentativas;
            
        }
        Title();
        
        if(tam_cod <= qte_cor){  
            cout << "\e[1mUso de peças repetidas no codigo:\e[0m (y/n)" << endl;
            cin >> rept;
            while(rept != 'y' && rept != 'n'){
                Title();
                cout << "\e[1mResposta invalida!\e[0m"  << endl;
                cout << "\e[1mUso de peças repetidas no codigo:\e[0m (y/n)"<< endl;
                cin >> rept;
            }
            Title();
            if( rept == 'y'){
                rep = true;
            }else if(rept == 'n'){
                rep = false;
            }
        } else if (tam_cod > qte_cor){
            rep = true;
        }

        cout << "\e[1mInsira o numero de jogadores:\e[0m (1-2)" << endl;
        cin >>n_jog;
        while(n_jog <1 || n_jog > 2){
            Title();
            cout<< "\e[1mResposta invalida!\e[0m"  << endl;
            cout << "\e[1mInsira o numero de jogadores:\e[0m (1-2)" << endl;
            cin >> n_jog;
        }
        Title();
    }
    int Definicoes::getQte_cor(){
        return qte_cor;
    }
    int Definicoes::getTam_cod (){
        return tam_cod;
    }
    int Definicoes::getTentativas (){
        return tentativas;
    }
    int Definicoes::getN_jog (){
        return n_jog;
    }
    bool Definicoes::getRep(){
        return rep;
    }
    
    bool Pino::igual(Pino &outro){
        if(this->cor == outro.cor){
            return true;
        } else {
            return false;
        }
    }
    void Pino::display(){
        int i;
        for(i=0;cor!=cores[i];i++){}    //procura a do pino no vetor cores i
        cout << cores_print[i] ;        //a cor que deve ser impressa está na mesma posição
    }
    void Pino::setCor(int i){
        if(i>=0 && i <=12){
            cor = cores[i];
        } else {
            cor = cores[0];
        }
    }
    void Pino::setCor(string c){
        cor = c;
    }
    string Pino::getCor(){
        return cor;
    }
        
    Tabuleiro::Tabuleiro(Definicoes &def){  //construtor aloca a matriz com espaço para os palpites e respostas de cada tentativa
        int i;
        codigo.reserve(def.getTam_cod());
        tentativas =def.getTentativas();
        matriz = new Pino*[def.getTentativas()];
        for(i=0;i<def.getTentativas();i++){
            matriz[i]= new Pino[2 * def.getTam_cod()];
        }
    }
    void Tabuleiro::setCodigo(vector<Pino> &cod){   //guarda o codigo na forma de um vetor de inteiros
        codigo.assign(cod.begin(),cod.end());
    }
    
    void Tabuleiro::displayTentativa(int tent){     //chama a função display para cada pino de uma tentativa (sem resposta)
        int i,j;
            for(j = 0;j < codigo.size();j++){
                (matriz[tent][j]).display();
            };
    }
    void Tabuleiro::displayTentativas(int tent){    //mostra o tabuleiro inteiro
        int i,j;
        if(tent >=1){
            cout << endl;
            cout << "\t\t\t\t\t";
            for(j = 0;j < codigo.size()*2;j++){     //imprime a linha superior
                cout << "--";
            }
            cout << "---";
            cout << endl;
            for(i = tentativas-1;i>tent-1;i--){
                cout << "\t\t\t\t\t|" ;
                for(j = 0;j < codigo.size();j++){
                    cout<< "\U00002219 " ;      //imprime uma bolinha para casas ainda n preenchidas do tabuleiro
                }
                cout << "| " ;
                for(j = 0;j < codigo.size();j++){
                    cout<< "\U00002219 " ;
                }
                cout << "|" ;
                cout << endl;
            }
        
        for(i = tent-1;i>=0;i--){
            cout << "\t\t\t\t\t|";
            for(j = 0;j < codigo.size();j++){
                (matriz[i][j]).display();
            }
            cout << "| " ;
            for(j = codigo.size();j < 2*codigo.size();j++){
                (matriz[i][j]).display();
            }
            cout << "|";
            cout << endl;
        }
        cout << "\t\t\t\t\t";
        for(j = 0;j < codigo.size()*2;j++){
            cout << "--";
        }
        cout << "---";
        cout << endl;
        cout << endl;
        }
    }
    vector<int> Tabuleiro::setTentativa(int tent,vector<int> chute){    //insere a tentativa enviada no vetor no tabuleiro
        int i,j;
        vector<int> resposta(codigo.size());
        for(i=0 ; i <codigo.size();i++){
            (matriz[tent][i]).setCor(chute[i]);     //insere a tentativa em cada pino
            if((matriz[tent][i]).igual(codigo[i])){
                resposta[i] = 2;                    //se a tentativa estiver na posição certa recebe 2
            } else{
                resposta[i] = 0;                    //se não recebe 0
            }
        }
        
        for(i=0;i<chute.size();i++){
            if(resposta[i] == 0){
                for(j=0;j<chute.size();j++){
                    if ( (matriz[tent][i]).igual(codigo[j]) && i!=j ){
                        resposta[i] = 1;            // se a cor estiver no codigo mas na posição errada recebe 1
                        break;
                    }
                }
            }
        }
        for(i=chute.size();i<chute.size()*2;i++){
            j = resposta[i - chute.size()] + 10 ;
            (matriz[tent][i]).setCor(j);            // a resposta já é inserida na matriz
        }
        return resposta;                            //e é retornada
    }
    void Tabuleiro::displayCodigo(){                // exibe o código
        int i;
        for(i=0;i<codigo.size();i++){
            codigo[i].display();
        }
        cout << endl;
    }
    Tabuleiro::~Tabuleiro(){                        //destrutor desaloca a matriz
        int i;
        for(i=0;i<tentativas;i++){
            delete[] matriz[i];
        }
        delete[] matriz;
    }    

    
    
    void Jogo::play(Definicoes &def,Tabuleiro &tab){        //jogo de jogador vs jogador
        int i,tent_atual = 0,aux2 = 0 ;
        bool fim = false;

        vector<int> codes(def.getTam_cod());
        cout << "\e[1mInicio de jogo!\e[0m" << endl;
        codemaker_jog(def,tab);                             //chama o jogador para inserir o código
        while(!fim && tent_atual<=def.getTentativas()-1){
            aux2 = 0;
            Title();
            tab.displayTentativas(tent_atual);              //mostra as tentativas anteriores
            codes = codebreaker(def,tab,tent_atual);        //chama a vez do codebreaker e recebe a resposta à essa tentativa
            codemaker_resp(codes,def,tab,tent_atual);       //chama o codemaker para inserir a sua resposta à tentativa
            for(i=0;i<codes.size();i++){
                aux2 += codes[i];
            }
            if(aux2 == 2*codes.size()){                     //se todos os elementos da resposta são 2 então a tentativa está certa
                fim = true;                                 //e saímos do loop
            }
        }
        cout<< "\033[2J\033[1;1H" << endl << endl;
        if(fim){                                            // se !fim é porque ultrapassamos o máximo de tentativas então o codebreaker perdeu
            cout << "\t\t\033[1;32m██╗   ██╗ ██████╗  ██████╗███████╗     ██████╗  █████╗ ███╗   ██╗██╗  ██╗ ██████╗ ██╗   ██╗    ██╗\033[0m" << endl;
            cout << "\t\t\033[1;32m██║   ██║██╔═══██╗██╔════╝██╔════╝    ██╔════╝ ██╔══██╗████╗  ██║██║  ██║██╔═══██╗██║   ██║    ██║\033[0m" << endl;
            cout << "\t\t\033[1;32m██║   ██║██║   ██║██║     █████╗      ██║  ███╗███████║██╔██╗ ██║███████║██║   ██║██║   ██║    ██║\033[0m" << endl;
            cout << "\t\t\033[1;32m╚██╗ ██╔╝██║   ██║██║     ██╔══╝      ██║   ██║██╔══██║██║╚██╗██║██╔══██║██║   ██║██║   ██║    ╚═╝\033[0m" << endl;
            cout << "\t\t\033[1;32m ╚████╔╝ ╚██████╔╝╚██████╗███████╗    ╚██████╔╝██║  ██║██║ ╚████║██║  ██║╚██████╔╝╚██████╔╝    ██╗\033[0m" << endl;
            cout << "\t\t\033[1;32m  ╚═══╝   ╚═════╝  ╚═════╝╚══════╝     ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝ ╚═════╝  ╚═════╝     ╚═╝\033[0m" << endl;
        }else{
            cout << "\t\t\033[1;31m██╗   ██╗ ██████╗  ██████╗███████╗    ██████╗ ███████╗██████╗ ██████╗ ███████╗██╗   ██╗    ██╗\033[0m" << endl;
            cout << "\t\t\033[1;31m██║   ██║██╔═══██╗██╔════╝██╔════╝    ██╔══██╗██╔════╝██╔══██╗██╔══██╗██╔════╝██║   ██║    ██║\033[0m" << endl;
            cout << "\t\t\033[1;31m██║   ██║██║   ██║██║     █████╗      ██████╔╝█████╗  ██████╔╝██║  ██║█████╗  ██║   ██║    ██║\033[0m" << endl;
            cout << "\t\t\033[1;31m╚██╗ ██╔╝██║   ██║██║     ██╔══╝      ██╔═══╝ ██╔══╝  ██╔══██╗██║  ██║██╔══╝  ██║   ██║    ╚═╝\033[0m" << endl;
            cout << "\t\t\033[1;31m ╚████╔╝ ╚██████╔╝╚██████╗███████╗    ██║     ███████╗██║  ██║██████╔╝███████╗╚██████╔╝    ██╗\033[0m" << endl;
            cout << "\t\t\033[1;31m  ╚═══╝   ╚═════╝  ╚═════╝╚══════╝    ╚═╝     ╚══════╝╚═╝  ╚═╝╚═════╝ ╚══════╝ ╚═════╝     ╚═╝\033[0m" << endl;
        }
        tab.displayTentativas(tent_atual);
        cout << "O código era: " << endl << "\t\t";
        tab.displayCodigo();
        cout << endl;
    }
    
    void Jogo::codemaker_jog(Definicoes &def, Tabuleiro &tab){          //função para que o jogador insira o codigo
        int i, j, bre = 0,qte = def.getQte_cor(), tam = def.getTam_cod();
        char aux[2];
        string code;
        string cores_print[10] ={"\033[21;31m\U000023FA\033[0m ","\033[21;33m\U000023FA\033[0m ","\033[1;33m\U000023FA\033[0m ","\033[21;32m\U000023FA\033[0m ","\033[21;34m\U000023FA\033[0m ","\033[1;36m\U000023FA\033[0m ", "\033[1;35m\U000023FA\033[0m ","\033[21;35m\U000023FA\033[0m ", "\033[1;30m\U000023FA\033[0m ", "\033[1;37m\U000023FA\033[0m "};
        
        aux[1] = '\0';
        cout << "\e[1mVez do Codemaker!\e[0m" << endl;
        
        for(i=0;i<qte;i++){
            cout << cores_print[i] << " ";
        }
        cout << endl;
        for(i=0;i<qte;i++){
            cout << i << "  " ;
        }
        cout << endl;
        cout << "\e[1mInsira seu código de " << tam << " caracteres";
        if(def.getRep()){
            cout << " com repetições: \e[0m" << endl;
        }else{
            cout << " sem repetições: \e[0m" << endl;
        }
        cin >> code;
        if(!(def.getRep()) && code.length() == tam){
            for(i=0;i<tam;i++){
                for(j=0;j<tam;j++){
                    if(code[i] == code[j] && i!= j){
                        bre=1;
                        break;
                    } else {bre = i+j;}
                }
                if(bre == 1){break;}
            }
            if ( bre == 2*tam-2){
                bre = 0;
            }     
        }
        if(bre == 0 && code.length() == tam){
            for(i=0;i<tam;i++){
                aux[0] = code[i];
                j = atoi(aux);
                if( j> (def.getQte_cor()-1) || j<0 ){
                    bre = 1;
                }
            }
        }
        while(code.length() != tam || bre !=0){         //o codemaker deve continuar inserindo o codigo até q ele esteja dentro das especificações:
                code.clear();                           //numero de cores, tamanho do codigo, sem repetições, etc;
                bre = 0;
                Title();
                cout << "\e[1mCódigo inválido!\e[0m" << endl;
                for(i=0;i<qte;i++){
                    cout << cores_print[i] << " ";
                }
                cout << endl;
                for(i=0;i<qte;i++){
                    cout << i << "  " ;
                }
                cout << endl;
                cout << "\e[1mInsira seu código de " << tam << " caracteres";
                if(def.getRep()){
                    cout << " com repetições: \e[0m" << endl;
                }else{
                    cout << " sem repetições: \e[0m" << endl;
                }
                cin >> code;
                if(!(def.getRep()) && code.length() == tam){
                    for(i=0;i<tam;i++){
                        for(j=0;j<tam;j++){
                            if(code[i] == code[j] && i!= j){
                                bre=1;
                                break;
                            } else {bre = i+j;}
                        }
                        if(bre == 1){break;}
                    }
                    if ( bre == 2*tam-2){
                        bre = 0;
                    }
                    
                }
                if(bre == 0 && code.length() == tam){
                    for(i=0;i<tam;i++){
                        aux[0] = code[i];
                        j = atoi(aux);
                        if( j> (def.getQte_cor()-1) || j<0 ){
                            bre = 1;
                        }
                    }
                }
        }
        vector<Pino> pin(tam);
        for(i = 0; i<tam;i++){
            aux[0] = code[i];
            j = atoi(aux);
            pin[i].setCor(j);
        }
        tab.setCodigo(pin);
        Title();
        cout << "\e[1mO código inserido foi:\e[0m" << endl << endl;
        cout << "\t\t";
        tab.displayCodigo();
        cout << endl;
        cout<< "Entre com qualquer tecla + ENTER para continuar...  ";
        cin >> code;
        Title();
    }    
 
    vector<int> Jogo::codebreaker(Definicoes &def, Tabuleiro &tab, int &tent_atual){
        int i,j,aux2 = 0,bre = 0;
        vector<int> codes(def.getTam_cod());
        string code;
        char aux[2];
        string cores_print[10] ={"\033[21;31m\U000023FA\033[0m ","\033[21;33m\U000023FA\033[0m ","\033[1;33m\U000023FA\033[0m ","\033[21;32m\U000023FA\033[0m ","\033[21;34m\U000023FA\033[0m ","\033[1;36m\U000023FA\033[0m ", "\033[1;35m\U000023FA\033[0m ","\033[21;35m\U000023FA\033[0m ", "\033[1;30m\U000023FA\033[0m ", "\033[1;37m\U000023FA\033[0m "};
        
        aux[1] = '\0';
        cout << "\e[1mVez do Codebreaker!\e[0m" << endl;
        
        cout << endl;
        for(i=0;i<def.getQte_cor();i++){                //mostra as opções de cores
            cout << cores_print[i] << " ";
        }
        cout << endl;
        for(i=0;i<def.getQte_cor();i++){
            cout << i << "  ";
        }
        cout << endl;
        cout << endl <<"\e[1mInsira sua tentativa de "<< def.getTam_cod() <<" cores: \e[0m" << "(" << def.getTentativas()-tent_atual << " tentativas restantes)"<< endl;
        cin >> code;
        if(code.length() == def.getTam_cod()){
            for(i=0;i<code.length();i++){
                aux[0] = code[i];
                j = atoi(aux);
                if( j> (def.getQte_cor()-1) || j<0 ){
                    bre = 1;
                }
            }
        }
        while(code.length() != def.getTam_cod() || bre != 0){       //garantem que a tentativa está dentro dos conformes
            Title();                                                // se não estivee pede outra entrada do usuario
            tab.displayTentativas(tent_atual);
            cout << "\e[1mResposta inválida!\e[0m" << endl;
            cout << endl;
            for(i=0;i<def.getQte_cor();i++){
                cout << cores_print[i] << " ";
            }
            cout << endl;
            for(i=0;i<def.getQte_cor();i++){
                cout << i << "  ";
            }
            cout << endl;
            cout << endl <<"\e[1mInsira sua tentativa de "<< def.getTam_cod() <<" cores: \e[0m" << "(" <<def.getTentativas()-tent_atual << " tentativas restantes)"<< endl;
            cin >> code;
            bre = 0;
            if(code.length() == def.getTam_cod()){
                for(i=0;i<code.length();i++){
                    aux[0] = code[i];
                    j = atoi(aux);
                    if( j> (def.getQte_cor()-1) || j<0 ){
                        bre = 1;
                    }
                }
            }
        }
        for(i=0;i<code.length();i++){
            aux[0] = code[i];
            codes[i] = atoi(aux);
        }
        codes = tab.setTentativa(tent_atual,codes);                     //insere a tentativa na matriz e recebe a resposta
        tent_atual++;
        Title();
        cout << "\e[1mA tentativa inserida foi:\e[0m" << endl << endl;
        cout << "\t\t";
        tab.displayTentativa(tent_atual-1);
        cout << endl <<endl;
        cout<< "Entre com qualquer tecla + ENTER para vez do codemaker...  ";
        cin >> code;
        return codes;
    }
    
    
    
    
    void Jogo_solo::play(Definicoes &def,Tabuleiro &tab){       //jogo contra o computador
        int i,tent_atual = 0,aux2 = 0 ;
        bool fim = false;
        Title();

        vector<int> codes(def.getTam_cod());
        cout << "\e[1mInicio de jogo!\e[0m" << endl;
        codemaker_comp(def,tab);                                //computador cria um codigo randomico
        while(!fim && tent_atual<=def.getTentativas()-1){       //igual a um jogo de jogador vs jogador só que as respostas são automaticas
            aux2 = 0;
            Title();
            tab.displayTentativas(tent_atual);
            codes = codebreaker(def,tab,tent_atual);
            for(i=0;i<codes.size();i++){
                aux2 += codes[i];
            }
            if(aux2 == 2*codes.size()){
                fim = true;
            }
        }
        cout<< "\033[2J\033[1;1H" << endl << endl;
        if(fim){
            cout << "\t\t\033[1;32m██╗   ██╗ ██████╗  ██████╗███████╗     ██████╗  █████╗ ███╗   ██╗██╗  ██╗ ██████╗ ██╗   ██╗    ██╗\033[0m" << endl;
            cout << "\t\t\033[1;32m██║   ██║██╔═══██╗██╔════╝██╔════╝    ██╔════╝ ██╔══██╗████╗  ██║██║  ██║██╔═══██╗██║   ██║    ██║\033[0m" << endl;
            cout << "\t\t\033[1;32m██║   ██║██║   ██║██║     █████╗      ██║  ███╗███████║██╔██╗ ██║███████║██║   ██║██║   ██║    ██║\033[0m" << endl;
            cout << "\t\t\033[1;32m╚██╗ ██╔╝██║   ██║██║     ██╔══╝      ██║   ██║██╔══██║██║╚██╗██║██╔══██║██║   ██║██║   ██║    ╚═╝\033[0m" << endl;
            cout << "\t\t\033[1;32m ╚████╔╝ ╚██████╔╝╚██████╗███████╗    ╚██████╔╝██║  ██║██║ ╚████║██║  ██║╚██████╔╝╚██████╔╝    ██╗\033[0m" << endl;
            cout << "\t\t\033[1;32m  ╚═══╝   ╚═════╝  ╚═════╝╚══════╝     ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝ ╚═════╝  ╚═════╝     ╚═╝\033[0m" << endl;
        }else{
            cout << "\t\t\033[1;31m██╗   ██╗ ██████╗  ██████╗███████╗    ██████╗ ███████╗██████╗ ██████╗ ███████╗██╗   ██╗    ██╗\033[0m" << endl;
            cout << "\t\t\033[1;31m██║   ██║██╔═══██╗██╔════╝██╔════╝    ██╔══██╗██╔════╝██╔══██╗██╔══██╗██╔════╝██║   ██║    ██║\033[0m" << endl;
            cout << "\t\t\033[1;31m██║   ██║██║   ██║██║     █████╗      ██████╔╝█████╗  ██████╔╝██║  ██║█████╗  ██║   ██║    ██║\033[0m" << endl;
            cout << "\t\t\033[1;31m╚██╗ ██╔╝██║   ██║██║     ██╔══╝      ██╔═══╝ ██╔══╝  ██╔══██╗██║  ██║██╔══╝  ██║   ██║    ╚═╝\033[0m" << endl;
            cout << "\t\t\033[1;31m ╚████╔╝ ╚██████╔╝╚██████╗███████╗    ██║     ███████╗██║  ██║██████╔╝███████╗╚██████╔╝    ██╗\033[0m" << endl;
            cout << "\t\t\033[1;31m  ╚═══╝   ╚═════╝  ╚═════╝╚══════╝    ╚═╝     ╚══════╝╚═╝  ╚═╝╚═════╝ ╚══════╝ ╚═════╝     ╚═╝\033[0m" << endl;
        }
        tab.displayTentativas(tent_atual);
        cout << "O código era: " << endl << "\t\t";
        tab.displayCodigo();
        cout << endl;
    }
    
    
    void Jogo::codemaker_resp(vector<int> &resp,Definicoes &def, Tabuleiro &tab, int &tent_atual){      //resposta inserida pelo codemaker
        int i,bre=0;                                                         //o codigo já sabe a resposta, ela é passada como argumento em respp
        vector<int> solu(def.getTam_cod());
        char aux[2];
        string sol; 
        string cores[3] = {"\U00002219 ","\033[1;37m\U000025CF\033[0m ","\033[1;37m\U000025CB\033[0m "};
        aux[1] = '\0';
        
        Title();
        cout << "\e[1mVez do Codemaker!\e[0m" << endl;
        cout<< "O código é:" << endl;
        tab.displayCodigo();
        cout<< endl << "A tentativa foi:" << endl;
        tab.displayTentativa(tent_atual-1);
        cout << endl<<endl;
        cout << cores[0] << cores[1] << cores[2] << endl;
        cout << "0 " << "1 " << "2" << endl;
        cin >> sol;
        if(sol.length() == def.getTam_cod()){
            for(i=0;i<def.getTam_cod();i++){
                aux[0] = sol[i];
                solu[i] = atoi(aux);
                if(solu[i] != resp[i]){
                    bre=1;
                    break;
                }
            }
        }
        while(sol.length() != def.getTam_cod() || bre != 0 ){
            bre = 0;
            Title();
            cout << "\e[1mResposta inválida!\e[0m" << endl;
            cout<< "O código é:" << endl;
            tab.displayCodigo();
            cout<< endl << "A tentativa foi:" << endl;
            tab.displayTentativa(tent_atual-1);
            cout << endl;
            cout << cores[0] << cores[1] << cores[2] << endl;
            cout << "0 " << "1 " << "2" << endl;
            cin >> sol;
            if(sol.length() == def.getTam_cod()){
                for(i=0;i<def.getTam_cod();i++){
                    aux[0] = sol[i];
                    solu[i] = atoi(aux);
                    if(solu[i] != resp[i]){
                        bre=1;
                        break;
                    }
                }
            }
        }
    }
   void Jogo_solo::codemaker_comp(Definicoes &def, Tabuleiro &tab){         //computador cria um codigo randomico
        int aux = 1,i, j,qte = def.getQte_cor(), tam = def.getTam_cod(),code[6];
        srand(time(NULL));
        vector<Pino> pin(tam);
        
        if(def.getRep()){       //se repetições forem permitadas 
            for(i = 0; i<tam;i++){
                aux = rand() % qte;     //ficar no intervalo de cores permitidas
                code[i] = aux;
            }
        }else{                  //se repetições n forem permitidas
            aux = rand() % qte;
            for(i=0;i<tam;i++){
                code[i] = aux;
                do{
                    aux = rand() % qte;
                    for(j=i;j>=0;j--){          //garante que o numero gerado forem diferente de todos os outros já inserido
                        if(aux == code[j]){
                            aux =-1;
                            break;
                        }
                    }
                } while(aux == -1);
            }
        }
        for(i=0;i<tam;i++){
            cout <<code[i]<< endl;
            pin[i].setCor(code[i]);
        }
        tab.setCodigo(pin);
        tab.displayCodigo();
        cout << endl;
        
    }
    
