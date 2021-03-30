//---------------------------------------------------------------------------
#ifndef DisplayFileH
#define DisplayFileH

#include "Poligono.h"
#include "Janela.h"
#include <vector>
#include <Vcl.ExtCtrls.hpp>
#include<Vcl.StdCtrls.hpp>

using std::vector;
//---------------------------------------------------------------------------
class DisplayFile
{
	private:
        int _id = 0;
	public:
		vector<Poligono> Poligonos;
        int GerarNovoId();
		void AdicionarPoligono(Poligono);
		void AdicionarPontoAoUltimoPoligono(Ponto2d);
		void Desenhar(TCanvas *, int, Janela, Janela);
		void MostrarPoligonosDesenhados(TListBox *);
		void GerarPontosDoCirculo(Ponto2d);
		void MostrarPontosDeUmPoligono(int, TListBox *);
        void AtualizarEixos(Janela mundo);
		void Transladar(int, double, double);
		void Escalonar(int, double, double, bool);
		void Rotacionar(int, double, bool);
		void Refletir(int, int, int);
		Ponto2d PontoCentral(int);
        void PintarPontoCentral(Ponto2d, TCanvas *, Janela, Janela);
		void AplicarClipping(Janela);
		void ApagarPoligono(int);
        // CURVAS
		void AplicarCasteljau(int, double);
		void AplicarHermite(int, double);
		void AplicarBSpline(int, double);
		void AplicarBSplineFwDif(int, double);
};

#endif
