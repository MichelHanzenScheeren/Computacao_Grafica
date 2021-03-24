//---------------------------------------------------------------------------
#ifndef ClippingH
#define ClippingH
#include "Ponto2d.h"
#include "Janela.h"
#include <vector>
using std::vector;
//---------------------------------------------------------------------------
class Clipping {
	private:
		Janela _clipping = Janela(0, 0, 0, 0);
		double _m = 0;
		vector<Ponto2d> _pontos;
		void _adicionarSeNaoExiste(Ponto2d);
		void _verificarPossiveisExtremidades(short, Ponto2d);
		void _extremidadeYmax(Ponto2d);
		void _extremidadeYmin(Ponto2d);
		void _extremidadeXmax(Ponto2d);
        void _extremidadeXmin(Ponto2d);
	public:
		Clipping(Janela);
		void PontoUnico(Ponto2d);
		void SegmentoReta(Ponto2d, Ponto2d);
		void CalcularPontosDaInterseccao(Ponto2d);
		vector<Ponto2d> ObterResultados();
};
#endif

