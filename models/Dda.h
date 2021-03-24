//---------------------------------------------------------------------------
#ifndef DdaH
#define DdaH
#include <Vcl.ExtCtrls.hpp>
#include "Janela.h"
#include <vector>
#include "Ponto2d.h"
using std::vector;
//---------------------------------------------------------------------------
class Dda {
	private:
		TCanvas *_canvas;
		vector<Ponto2d> _pontos;
	public:
		Dda(TCanvas *, vector<Ponto2d>);
        void Desenhar(Janela mundo, Janela viewport);
};
#endif

