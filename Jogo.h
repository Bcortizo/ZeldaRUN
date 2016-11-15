#pragma once
#include "util.h"
#include "Fase.h"

class Jogo
{
private:
	Status status;
	Sprite spr_telaJogo;
	BotaoSprite botaoJogar, botaoVoltar, botaoSair;
	Fase fase[3];
	NumeroFase numFase;
	bool podeCarregarFase;

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

