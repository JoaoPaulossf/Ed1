#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

//função que recebe um vetor ordenado e verifica se alguma soma entre dois elementos é igual ao valor fornecido
void procurarSoma(ll *vetor,ll somaProcurada, unsigned int tamanhoVetor){
    int indiceEsquerda = 0;
    int indiceDireita = tamanhoVetor - 1;

    
    while(indiceEsquerda < indiceDireita){
        ll soma = vetor[indiceEsquerda] + vetor[indiceDireita];
        
        if (soma == somaProcurada){
            printf("SIM\n%d %d\n",indiceEsquerda + 1,indiceDireita + 1);
            return;
        }
        else if (soma < somaProcurada) indiceEsquerda++;
        else if(soma > somaProcurada) indiceDireita--;
    }
    printf("NAO\n");
}

int main(){
    unsigned int quantidadeCasas = 0; // para atender a restrição de (2 <= N <= 10 ^ 5)
    // -- entradas --
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

    // -- saidas --
    procurarSoma(numeroDasCasas,somaProcurada,quantidadeCasas); //chamada da função principal para a resolução do problema
    
    free(numeroDasCasas); // desalocando a mémoria

    return 0;
}