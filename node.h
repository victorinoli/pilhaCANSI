//
// Created by victo on 13/02/2025.
//

#ifndef NODE_H
#define NODE_H

    typedef struct Node {
        char nome[100];
        char sexo[2];
        double salario;
        struct Node *next;
        struct Node *prev;
    } Node;

    typedef struct Queue {
        Node *front;
        Node *rear;
    } Queue;

    Node *newNode(const char *nome, const char *sexo, double salario);

    Queue *init();

    void push(Node *n, Queue *q);

    Node *pop(Queue *q);

    void printList(const Queue *q);

    void walkList(const Queue *q);

#endif // NODE_H
