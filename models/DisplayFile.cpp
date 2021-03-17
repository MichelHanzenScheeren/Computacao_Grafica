//---------------------------------------------------------------------------
#pragma hdrstop
#include "DisplayFile.h"
#include <cmath>
//---------------------------------------------------------------------------
#pragma package(smart_init)
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
	canvas->Pen->Width = 2;
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



