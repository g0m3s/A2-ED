#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

Elabore um programa para construir uma árvore binária de busca, onde cada nó da árvore
possua as informações sobre uma pessoa (nome, telefone e e-mail), com as operações:
inserir, remover, descobrir o telefone de uma pessoa, exibir as pessoas utilizando o
percurso pré-ordem. 
  

*/

struct arvore {

    char nome[30], telefone[30], email[30];

    struct arvore *esquerda, *direita;

};

typedef struct arvore ARVORE;


void insere ( ARVORE *arvore, char nome[30], char telefone[30], char email[30] ) {

    ARVORE *auxiliar;

    if (! ( arvore == NULL) ){

        if ( ( strcmp (nome, arvore  -> esquerda) ) < 0 )

            insere( & (arvore ->esquerda), nome, telefone, email  );

        else

            insere( & (arvore ->direita), nome, telefone, email  );

    }else {

        auxiliar = (ARVORE*)malloc(sizeof(ARVORE));
        strcpy(auxiliar  ->nome, nome);
        strcpy(auxiliar  ->telefone, telefone);
        strcpy(auxiliar  ->email, email);
        auxiliar  ->direita = NULL;
        auxiliar  ->esquerda = NULL;
        arvore = auxiliar;
        
    }

}

void remove ( ARVORE *arvore, char nome[30] ){

    


}

void descobreTelefone ( ARVORE *arvore, char nome[30] ) { //ver como percorre

    if ( ! (arvore == NULL) ){



    }

}

void preOrdem ( ARVORE *arvore ) {

    if ( arvore != NULL ) {
        
        printf("Nome: %s \n Telefone: %s \n Email: %s \n", arvore->nome, arvore  ->telefone, arvore  ->email);
        preOrdem(arvore->esquerda);
        preOrdem(arvore->direita);

    }else

        printf("\n A arvore esta vazia! \n");

}

int main (  ) {

    int escolha;
    char nome[30], telefone[30], email[30];
    ARVORE arvore;

     do {

        printf(" 1 - INSERIR \n");
        printf(" 2 - REMOVER \n");
        printf(" 3 - DESCOBRIR TELEFONE \n");
        printf(" 4 - EXIBIR EM PRE-ORDEM \n");
        scanf( "%d", &escolha );

        switch (escolha) {

            case 1:

            printf("\nInforme o nome\: ");
            scanf( "%s", nome );

            printf("\nInforme o telefone: ");
            scanf( "%s", telefone );

            printf("\nInforme a email: ");
            scanf( "%s", email );

            insere (&arvore, nome, telefone, email );

            break;

            case 2:

                printf("Informe o nome\ a ser removido");
                scanf( "%s", nome );

                remove( &arvore, nome );

            break;

            case 3:

                printf("Informe o nome\: ");
                scanf("%s", nome);

                descobreTelefone(&arvore, nome);

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