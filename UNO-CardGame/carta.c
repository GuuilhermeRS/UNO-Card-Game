#include "cartas.h"

// Carta
Carta* criarCarta(int cor, int valor) {
	Carta* c = (Carta*)malloc(sizeof(Carta));
	if (c) {
		c->cor = cor;
		c->valor = valor;
		c->proxima = NULL;
	}

	return c;
}

void imprimirCarta(Carta* c) {
	if (c) {
		char cor[10];
		char valor[20];

		if (c->cor == 0) strcpy_s(cor, 10, "Amarelo");
		else if (c->cor == 1) strcpy_s(cor, 10, "Azul");
		else if (c->cor == 2) strcpy_s(cor, 10, "Verde");
		else if (c->cor == 3) strcpy_s(cor, 10, "Vermelho");
		else if (c->cor == 4) strcpy_s(cor, 10, "Especial");

		if (c->valor >= 10) {
			if (c->valor == 10) strcpy_s(valor, 20, "Inverter	");
			else if (c->valor == 11) strcpy_s(valor, 20, "Passa a vez");
			else if (c->valor == 12) strcpy_s(valor, 20, "Comprar +2");

			printf("{		Cor: %s,	Valor: %s	}\n", cor, valor);
		} else if (c->cor != ESPECIAL) {
			printf("{		Cor: %s,	Valor: %d		}\n", cor, c->valor);
		} else {
			if (c->valor == 0) strcpy_s(valor, 20, "Curinga +4");
			else if (c->valor== 1) strcpy_s(valor, 20, "Trocar a Cor");
			else if (c->valor == 2) strcpy_s(valor, 20, "Trocar as Maos");
			printf("{		Cor: %s,	Valor: %s	}\n", cor, valor);
		}
	}
}

// Baralho

Baralho* criarBaralho() {
	Baralho* b = (Baralho*)malloc(sizeof(Baralho));
	if (!b) return NULL;

	b->quantidade_cartas = -1;
	preencherBaralho(b);

	return b;
}

void preencherBaralho(Baralho* b) {
	int i, j = 0;
	int cor;

	for (i = 0; i < TOTAL_CARTAS-6; i++) {
		if (j > 12) j = 0;

		// Definir a COR da Carta
		if (i < 1*26) cor = AMARELO;
		else if (i < 2*26) cor = AZUL;
		else if (i < 3*26) cor = VERDE;
		else if (i < 4*26) cor = VERMELHO;
		//else cor = ESPECIAL;

		Carta* c = criarCarta(cor, j);
		b->cartas[i] = c;
		b->quantidade_cartas++;
		j++;
	}

	for (i; i < TOTAL_CARTAS; i++) {
		cor = ESPECIAL;
		if (j > 2) j = 0;
		
		Carta* c = criarCarta(cor, j);
		b->cartas[i] = c;
		b->quantidade_cartas++;
		j++;
	}

	embaralharBaralho(b);
}

void embaralharBaralho(Baralho* b) {
	int i, eRandom;
	Carta* aux;

	srand(time(NULL));

	for (i = 0; i < TOTAL_CARTAS; i++) {
		eRandom = rand() % TOTAL_CARTAS;
		
		aux = b->cartas[i];
		b->cartas[i] = b->cartas[eRandom];
		b->cartas[eRandom] = aux;
	}
}



// Monte
Monte* criarMonte() {
	Monte* m = (Monte*)malloc(sizeof(Monte));
	if (!m) return NULL;

	m->quantidade_cartas = -1;
	m->topo = NULL;

	preencherMonte(m);

	return m;
}

void preencherMonte(Monte* m) {
	Baralho* b = criarBaralho();
	if (b) {
		int i;
		

		for (i = 0; i <= b->quantidade_cartas; i++) {
			inserirMonte(m, b->cartas[i]);
			m->quantidade_cartas++;
		}

		free(b);
	}
}

void inserirMonte(Monte* m, Carta* c) {
	c->proxima = m->topo;
	m->topo = c;
}

Carta* pegarCarta(Monte* m) { // Remover carta do Topo
	Carta* removida;
	
	removida = m->topo;
	m->topo = removida->proxima;
	m->quantidade_cartas--;

	return removida;
}



// Descarte
Descarte* criarDescarte() {
	Descarte* d = (Descarte*)malloc(sizeof(Descarte));
	if (!d) return NULL;

	d->topo = NULL;
	d->quantidade_cartas = -1;

	return d;
}

void inserirDescarte(Descarte* d, Carta* c) {
	c->proxima = d->topo;
	d->topo = c;
	d->quantidade_cartas++;
}


// Mao
Mao* criarMao() {
	Mao* m = (Mao*)malloc(sizeof(Mao));
	if (!m) return NULL;

	m->inicial = NULL;
	m->quantidade_cartas = 0;
};

void inserirMao(Mao* m, Carta* c) {
	c->proxima = m->inicial;
	m->inicial = c;
}

