//---------------------------------------------------------------------------
#pragma hdrstop
#include "Bresenham.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#define SIGN(x) ((x) < 0 ? (-1): (1))

Bresenham::Bresenham(TCanvas *canvas, vector<Ponto2d*> pontos) {
	_pontos = pontos;
	_canvas = canvas;
}

void Bresenham::Desenhar(Janela mundo, Janela viewport) {
	int deltax, deltay, signalx, signaly;
	int xvp1, yvp1, xvp2, yvp2, interchange, tmp, erro;

	for(int i = 0; i < _pontos.size() - 1; i++) {
		xvp1 = _pontos[i]->XMundoParaViewport(mundo, viewport);
		yvp1 = _pontos[i]->YMundoParaViewport(mundo, viewport);
		xvp2 = _pontos[i + 1]->XMundoParaViewport(mundo, viewport);
		yvp2 = _pontos[i + 1]->YMundoParaViewport(mundo, viewport);

		deltax = abs(xvp2 - xvp1);
		deltay = abs(yvp2 - yvp1);
		signalx = SIGN(xvp2 - xvp1);
		signaly = SIGN(yvp2 - yvp1);

		if (signalx < 0)
			xvp1 -= 1;
		if (signaly < 0 )
			yvp1 -= 1;

		interchange = false;
		if (deltay > deltax) {
			tmp = deltax;
			deltax = deltay;
			deltay = tmp;
			interchange = true;
		}
		erro = 2 * deltay - deltax;
		for (int j = 0; j < deltax; j++) {
			_canvas->Pixels[xvp1][yvp1] = _canvas->Pen->Color;
			while (erro >= 0) {
				if (interchange) {
					xvp1 += signalx;
				} else {
					yvp1 += signaly;
				}
				erro -= 2 * deltax;
			}
			if (interchange) {
				yvp1 += signaly;
			} else {
				xvp1 += signalx;
			}
			erro += 2 * deltay;
		}
	}
	if(_pontos.size() == 1) {
		xvp1 = _pontos[0]->XMundoParaViewport(mundo, viewport);
		yvp1 = _pontos[0]->YMundoParaViewport(mundo, viewport);
        _canvas->Pixels[xvp1][yvp1] = clBlack;
	}
}

