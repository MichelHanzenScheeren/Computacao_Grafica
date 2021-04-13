//---------------------------------------------------------------------------
#ifndef PoligonoH
#define PoligonoH

#include "Ponto2d.h"
#include "Ponto3d.h"
#include "Janela.h"
#include "Dda.h"
#include "Bresenham.h"
#include "Matriz.h"
#include "Clipping.h"
#include "Casteljau.h"
#include "Hermite.h"
#include "Bezier.h"
#include "BSpline.h"
#include <Vcl.ExtCtrls.hpp>
#include<Vcl.StdCtrls.hpp>

#include <cmath>
#include <vector>
using std::vector;
//---------------------------------------------------------------------------

class Poligono
{
	public:
		vector<Ponto2d*> Pontos;
		int Id;
		UnicodeString Tipo;

		Poligono(int, UnicodeString);
		void AdicionarPonto(Ponto2d*);
		void AdicionarPontos(vector<Ponto2d*>);
		void Desenhar(TCanvas *, int, Janela, Janela);
		void _alterarCorDoPincel(TCanvas *);
		void DesenharCirculo(TCanvas *, Janela, Janela);
		void GerarPontosDoCirculo(Ponto2d*);
		void AdicionarPontosAoCirculo(int, int, int, int);
		void LineTo(TCanvas *, Janela, Janela);
		UnicodeString ToString();
		void MostrarPontos(TListBox *);
		void AtualizarEixoX(double, double);
		void AtualizarEixoY(double, double);
		// TRANSFORMAÇÕES
		void Transladar(double, double);
		void Escalonar(double, double, bool);
		void EscalonamentoHomogeneo(double, double);
		void Rotacionar(double, bool);
        void RotacaoHomogenea(double);
		void Refletir(int, int);
		Ponto2d* PontoCentral();
		// CLIPPING
		vector<Ponto2d*> FiltrarPontosDoClipping(Janela);
        // CURVAS
		vector<Ponto2d*> AplicarCasteljau(double);
		vector<Ponto2d*> AplicarHermite(double);
		vector<Ponto2d*> AplicarBezier(double);
		vector<Ponto2d*> AplicarBSpline(double);
		vector<Ponto2d*> AplicarBSplineFwDif(double);

		public: virtual ~Poligono() {}
        template<typename T>
		bool IsTypeOf() {
			return (dynamic_cast<T*>(this) != NULL);
		}
};

#endif
