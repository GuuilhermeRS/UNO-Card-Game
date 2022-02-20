#ifndef JOGADORES_H
#define JOGADORES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cartas.h"


// Estrutura e métodos para jogador
typedef struct jogador {
	char nome[20];
	int quantidade_cartas;
	int pontuacao;
	int partidas_vencidas;
	Mao* mao;
} Jogador;

Jogador* criarJogador(char nome[]);


// Estrutura e métodos para jogadores
typedef struct jogadores {
	Jogador* j[2];
} Jogadores;

Jogadores* cadastrarJogadores();

#endif