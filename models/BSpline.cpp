//---------------------------------------------------------------------------

#pragma hdrstop

#include "BSpline.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

BSpline::BSpline(vector<Ponto2d> pontos) {
	_pontos = pontos;
}

vector<Ponto2d> BSpline::CriarCurva(double intervalo) {
	if (_pontos.size() < 4 || intervalo <= 0)
		return _curva;
	vector<vector<double>> Mbs = {
		{-1, 3, -3, 1},
		{3, -6, 3, 0},
		{-3, 0, 3, 0},
		{1, 4, 1, 0}
	};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			Mbs[i][j] /= 6;
		}
	}
	for (int i = 3; i < _pontos.size(); i++) {
		Ponto2d p1 = _pontos[i - 3];
		Ponto2d p2 = _pontos[i - 2];
		Ponto2d p3 = _pontos[i - 1];
		Ponto2d p4 = _pontos[i];

		vector<vector<double>> Gbsx = {{p1.X}, {p2.X}, {p3.X}, {p4.X}};
		vector<vector<double>> Gbsy = {{p1.Y}, {p2.Y}, {p3.Y}, {p4.Y}};
		vector<vector<double>> MGbsx = Matriz::Multiplicar(Mbs, Gbsx);
		vector<vector<double>> MGbsy = Matriz::Multiplicar(Mbs, Gbsy);

		double j = 0.0;
		while (j <= 1.0) {
			vector<vector<double>> T = {{pow(j, 3), pow(j, 2), j, 1}};
			vector matrizX = Matriz::Multiplicar(T, MGbsx);
			vector matrizY = Matriz::Multiplicar(T, MGbsy);
			_curva.push_back(Ponto2d(matrizX[0][0], matrizY[0][0]));
			j += intervalo;
		}
	}
	return _curva;
}

vector<Ponto2d> BSpline::CriarCurvaForwardDifference(double intervalo) {
	if (_pontos.size() < 4 || intervalo <= 0)
		return _curva;
	vector<vector<double>> Mbs = {
		{-1, 3, -3, 1},
		{3, -6, 3, 0},
		{-3, 0, 3, 0},
		{1, 4, 1, 0}
	};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			Mbs[i][j] /= 6;
		}
	}
	for (int i = 3; i < _pontos.size(); i++) {
		Ponto2d p1 = _pontos[i - 3];
		Ponto2d p2 = _pontos[i - 2];
		Ponto2d p3 = _pontos[i - 1];
		Ponto2d p4 = _pontos[i];

		vector<vector<double>> Gbsx = {{p1.X}, {p2.X}, {p3.X}, {p4.X}};
		vector<vector<double>> Gbsy = {{p1.Y}, {p2.Y}, {p3.Y}, {p4.Y}};
		vector<vector<double>> MGbsx = Matriz::Multiplicar(Mbs, Gbsx);
		vector<vector<double>> MGbsy = Matriz::Multiplicar(Mbs, Gbsy);

		double t3 = pow(intervalo, 3), t2 = pow(intervalo, 2), t = intervalo;

		double x = MGbsx[3][0];
		double dx = MGbsx[0][0] * t3 + MGbsx[1][0] * t2 + MGbsx[2][0] * t;
		double d2x = 6 * MGbsx[0][0] * t3 + 2 * MGbsx[1][0] * t2;
		double d3x = 6 * MGbsx[0][0] * t3;

		double y = MGbsy[3][0];
		double dy = MGbsy[0][0] * t3 + MGbsy[1][0] * t2 + MGbsy[2][0] * t;
		double d2y = 6 * MGbsy[0][0] * t3 + 2 * MGbsy[1][0] * t2;
		double d3y = 6 * MGbsy[0][0] * t3;

		_curva.push_back(Ponto2d(x, y));
		double j = 0.0;
		while (j <= 1.0) {
			j += intervalo;
			x += dx;
			dx += d2x;
			d2x += d3x;
			y += dy;
			dy += d2y;
			d2y += d3y;
			_curva.push_back(Ponto2d(x, y));
		}
	}
	return _curva;
}
