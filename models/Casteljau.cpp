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

	 if(_pontos.size() == 3) {
		Ponto2d p0 = _pontos[0];
		Ponto2d p1 = _pontos[1];
		Ponto2d p2 = _pontos[2];
		_casteljauRecursivo(p0, p1, p2, precisao);
	 } else {
        Ponto2d p0 = _pontos[0];
		Ponto2d p1 = _pontos[1];
		Ponto2d p2 = _pontos[2];
		Ponto2d p3 = _pontos[3];
		_casteljauRecursivo(p0, p1, p2, p3, precisao);
	 }
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

void  Casteljau::_casteljauRecursivo(
	Ponto2d p0, Ponto2d p1, Ponto2d p2, Ponto2d p3, int precisao)
{
	 if (_distancia(p0, p1 ) <= precisao &&  _distancia(p1, p2) <= precisao
		&& _distancia(p2, p3) <= precisao)
	 {
		_curva.push_back(p0);
		_curva.push_back(p1);
		_curva.push_back(p2);
		_curva.push_back(p3);
	 } else {
		 Ponto2d l2((p0.X + p1.X) / 2, (p0.Y + p1.Y) / 2);
		 Ponto2d h((p1.X + p2.X) / 2, (p1.Y + p2.Y) / 2);
		 Ponto2d r3((p2.X + p3.X) / 2, (p2.Y + p3.Y) / 2);
		 Ponto2d l3((l2.X + h.X) / 2, (l2.Y + h.Y) / 2);
		 Ponto2d r2((h.X + r3.X) / 2, (h.Y + r3.Y) / 2);
		 Ponto2d l4((l3.X + r2.X) / 2, (l3.Y + r2.Y) / 2);

		 _casteljauRecursivo(p0, l2, l3, l4, precisao);
		 _casteljauRecursivo(l4, r2, r3, p3, precisao);
	 }
}

double Casteljau::_distancia(Ponto2d p1, Ponto2d p2) {
	return sqrt(pow(p2.X - p1.X, 2) + pow(p2.Y - p1.Y, 2));
}


