//---------------------------------------------------------------------------
#pragma hdrstop
#include "Ponto3d.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Ponto3d::Ponto3d(double x, double y, double z) : Ponto2d(x, y) {
	Z = z;
}

UnicodeString Ponto3d::ToString() {
	return "(" + FloatToStr(X) + ", "
	+ FloatToStr(Y) + ", " + FloatToStr(Z) + ");";
}

void Ponto3d::Transladar(double dx, double dy, double dz) {
	Z += dz;
    Ponto2d::Transladar(dx, dy);
}
