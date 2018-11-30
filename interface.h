#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED
/*#include <wiringPi.h> //utilizado para Raspiberry
#define 7 bot1
#define 8 bot2
#define 9 bot3
#define 10 bot4
#define 11 bot5
#define 12 bot6
#define 13 bot7
#define 14 bot8
#define 15 bot9
#define 16 bot10
#define 17 led1
#define 18 led2

wiringPiSetup(); //inicia biblioteca wiringPi
pinMode(7, INPUT);          // configura pino 7 como entrada
pinMode(8, INPUT);          // configura pino 8 como entrada
pinMode(9, INPUT);          // configura pino 9 como entrada
pinMode(10, INPUT);          // configura pino 10 como entrada
pinMode(11, INPUT);          // configura pino 11 como entrada
pinMode(12, INPUT);          // configura pino 12 como entrada
pinMode(13, INPUT);          // configura pino 13 como entrada
pinMode(14, INPUT);          // configura pino 14 como entrada
pinMode(15, INPUT);          // configura pino 15 como entrada
pinMode(16, INPUT);          // configura pino 16 como entrada
pinMode(17, OUTPUT);         // configura pino 17 como saida
*/

class interface {

    public:
        int menuinicialpc();//função da menu principal da maquina de refrigerante apresentada no computador
        //int menuinicialrasp();//função da menu principal da maquina de refrigerante apresentada no Raspberry
        float menumoedapc();//função do menu das moedas apresentado no computador
        //float menumoedarasp();//função do menu das moedas apresentado no Raspberry
        void comprapc();//função utulizada para representar a compra de um produto no computador
        //void comprarasp();//função utulizada para representar a compra de um produto no Raspberry
        void devpc();//função utulizada para representar a devolução do saldo no computador
        //void devrasp();//função utulizada para representar a devolução do saldo no Raspberry
};

int interface::menuinicialpc(){
    int valor;
    cout << "1 - MEET" << endl;
    cout << "2 - ETIRPS" << endl;
    cout << "3 - Depositar moeda" << endl;
    cout << "4 - DEV" << endl;
    cout << "5 - Apresentar anuncio" << endl;
    cout << "6 - Lista de disponibilidade" << endl;
    cout << "7 - Modo programador" << endl; //A opção modo programador permite configurar a maquina
    cin >> valor;
    return valor;
}
/*
int interface::menuinicialrasp(){
        if(digitalRead(bot1) == HIGH){
            return 1;
        }
        if(digitalRead(bot2) == HIGH){
            return 2;
        }
        if(digitalRead(bot3) == HIGH){
            return 3;
        }
        if(digitalRead(bot4) == HIGH){
            return 4;
        }
        if(digitalRead(bot5) == HIGH){
            return 5;
        }
        if(digitalRead(bot6) == HIGH){
            return 6;
        }
        if(digitalRead(bot7) == HIGH){
            return 7;
        }
}
*/
float interface::menumoedapc(){
    float moeda;
    int selecao;
    cout << "Valor da moeda" << endl;
    cout << "1 - 0,25" << endl;
    cout << "2 - 0,50" << endl;
    cout << "3 - 1,00" << endl;
    cin >> selecao;
    switch (selecao){//Nesta etapa fazemos a diferenciação do valor da moeda
        case 1:
            moeda=0.25;
            return moeda;
        break;
        case 2:
            moeda=0.50;
            return moeda;
        break;
        case 3:
            moeda=1;
            return moeda;
        break;
        default :
            cout << "Objeto nao identificado" << endl;
            moeda=0;
            return moeda;
        break;
    }
}
/*
float interface::menumoedarasp(){
        if(digitalRead(bot8) == HIGH){
            return 0.25;
        }
        if(digitalRead(bot9) == HIGH){
            return 0.50;
        }
        if(digitalRead(bot10) == HIGH){
            return 10;
        }
}
*/
void interface::comprapc(){
    cout << "retire seu refrigerante" << endl;
}
/*
void interface::comprarasp(){
    digitalWrite(led1, HIGH); // liga o pino 17
    delay(1000);           // espera 1 segundo
    digitalWrite(led1, LOW);  // desliga o pino 17
    delay(1000);		 //  espera 1 segundo
}
*/
void interface::devpc(){
    cout << "retire seu saldo" << endl;
}
/*
void interface::devrasp(){
    digitalWrite(led2, HIGH); // liga o pino 17
    delay(1000);           // espera 1 segundo
    digitalWrite(led2, LOW);  // desliga o pino 17
    delay(1000);		 //  espera 1 segundo
}
*/
#endif // INTERFACE_H_INCLUDED
