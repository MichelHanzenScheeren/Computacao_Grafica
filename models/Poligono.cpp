//---------------------------------------------------------------------------
#pragma hdrstop
#include "Poligono.h"
#include <cmath>
//---------------------------------------------------------------------------
#pragma package(smart_init)

#define SIGN(x) ((x) < 0 ? (-1): (1))

Poligono::Poligono(int id, UnicodeString tipo) {
	Id = id;
	Tipo = tipo;
}

void Poligono::AdicionarPonto(Ponto2d ponto) {
	Pontos.push_back(ponto);
}

void Poligono::Desenhar(
	TCanvas *canvas, int algoritmo, Janela mundo, Janela viewport)
{
	canvas->Brush->Color = clBlack;
	if (Tipo.SubString(0, 7) == "Círculo") {
		DesenharCirculo(canvas, mundo, viewport);
	} else if (algoritmo == 0) {
		LineTo(canvas, mundo, viewport);
	} else if (algoritmo == 1) {
		DDA(canvas, mundo, viewport);
	} else if (algoritmo == 2) {
		Bresenham(canvas, mundo, viewport);
	}

}

void Poligono::DesenharCirculo(TCanvas *canvas, Janela mundo, Janela viewport) {
	int xvp, yvp;
	for(int i = 0; i < Pontos.size(); i++) {
		xvp = Pontos[i].XMundoParaViewport(mundo, viewport);
		yvp = Pontos[i].YMundoParaViewport(mundo, viewport);
		canvas->FrameRect(Rect(xvp, yvp, xvp, yvp));

	}
}


void Poligono::LineTo(TCanvas *canvas, Janela mundo, Janela viewport) {
	int xvp, yvp;
	for(int i = 0; i < Pontos.size(); i++) {
		xvp = Pontos[i].XMundoParaViewport(mundo, viewport);
		yvp = Pontos[i].YMundoParaViewport(mundo, viewport);
		if(i == 0) {
			canvas->FrameRect(Rect(xvp, yvp, xvp, yvp));
			canvas->MoveTo(xvp, yvp);
		} else {
			canvas->LineTo(xvp, yvp);
		}
	}
}



void Poligono::DDA(TCanvas *canvas, Janela mundo, Janela viewport) {
	int xvp1, yvp1, xvp2, yvp2, length;
	double deltax, deltay, x, y;

	for(int i = 0; i < Pontos.size() - 1; i++) {
		xvp1 = Pontos[i].XMundoParaViewport(mundo, viewport);
		yvp1 = Pontos[i].YMundoParaViewport(mundo, viewport);
		xvp2 = Pontos[i + 1].XMundoParaViewport(mundo, viewport);
		yvp2 = Pontos[i + 1].YMundoParaViewport(mundo, viewport);

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
			canvas->FrameRect(Rect(floor(x), floor(y), floor(x), floor(y)));
			x += deltax;
			y += deltay;
		}
	}
	if(Pontos.size() == 1) {
		xvp1 = Pontos[0].XMundoParaViewport(mundo, viewport);
		yvp1 = Pontos[0].YMundoParaViewport(mundo, viewport);
		canvas->FrameRect(Rect(xvp1, yvp1, xvp1, yvp1));
	}

}

