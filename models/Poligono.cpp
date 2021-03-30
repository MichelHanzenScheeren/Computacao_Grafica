//---------------------------------------------------------------------------
#pragma hdrstop
#include "Poligono.h"
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

void Poligono::AdicionarPontos(vector<Ponto2d> pontos) {
	for (int i = 0; i < pontos.size(); i++) {
	  AdicionarPonto(pontos[i]);  
	}
}

void Poligono::Desenhar(
	TCanvas *canvas, int algoritmo, Janela mundo, Janela viewport)
{
	if (Tipo.SubString(0, 7) == "Círculo") {
		DesenharCirculo(canvas, mundo, viewport);
	} else if (algoritmo == 0) {
		LineTo(canvas, mundo, viewport);
	} else if (algoritmo == 1) {
		Dda *dda = new Dda(canvas, Pontos);
		dda->Desenhar(mundo, viewport);
	} else if (algoritmo == 2) {
		Bresenham *bresenham = new Bresenham(canvas, Pontos);
		bresenham->Desenhar(mundo, viewport);
	}
}

void Poligono::DesenharCirculo(TCanvas *canvas, Janela mundo, Janela viewport) {
	int xvp, yvp;
	for(int i = 0; i < Pontos.size(); i++) {
		xvp = Pontos[i].XMundoParaViewport(mundo, viewport);
		yvp = Pontos[i].YMundoParaViewport(mundo, viewport);
		canvas->Pixels[xvp][yvp] = clBlack;
	}
}

void Poligono::LineTo(TCanvas *canvas, Janela mundo, Janela viewport) {
	int xvp, yvp;
	for(int i = 0; i < Pontos.size(); i++) {
		xvp = Pontos[i].XMundoParaViewport(mundo, viewport);
		yvp = Pontos[i].YMundoParaViewport(mundo, viewport);
		if(i == 0) {
            canvas->Pixels[xvp][yvp] = clBlack;
			canvas->MoveTo(xvp, yvp);
		} else {
			canvas->LineTo(xvp, yvp);
		}
	}
}

UnicodeString Poligono::ToString() {
	return "(" + IntToStr(Id) + ") " + Tipo;
}

void Poligono::MostrarPontos(TListBox *listbox) {
	listbox->Clear();
	for (int i = 0; i < Pontos.size(); i++)
	   listbox->Items->Add(Pontos[i].ToString());
}

void Poligono::AtualizarEixoX(double min, double max) {
	Pontos[0].X = min;
	Pontos[1].X = max;
}

void Poligono::AtualizarEixoY(double min, double max) {
	Pontos[0].Y = min;
	Pontos[1].Y = max;
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
	vector<vector<double>> mat1 = {{1, 0, 0}, {0, 1, 0}, {dx, dy, 1}};
	// Efetivamente escalonar o poligono
	vector<vector<double>> mat2 = {{fx, 0, 0}, {0, fy, 0}, {0, 0, 1}};
	// Transladar a matriz de volta a posição original
	vector<vector<double>> mat3 = {{1, 0, 0}, {0, 1, 0},{dx*-1, dy*-1, 1}};

	// Multiplicação das matrizes
	vector<vector<double>> aux = Matriz::Multiplicar(mat1, mat2);
	vector<vector<double>> homogenea = Matriz::Multiplicar(aux,mat3);

	// Aplicação do escalonamento em cada ponto
	for(int i = 0; i < Pontos.size(); i++)
		Pontos[i].EscalonamentoHomogeneo(homogenea);
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
	vector<vector<double>> mat1 = {{1, 0, 0}, {0, 1, 0}, {dx, dy, 1}};
	// Efetivamente rotacionar o poligono
	double radian = angulo * M_PI / 180;
	double coseno = cos(radian);
	double seno =  sin(radian);
	vector<vector<double>> mat2 = {{coseno,seno,0}, {-seno,coseno,0}, {0,0,1}};
	// Transladar a matriz de volta a posição original
	vector<vector<double>> mat3 = {{1, 0, 0}, {0, 1, 0}, {dx*-1, dy*-1, 1}};

    // Multiplicação das matrizes
	vector<vector<double>> aux = Matriz::Multiplicar(mat1, mat2);
	vector<vector<double>> homogenea = Matriz::Multiplicar(aux, mat3);

	// Aplicação da rotação em cada ponto
	for(int i = 0; i < Pontos.size(); i++)
		Pontos[i].RotacaoHomogenea(homogenea);
}

void Poligono::Refletir(int eixoX, int eixoY) {
	for(int i = 0; i < Pontos.size(); i++)
		Pontos[i].Refletir(eixoX, eixoY);
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

void Poligono::GerarPontosDoCirculo(Ponto2d c) {
	if(Pontos.size() == 0) return;
	double raio = sqrt(pow(c.X - Pontos[0].X, 2) + pow(c.Y - Pontos[0].Y, 2));
	double x = 0;
	double y = raio;
	double p = 1 - raio;
	AdicionarPontosAoCirculo(Pontos[0].X, Pontos[0].Y, x, y);
	while(y > x) {
		x += 1;
		if(p < 0) {
			p += 2.0 * x + 1.0;
		} else {
            y -= 1;
			p += 2.0 * (x - y) + 1.0;
		}
		AdicionarPontosAoCirculo(Pontos[0].X, Pontos[0].Y, x, y);
	}
}

vector<Ponto2d> Poligono::FiltrarPontosDoClipping(Janela clipping) {
	Clipping *clip = new Clipping(clipping);
	if (Pontos.size() == 1) {
		 clip->PontoUnico(Pontos[0]);
	}
	if (Tipo.SubString(0,3) == "Pol") {
		for (int i = 0; i < Pontos.size() - 1; i++)
			clip->SegmentoReta(Pontos[i], Pontos[i + 1]);
	} else {
		for (int i = 0; i < Pontos.size(); i++)
			clip->PontoUnico(Pontos[i]);
	}
	return clip->ObterResultados();
}

// CURVAS
vector<Ponto2d> Poligono::AplicarCasteljau(double precisao) {
	Casteljau casteljau(Pontos);
	return casteljau.CriarCurva(precisao);
}

vector<Ponto2d> Poligono::AplicarHermite(double intervalo) {
	Hermite hermite(Pontos);
	return hermite.CriarCurva(intervalo);
}

vector<Ponto2d> Poligono::AplicarBSpline(double intervalo) {
	BSpline bSpline(Pontos);
	return bSpline.CriarCurva(intervalo);
}

vector<Ponto2d> Poligono::AplicarBSplineFwDif(double intervalo) {
	BSpline bSpline(Pontos);
	return bSpline.CriarCurvaForwardDifference(intervalo);
}
