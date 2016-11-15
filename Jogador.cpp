#include "Jogador.h"



Jogador::Jogador()
{
}


Jogador::~Jogador()
{
}

void Jogador::inicializar(int jogador, int x_, int y_)
{
	numJogador = jogador;
	xInicial = x_;
	yInicial = y_;

	//carrega o sprite do jogador 1 e do 2
	if (numJogador == 1)
	{
		gRecursos.carregarSpriteSheet("jogador1", "assets/sprites/jogador1.png", 8, 12);
		sprite.setSpriteSheet("jogador1");
	}
	else if (numJogador == 2)
	{
		gRecursos.carregarSpriteSheet("jogador2", "assets/sprites/jogador1.png", 8, 12);
		sprite.setSpriteSheet("jogador2");
	}

	sprite.setVelocidadeAnimacao(5);
	sprite.setEscala(3, 3);
	resetar();

	// outras inicializações
}

void Jogador::desenhar()
{
	sprite.desenhar(x, y);
}

void Jogador::atualizar()
{
	sprite.avancarAnimacao();
	if (sprite.getFrame() == 11 && sprite.getAnimacao() == 0)
	{
		sprite.setAnimacao(4, true);
	}
	else if (sprite.getFrame() == 11 && sprite.getAnimacao() == 4)
	{
		sprite.setAnimacao(0, true);
	}

	// movimentos do jogador 1 e do 2
	if (numJogador == 1)
	{ 
		if (gTeclado.segurando[TECLA_A] && x > 8)
		{
			x -= velocidade;
		}

		if (gTeclado.segurando[TECLA_D] && x < gJanela.getLargura() - 8)
		{
			x += velocidade;
		}

		if (gTeclado.segurando[TECLA_W] && y > 0)
		{
			y -= velocidade;
		}

		if (gTeclado.segurando[TECLA_S] && y < gJanela.getAltura() - 32)
		{
			y += velocidade;
		}
	}
	else if (numJogador == 2)
	{
		if (gTeclado.segurando[TECLA_ESQ] && x > 8)
		{
			x -= velocidade;
		}

		if (gTeclado.segurando[TECLA_DIR] && x < gJanela.getLargura() - 8)
		{
			x += velocidade;
		}

		if (gTeclado.segurando[TECLA_CIMA] && y > 0)
		{
			y -= velocidade;
		}

		if (gTeclado.segurando[TECLA_BAIXO] && y < gJanela.getAltura() - 32)
		{
			y += velocidade;
		}
	}

}

// reseta o jogador à condição inicial
void Jogador::resetar()
{
	x = xInicial;
	y = yInicial;
	velocidade = 2;
	vidas = 5;
	bombas = 0;
	flechas = 0;
	rupees = 0;

	//sprite = spr_Jogador;
	//som = som_Jogador;
}

void Jogador::colisaoItens(Itens &item)
{
	// colisões com os itens (deve ter jeito melhor de fazer)
	if (uniTestarColisao(sprite, x, y, 0,
		item.getSprite(), item.getX(), item.getY(), 0))
	{
		if (numJogador == 1)
		{
			if (item.getTipo() == BOMBA)
			{
				bombas++;
			}
			else if (item.getTipo() == FLECHA)
			{
				flechas++;
			}
		}
		else if (numJogador == 2)
		{

		}
		item.respawn();
	}

	//if (uniTestarColisao(jogador1.getSprite(), jogador1.getX(), jogador1.getY(), 0,
	//	item2.getSprite(), item2.getX(), item2.getY(), 0))
	//{
	//	item2.respawn();
	//}
}


int Jogador::getX()
{
	return x;
}

int Jogador::getY()
{
	return y;
}

int Jogador::getVelocidade()
{
	return velocidade;
}

int Jogador::getVidas()
{
	return vidas;
}

int Jogador::getRupees()
{
	return rupees;
}

int Jogador::getBombas()
{
	return bombas;
}

int Jogador::getFlechas()
{
	return flechas;
}

int Jogador::getNumJogador()
{
	return numJogador;
}

Sprite Jogador::getSprite()
{
	return sprite;
}

void Jogador::setColisaoJ1(bool colisao)
{
	colisaoJ1 = colisao;
}

void Jogador::setColisaoJ2(bool colisao)
{
	colisaoJ2 = colisao;
}

void Jogador::setVelocidade(int velo)
{
	velocidade = velo;
}

void Jogador::setVidas(int vidas_)
{
	vidas += vidas_;
}

void Jogador::setRupees(int rup)
{
	rupees += rup;
}

void Jogador::setBombas(int bomb)
{
	bombas += bomb;
}

void Jogador::setFlechas(int fle)
{
	flechas += fle;
}
