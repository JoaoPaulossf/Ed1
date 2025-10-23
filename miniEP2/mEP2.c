#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

void procurarSoma(ll *numeroDasCasas,ll somaProcurada,int quantidadeCasas,ll *numero1,ll *numero2){
    ll soma = 0;
    int i = 0,j = 0;
    while(somaProcurada != soma){
        if (i == quantidadeCasas){
            printf("NAO\n");
            printf("\n");
            return;
        }
        if(j == quantidadeCasas){
            j = 0;
            i++;
        }

        soma = numeroDasCasas[i] + numeroDasCasas[j];
    }

    *numero1 = numeroDasCasas[i];
    *numero2 = numeroDasCasas[j];

    printf("SIM\n%lld %lld\n",*numero1,*numero2);
}

int main(){
    int QuantidadeCasas = 0;
    scanf("%d",&QuantidadeCasas);

    ll *numeroDasCasas = NULL;
    numeroDasCasas = (ll*) calloc(QuantidadeCasas, sizeof(ll));
    
    if (numeroDasCasas == NULL){
        printf("Erro ao alocar memória!");
        return(1);
    }

    for(int i = 0; i < QuantidadeCasas;i++){
        scanf("%lld", &numeroDasCasas[i]);
    }

    ll somaProcurada = 0;
    scanf("%lld",&somaProcurada);

    ll *numero1,*numero2;

    procurarSoma(numeroDasCasas,somaProcurada,QuantidadeCasas,numero1,numero2);

}