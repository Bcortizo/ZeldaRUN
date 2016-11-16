#include "util.h"
#include "Jogador.h"
#include "Itens.h"
#include "Objeto.h"

class Fase
{
private:
	Sprite sFundo, sFundo2, sInterface;
	Som musica;
	Jogador jogador1, jogador2;
	Itens item1, item2;
	Texto interfaceJ1, interfaceJ2;
	int scrollTela;

public:
	Fase();
	~Fase();

	void inicializar();
	void desenhar();
	void atualizar();
	void resetar();
};

