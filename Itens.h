#include "util.h"
#pragma once

class Itens
{
private:
	int x, xInicial, y, yInicial, velocidade;
	Sprite sprite;
	Som som;
	TipoItem tipo, tipoInicial;
	bool vivo;

public:
	Itens();
	~Itens();

	void inicializar(int x_, int y_, int velo, TipoItem tipo_);
	void desenhar();
	void atualizar();
	void resetar();
	void respawn();

	int getX();
	int getY();
	int getVelocidade();
	bool getVivo();
	TipoItem getTipo();
	Sprite getSprite();

	void setTipo(TipoItem tipo_);
	void setVivo(bool vivo_);
};

