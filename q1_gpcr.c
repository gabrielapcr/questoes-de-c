#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct no
{
    int item;
    struct no *esquerda;
    struct no *direita;
};