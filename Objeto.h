#include "libUnicornio.h"
#include "util.h"
#pragma once

class Objeto
{
private:
	float x, y, velocidade;
	Sprite sprite;
	TipoObjeto tipo;
	bool colisaoJ1, colisaoJ2;
	Som som;
	
public:
	Objeto();
	~Objeto();

	void inicializar();
	void desenhar();
	void atualizar();
	void resetar();

	float getX();
	float getY();
	float getVelocidade();
	TipoObjeto getTipo();
	bool getColisaoJ1();
	bool getColisaoJ2();

	void setTipo();
	void setColisaoJ1();
	void setColisaoJ2();
	void setVelocidade();
};

