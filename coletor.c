#include<stdio.h>
#include<stdlib.h>

#ifndef COLETOR_H
#define COLETOR_H

typedef struct coletor{
    int cont;
    int *end;
    struct coletor *prox;
}coletor;

coletor *c = NULL;

coletor *limpar(coletor *aux){
    
    if(aux != NULL){

        if(aux->cont == 0){

            aux->prox = limpar(aux->prox);

            coletor *novo = aux->prox;
            free(aux);

            return novo;
        }

        else{

            aux->prox = limpar(aux->prox);

            return aux;
        }
    }
}

void contadorRecebe(int *endd){

    coletor *aux = c;

    while(aux != NULL){

        if(aux->end == endd){

            aux->cont = aux->cont - 1;

            break;
        }

        aux = aux->prox;
    }
}

void contadorAtribuido(int *endd){

    coletor *aux = c;

    while(aux != NULL){

        if(aux->end == endd){

            aux->cont = aux->cont + 1;

            break;
        }

        aux = aux->prox;
    }
}

int *malloc2(int x){

    coletor *aux = c;

    c = (coletor *) malloc (sizeof(coletor));
    c->cont = 1;
    c->end = malloc(x);
    c->prox = aux;
    
    return c->end;
}

void atrib2(int recebe, int atribui){

    contadorRecebe(recebe);
    contadorAtribuido(atribui);

    c = limpar(c);

    recebe = atribui;

}

void dump(){

    coletor *aux = c;

    while(aux != NULL){
        
        printf("O endereco %d possui %d referencias\n", aux->end, aux->cont);

        aux = aux->prox;
        
    }

    printf("\n\n");
}

#endif