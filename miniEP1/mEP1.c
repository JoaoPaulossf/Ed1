#include <stdio.h>
#include <stdlib.h>

/* Definindo long long como ll */
typedef long long ll;

/* função para somar x nas posições do vetor de a ate b */
void soma(ll a, ll b, ll x, ll *vetor){
    a -= 1;
    for(int i = a; i < b; i++){
        vetor[i] += x;
    }

}
/* função para subtrair x nas posições do vetor de a ate b */
void subtracao(ll a, ll b, ll x, ll *vetor){
    a -= 1;
    for(int i = a; i < b; i++){
        vetor[i] -= x;
    }

}
/* função para imprimir o valor que esta na posição i do vetor */
void imprime(ll i, ll *vetor){
    i -= 1;
    printf("%lld\n",vetor[i]);
}

int main(){
    /* primeira linha de entrada */
    int n,m;
    scanf("%d %d", &n, &m);

    /* Alocando dimanicamente */
    ll *vetor;
    vetor = (ll *)calloc(n, sizeof(ll));
    if (vetor == NULL){
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    /* Criando variaveis e inicializando com 0*/
    ll opcao = 0,a = 0,b = 0,x = 0;
    
    for(ll i = 0; i < m; i++){
        scanf("%lld",&opcao);
        
        /* Switch para usar a função correspondente ao numero informado */
        switch (opcao){
        case 1:
            scanf("%lld %lld %lld",&a,&b,&x);
            soma(a,b,x,vetor);
            break;
        case 2:
            scanf("%lld %lld %lld",&a,&b,&x);
            subtracao(a,b,x,vetor);
            break;
        case 3:
            scanf("%lld", &a);
            imprime(a,vetor);
            break;
        default:
            break;
        }
    }
    free(vetor);
}