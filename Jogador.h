#include "libUnicornio.h"
#include "util.h"
#pragma once
class Jogador
{
private:
	float x, y, velocidade;
	Sprite sprite;
	Som som;
	int vidas, rupees, bombas, flechas, numJogador;

public:
	Jogador();
	~Jogador();

	void inicializar();
	void desenhar();
	void atualizar();
	void resetar();

	void testarColisao(TipoObjeto tipo);

	float getX();
	float getY();
	float getVelocidade();
	int getVidas();
	int getRupees();
	int getBombas();
	int getFlechas();
	int getNumJogador();

	void setColisaoJ1();
	void setColisaoJ2();
	void setVelocidade();
	void setVidas();
	void setRupees();
	void setBombas();
	void setFlechas();

};

