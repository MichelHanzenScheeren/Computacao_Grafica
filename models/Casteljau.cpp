//---------------------------------------------------------------------------

#pragma hdrstop

#include "Casteljau.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Casteljau::Casteljau(vector<Ponto2d> pontos) {
	_pontos = pontos;
}

vector<Ponto2d> Casteljau::CriarCurva(int precisao) {
	 if (_pontos.size() < 3) return _curva;

	 Ponto2d p0 = _pontos[0];
	 Ponto2d p1 = _pontos[1];
	 Ponto2d p2 = _pontos[2];
	 _curva.push_back(p0);
	 _casteljauRecursivo(p0, p1, p2, precisao);
     return _curva;
}

void  Casteljau::_casteljauRecursivo(
	Ponto2d p0, Ponto2d p1, Ponto2d p2, int precisao)
{
	 if (_distancia(p0, p1 ) <= precisao &&  _distancia(p1, p2) <= precisao) {
		_curva.push_back(p0);
		_curva.push_back(p1);
		_curva.push_back(p2);
	 } else {
		 Ponto2d aux1((p0.X + p1.X) / 2, (p0.Y + p1.Y) / 2);
		 Ponto2d aux3((p1.X + p2.X) / 2, (p1.Y + p2.Y) / 2);
		 Ponto2d aux2((aux1.X + aux3.X) / 2, (aux1.Y + aux3.Y) / 2);

		 _casteljauRecursivo(p0, aux1, aux2, precisao);
		 _casteljauRecursivo(aux2, aux3, p2, precisao);
	 }
}

double Casteljau::_distancia(Ponto2d p1, Ponto2d p2) {
	return sqrt(pow(p2.X - p1.X, 2) + pow(p2.Y - p1.Y, 2));
}


