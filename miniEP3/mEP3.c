#include <stdio.h>
#include <stdlib.h>

//struct que usei para armazenar as coordenadas dos pontos de interesse(final e inicial)
typedef struct ponto{
    int linha;
    int coluna;
}Ponto;

//variaveis globais
char **labirinto;
Ponto inicial,final;
int NumLinhas,NumColunas,menorCaminho = -1;
int passos = 0;


char **AlocaMatriz(int linhas,int colunas){
    char **matriz = malloc(linhas * sizeof(char *));
    for(int i = 0; i < linhas; i++){
        matriz[i] = malloc(colunas * sizeof(char));
    }
    return matriz;
}

void imprimeMatriz(char **matriz,int linhas,int colunas){
    for(int i = 0;i < linhas;i++){
        for(int j = 0;j < colunas; j++){
            printf("%c",matriz[i][j]);
        }
        printf("\n");
    }
}

void liberaMatriz(char **matriz,int linhas){
    for(int i = 0; i < linhas;i++){
        free(matriz[i]);
    }
    free(matriz);
}

//função que caminha e sempre armazena na variavel global o menor valor de caminho, caso exista caminho
void caminhaMapa(int linha,int coluna,int passosAtuais){
    
    //verificações para não acessar posições invalidas
    if(linha < 0 || coluna < 0 || linha >= NumLinhas || coluna >= NumColunas){
        passosAtuais--;
        return;
    }

    if (labirinto[linha][coluna] == '#' || labirinto[linha][coluna] == 'v'){
        return;
    }

    //verifica se chegou no final usando as coordenadas da variavel tipo ponto
    if(linha == final.linha && coluna == final.coluna){
        if(menorCaminho != -1){
            if(passosAtuais < menorCaminho){
                menorCaminho = passosAtuais;
            }
        }else{
            menorCaminho = passosAtuais;
        }
        return;
    }

    if (menorCaminho != -1 && passosAtuais >= menorCaminho){
        return;
    }

    char charOriginal = labirinto[linha][coluna]; // Guarda 'S' ou '.'
    labirinto[linha][coluna] = 'v';

    //tentativas de caminhar para a proxima casa
    caminhaMapa(linha, coluna - 1,passosAtuais+1);
    caminhaMapa(linha, coluna + 1,passosAtuais+1);
    caminhaMapa(linha - 1, coluna,passosAtuais + 1);
    caminhaMapa(linha + 1, coluna, passosAtuais + 1);

    labirinto[linha][coluna] = charOriginal; 
}

int main(){
    scanf("%d %d", &NumLinhas, &NumColunas);
    
    labirinto = AlocaMatriz(NumLinhas, NumColunas + 1);
    for (int i = 0; i < NumLinhas;i++){
        for(int j = 0;j < NumColunas;j++){
            scanf(" %c", &labirinto[i][j]);
            if(labirinto[i][j] == '#' || labirinto[i][j] == '.'){
                continue;
            }else if(labirinto[i][j] == 'S'){
                inicial.linha = i;
                inicial.coluna = j;
            }else if(labirinto[i][j] == 'E'){
                final.linha = i;
                final.coluna = j;
            }
        }
    }
    
    caminhaMapa(inicial.linha, inicial.coluna, passos);

    if(menorCaminho == -1){
        printf("Sem solucao\n");
    }else{
        printf("%d\n",menorCaminho);
    }

    liberaMatriz(labirinto,NumLinhas);
}