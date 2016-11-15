// a libunicornio desenha os elementos na ordem de inserção
#include "Jogo.h"

void Jogo::telaInicial()
{
	botaoJogar.atualizar();
	botaoJogar.desenhar();
	if (botaoJogar.estaClicado())
	{
		status = JOGO;
	}

	botaoSair.atualizar();
	botaoSair.desenhar();
	if (botaoSair.estaClicado())
	{
		status = SAIR;
	}

}

void Jogo::telaJogo()
{
	switch (numFase)
	{
	case FASE0: if (podeCarregarFase)
	{
		fase[0].inicializar();
		podeCarregarFase = false;
	}
		break;
	case FASE1:
		break;
	case FASE2:
		break;
	default:
		break;
	}
	// aqui entraria o lance das fases
	fase[0].atualizar();
	fase[0].desenhar();

	botaoVoltar.atualizar();
	botaoVoltar.desenhar();
	if (botaoVoltar.estaClicado())
	{
		status = INICIAL;
	}
}

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(1024, 768, false, "Zelda RUN!");

	// carrega os sprites dos botões
	gRecursos.carregarSpriteSheet("botaoJogar", "assets/buttons/botao1.png", 3);
	gRecursos.carregarSpriteSheet("botaoSair", "assets/buttons/botao4.png", 3);
	gRecursos.carregarSpriteSheet("botaoVoltar", "assets/buttons/botao5.png", 3);

	// atribui os sprites dos botões
	botaoJogar.setSpriteSheet("botaoJogar");
	botaoSair.setSpriteSheet("botaoSair");
	botaoVoltar.setSpriteSheet("botaoVoltar");

	// configura a posição dos botões
	botaoJogar.setPos(gJanela.getLargura() * 3 / 4, 640);
	botaoSair.setPos(gJanela.getLargura() * 3 / 4, 700);
	botaoVoltar.setPos(gJanela.getLargura() * 3 / 4, 700);

	// põe o jogo no status da tela inicial
	status = INICIAL;

	numFase = FASE0;
	podeCarregarFase = true;

}

void Jogo::finalizar()
{
	//	O resto da finalização vem aqui (provavelmente, em ordem inversa a inicialização)!
	//	...

	uniFinalizar();
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair && status != SAIR)
	{
		uniIniciarFrame();

		switch (status)
		{
		case INICIAL: telaInicial();
			break;
		case CREDITOS:
			break;
		case INSTRUCOES:
			break;
		case JOGO: telaJogo();
			break;
		}

		uniTerminarFrame();
	}
}