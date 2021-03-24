//---------------------------------------------------------------------------
#pragma hdrstop
#include "Janela.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Janela::Janela(double xmin, double xmax, double ymin, double ymax)
{
	Xmin = xmin;
	Xmax = xmax;
	Ymin = ymin;
	Ymax = ymax;
}

void Janela::EditarX(double xmin, double xmax)
{
	if (xmin < xmax) {
		Xmin = xmin;
		Xmax = xmax;
	}
}

void Janela::EditarY(double ymin, double ymax)
{   if (ymin < ymax) {
		Ymin = ymin;
		Ymax = ymax;
	}
}

void Janela::IncrementarX(double incrementoXmin, double incrementoXmax)
{
	if (Xmin +  incrementoXmin < Xmax + incrementoXmax) {
		Xmin +=  incrementoXmin;
		Xmax += incrementoXmax;
	}

}

void Janela::IncrementarY(double incrementoYmin, double incrementoYmax)
{
	if (Ymin +  incrementoYmin < Ymax + incrementoYmax) {
		Ymin +=  incrementoYmin;
		Ymax += incrementoYmax;
	}
}

