#include <iostream>
#include "lista.h"

using namespace std;

int main()
{
    List produtos;
    int loop=0;
    int selecao=0;
    int senha;
    string novo;

        produtos.insertAfterLast("cocacola-indisponivel");
        produtos.insertAfterLast("fanta-indisponivel");
        produtos.insertAfterLast("pureza-indisponivel");
        produtos.insertAfterLast("MEET-disponivel");
        produtos.insertAfterLast("ETIRPS-disponivel");

    while(loop == 0){

        switch (selecao){
            case 0:
                cout << "1 - listar produtos" << endl;
                cout << "2 - Modo programador" << endl; // senha:9090
                cin >> selecao;
            break;
            case 1:
                produtos.listAll();
                selecao=0;
            break;
            case 2:
                cout << "Senha:" << endl;
                cin >> senha;

                if(senha == 9090){
                    cout << "1 - Adicionar produto" << endl;
                    cout << "2 - remover produto" << endl;
                    cout << "3 - Sair do modo programador" << endl;
                    cin >> senha;

                    switch (senha){
                        case 1:
                            cout << "Para adicionar o produto a lista, escreva no seguinte formato:" << endl;
                            cout << "produto disponibilidade" << endl;
                            cin >> novo;
                            produtos.insertAfterLast(novo);
                            selecao=0;
                            cout << "produto adicionado" << endl;
                        break;
                        case 2:
                            cout << "digite o anuncio a ser removido" << endl;
                            cin >> novo;
                            produtos.removeNode(novo);
                            cout << "produto removido" << endl;
                            selecao=0;
                        break;
                        case 3:
                            selecao=0;
                        break;
                    }
                }
                else{
                    cout << "Senha invalida" << endl;
                    selecao=0;
                }
            break;
            default :
                selecao=0;
            break;
        }
    }

    return 0;
}
