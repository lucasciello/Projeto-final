#include <iostream>
#include "cofre.h"

using namespace std;

int main()
{   int selecao=0; //variavel usada para simular os botoes da maquina
    int loop=0; //variavel usada para gerar o loop
    float moeda; //varialvel usada para simular as moedas
    cofre refrigerante;

    while(loop == 0){
        switch (selecao){
            case 0:
                refrigerante.getsaldo();
                cout << "1 - MEET" << endl;
                cout << "2 - ETIRPS" << endl;
                cout << "3 - Depositar moeda" << endl;
                cout << "4 - DEV" << endl;
                cin >> selecao;
            break;
            case 1:
                refrigerante.compra();
                selecao=0;
            break;
            case 2:
                refrigerante.compra();
                selecao=0;
            break;
            case 3:
                cout << "Valor da moeda" << endl;
                cout << "1 - 0,25" << endl;
                cout << "2 - 0,50" << endl;
                cout << "3 - 1,00" << endl;
                cin >> selecao;
                    switch (selecao){
                        case 1:
                            moeda=0.25;
                            selecao=0;
                        break;
                        case 2:
                            moeda=0.50;
                            selecao=0;
                        break;
                        case 3:
                            moeda=1;
                            selecao=0;
                        break;
                        default :
                            cout << "Objeto nao identificado" << endl;
                            moeda=0;
                            selecao=0;
                        break;
                    }

                refrigerante.setsaldo(0,moeda);

            break;
            case 4:
                refrigerante.DEV();
                selecao=0;
            break;
            default :
                selecao=0;
            break;
        }
    }
    return 0;
}
