//---------------------------------------------------------------------------
#pragma hdrstop
#include "Ponto3d.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Ponto3d::Ponto3d(double x, double y, double z) : Ponto2d(x, y) {
	Z = z;
}

UnicodeString Ponto3d::ToString() {
	return "(" + FloatToStr(round(X)) + ", "
	+ FloatToStr(round(Y)) + ", " + FloatToStr(round(Z)) + ");";
}

void Ponto3d::Transladar(double dx, double dy, double dz) {
	Z += dz;
    Ponto2d::Transladar(dx, dy);
}

void Ponto3d::Escalonar(double fx, double fy, double fz) {
	Z *= fz;
    Ponto2d::Escalonar(fx, fy);
}

void Ponto3d::EscalonamentoHomogeneo(vector<vector<double>> homogenea) {
	vector<vector<double>> matrizPonto = {{X, Y, Z, 1}};
	vector<vector<double>> result = Matriz::Multiplicar(matrizPonto, homogenea);
	X = result[0][0];
	Y = result[0][1];
    Z = result[0][2];
}

void Ponto3d::Rotacionar(double angulo, int eixo) {
	if(eixo == 2) {
		Ponto2d::Rotacionar(angulo);
	} else if (eixo == 1) {
		double radian = angulo * M_PI / 180;
		double oldZ = Z;
		Z = Z * cos(radian) - X * sin(radian);
		X = oldZ * sin(radian) + X * cos(radian);
	} else {
		double radian = angulo * M_PI / 180;
		double oldY = Y;
		Y = Y * cos(radian) - Z * sin(radian);
		Z = oldY * sin(radian) + Z * cos(radian);
	}
}

void Ponto3d::RotacaoHomogenea(vector<vector<double>> homogenea) {
	vector<vector<double>> matrizPonto = {{X, Y, Z, 1}};
	vector<vector<double>> result = Matriz::Multiplicar(matrizPonto, homogenea);
	X = result[0][0];
	Y = result[0][1];
    Z = result[0][2];
}
