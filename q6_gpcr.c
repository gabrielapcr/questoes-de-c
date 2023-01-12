#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int cont1;
int comparar(char palavras[], char palavras_pesquisadas[])
{
    int i, cont = 0;
    for (i = 0;; i++) {
        if (palavras[i] == '\0' || palavras_pesquisadas[i] == '\0' 
        || palavras[i] != palavras_pesquisadas[i]) 
            break;
        cont++;
    }
    if (palavras[i] != '\0' && palavras_pesquisadas[i] != '\0')
        cont++;
    return cont;
}
int busca_binaria(char palavras[][11], int primeiro, int ultimo,
          char palavra_pesquisada[])
{
    int meio;
    int teste;
    while (ultimo >= primeiro) {
        meio = primeiro + (ultimo - primeiro) / 2;
        if (strcmp(palavras[meio], palavra_pesquisada) == 0) {
            cont1 += strlen(palavra_pesquisada);
            return meio;
        } else if (strcmp(palavras[meio], palavra_pesquisada) > 0) {
            ultimo = meio - 1;
            cont1 += comparar(palavras[meio], palavra_pesquisada);
        } else {
            primeiro = meio + 1;
            cont1 += comparar(palavras[meio], palavra_pesquisada);
        }
    }
    return -1;
}
int main(void)
{
    int qnt_palavras, qnt_pesquisadas, i = 0, resultado;
    int primeiro, meio, ultimo;
    cont1 = 0;
    scanf("%d %d", &qnt_palavras, &qnt_pesquisadas);

    char palavras[qnt_palavras][11],
        palavras_pesquisadas[qnt_pesquisadas][11];
    for (i = 0; i < qnt_palavras; i++) {
        scanf("%s", palavras[i]);
    }
    for (i = 0; i < qnt_pesquisadas; i++) {
        scanf("%s", palavras_pesquisadas[i]);
    }
    for (i = 0; i < qnt_pesquisadas; i++) {
        cont1 = 0;
        primeiro = 0;
        ultimo = qnt_palavras - 1;
        resultado = busca_binaria(palavras, primeiro, ultimo,
                      palavras_pesquisadas[i]);
        if (resultado == -1) {
            printf("NAO %d\n", cont1);
        } else {
            printf("SIM %d\n", cont1);
        }
    }

    return 0;
}
