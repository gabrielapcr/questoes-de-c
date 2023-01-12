#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct no
{
	int value;
	struct no *next;
};
struct pilha
{
	struct no *head;
};

int elemento;
void push(struct pilha *p, int elemento)
{
	struct no *No = malloc(sizeof(struct no));
	No->value = elemento;
	No->next = p->head;
	p->head = No;  
}

// 
void pop(struct pilha *p)
{
	struct no *No = p->head;
	if (p->head != NULL)
	{
		printf("%d\n", No->value);
		p->head = No->next;
		free(No);
	}
}


void maior_menor(int max, int min,struct pilha *p)
{  
    struct no *m = p->head;
    while(m != NULL)
    {  
        
        if (m->value > max){
            max = m->value;
        }
        if (m->value <min){
            min = m->value;
        }
        m = m->next;
        printf("%d\n", max - min);
    }
}


int main()
{
	struct pilha *p = (struct pilha*)malloc(sizeof(struct pilha));
    p->head = NULL;
	char entrada[15];
	int value;
	int condicaoParada = 1;

	while (scanf("%s", &entrada) != EOF)
	{
		if (strcmp(entrada, "push") == 0) {
			scanf("%d", &elemento);
			push(p, elemento);
		}
		else if (strcmp(entrada, "pop") == 0) {
			pop(p);
		}
		else if (strcmp(entrada, "abs") == 0) {
            int max = -1;
            int min = 1001;
			maior_menor(max, min,p);
		}
	}
}
