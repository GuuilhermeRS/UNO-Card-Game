#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include "cartas.h"
#include "jogadores.h"()

void inicializarJogo(Jogadores* jogadores, Monte* monte_compra, Descarte* mesa_descarte);
void imprimirCartasJogador(Jogador* j);

int quantidadeJogadasValidas(Jogador* j, Descarte* d);

#endif // !GAME_H