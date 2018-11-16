#include <iostream>
#include "fila.h"
#include "node.h"

using namespace std;

int main()
{
    fila fila1;
    fila fila2;
    int selecao=0;
    string anuncio;
    int loop=0;

    while(loop == 0){
        switch (selecao){
            case 0:
                cout << "1 - Incluir anuncio" << endl;
                cout << "2 - Carregar" << endl;
                cout << "3 - Remoner" << endl;
                cout << "4 - Iniciar apresentacao dos anuncios" << endl;
                cin >> selecao;
            break;
            case 1:
                cout << "Digite o anuncio" << endl;
                cin >> anuncio;
                fila2.adicionaritem(anuncio);
                selecao=0;
            break;
            case 2:
                while(fila2.head != 0){
                    fila1.adicionaritem(fila2.head->getVal());
                    fila2.removeranuncio();
                }
                cout << "Anuncios adicionados a lista de reproducao" << endl;
                selecao=0;
            break;
            case 3:
                if(fila1.head !=0){
                    fila1.removeranuncio();
                    cout << "Anuncio removido" << endl;
                }
                else{
                    cout << "Nao existem anuncios" << endl;
                }
                selecao=0;
            break;
            case 4:
                while(loop == 0){
                    cout << fila1.mostrar() << endl;
                    anuncio=fila1.mostrar();
                    fila1.removeranuncio();
                    fila1.adicionaritem(anuncio);
                }
            default :
                selecao=0;
            break;
        }
    }
    return 0;
}
