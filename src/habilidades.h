// src/habilidades.h
// ---------------------------------------------------------------------
// Cabeçalho das funções responsáveis por criar as matrizes de habilidades
// especiais: cone, cruz e octaedro.
// Cada habilidade será representada por uma pequena matriz 3x5,
// onde 0 = não afetado e 1 = área afetada pela habilidade.
// ---------------------------------------------------------------------

#ifndef HABILIDADES_H
#define HABILIDADES_H

// Dimensões fixas das matrizes de habilidades
#define HAB_LIN 3  // quantidade de linhas
#define HAB_COL 5  // quantidade de colunas

// Preenche uma matriz 3x5 com o padrão de CONE
void habilidadeCone(int matriz[HAB_LIN][HAB_COL]);

// Preenche uma matriz 3x5 com o padrão de CRUZ
void habilidadeCruz(int matriz[HAB_LIN][HAB_COL]);

// Preenche uma matriz 3x5 com o padrão de OCTAEDRO
void habilidadeOctaedro(int matriz[HAB_LIN][HAB_COL]);

// Imprime qualquer matriz de habilidade 3x5
void imprimirMatrizHabilidade(int matriz[HAB_LIN][HAB_COL], const char *nome);

#endif // HABILIDADES_H
