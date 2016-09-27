// a libunicornio desenha os elementos na ordem de inserção
#include "Jogo.h"
#include "util.h"

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
	spr_telaJogo.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	jogador1.atualizar();
	jogador1.desenhar();

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
	botaoJogar.setPos(gJanela.getLargura() * 3 / 4, 600);
	botaoSair.setPos(gJanela.getLargura() * 3 / 4, 700);
	botaoVoltar.setPos(gJanela.getLargura() * 3 / 4, 700);

	// carrega e atribui sprite do jogador, depois inicializa o jogador
	gRecursos.carregarSpriteSheet("jogador1", "assets/sprites/jogador1.png", 8, 12);
	spr_Jogador.setSpriteSheet("jogador1");
	jogador1.inicializar(1, spr_Jogador);

	// carrega e atribui sprites das telas
	gRecursos.carregarSpriteSheet("telaJogo", "assets/backgrounds/telaJogo.jpg");
	spr_telaJogo.setSpriteSheet("telaJogo");

	// põe o jogo no status da tela inicial
	status = INICIAL;

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