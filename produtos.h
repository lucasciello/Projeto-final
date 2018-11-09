#ifndef PRODUTOS_H_INCLUDED
#define PRODUTOS_H_INCLUDED
#include <iostream>

using namespace std;

class produto {
    private:
        int refri;
        float valor;
    public:
        produto();
        virtual void compra()=0;
};

produto::produto(){
    refri=0;
    valor=1.5;
}

#endif // PRODUTOS_H_INCLUDED
