#include <stdio.h>

#include "jogadores.h"
#include "cartas.h"
#include "game.h"

int main() {
	Jogadores* jogadores = cadastrarJogadores();
	if (!jogadores) return 1;
	system("cls");

	Monte* monte_compra = criarMonte();
	if (!monte_compra) return 1;

	Descarte* mesa_descarte = criarDescarte();
	if (!mesa_descarte) return 1;

	/*Carta* aux = pegarCarta(m);
	printf("REMOVIDA: { Cor: %c, Valor: %c }\n", aux->cor, aux->valor);
	inserirDescarte(mesa_descarte, aux);
	aux = pegarCarta(m);
	printf("REMOVIDA: { Cor: %c, Valor: %c }\n", aux->cor, aux->valor);
	inserirDescarte(mesa_descarte, aux);

	aux = mesa_descarte->topo;
	while (aux != NULL) {
		printf("{ Cor: %c, Valor: %c }\n", aux->cor, aux->valor);
		aux = aux->proxima;
	}*/

	Carta* aux;
	
	int quantidade_jogadas;

	inicializarJogo(jogadores, monte_compra, mesa_descarte);

	// Jogador 1
	quantidade_jogadas = quantidadeJogadasValidas(jogadores->j[0], mesa_descarte);
	printf("Quantidade de jogadas validas: %d\n", quantidade_jogadas);
	imprimirCartasJogador(jogadores->j[0]);

	// Jogador 2
	quantidade_jogadas = quantidadeJogadasValidas(jogadores->j[1], mesa_descarte);
	printf("Quantidade de jogadas validas: %d\n", quantidade_jogadas);
	imprimirCartasJogador(jogadores->j[1]);


	printf("Mesa Descarte: \n");
	imprimirCarta(mesa_descarte->topo);


	
	printf("\n\n\n\n\n\n\n\nPrograma Finalizado!\n\n");
	return 0;
}