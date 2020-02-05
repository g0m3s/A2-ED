#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

Elabore um programa para construir uma árvore binária de busca, onde cada nó da árvore
possua as informações sobre um livro (título, autor e editora), com as operações: inserir,
remover, descobrir quantas vezes um título existe na árvore, exibir os livros utilizando o
percurso pós-ordem. 

*/

struct arvore {

    char titulo[30], autor[30], editora[30];

    struct arvore *esquerda, *direita;

};

typedef struct arvore ARVORE;


void insere ( ARVORE *arvore, char titulo[30], char autor[30], char editora[30] ) {

    ARVORE *auxiliar;

    if (! ( arvore == NULL) ){

        if ( ( strcmp (titulo, arvore  -> esquerda) ) < 0 )

            insere( & (arvore ->esquerda), titulo, autor, editora  );

        else

            insere( & (arvore ->direita), titulo, autor, editora  );

    }else {

        auxiliar = (ARVORE*)malloc(sizeof(ARVORE));
        strcpy(auxiliar  ->titulo, titulo);
        strcpy(auxiliar  ->autor, autor);
        strcpy(auxiliar  ->editora, editora);
        auxiliar  ->direita = NULL;
        auxiliar  ->esquerda = NULL;
        arvore = auxiliar;
        
    }

}

void remove ( ARVORE *arvore, char titulo[30] ){

    


}

void verificaQuantidade ( ARVORE *arvore, char titulo[30] ) { //ver como percorre

    if ( ! (arvore == NULL) ){



    }

}

void posOrdem ( ARVORE *arvore ){

    if ( arvore != NULL ) {
        
        ordem(arvore->esquerda);
        ordem(arvore->direita);
        printf("Titulo: %s \n Autor: %s \n Editora: %s \n", arvore->titulo, arvore  ->autor, arvore  ->editora);

    }else

        printf("\n A arvore esta vazia! \n");

}


int main (  ) {

    int escolha;
    char titulo[30], autor[30], editora[30];
    ARVORE arvore;

     do {

        printf(" 1 - INSERIR \n");
        printf(" 2 - REMOVER \n");
        printf(" 3 - QUANT. DO LIVRO \n");
        printf(" 4 - EXIBIR EM POS-ORDEM \n");
        scanf( "%d", &escolha );

        switch (escolha) {

            case 1:

            printf("\nInforme o titulo: ");
            scanf( "%s", titulo );

            printf("\nInforme o autor: ");
            scanf( "%s", autor );

            printf("\nInforme a editora: ");
            scanf( "%s", editora );

            insere (&arvore, titulo, autor, editora );

            break;

            case 2:

                printf("Informe o titulo a ser removido");
                scanf( "%s", titulo );

                remove( &arvore, titulo );

            break;

            case 3:

                printf("Informe o titulo: ");
                scanf("%s", titulo);

                verificaQuantidade(&arvore, titulo);

            break;

            

            case 4:

                posOrdem(&arvore);

            break;
            
            default:

                printf("\n Opcao invalida! \n");

            break;

            

        }

    }while( escolha != 0 );



    return 0;
}