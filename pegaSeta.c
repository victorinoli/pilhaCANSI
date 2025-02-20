#include "pegaSeta.h"
#include <stdio.h>

#ifdef _WIN32
    #include <conio.h>  // Para _getch() no Windows
#else
    #include <termios.h>
    #include <unistd.h>
#endif

// Função para capturar um único caractere sem necessidade de pressionar ENTER (Linux)
#ifndef _WIN32
char getch_linux() {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);  // Salva configuração atual do terminal
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);  // Desativa entrada bufferizada e eco
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);  // Aplica nova configuração
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);  // Restaura configuração original
    return ch;
}
#endif

int detectArrowKeys() {
    printf("Pressione as setas ou use W, A, S, D como alternativa.\n");

    while (1) {
        char ch;

#ifdef _WIN32
        ch = _getch();  // Captura tecla no Windows

        if (ch == 224) {  // Código especial (setas)
            ch = _getch();  // Captura o segundo código
            switch (ch) {
                case 72: return 0; // CIMA
                case 80: return 1; // BAIXO
                case 75: return 1; // ESQUERDA
                case 77: return 0; // DIREITA
            }
        }
#else
        ch = getch_linux();  // Captura tecla no Linux
#endif

        // Teclas alternativas: W, A, S, D
        switch (ch) {
            case 'w': case 'W': return 0; // CIMA
            case 's': case 'S': return 1; // BAIXO
            case 'a': case 'A': return 1; // ESQUERDA
            case 'd': case 'D': return 0; // DIREITA
            default:
                printf("Outra tecla: %c\nPor favor, digite apenas setas ou W, A, S, D.\n", ch);
            break;
        }
    }
}
