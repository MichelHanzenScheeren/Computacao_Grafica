//---------------------------------------------------------------------------
#pragma hdrstop
#include "Clipping.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Clipping::Clipping(Janela clipping) {
    _clipping = clipping;
}

void Clipping::PontoUnico(Ponto2d *ponto) {
	if (ponto->ObterValorDeClipping(_clipping) == 0) {
		_adicionarSeNaoExiste(ponto);
	}
}

void Clipping::SegmentoReta(Ponto2d *ponto1, Ponto2d *ponto2) {
	short valor1 = ponto1->ObterValorDeClipping(_clipping);
	short valor2 = ponto2->ObterValorDeClipping(_clipping);
	if(valor1 == 0 && valor2 == 0) {
		_adicionarSeNaoExiste(ponto1);
		_adicionarSeNaoExiste(ponto2);
	}
	else if ((valor1 & valor2) == 0) {
		double divisor = ponto2->X - ponto1->X;
		divisor = divisor == 0 ? 0.000000000001 : divisor;
		_m = (ponto2->Y - ponto1->Y) / (divisor);
		_m = _m == 0 ? 0.000000000001 : _m;
		if (valor1 == 0) {
			_adicionarSeNaoExiste(ponto1);
		} else {
			_verificarPossiveisExtremidades(valor1, ponto1);
		}
		if (valor2 == 0)
			_adicionarSeNaoExiste(ponto2);
		else
			_verificarPossiveisExtremidades(valor2, ponto2);
	}
}

void Clipping::_adicionarSeNaoExiste(Ponto2d *ponto) {
	Ponto2d *newPonto = new Ponto2d(ponto->X, ponto->Y);
	if (_pontos.size() == 0)
		_pontos.push_back(newPonto);
	else if (_pontos.back()->X != ponto->X || _pontos.back()->Y != ponto->Y)
		_pontos.push_back(newPonto);
}

void Clipping::_verificarPossiveisExtremidades(short valor, Ponto2d *ponto) {
	if (valor >= 8) {
		_extremidadeYmax(ponto);
		valor -= 8;
	}
	if (valor >= 4) {
		_extremidadeYmin(ponto);
		valor -= 4;
	}
	if (valor >= 2) {
		_extremidadeXmax(ponto);
		valor -= 2;
	}
	if (valor >= 1) {
		_extremidadeXmin(ponto);
	}
}

void Clipping::_extremidadeYmax(Ponto2d *ponto) {
	double x = ponto->X + (1 / _m) * (_clipping.Ymax - ponto->Y);
	if (x >= _clipping.Xmin && x < _clipping.Xmax)
		_adicionarSeNaoExiste(new Ponto2d(x, _clipping.Ymax));
}

void Clipping::_extremidadeYmin(Ponto2d *ponto) {
	double x = ponto->X + (1 / _m) * (_clipping.Ymin - ponto->Y);
	if (x >= _clipping.Xmin && x < _clipping.Xmax)
		_adicionarSeNaoExiste(new Ponto2d(x, _clipping.Ymin));
}

void Clipping::_extremidadeXmax(Ponto2d *ponto) {
	double y = _m * (_clipping.Xmax - ponto->X) + ponto->Y;
	if (y >= _clipping.Ymin && y < _clipping.Ymax)
	  _adicionarSeNaoExiste(new Ponto2d(_clipping.Xmax, y));
}

void Clipping::_extremidadeXmin(Ponto2d *ponto) {
	double y = _m * (_clipping.Xmin - ponto->X) + ponto->Y;
	if (y >= _clipping.Ymin && y < _clipping.Ymax)
	  _adicionarSeNaoExiste(new Ponto2d(_clipping.Xmin, y));
}

vector<Ponto2d*> Clipping::ObterResultados() {
	return _pontos;
}

