// src/tabuleiro.c
// ---------------------------------------------------------------------
// Implementação das funções que manipulam o tabuleiro do Batalha Naval.
// Aqui utilizamos uma matriz 10x10 de inteiros para representar o mapa.
// ---------------------------------------------------------------------

#include <stdio.h>
#include "tabuleiro.h"

// ---------------------------------------------------------------------
// Função: inicializarTabuleiro
// Preenche toda a matriz do tabuleiro com VALOR_AGUA (0).
// ---------------------------------------------------------------------
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {          // Percorre as linhas
        for (int j = 0; j < TAM; j++) {      // Percorre as colunas
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }
}

// ---------------------------------------------------------------------
// Função: imprimirTabuleiro
// Imprime a matriz 10x10 no console, com espaços entre os números,
// para facilitar a visualização do tabuleiro.
// ---------------------------------------------------------------------
void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("=== TABULEIRO 10x10 ===\n\n");

    // Cabeçalho de colunas
    printf("    ");
    for (int j = 0; j < TAM; j++) {
        printf("%2d ", j);
    }
    printf("\n");

    // Linha separadora
    printf("   ");
    for (int j = 0; j < TAM; j++) {
        printf("---");
    }
    printf("\n");

    // Linhas do tabuleiro
    for (int i = 0; i < TAM; i++) {
        printf("%2d |", i); // Índice da linha
        for (int j = 0; j < TAM; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nLegenda: %d = água, %d = navio\n\n", VALOR_AGUA, VALOR_NAVIO);
}

// ---------------------------------------------------------------------
// Função auxiliar: verifica se uma posição está livre (água).
// Retorna 1 se estiver livre, 0 caso contrário.
// ---------------------------------------------------------------------
static int posicaoLivre(int tabuleiro[TAM][TAM], int linha, int coluna) {
    return (tabuleiro[linha][coluna] == VALOR_AGUA);
}

// ---------------------------------------------------------------------
// Função: posicionarNavioHorizontal
// Tenta posicionar um navio na horizontal.
// linha         -> linha fixa onde o navio será colocado
// colunaInicial -> primeira coluna do navio
// tamanho       -> quantidade de casas ocupadas pelo navio
// ---------------------------------------------------------------------
int posicionarNavioHorizontal(int tabuleiro[TAM][TAM],
                              int linha,
                              int colunaInicial,
                              int tamanho) {
    // Verifica se o navio cabe dentro do tabuleiro
    if (linha < 0 || linha >= TAM) return 0;
    if (colunaInicial < 0 || colunaInicial + tamanho > TAM) return 0;

    // Verifica se todas as casas estão livres
    for (int c = 0; c < tamanho; c++) {
        if (!posicaoLivre(tabuleiro, linha, colunaInicial + c)) {
            return 0; // Tentou sobrepor outro navio
        }
    }

    // Posiciona o navio
    for (int c = 0; c < tamanho; c++) {
        tabuleiro[linha][colunaInicial + c] = VALOR_NAVIO;
    }

    return 1;
}

// ---------------------------------------------------------------------
// Função: posicionarNavioVertical
// Tenta posicionar um navio na vertical.
// linhaInicial  -> primeira linha do navio
// coluna        -> coluna fixa onde o navio ficará
// tamanho       -> quantidade de casas ocupadas pelo navio
// ---------------------------------------------------------------------
int posicionarNavioVertical(int tabuleiro[TAM][TAM],
                            int linhaInicial,
                            int coluna,
                            int tamanho) {
    // Verifica se o navio cabe dentro do tabuleiro
    if (coluna < 0 || coluna >= TAM) return 0;
    if (linhaInicial < 0 || linhaInicial + tamanho > TAM) return 0;

    // Verifica se todas as casas estão livres
    for (int l = 0; l < tamanho; l++) {
        if (!posicaoLivre(tabuleiro, linhaInicial + l, coluna)) {
            return 0;
        }
    }

    // Posiciona o navio
    for (int l = 0; l < tamanho; l++) {
        tabuleiro[linhaInicial + l][coluna] = VALOR_NAVIO;
    }

    return 1;
}

// ---------------------------------------------------------------------
// Função: posicionarNavioDiagonalPrincipal
// Tenta posicionar um navio na diagonal principal (↘).
// linhaInicial  -> linha do primeiro bloco do navio
// colunaInicial -> coluna do primeiro bloco do navio
// tamanho       -> quantidade de casas ocupadas pelo navio
// ---------------------------------------------------------------------
int posicionarNavioDiagonalPrincipal(int tabuleiro[TAM][TAM],
                                     int linhaInicial,
                                     int colunaInicial,
                                     int tamanho) {
    // Verifica se o navio cabe dentro do tabuleiro
    if (linhaInicial < 0 || colunaInicial < 0) return 0;
    if (linhaInicial + tamanho > TAM) return 0;
    if (colunaInicial + tamanho > TAM) return 0;

    // Verifica se todas as casas estão livres
    for (int k = 0; k < tamanho; k++) {
        int linha = linhaInicial + k;
        int coluna = colunaInicial + k;
        if (!posicaoLivre(tabuleiro, linha, coluna)) {
            return 0;
        }
    }

    // Posiciona o navio
    for (int k = 0; k < tamanho; k++) {
        int linha = linhaInicial + k;
        int coluna = colunaInicial + k;
        tabuleiro[linha][coluna] = VALOR_NAVIO;
    }

    return 1;
}

// ---------------------------------------------------------------------
// Função: posicionarNavioDiagonalSecundaria
// Tenta posicionar um navio na diagonal secundária (↙).
// linhaInicial  -> linha do primeiro bloco do navio
// colunaInicial -> coluna do primeiro bloco do navio
// tamanho       -> quantidade de casas ocupadas pelo navio
// ---------------------------------------------------------------------
int posicionarNavioDiagonalSecundaria(int tabuleiro[TAM][TAM],
                                      int linhaInicial,
                                      int colunaInicial,
                                      int tamanho) {
    // Verifica se o navio cabe dentro do tabuleiro
    if (linhaInicial < 0 || colunaInicial < 0) return 0;
    if (linhaInicial + tamanho > TAM) return 0;
    if (colunaInicial - (tamanho - 1) < 0) return 0;

    // Verifica se todas as casas estão livres
    for (int k = 0; k < tamanho; k++) {
        int linha = linhaInicial + k;
        int coluna = colunaInicial - k;
        if (!posicaoLivre(tabuleiro, linha, coluna)) {
            return 0;
        }
    }

    // Posiciona o navio
    for (int k = 0; k < tamanho; k++) {
        int linha = linhaInicial + k;
        int coluna = colunaInicial - k;
        tabuleiro[linha][coluna] = VALOR_NAVIO;
    }

    return 1;
}
