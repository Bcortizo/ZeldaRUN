#include "util.h"
#include "Jogador.h"
#include "Itens.h"
#include "Objeto.h"
#pragma once
class Fase
{
private:
	Sprite sFundo, sInterface;
	Som musica;
	Itens item1, item2;;
	Jogador jogador1, jogador2;

public:
	Fase();
	~Fase();

	void inicializar();
	void desenhar();
	void atualizar();
	//void resetar();
};

