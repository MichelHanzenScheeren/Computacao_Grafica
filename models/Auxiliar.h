//---------------------------------------------------------------------------
#ifndef AuxiliarH
#define AuxiliarH

#include "Janela.h"
#include "Ponto2d.h"
#include "Poligono.h"
#include "DisplayFile.h"
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.StdCtrls.hpp>
//---------------------------------------------------------------------------
class Auxiliar
{
	private:

		bool _desenhandoPoligono = false;
		bool _primeiroPontoPoligono = false;
		bool _desenhandoCirculo = false;
        bool _primeiroPontoCirculo = false;
		Janela _mundo = Janela(-250, 250, -250, 250);
		Janela _viewport = Janela(0, 500, 0, 500);
		Janela _clipping = Janela(-100, 100, -100, 100);
		DisplayFile _display;
	public:
		void SalvarEixos();
		void DesenharPoligonos(TCanvas *, int);
		void MostrarPoligonosDesenhados(TListBox *);
		void MostrarPontosDeUmPoligono(int, TListBox *);
		double XViewportParaMundo(int xVp);
		double YViewportParaMundo(int yVp);
		void IniciarDesenhoPoligono();
		void FinalizarDesenhoPoligono();
        bool EstaDesenhandoPoligono();
		void SalvarNovoPontoDoPoligono(int, int);
		void IniciarDesenhoCirculo();
		void FinalizarDesenhoDoCirculo();
		bool EstaDesenhandoCirculo();
		void SalvarNovoPontoDoCirculo(int x, int y);
		void AtualizarCoordenadasDeMundo(double, double, double, double);
		void AtualizarCoordenadasDosForms(TEdit *, TEdit *, TEdit *, TEdit *);
		void AtualizarEixos();
		void Zoom(UnicodeString, double);
		void Move(UnicodeString, double);
		void Transladar(int, double, double);
		void Escalonar(int, double, double, bool);
		void Rotacionar(int, double, bool);
		void Refletir(int, int, int);
		Ponto2d PontoCentral(int);
		void PintarPontoCentral(TCanvas *, Ponto2d);
        void AplicarClipping();
};
#endif
