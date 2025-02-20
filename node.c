/*
   Created by victo on 13/02/2025.
*/

#include "node.h"
/* #include "pegaSeta.h" */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pegaSeta.h"

struct Node *newNode(const char *nome, const char *sexo, double salario) {
    struct Node *n = malloc(sizeof(struct Node));
    if (!n) {
        printf("Erro ao alocar memória!\n");
        return NULL;
    }
    strncpy(n->nome, nome, sizeof(n->nome) - 1);
    n->nome[sizeof(n->nome) - 1] = '\0'; /* Garante que a string seja terminada corretamente */
    strncpy(n->sexo, sexo, sizeof(n->sexo) - 1);
    n->sexo[sizeof(n->sexo) - 1] = '\0';
    n->salario = salario;
    n->next = NULL;
    return n;
}

struct Queue *init() {
    struct Queue *q = malloc(sizeof(struct Queue));
    if (q == NULL) {
        printf("Erro ao alocar memoria\n");
        return NULL; /* Melhor do que chamar exit(1) */
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void push(struct Node *n, struct Queue *q) {
    n->next = NULL;
    n->prev = NULL;

    if (q->rear == NULL) {
        q->front = n;
        q->rear = n;
    } else {
        n->prev = q->rear;
        q->rear->next = n;
        q->rear = n;
    }
}

struct Node *pop(struct Queue *q) {
    if (q->front == NULL) {
        printf("Sem mais elementos\n");
        return NULL; /* Em vez de exit(1) */
    }

    struct Node *temp = q->rear;
    q->rear = q->rear->prev;
    return temp;
}

void printList(const struct Queue *q) {
    struct Node *temp = q->front;

    if (temp == NULL) {
        printf("Lista vazia\n");
        return;
    }

    while (temp != NULL) {
        printf("%s\n", temp->nome);
        printf("%s\n", temp->sexo);
        printf("%.2f\n", temp->salario);
        temp = temp->next;
    }
}

void walkList(const struct Queue *q, int ordem) {
    struct Node *temp;

    if (q == NULL || q->front == NULL) {
        printf("Lista vazia\n");
        return;
    }

    if (ordem == 1) {
        temp = q->front;
    } else if (ordem == 2) {
        temp = q->rear;
    } else {
        printf("Ordem inválida! Use 1 para crescente e 2 para decrescente.\n");
        return;
    }

    while (1) {
        printf("-----------------------------------------------------------------\n");
        printf("Nome: %s\n", temp->nome);
        printf("Sexo: %s\n", temp->sexo);
        printf("Salario: %.2f\n", temp->salario);

        int i = detectArrowKeys(); // Detecta teclas (0 = frente, 1 = trás)

        if (ordem == 1) {  // Percorrendo em ordem crescente
            if (i == 0 && temp->next != NULL) {
                temp = temp->next;
            } else if (i == 1 && temp->prev != NULL) {
                temp = temp->prev;
            } else {
                printf("Fim da lista.\n");
                break;
            }
        }
        else if (ordem == 2) {
            if (i == 0 && temp->prev != NULL) {
                temp = temp->prev;
            } else if (i == 1 && temp->next != NULL) {
                temp = temp->next;
            } else {
                printf("Fim da lista.\n");
                break;
            }
        }
    }
}


void ordenaLista(struct Queue *q) {
    if (q->front == NULL || q->front->next == NULL) {
        printf("Lista vazia ou com apenas um elemento.\n");
        return;
    }

    int trocou;
    struct Node *atual;
    struct Node *ultimo = NULL;

    do {
        trocou = 0;
        atual = q->front;

        while (atual->next != ultimo) {
            if (strcmp(atual->nome, atual->next->nome) > 0) {

                struct Node *proximo = atual->next;
                struct Node *anterior = atual->prev;

                atual->next = proximo->next;
                if (proximo->next != NULL) {
                    proximo->next->prev = atual;
                }

                proximo->prev = anterior;
                proximo->next = atual;
                atual->prev = proximo;

                if (anterior != NULL) {
                    anterior->next = proximo;
                } else {
                    q->front = proximo;
                }

                if (atual->next == NULL) {
                    q->rear = atual;
                }

                trocou = 1;
            } else {
                atual = atual->next;
            }
        }
        ultimo = atual;
    } while (trocou);
}

