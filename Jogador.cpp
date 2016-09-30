#include "Jogador.h"



Jogador::Jogador()
{
}


Jogador::~Jogador()
{
}

void Jogador::inicializar(int jogador)
{
	numJogador = jogador;

	//carrega o sprite do jogador
	gRecursos.carregarSpriteSheet("jogador1", "assets/sprites/jogador1.png", 8, 12);
	sprite.setSpriteSheet("jogador1");

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

void Jogador::resetar()
{
	x = gJanela.getLargura() / 2;
	y = gJanela.getAltura() * 4/5;
	velocidade = 2;
	vidas = 5;
	bombas = 0;
	flechas = 0;
	rupees = 0;

	//sprite = spr_Jogador;
	//som = som_Jogador;
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

bool Jogador::getColisaoJ1()
{
	return colisaoJ1;
}

bool Jogador::getColisaoJ2()
{
	return colisaoJ2;
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
