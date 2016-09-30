#include "Fase.h"



Fase::Fase()
{
}


Fase::~Fase()
{
}

void Fase::inicializar()
{
	// carrega as sprites da fase
	gRecursos.carregarSpriteSheet("telaJogo", "assets/backgrounds/grass2.png");
	gRecursos.carregarSpriteSheet("flecha", "assets/sprites/flecha.png");
	gRecursos.carregarSpriteSheet("bomba", "assets/sprites/bomba.png");

	sFundo.setSpriteSheet("telaJogo");
	sFundo2.setSpriteSheet("telaJogo");

	// inicializa jogador, itens e objetos, e o valor de scroll da tela
	jogador1.inicializar(1);
	item1.inicializar(500, -150, 4, BOMBA);
	item2.inicializar(300, -75, 2, FLECHA);
	scrollTela = 0;
}

void Fase::desenhar()
{
	sFundo.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2 + scrollTela);
	sFundo2.desenhar(gJanela.getLargura() / 2, - gJanela.getAltura() / 2 + scrollTela);
	item1.desenhar();
	item2.desenhar();
	jogador1.desenhar();
}

void Fase::atualizar()
{
	item1.atualizar();
	item2.atualizar();
	jogador1.atualizar();

	// configura a velocidade de scroll da tela de fundo
	if (scrollTela >= gJanela.getAltura())
	{
		scrollTela = 0;
	}
	else
	{
		scrollTela += 1;
	}
}
