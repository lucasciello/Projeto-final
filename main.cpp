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
    string anuncio; //variavel usada para salvar os anuncios que sairam da fila e serão adicionados novamente
    int senha; //carial usada para armazenar a senha para acessar o modo programador
    string novo; //varial usada para armazenar um noco produto
    interface *p;//ponteiro usadado para fazer o polimorfismo entre as interfaces do sistema

    produtos.insertAfterLast("MEET-disponivel"); //produto inicial
    produtos.insertAfterLast("ETIRPS-disponivel"); //produto inicial

    while(loop == 0){ // Loop
        switch (selecao){ //Menu da maquina
            case 0:
                refrigerante.getsaldo();//função utilizada para apresentar o soldo, utilizada no computador
                selecao=p->menuinicialpc();//Aqui é feito o polimorfismo, o ponteiro pode apontar para a função correspondente ao seu sistema operacional
            break;
            case 1: //Nesta opção se existe saldo é efetuada a compra do produto MEET
                if(refrigerante.compra()==1){
                    p->comprapc();
                    selecao=0;
                }
                else{
                    selecao=0;
                }
            break;
            case 2://Nesta opção se existe saldo é efetuada a compra do produto ETIRPS
                if(refrigerante.compra()==1){
                    p->comprapc();
                    selecao=0;
                }
                else{
                    selecao=0;
                }
            break;
            case 3://Nesta opção é simulado a entrada das moedas
                moeda=p->menumoedapc();
                refrigerante.setsaldo(0,moeda);
                selecao=0;
            break;
            case 4://Nesta opção é devolvido o saldo caso exista
                if(refrigerante.DEV()==1){
                    p->devpc();
                    selecao=0;
                }
                else{
                    selecao=0;
                }
            break;
            case 5://Nesta opção é apresetado o anuncio
                if(fila1.head ==0){
                    cout << "Nao existem anuncios" << endl;//caso não existam anuncios cadastrados a maquina acusa
                }
                else{
                    cout << fila1.mostrar() << endl;
                    anuncio=fila1.mostrar();
                    fila1.removeranuncio();
                    fila1.adicionaritem(anuncio);
                }
                selecao=0;
            break;
            case 6://Nesta opção são apresentados os produtos e suas disponibilidades
                if(produtos.head == 0){
                    cout << "Nao existem produtos cadastrados" << endl;//caso não existam produtos cadastrados a maquina acusa
                }
                else{
                    produtos.listAll();
                }
                selecao=0;
            break;
            case 7://Nesta opção é acessado o modo programador
                cout << "Senha:" << endl;
                cin >> senha;//Leitura da senha

                if(senha == 9090){//ao digitar a senha correta, é apresentado o menu do programador
                    cout << "1 - Incluir anuncio" << endl;
                    cout << "2 - Adicionar a lista de reporducao" << endl;
                    cout << "3 - Remoner anuncio" << endl;
                    cout << "4 - Adicionar produto" << endl;
                    cout << "5 - Remover produto" << endl;
                    cout << "6 - Sair do modo programador" << endl;
                    cin >> senha;

                    switch (senha){
                        case 1://Nesta opção são adicionados novos anuncios
                            cout << "Digite o anuncio" << endl;
                            cin >> anuncio;
                            fila2.adicionaritem(anuncio);
                            cout << "Anuncio armazenado" << endl;
                            selecao=0;
                        break;
                        case 2://Nesta opção são carregados os anuncios da fila 2 para a fila 1
                            while(fila2.head != 0){
                                fila1.adicionaritem(fila2.head->getVal());
                                fila2.removeranuncio();
                            }
                            cout << "Anuncios adicionados a lista de reproducao" << endl;
                            selecao=0;
                        break;
                        case 3://Nesta opção é removido o primeiro anuncio da fila 1
                            if(fila1.head !=0){
                                fila1.removeranuncio();
                                cout << "Anuncio removido" << endl;
                            }
                            else{//Caso não existam anuncios a maquina acusa
                                cout << "Nao existem anuncios" << endl;
                            }
                            selecao=0;
                        break;
                        case 4://Nesta opção são adicioados os produto e sua deisponibilidade
                            cout << "Para adicionar o produto a lista, escreva no seguinte formato:" << endl;
                            cout << "produto-disponibilidade" << endl;
                            cin >> novo;
                            produtos.insertAfterLast(novo);
                            cout << "produto adicionado" << endl;
                            selecao=0;
                        break;
                        case 5://Nesta opção são removidos os anuncios
                            cout << "digite o anuncio a ser removido" << endl;
                            cin >> novo;
                            produtos.removeNode(novo);
                            cout << "produto removido" << endl;
                            selecao=0;
                        break;
                        case 6://Nesta opção saimos do modo programdor
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
