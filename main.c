#include "Node.h"
#include "LeArquivo.h"

#include <stdio.h>

int main() {

    int ordem = 0;
    struct Queue *lista = init();

    printf("deseja imprimir a lista em 1 para ordem crescente ou 2 para decrescente?");

    scanf("%d", &ordem);

    retornaLinha(lista);
    ordenaLista(lista);

    walkList(lista, ordem);

    return 0;
}
