//---------------------------------------------------------------------------

#ifndef Ponto2dH
#define Ponto2dH
#include "Janela.h"
#include "Matriz.h"
#include<Vcl.StdCtrls.hpp>
#include <vector>
using std::vector;
//---------------------------------------------------------------------------
class Ponto2d
{
	public:
		double X;
		double Y;

		Ponto2d(double, double);
        void Editar(double, double);
		int XMundoParaViewport(Janela, Janela);
		int YMundoParaViewport(Janela, Janela);
		UnicodeString ToString();
		void Transladar(double, double);
		void Escalonar(double, double);
		void EscalonamentoHomogeneo(vector<vector<double>> homogenea);
		void Rotacionar(double);
        void RotacaoHomogenea(vector<vector<double>> homogenea);
        void Refletir(int, int);
};
#endif
