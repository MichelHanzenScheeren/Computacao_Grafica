//---------------------------------------------------------------------------

#pragma hdrstop

#include "Bezier.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Bezier::Bezier(vector<Ponto2d> pontos) {
	_pontos = pontos;
}

vector<Ponto2d> Bezier::CriarCurva(double intervalo) {
	if (_pontos.size() < 4 || intervalo <= 0)
		return _curva;

	Ponto2d p1 = _pontos[0];
	Ponto2d p2 = _pontos[1];
	Ponto2d p3 = _pontos[2];
	Ponto2d p4 = _pontos[3];

	vector<vector<double>> Mh = {
		{1, 0, 0, 0},
		{-3, 3, 0, 0},
		{3, -6, 3, 0},
		{-1, 3, -3, 1}
	};
	vector<vector<double>> Ghx = {{p1.X}, {p2.X}, {p3.X}, {p4.X}};
	vector<vector<double>> Ghy = {{p1.Y}, {p2.Y}, {p3.Y}, {p4.Y}};

	vector<vector<double>> MGhx = Matriz::Multiplicar(Mh, Ghx);
	vector<vector<double>> MGhy = Matriz::Multiplicar(Mh, Ghy);

	double i = 0.0;
	while (i <= 1.0) {
		vector<vector<double>> T = {{1, i, pow(i, 2), pow(i, 3)}};
		vector<vector<double>> resultadoX = Matriz::Multiplicar(T, MGhx);
		vector<vector<double>> resultadoY = Matriz::Multiplicar(T, MGhy);
		_curva.push_back(Ponto2d(resultadoX[0][0], resultadoY[0][0]));
		i += intervalo;
	}
	return _curva;
}
