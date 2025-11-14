// src/tabuleiro.h
// ---------------------------------------------------------------------
// Arquivo de cabeçalho responsável pelas funções relacionadas ao tabuleiro
// do jogo de Batalha Naval (tamanho fixo 10x10).
// ---------------------------------------------------------------------

#ifndef TABULEIRO_H
#define TABULEIRO_H

// Tamanho fixo do tabuleiro (10 x 10)
#define TAM 10

// Valores simbólicos para facilitar a leitura do código
#define VALOR_AGUA  0   // Representa uma casa vazia (água)
#define VALOR_NAVIO 3   // Representa uma casa ocupada por navio

// Inicializa todo o tabuleiro com VALOR_AGUA (0)
void inicializarTabuleiro(int tabuleiro[TAM][TAM]);

// Imprime o tabuleiro completo no console
void imprimirTabuleiro(int tabuleiro[TAM][TAM]);

// As funções abaixo tentam posicionar navios com tamanho "tamanho".
// Retornam 1 se o posicionamento foi possível, 0 se houve erro
// (saiu dos limites do tabuleiro ou tentou sobrepor outro navio).

// Navio na horizontal (linha fixa, colunas crescentes)
int posicionarNavioHorizontal(int tabuleiro[TAM][TAM],
                              int linha,
                              int colunaInicial,
                              int tamanho);

// Navio na vertical (coluna fixa, linhas crescentes)
int posicionarNavioVertical(int tabuleiro[TAM][TAM],
                            int linhaInicial,
                            int coluna,
                            int tamanho);

// Navio na diagonal principal (linha e coluna aumentando ao mesmo tempo)
int posicionarNavioDiagonalPrincipal(int tabuleiro[TAM][TAM],
                                     int linhaInicial,
                                     int colunaInicial,
                                     int tamanho);

// Navio na diagonal secundária (linha aumentando e coluna diminuindo)
int posicionarNavioDiagonalSecundaria(int tabuleiro[TAM][TAM],
                                      int linhaInicial,
                                      int colunaInicial,
                                      int tamanho);

#endif // TABULEIRO_H
