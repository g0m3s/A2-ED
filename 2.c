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
    strcpy(carta->naipe, naipe); //ta errado kkkkkk
    carta  ->proximo = NULL;


    if(!(duracell  ->inicio == NULL )){

        duracell  ->topo  ->proximo = carta;
        duracell  ->topo = carta;

    }else
        
        duracell  ->inicio = carta;
        duracell  ->topo = carta;

    printf("\n A carta foi inserida!\n");

}


void remove(PILHA *duracell, char naipe[2] ){

    CARTA *auxiliar;

    if(!(duracell  ->inicio == NULL)){

        auxiliar = duracell  ->inicio;

        while(!(auxiliar == duracell  ->topo)){

            if(strcmp(auxiliar  ->naipe, naipe) == 0){

                free(auxiliar);
                printf("\nA carta foi removida! \n");

            }else

                auxiliar = auxiliar  ->proximo;

        }

    }else

        printf("\nImpossivel remover qualquer item pois a pilha esta vazia!\n");

}


void exibeTopo(PILHA *duracell){

    if (!(duracell  ->inicio == NULL)){

        printf("\ nA carta do topo e %s ", duracell->topo->naipe);

    }else

        printf("A pilha esta vazia!");

}



int main(){

    PILHA duracell;
    int escolha;
    char nNaipe[2];

    inicializar(&duracell);

    do{

        printf("\n 1 - PARA INSERIR UMA CARTA\n");
        printf("\n 2 - PARA REMOVER UMA CARTA\n");
        printf("\n 3 - PARA EXIBIR A CARTA QUE ESTA NO TOPO DA PILHA\n");
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
/*
        case 2:

            printf("Informe a carta a ser removida: ");
            scanf(" %s", nNaipe);
            remove(&duracell, nNaipe);

        break;
*/
        case 3:

            exibeTopo(&duracell);

        default:

            printf("\nOpcao invalida!\n");

            break;
        }

    }while(escolha != 0);


    return 0;
}