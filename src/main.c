// src/main.c
// ---------------------------------------------------------------------
// Programa principal do desafio "Batalha Naval - Nível Mestre".
// Neste arquivo, unimos:
//  - Tabuleiro 10x10 (matriz)
//  - 4 navios (horizontal, vertical e dois diagonais)
//  - Matrizes de habilidades (cone, cruz, octaedro)
// Tudo com vetores, matrizes, loops aninhados e condicionais.
// ---------------------------------------------------------------------

#include <stdio.h>
#include "tabuleiro.h"
#include "habilidades.h"

#define TAM_NAVIO 3  // tamanho fixo dos navios

// ---------------------------------------------------------------------
// Função auxiliar para imprimir as coordenadas de um navio horizontal
// ---------------------------------------------------------------------
void imprimirCoordenadasNavioHorizontal(int linha, int colunaInicial, int tamanho) {
    printf("Navio horizontal (tamanho %d):\n", tamanho);
    for (int c = 0; c < tamanho; c++) {
        printf("  (%d, %d)\n", linha, colunaInicial + c);
    }
    printf("\n");
}

// ---------------------------------------------------------------------
// Função auxiliar para imprimir as coordenadas de um navio vertical
// ---------------------------------------------------------------------
void imprimirCoordenadasNavioVertical(int linhaInicial, int coluna, int tamanho) {
    printf("Navio vertical (tamanho %d):\n", tamanho);
    for (int l = 0; l < tamanho; l++) {
        printf("  (%d, %d)\n", linhaInicial + l, coluna);
    }
    printf("\n");
}

// ---------------------------------------------------------------------
// Função auxiliar para imprimir as coordenadas de um navio na diagonal
// principal (↘).
// ---------------------------------------------------------------------
void imprimirCoordenadasNavioDiagonalPrincipal(int linhaInicial, int colunaInicial, int tamanho) {
    printf("Navio diagonal principal (↘) (tamanho %d):\n", tamanho);
    for (int k = 0; k < tamanho; k++) {
        int linha = linhaInicial + k;
        int coluna = colunaInicial + k;
        printf("  (%d, %d)\n", linha, coluna);
    }
    printf("\n");
}

// ---------------------------------------------------------------------
// Função auxiliar para imprimir as coordenadas de um navio na diagonal
// secundária (↙).
// ---------------------------------------------------------------------
void imprimirCoordenadasNavioDiagonalSecundaria(int linhaInicial, int colunaInicial, int tamanho) {
    printf("Navio diagonal secundária (↙) (tamanho %d):\n", tamanho);
    for (int k = 0; k < tamanho; k++) {
        int linha = linhaInicial + k;
        int coluna = colunaInicial - k;
        printf("  (%d, %d)\n", linha, coluna);
    }
    printf("\n");
}

int main(void) {
    // -----------------------------------------------------------------
    // 1. Criação e inicialização do tabuleiro 10x10
    // -----------------------------------------------------------------
    int tabuleiro[TAM][TAM];

    inicializarTabuleiro(tabuleiro);

    // -----------------------------------------------------------------
    // 2. Definição das posições iniciais dos navios (fixas no código)
    //    Escolhidas para não saírem do tabuleiro e não se sobreporem.
    // -----------------------------------------------------------------
    // Navio 1: vertical
    int n1_linhaInicial = 0;
    int n1_coluna       = 0;

    // Navio 2: horizontal
    int n2_linha        = 2;
    int n2_colunaInicial = 4;

    // Navio 3: diagonal principal (↘)
    int n3_linhaInicial  = 4;
    int n3_colunaInicial = 1;

    // Navio 4: diagonal secundária (↙)
    int n4_linhaInicial  = 4;
    int n4_colunaInicial = 8;

    // -----------------------------------------------------------------
    // 3. Posicionamento dos navios no tabuleiro
    // -----------------------------------------------------------------
    if (!posicionarNavioVertical(tabuleiro, n1_linhaInicial, n1_coluna, TAM_NAVIO)) {
        printf("Erro ao posicionar navio vertical!\n");
        return 1;
    }

    if (!posicionarNavioHorizontal(tabuleiro, n2_linha, n2_colunaInicial, TAM_NAVIO)) {
        printf("Erro ao posicionar navio horizontal!\n");
        return 1;
    }

    if (!posicionarNavioDiagonalPrincipal(tabuleiro, n3_linhaInicial, n3_colunaInicial, TAM_NAVIO)) {
        printf("Erro ao posicionar navio diagonal principal!\n");
        return 1;
    }

    if (!posicionarNavioDiagonalSecundaria(tabuleiro, n4_linhaInicial, n4_colunaInicial, TAM_NAVIO)) {
        printf("Erro ao posicionar navio diagonal secundária!\n");
        return 1;
    }

    // -----------------------------------------------------------------
    // 4. Exibição das coordenadas de cada navio (requisito do nível Novato)
    // -----------------------------------------------------------------
    printf("=== COORDENADAS DOS NAVIOS ===\n\n");

    imprimirCoordenadasNavioVertical(n1_linhaInicial, n1_coluna, TAM_NAVIO);
    imprimirCoordenadasNavioHorizontal(n2_linha, n2_colunaInicial, TAM_NAVIO);
    imprimirCoordenadasNavioDiagonalPrincipal(n3_linhaInicial, n3_colunaInicial, TAM_NAVIO);
    imprimirCoordenadasNavioDiagonalSecundaria(n4_linhaInicial, n4_colunaInicial, TAM_NAVIO);

    // -----------------------------------------------------------------
    // 5. Impressão do tabuleiro completo (requisito do nível Aventureiro)
    // -----------------------------------------------------------------
    imprimirTabuleiro(tabuleiro);

    // -----------------------------------------------------------------
    // 6. Matrizes de habilidades especiais (nível Mestre)
    // -----------------------------------------------------------------
    int cone[HAB_LIN][HAB_COL];
    int cruz[HAB_LIN][HAB_COL];
    int octaedro[HAB_LIN][HAB_COL];

    // Preenche cada matriz com o padrão correto
    habilidadeCone(cone);
    habilidadeCruz(cruz);
    habilidadeOctaedro(octaedro);

    // Imprime os padrões no console
    imprimirMatrizHabilidade(cone, "CONE");
    imprimirMatrizHabilidade(cruz, "CRUZ");
    imprimirMatrizHabilidade(octaedro, "OCTAEDRO");

    // -----------------------------------------------------------------
    // Fim do programa
    // -----------------------------------------------------------------
    return 0;
}
