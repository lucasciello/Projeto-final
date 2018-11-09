#ifndef COFRE_H_INCLUDED
#define COFRE_H_INCLUDED
#include "produtos.h""
#include <iostream>

using namespace std;

class cofre : public produto {
    private:
        float saldo;
    public:
        cofre();
        void setsaldo(int i, float val); // i=0 +, i=1 - ; função usada para acrescentar o valor da moeda colocada na maquina
        void getsaldo();
        void compra();
        void DEV();
};

cofre::cofre(){
    saldo=0;
}

void cofre::setsaldo(int i, float val){
    if(i==0){
        saldo=saldo+val;
        if(saldo > 1.5 ){
            cout << "Devolve: " << saldo-1.5 << endl;
            saldo=1.5;
        }
    }
    if(i==1){
        saldo=saldo-val;
        if(saldo < 0){
            saldo=0;
        }
    }
}

void cofre::getsaldo(){
    cout << "Saldo: " << saldo << endl;
}

void cofre::compra(){
    if(saldo >= 1.5){
        saldo=0;
        cout << "retire seu refrigerante" << endl;
    }
}

void cofre::DEV(){
    cout << "Devolve: " << saldo << endl;
    saldo = 0;
}

#endif // COFRE_H_INCLUDED
