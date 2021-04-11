//---------------------------------------------------------------------------

#pragma hdrstop

#include "Hermite.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Hermite::Hermite(vector<Ponto2d*> pontos) {
	_pontos = pontos;
}

vector<Ponto2d*> Hermite::CriarCurva(double intervalo) {
	if (_pontos.size() < 4 || intervalo <= 0)
		return _curva;

	Ponto2d *p1 = _pontos[0];
	Ponto2d *p2 = _pontos[1];
	Ponto2d *p3 = _pontos[2];
	Ponto2d *p4 = _pontos[3];
	Ponto2d *r1 = new Ponto2d(p2->X - p1->X, p2->Y - p1->Y);
	Ponto2d *r4 = new Ponto2d(p4->X - p3->X, p4->Y - p3->Y);

	vector<vector<double>> Mh = {
		{2, -2, 1, 1},
		{-3, 3, -2, -1},
		{0, 0, 1, 0},
		{1, 0, 0, 0}
	};
	vector<vector<double>> Ghx = {{p1->X}, {p4->X}, {r1->X}, {r4->X}};
	vector<vector<double>> Ghy = {{p1->Y}, {p4->Y}, {r1->Y}, {r4->Y}};

	vector<vector<double>> MGhx = Matriz::Multiplicar(Mh, Ghx);
	vector<vector<double>> MGhy = Matriz::Multiplicar(Mh, Ghy);

	double t = 0.0;
	while (t <= 1.0) {
		vector<vector<double>> T = {{pow(t, 3), pow(t, 2), t, 1}};
		vector<vector<double>> resultadoX = Matriz::Multiplicar(T, MGhx);
		vector<vector<double>> resultadoY = Matriz::Multiplicar(T, MGhy);
		_curva.push_back(new Ponto2d(resultadoX[0][0], resultadoY[0][0]));
		t += intervalo;
	}
	return _curva;
}
