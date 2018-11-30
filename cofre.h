#ifndef COFRE_H_INCLUDED
#define COFRE_H_INCLUDED
#include "produtos.h""
#include <iostream>

using namespace std;

class cofre : public produto {
    private:
        float saldo;//variavel usada para armazenar o saldo
    public:
        cofre();
        void setsaldo(int i, float val); // i=0 +, i=1 - ; função usada para acrescentar o valor da moeda colocada na maquina
        void getsaldo();//função usada para apresentar o saldo
        int compra();//funcao usada para liberar o produto e descontar o saldo
        int DEV();// funçao usada para devolver o saldo
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

int cofre::compra(){
    if(saldo >= 1.5){
        saldo=0;
        return 1;
    }
}

int cofre::DEV(){
    if(saldo != 0){
        saldo = 0;
        return 1;
    }
}

#endif // COFRE_H_INCLUDED
