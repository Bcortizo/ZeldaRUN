#include "libUnicornio.h"
#include "util.h"
#pragma once
class Itens
{
private:
	float x, y, velocidade;
	Sprite sprite;
	Som som;
	TipoObjeto tipo;
	bool vivo;

public:
	Itens();
	~Itens();

	void inicializar();
	void desenhar();
	void atualizar();
	void resetar();

	void testarColisao(TipoObjeto tipo);

	float getX();
	float getY();
	float getVelocidade();
	bool getVivo();
	TipoObjeto getTipo();

	void setSprite();
	void setVivo();
};

