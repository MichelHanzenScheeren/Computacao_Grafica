//---------------------------------------------------------------------------
#pragma hdrstop
#include "Auxiliar.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
int Auxiliar::GerarNovoId() {
	_id++;
    return _id;
}

void Auxiliar::SalvarEixos() {
	Poligono poligono1(GerarNovoId(), "Eixo x");
	poligono1.AdicionarPonto(Ponto2d(_mundo.Xmin, 0));
	poligono1.AdicionarPonto(Ponto2d(_mundo.Xmax, 0));
	_display.AdicionarPoligono(poligono1);

	Poligono poligono2(GerarNovoId(), "Eixo y");
	poligono2.AdicionarPonto(Ponto2d(0, _mundo.Ymin));
	poligono2.AdicionarPonto(Ponto2d(0, _mundo.Ymax));
	_display.AdicionarPoligono(poligono2);
}

void Auxiliar::DesenharPoligonos(TCanvas *canvas, int algoritmo) {
	_display.Desenhar(canvas, algoritmo, _mundo, _viewport);
}

void Auxiliar::MostrarPoligonosDesenhados(TListBox *lbPoligono) {
	_display.MostrarPoligonosDesenhados(lbPoligono);
}

void Auxiliar::MostrarPontosDeUmPoligono(int posicao, TListBox *lbPontos) {
	_display.MostrarPontosDeUmPoligono(posicao, lbPontos);
}

double Auxiliar::XViewportParaMundo (int xVp) {
	return ((xVp - _viewport.Xmin)/(_viewport.Xmax - _viewport.Xmin))
		* (_mundo.Xmax - _mundo.Xmin) + _mundo.Xmin;
}

double Auxiliar::YViewportParaMundo (int yVp) {
	return (1 - ((yVp - _viewport.Ymin) / (_viewport.Ymax - _viewport.Ymin)))
		* (_mundo.Ymax - _mundo.Ymin) + _mundo.Ymin;
}

void Auxiliar::IniciarDesenhoPoligono() {
	_desenhandoPoligono = true;
	_primeiroPontoPoligono = true;
	_desenhandoCirculo = false;
	_primeiroPontoCirculo = false;
}

void Auxiliar::FinalizarDesenhoPoligono() {
	_desenhandoPoligono = false;
	_primeiroPontoPoligono = false;
}

bool Auxiliar::EstaDesenhandoPoligono() {
	return _desenhandoPoligono;
}

void Auxiliar::SalvarNovoPontoDoPoligono(int x, int y) {
	Ponto2d ponto(XViewportParaMundo(x), YViewportParaMundo(y));
	if(_primeiroPontoPoligono) {
		_primeiroPontoPoligono = false;
		int id = GerarNovoId();
		Poligono poligono(id, "Poligono " + IntToStr(id - 2));
		poligono.AdicionarPonto(ponto);
		_display.AdicionarPoligono(poligono);
	} else {
	   _display.AdicionarPontoAoUltimoPoligono(ponto);
	}
}

void Auxiliar::IniciarDesenhoCirculo() {
	_desenhandoCirculo = true;
	_primeiroPontoCirculo = true;
	_desenhandoPoligono = false;
	_primeiroPontoPoligono = false;
}

void Auxiliar::FinalizarDesenhoDoCirculo() {
	_desenhandoCirculo = false;
	_primeiroPontoCirculo = false;
}

bool Auxiliar::EstaDesenhandoCirculo() {
	return _desenhandoCirculo;
}

void Auxiliar::SalvarNovoPontoDoCirculo(int x, int y) {
	Ponto2d ponto(XViewportParaMundo(x), YViewportParaMundo(y));
	if(_primeiroPontoCirculo) {
		_primeiroPontoCirculo = false;
		int id = GerarNovoId();
		Poligono poligono(id, "C�rculo " + IntToStr(id - 2));
		poligono.AdicionarPonto(ponto);
		_display.AdicionarPoligono(poligono);
	} else {
	   FinalizarDesenhoDoCirculo();
	   _display.GerarPontosDoCirculo(ponto);
	}
}

void Auxiliar::AtualizarCoordenadasDeMundo(
	double xwmin, double xwmax, double ywmin, double ywmax)
{
	_mundo.EditarX(xwmin, xwmax);
	_mundo.EditarY(ywmin, ywmax);
}

void Auxiliar::AtualizarCoordenadasDosForms(
	TEdit *edXwmin, TEdit *edXwmax, TEdit *edYwmin, TEdit *edYwmax)
{
   edXwmin->Text = FloatToStr(_mundo.Xmin);
   edXwmax->Text = FloatToStr(_mundo.Xmax);
   edYwmin->Text = FloatToStr(_mundo.Ymin);
   edYwmax->Text = FloatToStr(_mundo.Ymax);
}

void Auxiliar::AtualizarEixos() {
	_display.Poligonos[0].Pontos[0].X = _mundo.Xmin;
	_display.Poligonos[0].Pontos[1].X = _mundo.Xmax;
	_display.Poligonos[1].Pontos[0].Y = _mundo.Ymin;
	_display.Poligonos[1].Pontos[1].Y = _mundo.Ymax;
}

void Auxiliar::Zoom(UnicodeString type, double incremento) {
	if (type == "in") {
		_mundo.IncrementarX(incremento, incremento * -1);
		_mundo.IncrementarY(incremento, incremento * -1);
	} else if (type == "out") {
		_mundo.IncrementarX(incremento * -1, incremento);
		_mundo.IncrementarY(incremento * -1, incremento);
    }
}

void Auxiliar::Move(UnicodeString type, double incremento) {
	if (type == "up")
		_mundo.IncrementarY(incremento, incremento);
	else if (type == "down")
		_mundo.IncrementarY(incremento * -1, incremento * -1);
	else if (type == "right")
		_mundo.IncrementarX(incremento, incremento);
	else if (type == "left")
		_mundo.IncrementarX(incremento * -1, incremento * -1);
}

void Auxiliar::Transladar(int index, double dx, double dy) {
	_display.Transladar(index, dx, dy);
}

void Auxiliar::Escalonar(int index, double fx, double fy, bool homogeneo) {
	_display.Escalonar(index, fx, fy, homogeneo);
}

void Auxiliar::Rotacionar(int index, double angulo, bool homogeneo) {
	_display.Rotacionar(index, angulo, homogeneo);
}

void Auxiliar::Refletir(int index, int eixoX, int eixoY) {
	_display.Refletir(index, eixoX, eixoY);
}

Ponto2d Auxiliar::PontoCentral(int index) {
	return _display.PontoCentral(index);
}

void Auxiliar::PintarPontoCentral(TCanvas *canvas, Ponto2d ponto) {
	int xvp = ponto.XMundoParaViewport(_mundo, _viewport);
	int yvp = ponto.YMundoParaViewport(_mundo, _viewport);
	canvas->Brush->Color = clRed;
	canvas->FillRect(Rect(xvp - 2, yvp - 2, xvp + 2, yvp + 2));
}
