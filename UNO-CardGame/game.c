#include "game.h"

void inicializarJogo(Jogadores *jogadores, Monte *monte_compra, Descarte *mesa_descarte) {
	Carta* removida_monte;
	int i, j;

	removida_monte = pegarCarta(monte_compra);
	inserirDescarte(mesa_descarte, removida_monte);

	for (i = 0; i < 7; i++) {
		removida_monte = pegarCarta(monte_compra);
		inserirMao(jogadores->j[0]->mao, removida_monte);

		removida_monte = pegarCarta(monte_compra);
		inserirMao(jogadores->j[1]->mao, removida_monte);
	}
}

void imprimirCartasJogador(Jogador* j) {
	int jogadas_validas;
	printf("Jogador: %s\n\n", j->nome);

	Carta *aux = j->mao->inicial;
	while (aux) {
		imprimirCarta(aux);
		aux = aux->proxima;
	}

	printf("\n\n");
}

int quantidadeJogadasValidas(Jogador* j, Descarte* d) {
	int quantidade = 0;
	Carta* aux;

	aux = j->mao->inicial;

	while (aux) {
		if (aux->cor == d->topo->cor || aux->valor == d->topo->valor) {
			quantidade++;
		}
		aux = aux->proxima;
	}

	return quantidade;
}