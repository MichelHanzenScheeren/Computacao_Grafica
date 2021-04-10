//---------------------------------------------------------------------------
#ifndef Ponto3dH
#define Ponto3dH
#include<Vcl.StdCtrls.hpp>
#include "Ponto2d.h"
//---------------------------------------------------------------------------
class Ponto3d : public Ponto2d
{
	public:
		double Z;

		Ponto3d(double, double, double);
		UnicodeString ToString();
		void Transladar(double, double, double);
//		void Escalonar(double, double);
//		void Rotacionar(double);
};
#endif
