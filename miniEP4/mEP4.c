#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"

Lista *criaLista() {
    Lista *lista = malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->fim = NULL;
    return lista;
}

Lista *juntaLista(Lista *l1, Lista *l2) {
    Lista *resultado = criaLista();

    No **pontProximo = &(resultado->inicio);
    
    No *atualL1 = l1->inicio; 
    No *atualL2 = l2->inicio;
    
    while(atualL1 != NULL && atualL2 != NULL){
    
        No *menor = NULL;

        if(atualL1->id >= atualL2->id){
            menor = atualL2;
            atualL2 = atualL2->proximo;
        }else{
            menor = atualL1;
            atualL1 = atualL1->proximo;
        }

        *pontProximo = menor;
        pontProximo = &(menor->proximo);

        resultado->fim = menor;
    }

    if(atualL1 != NULL){
        *pontProximo = atualL1;
        resultado->fim = l1->fim;
    }else if (atualL2 != NULL){
        *pontProximo = atualL2;
        resultado->fim = l2->fim;
    }
    if (resultado->fim != NULL){
        resultado->fim->proximo = NULL;
    }
        
    return resultado;
}
