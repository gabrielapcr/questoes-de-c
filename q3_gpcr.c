#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int produto(int x, int y);
int main(void)
{
    int cordas, custo_corda, resultado, moedas;
    while (scanf("%d %d %d", &cordas, &moedas, &custo_corda) != EOF) {
        resultado = produto(cordas, custo_corda);
        if (moedas - resultado >= 0) {
            printf("Sim\n");
        } else {
            printf("Nao\n");
        }
    }
    return 0;
}
int produto(int x, int y)
{
    if (y > x) {
        return produto(y, x);
    }
    if (y != 0) {
        return (y + produto(y, x - 1));
    } else {
        return 0;
    }
}