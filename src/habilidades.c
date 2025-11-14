// src/habilidades.c
// ---------------------------------------------------------------------
// Implementação das habilidades especiais (cone, cruz, octaedro),
// cada uma representada por uma matriz 3x5 de inteiros.
// Usamos loops aninhados e condicionais para montar os padrões.
// ---------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h> // para abs
#include "habilidades.h"

// ---------------------------------------------------------------------
// Função auxiliar: zera toda a matriz de habilidade
// ---------------------------------------------------------------------
static void zerarMatriz(int matriz[HAB_LIN][HAB_COL]) {
    for (int i = 0; i < HAB_LIN; i++) {
        for (int j = 0; j < HAB_COL; j++) {
            matriz[i][j] = 0;
        }
    }
}

// ---------------------------------------------------------------------
// Função: habilidadeCone
// Gera o padrão:
//
// 0 0 1 0 0
// 0 1 1 1 0
// 1 1 1 1 1
// ---------------------------------------------------------------------
void habilidadeCone(int matriz[HAB_LIN][HAB_COL]) {
    zerarMatriz(matriz);

    int centro = HAB_COL / 2; // posição central das colunas (2 em 0..4)

    for (int i = 0; i < HAB_LIN; i++) {          // linhas
        int alcance = i;                         // cresce à medida que desce
        for (int j = 0; j < HAB_COL; j++) {      // colunas
            if (j >= centro - alcance && j <= centro + alcance) {
                matriz[i][j] = 1;
            }
        }
    }
}

// ---------------------------------------------------------------------
// Função: habilidadeCruz
// Gera o padrão:
//
// 0 0 1 0 0
// 1 1 1 1 1
// 0 0 1 0 0
//
// (linha e coluna centrais com valor 1)
// ---------------------------------------------------------------------
void habilidadeCruz(int matriz[HAB_LIN][HAB_COL]) {
    zerarMatriz(matriz);

    int centroLin = HAB_LIN / 2; // linha central (1 em 0..2)
    int centroCol = HAB_COL / 2; // coluna central (2 em 0..4)

    for (int i = 0; i < HAB_LIN; i++) {
        for (int j = 0; j < HAB_COL; j++) {
            if (i == centroLin || j == centroCol) {
                matriz[i][j] = 1;
            }
        }
    }
}

// ---------------------------------------------------------------------
// Função: habilidadeOctaedro
// Gera o padrão (distância de Manhattan <= 1 do centro):
//
// 0 0 1 0 0
// 0 1 1 1 0
// 0 0 1 0 0
// ---------------------------------------------------------------------
void habilidadeOctaedro(int matriz[HAB_LIN][HAB_COL]) {
    zerarMatriz(matriz);

    int centroLin = HAB_LIN / 2; // 1
    int centroCol = HAB_COL / 2; // 2

    for (int i = 0; i < HAB_LIN; i++) {
        for (int j = 0; j < HAB_COL; j++) {
            int distancia = abs(i - centroLin) + abs(j - centroCol);
            if (distancia <= 1) {
                matriz[i][j] = 1;
            }
        }
    }
}

// ---------------------------------------------------------------------
// Função: imprimirMatrizHabilidade
// Imprime a matriz 3x5, com um nome de título.
// ---------------------------------------------------------------------
void imprimirMatrizHabilidade(int matriz[HAB_LIN][HAB_COL], const char *nome) {
    printf("=== Habilidade: %s ===\n", nome);
    for (int i = 0; i < HAB_LIN; i++) {
        for (int j = 0; j < HAB_COL; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
