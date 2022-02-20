#ifndef CARTAS_H
#define CARTAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define TOTAL_CARTAS 110

// CORES
#define AMARELO 0
#define AZUL 1
#define VERDE 2
#define VERMELHO 3
#define ESPECIAL 4

// CARTAS ESPECIAIS - CORES
#define INVERTER 10
#define PASSA_VEZ 11
#define COMPRAR_MAIS_2 12

// CARTAS ESPECIAIS
#define CURINGA_MAIS_4 0
#define TROCAR_A_COR 1
#define TROCAR_AS_MAOS 2



// Estrutura e Métodos para Carta
typedef struct carta {
	int cor;
	int valor;
	struct carta* proxima;
} Carta;

Carta* criarCarta(int cor, int valor);

void imprimirCarta(Carta* c);

// Estrutura e Métodos para Baralho
typedef struct baralho {
	Carta* cartas[TOTAL_CARTAS];
	int quantidade_cartas;
} Baralho;

Baralho* criarBaralho();
void preencherBaralho(Baralho* b);
void embaralharBaralho(Baralho* b);

// Estrutura e Métodos para Monte de Cartas
typedef struct monte {
	Carta *topo;
	int quantidade_cartas;
} Monte;

Monte* criarMonte();
void preencherMonte(Monte* m);
void inserirMonte(Monte* m, Carta* c);
Carta* pegarCarta(Monte* m);

// Estrutura e Métodos para Mesa de Descarte
typedef struct descarte {
	Carta* topo;
	int quantidade_cartas;
} Descarte;

Descarte* criarDescarte();
void inserirDescarte(Descarte *d, Carta *c);


// Estrutura e Métodos para Mão do Jogador
typedef struct mao {
	Carta* inicial;
	int quantidade_cartas;
} Mao;

Mao* criarMao();
void inserirMao(Mao* m, Carta* c);





#endif // !CARTAS_H