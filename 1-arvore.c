#include <stdio.h>
#include <stdlib.h>

/*

    1. Desenhe uma árvore binária de busca após as operações abaixo:
a) Inserção dos números 15, 6, 20, 3, 12, 18, 25, 23, 30.
b) Remoção do número 15.
c) Remoção do número 20.
d) Escreva os números da árvore utilizando o percurso pré-ordem.
e) Escreva os números da árvore utilizando o percurso em ordem.
f) Escreva os números da árvore utilizando o percurso pós-ordem. 

*/

struct arvore {

    int numero;
    struct arvore *direita, *esquerda;

};

typedef struct arvore ARVORE;

void insere (ARVORE *arvore, int numero ) {

    ARVORE *galho;

    if( (arvore) == NULL ){

        galho = (ARVORE*)malloc(sizeof(ARVORE));
        galho  ->numero = numero;
        galho  ->direita = NULL;
        galho  ->esquerda = NULL;
        arvore = galho;

    }else{

        if( numero < arvore->numero )
            insere( &(arvore->esquerda), numero );
        else
            insere( &(arvore->esquerda), numero );

    }

    printf("\nO numero foi inserido!\n");

}

void preOrdem ( ARVORE *arvore ) {

    if ( arvore != NULL ) {
        
        printf("%d\n", arvore->numero);
        preOrdem(arvore->esquerda);
        preOrdem(arvore->direita);

    }else

        printf("\n A arvore esta vazia! \n");

}

void ordem ( ARVORE *arvore ){

    if ( arvore != NULL ) {
        
        ordem(arvore->esquerda);
        printf("%d\n", arvore->numero);
        ordem(arvore->direita);

    }else

        printf("\n A arvore esta vazia! \n");

}

void posOrdem ( ARVORE *arvore ){

    if ( arvore != NULL ) {
        
        ordem(arvore->esquerda);
        ordem(arvore->direita);
        printf("%d\n", arvore->numero);

    }else

        printf("\n A arvore esta vazia! \n");

}

int main (  ) {

    ARVORE *arvore = NULL;
    int escolha, numero;

    do {

        printf(" 1 - INSERIR \n");
        printf(" 2 - EXIBIR EM PRE-ORDEM \n");
        printf(" 3 - EXIBIR EM ORDEM \n");
        printf(" 4 - EXIBIR EM POS-ORDEM \n");
        scanf( "%d", &escolha );

        switch (escolha) {

            case 1:

            printf("\nInforme um numero: ");
            scanf( "%d", &numero );

            insere (&arvore, numero);

            break;

            case 2:

                preOrdem(&arvore);

            break;

            case 3:

                ordem(&arvore);

            break;

            case 4:

                posOrdem(&arvore);

            break;
            
            default:

            break;

        }

    }while( escolha != 0 );



    return 0;
}