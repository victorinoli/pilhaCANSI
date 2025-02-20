/*
Created by victo on 17/02/2025.
*/

#include "leArquivo.h"

#include <ctype.h>
#include "node.h"
#include <stdio.h>
#include <stdlib.h>

void retornaLinha(struct Queue *q) {
    FILE *arquivo = fopen("./exemplo.txt", "r");
    char linha[256];

    if (arquivo == NULL) {
        printf("Arquivo nao encontrado.\n");
    } else {
        while (fgets(linha, 256, arquivo) != NULL) {

            /* printf("%s\n", linha); */

            char nome[101];
            char sexo[2];
            char salario[10];
            double salarioDouble;
            int i;

            for (i = 0; i < 100; i++) {
                nome[i] = linha[i];
            }
            nome[100] = '\0';

            sexo[0] = linha[100];
            sexo[1] = '\0';

            for (i = 0; i < 10; i++) {
                salario[i] = linha[101 + i];
            }
            salario[9] = '\0';

            salarioDouble = atof(salario);

            /* printf("%s\n", nome); */
            /* printf("%s\n", sexo); */
            /* printf("%.2f\n", salarioDouble); */

            toLowerCase(nome);

            struct Node *temp = newNode(nome, sexo, salarioDouble);
            push(temp, q);
        }
    }
    fclose(arquivo);
}

void toLowerCase(char *str) {
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;

        if (*str == ' ' && *(str + 1) == ' ') {
            *str = '\0';
            break;
        }
    }
}
