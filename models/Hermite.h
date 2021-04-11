//---------------------------------------------------------------------------

#ifndef HermiteH
#define HermiteH

#include "Ponto2d.h"
#include "Matriz.h"
#include <vector>
#include <cmath>
using std::vector;
//---------------------------------------------------------------------------
class Hermite {
	private:
		vector<Ponto2d*> _pontos;
		vector<Ponto2d*> _curva;

	public:
		Hermite(vector<Ponto2d*>);
		vector<Ponto2d*> CriarCurva(double);
};
#endif
