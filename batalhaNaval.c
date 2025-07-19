#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.


#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

// Função para verificar se pode posicionar o navio sem sair do tabuleiro ou sobrepor
int podePosicionar(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int direcaoLinha, int direcaoColuna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int novaLinha = linha + i * direcaoLinha;
        int novaColuna = coluna + i * direcaoColuna;

        if (novaLinha < 0 || novaLinha >= TAMANHO_TABULEIRO || novaColuna < 0 || novaColuna >= TAMANHO_TABULEIRO)
            return 0; // Fora do tabuleiro
        if (tabuleiro[novaLinha][novaColuna] != VALOR_AGUA)
            return 0; // Sobreposição
    }
    return 1;
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int direcaoLinha, int direcaoColuna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int novaLinha = linha + i * direcaoLinha;
        int novaColuna = coluna + i * direcaoColuna;
        tabuleiro[novaLinha][novaColuna] = VALOR_NAVIO;
    }
}



int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.


    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Navio 1 – Horizontal (linha 2, colunas 1 a 3 → B3 a D3)
    if (podePosicionar(tabuleiro, 2, 1, 0, 1))
        posicionarNavio(tabuleiro, 2, 1, 0, 1);
    else {
        printf("Erro ao posicionar o Navio 1.\n");
        return 1;
    }

    // Navio 2 – Vertical (coluna 6, linhas 4 a 6 → G5 a G7)
    if (podePosicionar(tabuleiro, 4, 6, 1, 0))
        posicionarNavio(tabuleiro, 4, 6, 1, 0);
    else {
        printf("Erro ao posicionar o Navio 2.\n");
        return 1;
    }

    // Navio 3 – Diagonal principal (linha 0, coluna 0 → A1 a C3)
    // Navio 3 – Diagonal principal (linha 6, coluna 0 → A7 a C9)
    if (podePosicionar(tabuleiro, 6, 0, 1, 1))
    posicionarNavio(tabuleiro, 6, 0, 1, 1);

    else {
        printf("Erro ao posicionar o Navio 3.\n");
        return 1;
    }

    // Navio 4 – Diagonal secundária (linha 0, coluna 9 → J1 a H3)
    if (podePosicionar(tabuleiro, 0, 9, 1, -1))
        posicionarNavio(tabuleiro, 0, 9, 1, -1);
    else {
        printf("Erro ao posicionar o Navio 4.\n");
        return 1;
    }

    // Impressão do cabeçalho (A a J)
    printf("\n     ");
    for (int col = 0; col < TAMANHO_TABULEIRO; col++) {
        printf(" %c ", 'A' + col);
    }
    printf("\n");

    // Impressão do tabuleiro com linhas numeradas
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d |", i + 1);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }



    
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
