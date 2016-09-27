#include "Jogo.h"

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ptb");

	Jogo jogo;
	jogo.inicializar();
	jogo.executar();
	jogo.finalizar();

	return 0;
}