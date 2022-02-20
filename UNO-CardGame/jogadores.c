#include "jogadores.h"

Jogador* criarJogador(char nome[]) {
	Jogador* j = (Jogador*)malloc(sizeof(Jogador));
	if (!j) return NULL;
	
	strcpy_s(j->nome, 20, nome);
	j->quantidade_cartas = 0;
	j->pontuacao = 0;
	j->partidas_vencidas = 0;

	j->mao = criarMao();
	if (!j->mao) return NULL;
	
	return j;
}


Jogadores* cadastrarJogadores() {
	Jogadores* jogadores = (Jogadores*)malloc(sizeof(Jogadores));
	int i;
	char nome[20];

	if (jogadores) {
		for (i = 0; i < 2; i++) {
			printf("Cadastro Jogador %d\n", i + 1);
			printf("Informe o nome: ");
			gets_s(nome, 20);
			
			jogadores->j[i] = criarJogador(nome);
		}
	}

	return jogadores;
}