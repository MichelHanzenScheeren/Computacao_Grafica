//---------------------------------------------------------------------------
#pragma hdrstop
#include "DisplayFile.h"
#include <cmath>
//---------------------------------------------------------------------------
#pragma package(smart_init)

int DisplayFile::GerarNovoId() {
	_id++;
    return _id;
}

void DisplayFile::AdicionarPoligono(Poligono *poligono) {
    Poligonos.push_back(poligono);
}

void DisplayFile::AdicionarPontoAoUltimoPoligono(Ponto2d *ponto) {
	if(Poligonos.size() != 0)
		Poligonos[Poligonos.size() - 1]->AdicionarPonto(ponto);
}

void DisplayFile::Desenhar(
	TCanvas *canvas, int algoritmo, Janela mundo, Janela viewport)
{
	canvas->Brush->Color = clWhite;
	canvas->FillRect(Rect(0, 0, 500, 500));
	canvas->Pen->Color = clBlack;
	canvas->Pen->Width = 1;
	for(int i = 0; i < Poligonos.size(); i++)
		Poligonos[i]->Desenhar(canvas, algoritmo, mundo, viewport);
}

void DisplayFile::MostrarPoligonosDesenhados(TListBox *listbox) {
	listbox->Clear();
	for(int i = 0; i < Poligonos.size(); i++) {
		listbox->Items->Add(Poligonos[i]->ToString());
	}

}

void DisplayFile::MostrarPontosDeUmPoligono(int posicao, TListBox *listbox) {
	if(Poligonos[posicao]->IsTypeOf<Poliedro>()){
		Poliedro *poliedro = (Poliedro*)Poligonos[posicao];
		poliedro->MostrarPontos(listbox);
	} else {
		Poligonos[posicao]->MostrarPontos(listbox);
    }

}

void DisplayFile::GerarPontosDoCirculo(Ponto2d *ponto) {
	if(Poligonos.size() != 0)
		Poligonos[Poligonos.size() - 1]->GerarPontosDoCirculo(ponto);
}

void DisplayFile::AtualizarEixos(Janela mundo) {
	Poligonos[0]->AtualizarEixoX(mundo.Xmin, mundo.Xmax);
	Poligonos[1]->AtualizarEixoY(mundo.Ymin, mundo.Ymax);
}

void DisplayFile::Transladar(int index, double dx, double dy, double dz) {
	if(Poligonos[index]->IsTypeOf<Poliedro>()){
		Poliedro *poliedro = (Poliedro*)Poligonos[index];
		poliedro->Transladar(dx, dy, dz);
	} else {
		Poligonos[index]->Transladar(dx, dy);
	}
}

void DisplayFile::Escalonar
	(int index, double fx, double fy, double fz, bool homogenea)
{
    if(Poligonos[index]->IsTypeOf<Poliedro>()){
		Poliedro *poliedro = (Poliedro*)Poligonos[index];
		poliedro->Escalonar(fx, fy, fz, homogenea);
	} else {
		Poligonos[index]->Escalonar(fx, fy, homogenea);
	}
}

bool DisplayFile::ApenasPoligono(int index) {
	if(Poligonos[index]->IsTypeOf<Poliedro>())
		return false;
    return true;
}

void DisplayFile::Rotacionar(int index, double angulo, bool homogenea, int eixo) {
	if(Poligonos[index]->IsTypeOf<Poliedro>()){
		Poliedro *poliedro = (Poliedro*)Poligonos[index];
		poliedro->Rotacionar(angulo, homogenea, eixo);
	} else {
		Poligonos[index]->Rotacionar(angulo, homogenea);
	}
}

void DisplayFile::Refletir(int index, int eixoX, int eixoY) {
	Poligonos[index]->Refletir(eixoX, eixoY);
}

Ponto2d* DisplayFile::PontoCentral(int index) {
	return Poligonos[index]->PontoCentral();
}

void DisplayFile::PintarPontoCentral(
	Ponto2d *ponto, TCanvas *canvas, Janela mundo, Janela viewport)
{
	int xvp = ponto->XMundoParaViewport(mundo, viewport);
	int yvp = ponto->YMundoParaViewport(mundo, viewport);
	canvas->Brush->Color = clRed;
	canvas->FillRect(Rect(xvp - 2, yvp - 2, xvp + 2, yvp + 2));
}

void DisplayFile::AplicarClipping(Janela clipping) {
	int size = Poligonos.size();
	for(int i = 0; i < size; i++) {
		if(Poligonos[i]->Tipo.SubString(0, 4) == "Eixo") continue;
		if(Poligonos[i]->Tipo.SubString(0, 4) == "Clip") continue;

		vector<Ponto2d*> pontos = Poligonos[i]->FiltrarPontosDoClipping(clipping);
		if(pontos.size() != 0) {
			Poligono *poligono = new Poligono(
				GerarNovoId(), "Clip " + Poligonos[i]->Tipo.SubString(0,5)
				 + ". (" + IntToStr(Poligonos[i]->Id) + ")"
			);
			poligono->AdicionarPontos(pontos);
			AdicionarPoligono(poligono);
		}
	}
}

void DisplayFile::ApagarPoligono(int index) {
	if (index >= 0 && index < Poligonos.size()) {
		vector<Poligono*>::iterator myIterator;
		myIterator = Poligonos.begin();
		for (int i = 1; i <= index; i++)
			myIterator++;
		Poligonos.erase(myIterator);
	}
}

// CURVAS
void DisplayFile::_registrarCurva(
	vector<Ponto2d*> *pontos, UnicodeString nome, int index)
{
	if(pontos->size() != 0) {
		int id = GerarNovoId();
		Poligono *poligono = new Poligono(
			id,
			nome + " (" + IntToStr(Poligonos[index]->Id) + ")"
		);
		poligono->AdicionarPontos(*pontos);
		AdicionarPoligono(poligono);
	}
}
void DisplayFile::AplicarCasteljau(int index, double precisao) {
	vector<Ponto2d*> pontos = Poligonos[index]->AplicarCasteljau(precisao);
	_registrarCurva(&pontos, "Casteljau ", index);
}

void DisplayFile::AplicarHermite(int index, double intervalo) {
	vector<Ponto2d*> pontos = Poligonos[index]->AplicarHermite(intervalo);
	_registrarCurva(&pontos, "Hermite ", index);
}

void DisplayFile::AplicarBezier(int index, double intervalo) {
	vector<Ponto2d*> pontos = Poligonos[index]->AplicarBezier(intervalo);
	_registrarCurva(&pontos, "Bezier ", index);
}

void DisplayFile::AplicarBSpline(int index, double intervalo) {
	vector<Ponto2d*> pontos = Poligonos[index]->AplicarBSpline(intervalo);
	_registrarCurva(&pontos, "BSpline ", index);
}

void DisplayFile::AplicarBSplineFwDif(int index, double intervalo) {
	vector<Ponto2d*> pontos = Poligonos[index]->AplicarBSplineFwDif(intervalo);
	_registrarCurva(&pontos, "BSplineFwDif ", index);
}

// 3D
void DisplayFile::CriarPoliedro(vector<vector<double>> linhas) {
	int id = GerarNovoId();
	Poligono *poligono = (Poligono*)new Poliedro(id, "Poliedro");
	for (int i = 0; i < linhas.size(); i++) {
		Ponto2d *ponto = new Ponto3d(linhas[i][0], linhas[i][1], linhas[i][2]);
		poligono->Pontos.push_back(ponto);
	}
	AdicionarPoligono(poligono);
}


