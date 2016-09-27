#pragma once
#include "util.h"
#include "Jogador.h"
#include "Itens.h"
#include "Objeto.h"

class Jogo
{
private:
	Status status;
	Sprite spr_telaJogo, spr_Jogador;
	BotaoSprite botaoJogar, botaoVoltar, botaoSair;
	Jogador jogador1, jogador2;

	// gerencia as telas de jogo
	void telaInicial();
	void telaJogo();

public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();

	void executar();
};

