#include <iostream>
#include "cofre.h"
#include "fila.h"
#include "lista.h"
#include "interface.h"

using namespace std;

int main()
{   int selecao=0; //variavel usada para simular os botoes da maquina
    int loop=0; //variavel usada para gerar o loop
    float moeda; //varialvel usada para simular as moedas
    cofre refrigerante;
    fila fila1;
    fila fila2;
    List produtos;
    string anuncio; //variavel usada para salvar os anuncios que sairam da fila e ser�o adicionados novamente
    int senha; //carial usada para armazenar a senha para acessar o modo programador
    string novo; //varial usada para armazenar um noco produto
    interface *p;//ponteiro usadado para fazer o polimorfismo entre as interfaces do sistema

    produtos.insertAfterLast("MEET-disponivel"); //produto inicial
    produtos.insertAfterLast("ETIRPS-disponivel"); //produto inicial

    while(loop == 0){ // Loop
        switch (selecao){ //Menu da maquina
            case 0:
                refrigerante.getsaldo();//fun��o utilizada para apresentar o soldo, utilizada no computador
                selecao=p->menuinicialpc();//Aqui � feito o polimorfismo, o ponteiro pode apontar para a fun��o correspondente ao seu sistema operacional
            break;
            case 1: //Nesta op��o se existe saldo � efetuada a compra do produto MEET
                if(refrigerante.compra()==1){
                    p->comprapc();
                    selecao=0;
                }
                else{
                    selecao=0;
                }
            break;
            case 2://Nesta op��o se existe saldo � efetuada a compra do produto ETIRPS
                if(refrigerante.compra()==1){
                    p->comprapc();
                    selecao=0;
                }
                else{
                    selecao=0;
                }
            break;
            case 3://Nesta op��o � simulado a entrada das moedas
                moeda=p->menumoedapc();
                refrigerante.setsaldo(0,moeda);
                selecao=0;
            break;
            case 4://Nesta op��o � devolvido o saldo caso exista
                if(refrigerante.DEV()==1){
                    p->devpc();
                    selecao=0;
                }
                else{
                    selecao=0;
                }
            break;
            case 5://Nesta op��o � apresetado o anuncio
                if(fila1.head ==0){
                    cout << "Nao existem anuncios" << endl;//caso n�o existam anuncios cadastrados a maquina acusa
                }
                else{
                    cout << fila1.mostrar() << endl;
                    anuncio=fila1.mostrar();
                    fila1.removeranuncio();
                    fila1.adicionaritem(anuncio);
                }
                selecao=0;
            break;
            case 6://Nesta op��o s�o apresentados os produtos e suas disponibilidades
                if(produtos.head == 0){
                    cout << "Nao existem produtos cadastrados" << endl;//caso n�o existam produtos cadastrados a maquina acusa
                }
                else{
                    produtos.listAll();
                }
                selecao=0;
            break;
            case 7://Nesta op��o � acessado o modo programador
                cout << "Senha:" << endl;
                cin >> senha;//Leitura da senha

                if(senha == 9090){//ao digitar a senha correta, � apresentado o menu do programador
                    cout << "1 - Incluir anuncio" << endl;
                    cout << "2 - Adicionar a lista de reporducao" << endl;
                    cout << "3 - Remoner anuncio" << endl;
                    cout << "4 - Adicionar produto" << endl;
                    cout << "5 - Remover produto" << endl;
                    cout << "6 - Sair do modo programador" << endl;
                    cin >> senha;

                    switch (senha){
                        case 1://Nesta op��o s�o adicionados novos anuncios
                            cout << "Digite o anuncio" << endl;
                            cin >> anuncio;
                            fila2.adicionaritem(anuncio);
                            cout << "Anuncio armazenado" << endl;
                            selecao=0;
                        break;
                        case 2://Nesta op��o s�o carregados os anuncios da fila 2 para a fila 1
                            while(fila2.head != 0){
                                fila1.adicionaritem(fila2.head->getVal());
                                fila2.removeranuncio();
                            }
                            cout << "Anuncios adicionados a lista de reproducao" << endl;
                            selecao=0;
                        break;
                        case 3://Nesta op��o � removido o primeiro anuncio da fila 1
                            if(fila1.head !=0){
                                fila1.removeranuncio();
                                cout << "Anuncio removido" << endl;
                            }
                            else{//Caso n�o existam anuncios a maquina acusa
                                cout << "Nao existem anuncios" << endl;
                            }
                            selecao=0;
                        break;
                        case 4://Nesta op��o s�o adicioados os produto e sua deisponibilidade
                            cout << "Para adicionar o produto a lista, escreva no seguinte formato:" << endl;
                            cout << "produto-disponibilidade" << endl;
                            cin >> novo;
                            produtos.insertAfterLast(novo);
                            cout << "produto adicionado" << endl;
                            selecao=0;
                        break;
                        case 5://Nesta op��o s�o removidos os anuncios
                            cout << "digite o anuncio a ser removido" << endl;
                            cin >> novo;
                            produtos.removeNode(novo);
                            cout << "produto removido" << endl;
                            selecao=0;
                        break;
                        case 6://Nesta op��o saimos do modo programdor
                            selecao=0;
                        break;
                    }

                }
                else{//caso a senha esteja errada
                    cout << "Senha invalida" << endl;
                    selecao=0;
                }
            default :
                selecao=0;
            break;
        }
    }
    return 0;
}
