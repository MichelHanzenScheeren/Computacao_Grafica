//---------------------------------------------------------------------------

#ifndef Ponto2dH
#define Ponto2dH
#include "Janela.h"
#include<Vcl.StdCtrls.hpp>
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
		void Rotacionar(double);
        void Refletir(int, int);
};
#endif
