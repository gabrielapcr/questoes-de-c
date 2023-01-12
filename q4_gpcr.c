#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int menor(int primeiro, int segundo, int terceiro);

int main(void)
{
    int n;
    scanf("%d", &n);
    int matriz[n][n];
    int i, j, mesa[n][n], maior, maior_resultado;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
    for (i = 0; i < n; i++) {
        mesa[i][0] = matriz[i][0];
    }
    for (j = 0; j < n; j++) {
        mesa[0][j] = matriz[0][j];
    }
    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            if (matriz[i][j] == 1) {
                mesa[i][j] = 1 + menor(mesa[i-1][j-1],
                 mesa[i-1][j], mesa[i][j-1]);
            } else {
                mesa[i][j] = 0;
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (mesa[i][j] > maior) {
                maior = mesa[i][j];
            }
        }
    }
    maior_resultado = maior * maior;
    printf("%d", maior_resultado);
    return 0;
}
int menor(int primeiro, int segundo, int terceiro)
{
    int menor = primeiro;
    if (menor > segundo) {
        menor = segundo;
    }
    if (menor > terceiro) {
        menor = terceiro;
    }
    return menor;
}