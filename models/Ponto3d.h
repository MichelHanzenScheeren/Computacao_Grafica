//---------------------------------------------------------------------------

#ifndef Ponto3dH
#define Ponto3dH
#include "Ponto2d.h"
//---------------------------------------------------------------------------
class Ponto3d : public Ponto2d
{
	public:
		double Z;

		Ponto3d(double, double, double);
};
#endif
