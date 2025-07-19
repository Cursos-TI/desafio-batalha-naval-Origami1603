#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define NAVIO_VALOR 3
#define HABILIDADE_VALOR 5

// Função para imprimir o tabuleiro com cabeçalho A-J e linhas 1-10
void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("    A  B  C  D  E  F  G  H  I  J\n");
    for (int i = 0; i < TAM; i++) {
        printf("%2d |", i + 1);
        for (int j = 0; j < TAM; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para aplicar uma matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[7][7], int tamanho, int cx, int cy) {
    int offset = tamanho / 2;
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            int x = cx - offset + i;
            int y = cy - offset + j;
            if (x >= 0 && x < TAM && y >= 0 && y < TAM) {
                if (habilidade[i][j] == 1 && tabuleiro[x][y] != NAVIO_VALOR) {
                    tabuleiro[x][y] = HABILIDADE_VALOR;
                }
            }
        }
    }
}

// Preenche matriz de cone (ponta para baixo)
void criarCone(int matriz[7][7]) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            matriz[i][j] = (i >= 2 && abs(3 - j) <= i - 2) ? 1 : 0;
        }
    }
}

// Preenche matriz em forma de cruz
void criarCruz(int matriz[7][7]) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            matriz[i][j] = (i == 3 || j == 3) ? 1 : 0;
        }
    }
}

// Preenche matriz em forma de octaedro (losango)
void criarOctaedro(int matriz[7][7]) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            matriz[i][j] = (abs(3 - i) + abs(3 - j) <= 3) ? 1 : 0;
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // Posiciona dois navios horizontais/verticais
    for (int i = 0; i < NAVIO; i++) tabuleiro[2][1 + i] = NAVIO_VALOR; // Horizontal
    for (int i = 0; i < NAVIO; i++) tabuleiro[4 + i][6] = NAVIO_VALOR; // Vertical

    // Posiciona dois navios diagonais
    for (int i = 0; i < NAVIO; i++) tabuleiro[6 + i][1 + i] = NAVIO_VALOR; // Diagonal principal
    for (int i = 0; i < NAVIO; i++) tabuleiro[1 + i][8 - i] = NAVIO_VALOR; // Diagonal secundária

    // Criar matrizes de habilidade
    int cone[7][7], cruz[7][7], octaedro[7][7];
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Aplicar habilidades ao tabuleiro
    aplicarHabilidade(tabuleiro, cone, 7, 1, 1);       // Cone em B2
    aplicarHabilidade(tabuleiro, cruz, 7, 5, 5);       // Cruz em F6
    aplicarHabilidade(tabuleiro, octaedro, 7, 8, 8);   // Octaedro em I9

    // Imprimir tabuleiro final
    printf("=== TABULEIRO DE BATALHA NAVAL ===\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}