void Poligono::Bresenham(TCanvas *canvas, Janela mundo, Janela viewport) {
	
	int deltax, deltay, signalx, signaly;
	int xvp1, yvp1, xvp2, yvp2, interchange, tmp, erro;

	for(int i = 0; i < Pontos.size() - 1; i++) {
		xvp1 = Pontos[i].XMundoParaViewport(mundo, viewport);
		yvp1 = Pontos[i].YMundoParaViewport(mundo, viewport);
		xvp2 = Pontos[i + 1].XMundoParaViewport(mundo, viewport);
		yvp2 = Pontos[i + 1].YMundoParaViewport(mundo, viewport);

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
			canvas->FrameRect(Rect(xvp1, yvp1, xvp1, yvp1));
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
	if(Pontos.size() == 1) {
		xvp1 = Pontos[0].XMundoParaViewport(mundo, viewport);
		yvp1 = Pontos[0].YMundoParaViewport(mundo, viewport);
		canvas->FrameRect(Rect(xvp1, yvp1, xvp1, yvp1));
	}
}

UnicodeString Poligono::ToString() {
	return IntToStr(Id) + " - " + Tipo;
}

void Poligono::MostrarPontos(TListBox *listbox) {
	listbox->Clear();
	for(int i = 0; i < Pontos.size(); i++)
	   listbox->Items->Add(Pontos[i].ToString());
}

void Poligono::Transladar(double dx, double dy) {
	for(int i = 0; i < Pontos.size(); i++)
        Pontos[i].Transladar(dx, dy);
}

void Poligono::Escalonar(double fx, double fy, bool homogenea) {
	if(homogenea) {
		EscalonamentoHomogeneo(fx, fy);
    } else {
		for(int i = 0; i < Pontos.size(); i++)
			Pontos[i].Escalonar(fx, fy);
	}
}

void Poligono::EscalonamentoHomogeneo(double fx, double fy) {
	// o deslocamento usado será o ponto inicial * (-1)
	double dx = Pontos[0].X * (-1);
	double dy = Pontos[0].Y * (-1);
	// Transladar polígono para a origem
	vector<vector<double>> mat1 = {
		{1, 0, 0},
		{0, 1, 0},
		{dx, dy, 1}
	};
	// Efetivamente escalonar o poligono
	vector<vector<double>> mat2 = {
		{fx, 0, 0},
		{0, fy, 0},
		{0, 0, 1}
	};
	// Transladar a matriz de volta a posição original
	vector<vector<double>> mat3 = {
		{1, 0, 0},
		{0, 1, 0},
		{dx*-1, dy*-1, 1}
	};

	// Multiplicação das matrizes
	vector<vector<double>> aux = MultiplicarMatrizes(mat1, mat2);
	vector<vector<double>> homogenea = MultiplicarMatrizes(aux,mat3);
    // Multiplicação de cada ponto pela matriz de transformação
	for(int i = 0; i < Pontos.size(); i++) {
		vector<vector<double>> point = {{Pontos[i].X, Pontos[i].Y, 1}};
		vector<vector<double>> result = MultiplicarMatrizes(point, homogenea);
		Pontos[i].Editar(result[0][0], result[0][1]);
	}
			
}   

vector<vector<double>> Poligono::MultiplicarMatrizes(
	vector<vector<double>> mat1, vector<vector<double>> mat2) 
{
	int m = mat1.size();
	int n = mat1[0].size();
	int j = mat2.size();
	int k = mat2[0].size();
	vector<vector<double>> result;
	for (int i = 0; i < m; i++) {
        result.push_back(vector<double>());
		for (int j = 0; j < k; j++) {
			result[i].push_back(0);
		}
	}
	for (int l = 0; l < m; l++) {
		for (int c = 0; c < k; c++) {
			for (int x = 0; x < k; x++) {
				result[l][c] = result[l][c] + mat1[l][x] * mat2[x][c];
			}
		}
	}
	return result;
}


void Poligono::Rotacionar(double angulo, bool homogeneo) {
	if(homogeneo) {
		RotacaoHomogenea(angulo);
	} else {
		for(int i = 0; i < Pontos.size(); i++) {
			Pontos[i].Rotacionar(angulo);
		}
    }

}

void Poligono::RotacaoHomogenea(double angulo) {
	 // O deslocamento usado será o ponto central * (-1)
	Ponto2d ponto = PontoCentral();
	double dx = ponto.X * (-1);
	double dy = ponto.Y * (-1);
	// Transladar polígono para que o ponto central seja na origem
	vector<vector<double>> mat1 = {
		{1, 0, 0},
		{0, 1, 0},
		{dx, dy, 1}
	};
	// Efetivamente rotacionar o poligono
	double radian = angulo * M_PI / 180;
	vector<vector<double>> mat2 = {
		{cos(radian), sin(radian), 0},
		{-sin(radian), cos(radian), 0},
		{0, 0, 1}
	};
	// Transladar a matriz de volta a posição original
	vector<vector<double>> mat3 = {
		{1, 0, 0},
		{0, 1, 0},
		{dx*-1, dy*-1, 1}
	};

    // Multiplicação das matrizes
	vector<vector<double>> aux = MultiplicarMatrizes(mat1, mat2);
	vector<vector<double>> homogenea = MultiplicarMatrizes(aux, mat3);
	// Multiplicação de cada ponto pela matriz de transformação
	for(int i = 0; i < Pontos.size(); i++) {
		vector<vector<double>> point = {{Pontos[i].X, Pontos[i].Y, 1}};
		vector<vector<double>> result = MultiplicarMatrizes(point, homogenea);
		Pontos[i].Editar(result[0][0], result[0][1]);
	}
}

void Poligono::Refletir(int eixoX, int eixoY) {
	for(int i = 0; i < Pontos.size(); i++)
		Pontos[i].Refletir(eixoX, eixoY);
}

void Poligono::AdicionarPontosAoCirculo(int xc, int yc, int x, int y) {
	AdicionarPonto(Ponto2d(xc + x, yc + y)); // x, y
	AdicionarPonto(Ponto2d(xc - x, yc + y)); // -x, y
	AdicionarPonto(Ponto2d(xc + x, yc - y)); // x, -y
	AdicionarPonto(Ponto2d(xc - x, yc - y)); // -x, -y
	AdicionarPonto(Ponto2d(xc + y, yc + x)); // y, x
	AdicionarPonto(Ponto2d(xc - y, yc + x)); // -y, x
	AdicionarPonto(Ponto2d(xc + y, yc - x)); // y, -x
	AdicionarPonto(Ponto2d(xc - y, yc - x)); // -y, -x
}

void Poligono::GerarPontosDoCirculo(Ponto2d p) {
	if(Pontos.size() == 0) return;
	double raio = sqrt(pow(p.X - Pontos[0].X, 2) + pow(p.Y - Pontos[0].Y, 2));
	double x = 0;
	double y = raio;
	double ponto = 1 - raio;
	AdicionarPontosAoCirculo(Pontos[0].X, Pontos[0].Y, x, y);

	while(x < y) {
		x += 1;
		if (ponto >= 0)
			y -= 1;
		if(ponto < 0)
			ponto += 2 * x + 1;
		else
			ponto += 2 * (x - y) + 1;
		AdicionarPontosAoCirculo(Pontos[0].X, Pontos[0].Y, x, y);
	}

}

Ponto2d Poligono::PontoCentral() {
	double somatorioX = 0;
	double somatorioY = 0;
	for (int i = 0; i < Pontos.size(); i++) {
		somatorioX += Pontos[i].X;
		somatorioY += Pontos[i].Y;
	}
	return Ponto2d(somatorioX / Pontos.size(), somatorioY / Pontos.size());
}


