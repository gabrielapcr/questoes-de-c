#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct no {
    char character;
    struct no *next;
};

struct pilha {
    struct no *head;
};

void push(struct pilha *p, char character);
void pop(struct pilha *p);

int main(void)
{
    struct pilha *p = (struct pilha *)malloc(sizeof(struct pilha));
    p->head = NULL;
    char character[100000];
    int value, cont = 0, i = 0, teste = 0;

    scanf("%d", &value);
    while (cont < value) {
        cont++;
        i = 0;
        scanf("%s", character);
        while (character[i] != '\0') {
            if (character[i] == '[' || character[i] == '(' 
            || character[i] == '{') {
                teste = 1;
            } else {
                teste = 0;
            }
            if (teste == 0) {
                if (p->head == NULL) {
                    push(p, character[i]);
                    break;
                }
                if (character[i] == ']') {
                    if (p->head->character == '[') {
                        pop(p);
                        i++;
                    } else {
                        break;
                    }
                } else if (character[i] == ')') {
                    if (p->head->character == '(') {
                        pop(p);
                        i++;
                    } else {
                        break;
                    }
                } else if (character[i] == '}') {
                    if (p->head->character == '{') {
                        pop(p);
                        i++;
                    } else {
                        break;
                    }
                }
            } else {
                push(p, character[i]);
                i++;
            }
        }
        if (p->head != NULL) {
            printf("N\n");
        } else {
            printf("S\n");
        }
        while (p->head != NULL) {
            pop(p);
        }
    }
    return 0;
}
void push(struct pilha *p, char character)
{
    struct no *No = (struct no *)malloc(sizeof(struct no));

    No->character = character;
    No->next = p->head;
    p->head = No;
}
void pop(struct pilha *p)
{
    struct no *ponteiro = p->head;

    p->head = ponteiro->next;
    free(ponteiro);
}
