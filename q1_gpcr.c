#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct no
{
    char produto[15];
    float value;
    int qnt;
    struct no *next;
};
char produto[15];
float value = 0;
int qnt = 0;
char escolha[20];

struct no *head = NULL;

void Inserir()
{
    struct no *No = malloc(sizeof(struct no));

    scanf("%s %f %d", &produto, &value, &qnt);

    strcpy(No->produto, produto);
    No->value = value;
    No->qnt = qnt;
    No->next = head;
    head = No;
}

void Remover(char produto[15], int qnt)
{
    struct no *No = head;
    struct no *anterior = head;

    if (head != NULL)
    {
        while (strcmp(produto, No->produto) != 0)
        {
            anterior = No;
            No = No->next;
            if (No->next == NULL)
            {
                break;
            }
        }
        if (strcmp(produto, No->produto) == 0)
        {
            No->qnt = No->qnt - qnt;
            if (No->qnt == 0)
            {
                if (No->next == NULL)
                {
                    anterior->next = NULL;
                    free(No);
                }
                else if (No->next != NULL)
                {
                    anterior->next = No->next;
                    free(No);
                }
            }
        }
    }
}

void remover_grupo()
{
    scanf(" %f", &value);
    struct no *No = head;
    struct no *anterior = head;
    while (No != NULL)
    {
        if (No->value > value)
        {
            if (head == No)
            {
                head = head->next;
                free(No);
            }
            else if (No->next == NULL)
            {
                anterior->next == NULL;
                free(No);
            }
            else if (No->next != NULL)
            {
                anterior->next = No->next;
                free(No);
            }
        }
        anterior = No;
        No = No->next;
    }
}

void consultar()
{
    float soma = 0;
    struct no *No = head;
    while (No != NULL)
    {
        soma += (No->value * No->qnt);
        No = No->next;
    }
    printf("\nAtualmente a lista esta em R$%.1f\n", soma);
}

void procurar_nome(char produto[15])
{
    struct no *aux = head;
    while (strcmp(produto, aux->produto) != 0)
    {
        if (aux->next == NULL)
        {
            break;
        }
        aux = aux->next;
    }
    if (aux != NULL)
    {
        if (strcmp(produto, aux->produto) == 0)
        {
            printf("\n%s\n- %.1f\n- %d\n", aux->produto, aux->value, aux->qnt);
        }
        else
        {
            printf("\n%s nao foi encontrado.\n", produto);
        }
    }
}

int main()
{

    while (scanf("%s", &escolha) != EOF)
    {
        if (strcmp(escolha, "INSERIR") == 0)
        {
            Inserir();
        }
        else if (strcmp(escolha, "REMOVER") == 0)
        {
            Remover(produto, qnt);
        }
        else if (strcmp(escolha, "CONSULTAR") == 0)
        {
            consultar();
        }
        else if (strcmp(escolha, "PROCURAR") == 0)
        {
            procurar_nome(produto);
        }
        else if (strcmp(escolha, "REMOVERGRUPO") == 0)
        {

            remover_grupo();
        }


    }
    return 0;
}