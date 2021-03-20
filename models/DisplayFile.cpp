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

void DisplayFile::AdicionarPoligono(Poligono poligono) {
    Poligonos.push_back(poligono);
}

void DisplayFile::AdicionarPontoAoUltimoPoligono(Ponto2d ponto) {
	if(Poligonos.size() != 0)
		Poligonos[Poligonos.size() - 1].AdicionarPonto(ponto);
}

void DisplayFile::Desenhar(
	TCanvas *canvas, int algoritmo, Janela mundo, Janela viewport)
{
	canvas->Brush->Color = clWhite;
	canvas->FillRect(Rect(0, 0, 500, 500));
	canvas->Pen->Color = clBlack;
	canvas->Pen->Width = 1;
	for(int i = 0; i < Poligonos.size(); i++)
		Poligonos[i].Desenhar(canvas, algoritmo, mundo, viewport);
}

void DisplayFile::MostrarPoligonosDesenhados(TListBox *listbox) {
	listbox->Clear();
	for(int i = 0; i < Poligonos.size(); i++)
		listbox->Items->Add(Poligonos[i].ToString());
}

void DisplayFile::MostrarPontosDeUmPoligono(int posicao, TListBox *listbox) {
	Poligonos[posicao].MostrarPontos(listbox);
}



void DisplayFile::GerarPontosDoCirculo(Ponto2d ponto) {
	if(Poligonos.size() != 0)
		Poligonos[Poligonos.size() - 1].GerarPontosDoCirculo(ponto);
}



void DisplayFile::Transladar(int index, double dx, double dy) {
	Poligonos[index].Transladar(dx, dy);
}

void DisplayFile::Escalonar(int index, double fx, double fy, bool homogenea) {
	Poligonos[index].Escalonar(fx, fy, homogenea);
}

void DisplayFile::Rotacionar(int index, double angulo, bool homogeneo) {
	Poligonos[index].Rotacionar(angulo, homogeneo);
}

void DisplayFile::Refletir(int index, int eixoX, int eixoY) {
	Poligonos[index].Refletir(eixoX, eixoY);
}

Ponto2d DisplayFile::PontoCentral(int index) {
	return Poligonos[index].PontoCentral();
}

void DisplayFile::PintarPontoCentral(
	Ponto2d ponto, TCanvas *canvas, Janela mundo, Janela viewport)
{
	int xvp = ponto.XMundoParaViewport(mundo, viewport);
	int yvp = ponto.YMundoParaViewport(mundo, viewport);
	canvas->Brush->Color = clRed;
	canvas->FillRect(Rect(xvp - 2, yvp - 2, xvp + 2, yvp + 2));
}

void DisplayFile::AplicarClipping(Janela clipping) {
	int size = Poligonos.size();
	for(int i = 0; i < size; i++) {
		if(Poligonos[i].Tipo.SubString(0, 4) == "Eixo") continue;
		if(Poligonos[i].Tipo.SubString(0, 4) == "Clip") continue;

		vector<Ponto2d> pontos = Poligonos[i].FiltrarPontosDoClipping(clipping);
		if(pontos.size() != 0) {
             Poligono poligono(GerarNovoId(), Poligonos[i].Tipo + " - Clipped");
			poligono.AdicionarPontos(pontos);
			AdicionarPoligono(poligono);
		}
	}
}



