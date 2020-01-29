#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Construa um programa que implemente uma pilha de cartas de baralho. Cada carta deve
conter o número e o naipe. Implemente as operações abaixo:
a) Inserir uma carta.
b) Remover uma carta.
c) Exibir a carta do topo da pilha.
d) Consultar se uma carta está na pilha.
e) Embaralhar as cartas da pilha. 
*/

struct carta {

    char naipe[2];
    struct carta *proximo;

};

struct pilha {

    struct carta *topo;
    struct carta *inicio;

};

typedef struct carta CARTA;
typedef struct pilha PILHA;

void inicializar(PILHA *duracell){

    duracell->inicio = NULL;
    duracell->topo = NULL;

}

void insere(PILHA *duracell, char naipe[2] ){

    CARTA *carta;

    carta = (CARTA*)malloc(sizeof(CARTA));
    carta  ->naipe = strcpy(naipe, carta->naipe); //ta errado kkkkkk
    carta  ->proximo = NULL;


    if(!(duracell  ->inicio == NULL )){

        duracell  ->topo  ->proximo = carta;
        duracell  ->topo = carta;

    }else
        
        duracell  ->inicio = carta;
        duracell  ->topo = carta;

}




int main(){

    PILHA duracell;
    int escolha;
    char nNaipe[2];

    inicializar(&duracell);

    do{

        printf("\n 1 - PARA INSERIR UMA CARTA\n");
        printf("\n 2 - PARA REMOVER UMA CARTA\n");
        printf(" 0 - PARA SAIR\n");
        printf("\n");
        printf(" Sua escolha: ");
        scanf("%d", &escolha);

        switch (escolha){
            
        case 1:

        printf("Informe o numero e o naipe da carta: ");
        scanf(" %s", nNaipe);
        insere(&duracell, nNaipe);

        break;
        
        default:

            printf("\nOpcao invalida!\n");

            break;
        }

    }while(escolha != 0);


    return 0;
}