#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

/* cria uma lista a partir de um vetor (apenas para teste) */
Lista *criaListaDeVetor(int *v, int n) {
    Lista *l = criaLista();
    No *ultimo = NULL;
    for (int i = 0; i < n; ++i) {
        No *no = novoNo(v[i]);
        if (!no) return l;
        if (l->inicio == NULL) {
            l->inicio = no;
            l->fim = no;
        } else {
            l->fim->proximo = no;
            l->fim = no;
        }
    }
    return l;
}

/* libera memória (somente nós) - usado no exemplo */
void liberaLista(Lista *l) {
    if (!l) return;
    No *p = l->inicio;
    while (p) {
        No *tmp = p->proximo;
        free(p);
        p = tmp;
    }
    free(l);
}

int main() {
    int a[] = {1,2,5,10};
    int b[] = {3,7,8,11};

    Lista *l1 = criaListaDeVetor(a, sizeof(a)/sizeof(a[0]));
    Lista *l2 = criaListaDeVetor(b, sizeof(b)/sizeof(b[0]));

    printf("l1: "); imprimeLista(l1);
    printf("l2: "); imprimeLista(l2);

    Lista *res = juntaLista(l1, l2);
    printf("resultado: "); imprimeLista(res);

    // se quiser, libera as estruturas (os nós agora pertencem a res)
    liberaLista(res);
    free(l1); // l1->inicio já foi "movido" para res; só libera o struct Lista
    free(l2);

    return 0;
}
