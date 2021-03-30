//---------------------------------------------------------------------------

#ifndef BSplineH
#define BSplineH

#include "Ponto2d.h"
#include "Matriz.h"
#include <vector>
#include <cmath>
using std::vector;
//---------------------------------------------------------------------------
class BSpline {
	private:
		vector<Ponto2d> _pontos;
		vector<Ponto2d> _curva;

	public:
		BSpline(vector<Ponto2d>);
		vector<Ponto2d> CriarCurva(double);
		vector<Ponto2d> CriarCurvaForwardDifference(double);
};
#endif
