//---------------------------------------------------------------------------
#pragma hdrstop
#include "Ponto2d.h"
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
	return "(" + FloatToStr(round(X)) + ", " + FloatToStr(round(Y)) + ");";
}

void Ponto2d::Transladar(double dx, double dy) {
	X += dx;
	Y += dy;
}

void Ponto2d::Escalonar(double fx, double fy) {
	X *= fx;
	Y *= fy;
}

void Ponto2d::EscalonamentoHomogeneo(vector<vector<double>> homogenea) {
	vector<vector<double>> matrizPonto = {{X, Y, 1}};
	vector<vector<double>> result = Matriz::Multiplicar(matrizPonto, homogenea);
	X = result[0][0];
	Y = result[0][1];
}

void Ponto2d::Rotacionar(double angulo) {
	double radian = angulo * M_PI / 180;
	double oldX = X;
	X = X * cos(radian) - Y * sin(radian);
	Y = oldX * sin(radian) + Y * cos(radian);
}

void Ponto2d::RotacaoHomogenea(vector<vector<double>> homogenea) {
	vector<vector<double>> matrizPonto = {{X, Y, 1}};
	vector<vector<double>> result = Matriz::Multiplicar(matrizPonto, homogenea);
	X = result[0][0];
	Y = result[0][1];
}

void Ponto2d::Refletir(int eixoX, int eixoY) {
	X *= eixoX;
	Y *= eixoY;
}

short Ponto2d::ObterValorDeClipping(Janela clipping) {
	short somatorio = 0;
	if (X < clipping.Xmin)
		somatorio += 1;
	if (X > clipping.Xmax)
		somatorio += 2;
	if (Y < clipping.Ymin)
		somatorio += 4;
	if (Y > clipping.Ymax)
		somatorio += 8;
	return somatorio;
}

