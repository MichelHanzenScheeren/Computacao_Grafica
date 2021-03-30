//---------------------------------------------------------------------------
#ifndef PoligonoH
#define PoligonoH

#include "Ponto2d.h"
#include "Janela.h"
#include "Dda.h"
#include "Bresenham.h"
#include "Matriz.h"
#include "Clipping.h"
#include "Casteljau.h"
#include "Hermite.h"
#include "BSpline.h"
#include <vector>
#include <Vcl.ExtCtrls.hpp>
#include<Vcl.StdCtrls.hpp>
#include <cmath>

using std::vector;
using std::string;
//---------------------------------------------------------------------------
class Poligono
{
	public:
		vector<Ponto2d> Pontos;
		int Id;
		UnicodeString Tipo;

		Poligono(int, UnicodeString);
		void AdicionarPonto(Ponto2d);
		void AdicionarPontos(vector<Ponto2d>);
		void Desenhar(TCanvas *, int, Janela, Janela);
		void DesenharCirculo(TCanvas *, Janela, Janela);
		void GerarPontosDoCirculo(Ponto2d);
		void AdicionarPontosAoCirculo(int, int, int, int);
		void LineTo(TCanvas *, Janela, Janela);
		UnicodeString ToString();
		void MostrarPontos(TListBox *);
		void AtualizarEixoX(double, double);
		void AtualizarEixoY(double, double);
		void Transladar(double, double);
		void Escalonar(double, double, bool);
		void EscalonamentoHomogeneo(double, double);
		vector<vector<double>> MultiplicarMatrizes(vector<vector<double>>, vector<vector<double>>);
		void Rotacionar(double, bool);
        void RotacaoHomogenea(double);
		void Refletir(int, int);
		Ponto2d PontoCentral();
		vector<Ponto2d> FiltrarPontosDoClipping(Janela);
		vector<Ponto2d> AplicarCasteljau(double);
		vector<Ponto2d> AplicarHermite(double);
		vector<Ponto2d> AplicarBSpline(double);
		vector<Ponto2d> AplicarBSplineFwDif(double);
};

#endif
