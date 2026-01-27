#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Imagem.h"
#include "Filtros.h"

/**
 * @brief Converte uma imagem para escala de cinza
 * 
 * @param img Ponteiro para a imagem a ser convertida
 */
void escalaDeCinzaImagem(Imagem *img){
    AVISO(Filtros.c: Ainda não implementei a função 'escalaDeCinzaImagem'); //Retire esssa mensagem ao implementar a fução
    if(img == NULL)
        return;
    for(int i = 0; i < obtemAltura(img); i++){
        for(int j = 0; j < obtemLargura(img); j++){
            Cor c = obtemCorPixel(img, i, j);
            int media = (c.r + c.g + c.b) / 3;
            c.r = c.g = c.b = media;
            recolorePixel(img,i,j,c);
        }
    }
    
}

/**
 * @brief Aplica o filtro Sobel a uma imagem
 * 
 * @param img Ponteiro para a imagem a ser filtrada
 */
void filtroSobel(Imagem *img){//rever depois
    if(img == NULL)
        return;
    Imagem *copia = copiaImagem(img);
    if(copia == NULL)
        return; 
    int Gx[3][3] = {
        {  1,  0, -1 },
        {  2,  0, -2 },
        {  1,  0, -1 }
    };

    int Gy[3][3] = {
        {  1,  2,  1 },
        {  0,  0,  0 },
        { -1, -2, -1 }
    };

    for (int i = 1; i < obtemAltura(img) - 1;i++){
        for(int j = 1; j < obtemLargura(img) - 1; j++){
            int gx_r = 0, gx_g = 0, gx_b = 0;
            int gy_r = 0, gy_g = 0, gy_b = 0;

            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {

                    Cor c = obtemCorPixel(copia, i + di, j + dj);

                    int wx = Gx[di + 1][dj + 1];
                    int wy = Gy[di + 1][dj + 1];

                    gx_r += c.r * wx;
                    gx_g += c.g * wx;
                    gx_b += c.b * wx;

                    gy_r += c.r * wy;
                    gy_g += c.g * wy;
                    gy_b += c.b * wy;
                }
            }
            int r = abs(gx_r) + abs (gy_r);
            int g = abs(gx_g) + abs(gy_g);
            int b = abs(gx_b) + abs(gy_b);

            if (r > 255) r = 255;
            if (g > 255) g = 255;
            if (b > 255) b = 255;

            if (r < 0) r = 0;
            if (g < 0) g = 0;
            if (b < 0) b = 0;

            Cor out = { r, g, b };
            recolorePixel(img, i, j, out);
        }
    }
    liberaImagem(copia);
}

/**
 * @brief Aplica o filtro Laplace a uma imagem
 * 
 * @param img Ponteiro para a imagem a ser filtrada
 */
void deteccaoBordasLaplace(Imagem *img) {
    if(img == NULL)
        return;
    Imagem *copia = copiaImagem(img);
    if(copia == NULL)
        return;
    int mat[3][3] = {
        {0, -1 , 0},
        {-1 , 4, -1},
        {0, -1, 0}
    };
    for (int i = 1; i < obtemAltura(img) - 1;i++){
        for(int j = 1; j < obtemLargura(img) - 1; j++){
            int mat_r = 0, mat_g = 0, mat_b = 0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    Cor c = obtemCorPixel(copia, i + di, j + dj);
                    
                    int matriz = mat[di + 1][dj + 1];

                    mat_r += c.r * matriz;
                    mat_g += c.g * matriz;
                    mat_b += c.b * matriz;
                }
            }
            int r = abs(mat_r);
            int g = abs(mat_g);
            int b = abs(mat_b);

            if (r > 255) r = 255;
            if (g > 255) g = 255;
            if (b > 255) b = 255;

            if (r < 0) r = 0;
            if (g < 0) g = 0;
            if (b < 0) b = 0;

            Cor out = { r, g, b };
            recolorePixel(img, i, j, out);
        }
    }
    liberaImagem(copia);
}

/**
 * @brief Aplica um filtro personalizado a uma imagem
 * 
 * @param img Ponteiro para a imagem a ser filtrada
 */
void meuFiltro(Imagem *img){
    if(img == NULL)
        return;   
    int h = obtemAltura(img);
    int l = obtemLargura(img);

    Imagem *copia = copiaImagem(img);
    if (copia == NULL)
        return; 
    
    int ch = h / 2;
    int cl = l / 2;

    float k = 0.7f;

    float rMax = sqrt(ch*ch + cl*cl);

    for(int i = 0; i < h; i++){
        for(int j = 0; j < l; j++){
            float dh = i - ch;
            float dl = j - cl;

            float r = sqrt(dh*dh + dl*dl);
            float fator = 1 + k * (r*r) /(rMax * rMax);

            int srcH = (int)(ch + dh / fator);
            int srcL = (int)(cl + dl / fator);

            if(srcH >=0 && srcH < h && srcL >=0 && srcL < l){
                Cor c = obtemCorPixel(copia, srcH, srcL);
                recolorePixel(img,i,j,c);
            }
        }
    }
    liberaImagem(copia);
}