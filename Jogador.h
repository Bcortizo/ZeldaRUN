#pragma once
#include "util.h"
class Jogador
{
private:
	int x, y, velocidade;
	Sprite sprite;
	Som som;
	int vidas, rupees, bombas, flechas, numJogador;
	bool colisaoJ1, colisaoJ2;

public:
	Jogador();
	~Jogador();

	void inicializar(int jogador); // se é jogador 1 ou 2
	void desenhar();
	void atualizar();
	void resetar(); // volta o jogador ao padrão inicial

	void testarColisao(TipoObjeto tipo);

	// GETS e SETS
	int getX();
	int getY();
	int getVelocidade();
	int getVidas();
	int getRupees();
	int getBombas();
	int getFlechas();
	int getNumJogador();
	bool getColisaoJ1();
	bool getColisaoJ2();
	
	void setVelocidade(int velo);
	void setVidas(int vidas_);
	void setRupees(int rup);
	void setBombas(int bomb);
	void setFlechas(int fle);
	void setColisaoJ1(bool colisao);
	void setColisaoJ2(bool colisao);

};

