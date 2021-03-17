//---------------------------------------------------------------------------

#ifndef DisplayFileH
#define DisplayFileH

#include "Poligono.h"
#include <vector>
#include <Vcl.ExtCtrls.hpp>
#include<Vcl.StdCtrls.hpp>
//---------------------------------------------------------------------------
class DisplayFile
{
	public:
		vector<Poligono> Poligonos;
		void AdicionarPoligono(Poligono);
		void AdicionarPontoAoUltimoPoligono(Ponto2d);
		void Desenhar(TCanvas *, int, Janela, Janela);
		void MostrarPoligonosDesenhados(TListBox *);
		void GerarPontosDoCirculo(Ponto2d);
		void MostrarPontosDeUmPoligono(int, TListBox *);
		void Transladar(int, double, double);
		void Escalonar(int, double, double, bool);
		void Rotacionar(int, double, bool);
		void Refletir(int, int, int);
		Ponto2d PontoCentral(int);
};

#endif
