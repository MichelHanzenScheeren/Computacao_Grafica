//---------------------------------------------------------------------------

#pragma hdrstop

#include "Ponto2d.h"
#include <cmath>
//---------------------------------------------------------------------------
#pragma package(smart_init)
Ponto2d::Ponto2d(double x, double y) {
	X = x;
	Y = y;
}

void Ponto2d::Editar(double x, double y) {
	X = x;
	Y = y;
}

int Ponto2d::XMundoParaViewport(Janela mundo, Janela viewport) {
	return ((X - mundo.Xmin)/(mundo.Xmax - mundo.Xmin))
		* (viewport.Xmax - viewport.Xmin);
}

int Ponto2d::YMundoParaViewport(Janela mundo, Janela viewport) {
	return (1-((Y - mundo.Ymin)/(mundo.Ymax - mundo.Ymin)))
		* (viewport.Ymax - viewport.Ymin);
}

UnicodeString Ponto2d::ToString() {
	return "(" + FloatToStr(X) + ", " + FloatToStr(Y) + ");";
}

void Ponto2d::Transladar(double dx, double dy) {
	X += dx;
	Y += dy;
}

void Ponto2d::Escalonar(double fx, double fy) {
	X *= fx;
	Y *= fy;
}

void Ponto2d::Rotacionar(double angulo) {
	double radian = angulo * M_PI / 180;
	double newX = X * cos(radian) - Y * sin(radian);
	double newY = X * sin(radian) + Y * cos(radian);
	X = newX;
    Y = newY;
}

void Ponto2d::Refletir(int eixoX, int eixoY) {
	X *= eixoX;
	Y *= eixoY;
}

