//---------------------------------------------------------------------------

#ifndef CasteljauH
#define CasteljauH

#include "Ponto2d.h"
#include <vector>
#include <cmath>
using std::vector;
//---------------------------------------------------------------------------
class Casteljau {
	private:
		vector<Ponto2d*> _pontos;
		vector<Ponto2d*> _curva;

		void _casteljauRecursivo(Ponto2d*, Ponto2d*, Ponto2d*, int);
		void  _casteljauRecursivo(Ponto2d*, Ponto2d*, Ponto2d*, Ponto2d*, int);
		double _distancia(Ponto2d*, Ponto2d*);
	public:
		Casteljau(vector<Ponto2d*>);
		vector<Ponto2d*> CriarCurva(int);
};

#endif
