//---------------------------------------------------------------------------

#pragma hdrstop

#include "Dda.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
Dda::Dda(TCanvas *canvas, vector<Ponto2d> pontos) {
	_pontos = pontos;
	_canvas = canvas;
}

#define SIGN(x) ((x) < 0 ? (-1): (1))

void Dda::Desenhar(Janela mundo, Janela viewport) {
	int xvp1, yvp1, xvp2, yvp2, length;
	double deltax, deltay, x, y;

	for(int i = 0; i < _pontos.size() - 1; i++) {
		xvp1 = _pontos[i].XMundoParaViewport(mundo, viewport);
		yvp1 = _pontos[i].YMundoParaViewport(mundo, viewport);
		xvp2 = _pontos[i + 1].XMundoParaViewport(mundo, viewport);
		yvp2 = _pontos[i + 1].YMundoParaViewport(mundo, viewport);

		if(abs(xvp2 - xvp1) >= abs(yvp2 - yvp1)) {
			length = abs(xvp2 - xvp1);
		} else {
			length = abs(yvp2 - yvp1);
		}

		deltax = ((double)(xvp2 - xvp1)) / ((double)length);
		deltay = ((double)(yvp2 - yvp1)) / ((double)length);
		x = xvp1 + 0.5 * SIGN(deltax);
		y = yvp1 + 0.5 * SIGN(deltay);

		for (int j = 0; j < length; j++) {
			_canvas->FrameRect(Rect(floor(x), floor(y), floor(x), floor(y)));
			x += deltax;
			y += deltay;
		}
	}
	if(_pontos.size() == 1) {
		xvp1 = _pontos[0].XMundoParaViewport(mundo, viewport);
		yvp1 = _pontos[0].YMundoParaViewport(mundo, viewport);
		_canvas->FrameRect(Rect(xvp1, yvp1, xvp1, yvp1));
	}
}
