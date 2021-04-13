//---------------------------------------------------------------------------

#pragma hdrstop

#include "Bezier.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Bezier::Bezier(vector<Ponto2d*> pontos) {
	_pontos = pontos;
}

vector<Ponto2d*> Bezier::CriarCurva(double intervalo) {
	if (_pontos.size() < 4 || intervalo <= 0)
		return _curva;

	Ponto2d *p1 = _pontos[0];
	Ponto2d *p2 = _pontos[1];
	Ponto2d *p3 = _pontos[2];
	Ponto2d *p4 = _pontos[3];

	vector<vector<double>> Mb = {
		{-1, 3, -3, 1},
		{3, -6, 3, 0},
		{-3, 3, 0, 0},
		{1, 0, 0, 0}
	};
	vector<vector<double>> Gbx = {{p1->X}, {p2->X}, {p3->X}, {p4->X}};
	vector<vector<double>> Gby = {{p1->Y}, {p2->Y}, {p3->Y}, {p4->Y}};

	vector<vector<double>> MGbx = Matriz::Multiplicar(Mb, Gbx);
	vector<vector<double>> MGby = Matriz::Multiplicar(Mb, Gby);

	double t = 0.0;
	while (t <= 1.0) {
		vector<vector<double>> T = {{pow(t, 3), pow(t, 2), t, 1}};
		vector<vector<double>> resultadoX = Matriz::Multiplicar(T, MGbx);
		vector<vector<double>> resultadoY = Matriz::Multiplicar(T, MGby);
		_curva.push_back(new Ponto2d(resultadoX[0][0], resultadoY[0][0]));
		t += intervalo;
	}
	return _curva;
}
