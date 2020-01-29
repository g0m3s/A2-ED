#include <stdio.h>
#include <stdlib.h>

/*Construa um programa que implemente as operações abaixo em uma pilha de números
inteiros:
a) Inserir um número.
b) Remover um número.
c) Exibir o número do topo da pilha.
d) Exibir todos os números de uma pilha.
e) Copiar todos os números para outra pilha. */

 struct celula {

  int valor;
  struct celula *proximo;

};

typedef struct celula CELULA;

struct pilha{

  CELULA *topo;
  CELULA *inicio;

};

typedef struct pilha PILHA;

void inicializar(PILHA *duracell){

    duracell->topo = NULL;
    duracell->inicio = NULL;

}

void inserir(PILHA *duracell, int valor){

    CELULA *procarionte;

    procarionte = (CELULA*) malloc(sizeof(CELULA));

    procarionte ->valor = valor;
    procarionte ->proximo = NULL;

    if(!(duracell->inicio == NULL)){

        duracell  ->topo->proximo = procarionte;
        duracell  ->topo = procarionte;

    }else{

        duracell  ->inicio = procarionte;
        duracell  ->topo = procarionte;

    }
    
    printf("\no valor foi inserido!\n");

}

void remover(PILHA *duracell, int valor){ 

    CELULA *auxiliar;

    if(!(duracell  ->inicio == NULL)){

        auxiliar  = duracell ->inicio;

        do{
        
        if( auxiliar  ->valor == valor){

            auxiliar->valor = 0;
            free(auxiliar); //acho que agora tem que ligar o anterior a outro proximo
            printf("\nO valor foi excluido!\n");

        }else

            auxiliar = auxiliar  ->proximo;

        }while(auxiliar ->proximo != duracell -> topo);

    }else

        printf("\nA pilha esta vazia. Impossivel excluir qualquer valor!\n");

}

void valorTopo(PILHA *duracell){

    if(!(duracell ->inicio == NULL)){

        printf("O valor do topo da pilha e: %d", duracell->topo->valor);

    }else
        printf("A pilha esta vazia! impossivel exibir qualquer valor");

}

void exibeTodos(PILHA *duracell){ 

    if(!(duracell ->inicio == NULL)){

        CELULA *auxiliar;
        int contador = 0;

        auxiliar = duracell ->inicio;

        do{

        printf("    posicao %d: %d \n", contador, auxiliar-> valor);

        auxiliar = auxiliar  ->proximo;
        contador++;

        if(auxiliar == duracell ->topo)
            printf("    posicao %d: %d \n", contador, auxiliar-> valor);

        }while(!(auxiliar == duracell ->topo ));

    }else
    
        printf("\n Nao ha o que exibir! \n");

}

void copiar(PILHA *duracell, PILHA *panasonic){

    CELULA *auxiliar;

    if(!(duracell->inicio == NULL)){

        while(duracell  ->topo != NULL){

        auxiliar = duracell ->topo;
        inserir(&panasonic, auxiliar  ->valor);
        remover(&duracell, auxiliar ->valor);

        }


    }else

        printf("\nA pilha esta vazia!\n");

}




int main(void) {

    PILHA duracell, panasonic;
    int escolha, valor;

    inicializar(&panasonic);
    inicializar(&duracell);
  

    do{

        printf("\n 1 - PARA INSERIR UM VALOR\n");
        printf(" 2 - PARA REMOVER UM VALOR\n");
        printf(" 3 - PARA EXIBIR O VALOR DO TOPO DA PILHA\n");
        printf(" 4 - PARA EXIBIR TODOS OS VALORES DA PILHA\n");
        printf(" 5 - PARA COPIAR TODOS OS VALORES PARA OUTRA PILHA\n");
        printf(" 0 - PARA SAIR\n");
        printf("\n");
        printf(" Sua escolha: ");
        scanf("%d", &escolha);
        

        switch(escolha){

            case 1:

                printf("\nInforme o valor: ");
                scanf("%d",&valor);

                inserir(&duracell, valor);

            break;

            case 2:

                printf("\nInforme o valor a ser removido: ");
                scanf("%d",&valor);

                remover(&duracell, valor);

            break;

            case 3:

                valorTopo(&duracell);

            break;

            case 4:

                exibeTodos(&duracell);

            break;

            case 5: 
            
                copiar(&duracell, &panasonic);

            break;

        }


    }while(escolha != 0);
    
    return 0;
}