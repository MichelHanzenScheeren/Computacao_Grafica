//---------------------------------------------------------------------------
#pragma hdrstop
#include "Ponto3d.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Ponto3d::Ponto3d(double x, double y, double z) : Ponto2d(x, y) {
	Z = z;
}
