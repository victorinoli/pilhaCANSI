#include "Node.h"
#include "LeArquivo.h"

#include <stdio.h>

int main() {
    struct Queue *lista = init();

    /* Criando alguns nós manualmente */
    struct Node *victor = newNode("victor", "m", 50000.0);
    struct Node *vivian = newNode("vivian", "f", 50000.0);
    struct Node *lanche = newNode("lanche", "m", 10.0);
    struct Node *chaticia = newNode("chaticia", "f", 80.0);
    struct Node *meninas = newNode("meninas", "f", 20.0);
    struct Node *pequena = newNode("pequena", "f", 15.0);

    /* Inserindo na lista */
    push(victor, lista);
    push(vivian, lista);
    push(chaticia, lista);
    push(meninas, lista);
    push(lanche, lista);
    push(pequena, lista);

    /* Imprimindo lista */
    printList(lista);

    printf("-----------\n");

    retornaLinha(lista);

    walkList(lista);

    int temp = 0;

    if (scanf("%d", &temp) != 1) {
        printf("Erro na entrada de dados.\n");
        return 1;
    }

    return 0;
}
