//---------------------------------------------------------------------------
#ifndef DisplayFileH
#define DisplayFileH

#include "Poligono.h"
#include "Poliedro.h"
#include "Janela.h"
#include "Ponto2d.h"
#include "Ponto3d.h"
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
		vector<Poligono*> Poligonos;

        int GerarNovoId();
		void AdicionarPoligono(Poligono*);
		void AdicionarPontoAoUltimoPoligono(Ponto2d*);
		void Desenhar(TCanvas *, int, Janela, Janela);
		void MostrarPoligonosDesenhados(TListBox *);
		void GerarPontosDoCirculo(Ponto2d*);
		void MostrarPontosDeUmPoligono(int, TListBox *);
		void AtualizarEixos(Janela mundo);
		// TRANSFORMAÇÕES
		void Transladar(int, double, double, double);
		void Escalonar(int, double, double, double, bool);
        bool ApenasPoligono(int index);
		void Rotacionar(int, double, bool, int);
		void Refletir(int, int, int);
		Ponto2d* PontoCentral(int);
		void PintarPontoCentral(Ponto2d*, TCanvas *, Janela, Janela);
		// CLIPPING
		void AplicarClipping(Janela);
		void ApagarPoligono(int);
		// CURVAS
        void _registrarCurva(vector<Ponto2d*> *, UnicodeString, int);
		void AplicarCasteljau(int, double);
		void AplicarHermite(int, double);
        void AplicarBezier(int, double);
		void AplicarBSpline(int, double);
		void AplicarBSplineFwDif(int, double);
		// 3D
		void CriarPoliedro(vector<vector<double>>);
};

#endif
