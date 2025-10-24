#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

void procurarSoma(ll *numeroDasCasas,ll somaProcurada,unsigned int quantidadeCasas){
    ll somaAtual = 0;

    for(int i = 0; i < quantidadeCasas; i++){
        for(int j = i + 1; j < quantidadeCasas; j++){
            somaAtual = numeroDasCasas[i] + numeroDasCasas[j];

            if(somaAtual == somaProcurada){

                printf("SIM\n%d %d\n",i+1,j+1);

                return;
            }
        }
    }
    printf("NAO\n");
    
}

int main(){
    // para atender a restrição de (2 <= N <= 10 ^ 5)
    unsigned int quantidadeCasas = 0;
    scanf("%d",& quantidadeCasas);

    ll *numeroDasCasas = NULL;
    numeroDasCasas = (ll*) calloc(quantidadeCasas, sizeof(ll));
    
    if (numeroDasCasas == NULL){
        printf("Erro ao alocar memória!");
        return(1);
    }

    for(int i = 0; i < quantidadeCasas;i++){
        scanf("%lld", &numeroDasCasas[i]);
    }

    ll somaProcurada;
    scanf("%lld",&somaProcurada);

    procurarSoma(numeroDasCasas, somaProcurada, quantidadeCasas);

    free(numeroDasCasas);

    return 0;
}