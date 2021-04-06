//---------------------------------------------------------------------------

#ifndef BezierH
#define BezierH

#include "Ponto2d.h"
#include "Matriz.h"
#include <vector>
#include <cmath>
using std::vector;
//---------------------------------------------------------------------------
class Bezier {
	private:
		vector<Ponto2d> _pontos;
		vector<Ponto2d> _curva;

	public:
		Bezier(vector<Ponto2d>);
		vector<Ponto2d> CriarCurva(double);
};
#endif
