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

	// seta a fonte do texto

	

	// inicializa jogador, itens e objetos, e o valor de scroll da tela
	jogador1.inicializar(1, gJanela.getLargura() / 3, gJanela.getAltura() * 4 / 5);
	jogador2.inicializar(2, gJanela.getLargura() * 2 / 3, gJanela.getAltura() * 4 / 5);
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
	jogador2.desenhar();
}

void Fase::atualizar()
{
	item1.atualizar();
	item2.atualizar();
	jogador1.atualizar();
	jogador2.atualizar();

	jogador1.colisaoItens(item1);
	jogador1.colisaoItens(item2);

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
