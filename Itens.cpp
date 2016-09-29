#include "Itens.h"



Itens::Itens()
{
}


Itens::~Itens()
{
}

void Itens::inicializar(int x_, int y_, int velo, TipoItem tipo_)
{
	xInicial = x_;
	yInicial = y_;
	velocidade = velo;
	tipoInicial = tipo_;
	resetar();

	switch (tipo)
	{
	case RUPEEVERDE:
		break;
	case RUPEEVERMELHA:
		break;
	case RUPEEAZUL:
		break;
	case BOMBA: sprite.setSpriteSheet("bomba");
		break;
	case FLECHA: sprite.setSpriteSheet("flecha");
		break;
	}

}

void Itens::desenhar()
{
	sprite.desenhar(x, y);
}

void Itens::atualizar()
{
	y += velocidade;
	//testarColisao();
	if (y > gJanela.getAltura() + 20)
	{
		y = -(rand() % 565 + 70);
		
		switch (rand() % 2)
		{
		case 0: setTipo(BOMBA);
			sprite.setSpriteSheet("bomba");
			break;
		case 1: setTipo(FLECHA);
			sprite.setSpriteSheet("flecha");
			break;
		}
	}
}

void Itens::resetar()
{
	x = xInicial;
	y = yInicial;
	tipo = tipoInicial;
}

int Itens::getX()
{
	return x;
}

int Itens::getY()
{
	return y;
}

int Itens::getVelocidade()
{
	return velocidade;
}

bool Itens::getVivo()
{
	return vivo;
}

TipoItem Itens::getTipo()
{
	return tipo;
}

void Itens::setTipo(TipoItem tipo_)
{
	tipo = tipo_;
}

void Itens::setVivo(bool vivo_)
{
	vivo = vivo_;
}
