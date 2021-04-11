//---------------------------------------------------------------------------
#ifndef Ponto3dH
#define Ponto3dH
#include<Vcl.StdCtrls.hpp>
#include "Ponto2d.h"
#include <vector>
using std::vector;
//---------------------------------------------------------------------------
class Ponto3d : public Ponto2d
{
	public:
		double Z;

		Ponto3d(double, double, double);
		UnicodeString ToString();
		void Transladar(double, double, double);
		void Escalonar(double, double, double);
        void EscalonamentoHomogeneo(vector<vector<double>> homogenea);
		void Rotacionar(double, int);
		void RotacaoHomogenea(vector<vector<double>>);
};
#endif
