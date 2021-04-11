//---------------------------------------------------------------------------

#pragma hdrstop

#include "Poliedro.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Poliedro::Poliedro(int id, UnicodeString tipo) : Poligono(id, tipo) {}

void Poliedro::MostrarPontos(TListBox *listbox) {
	listbox->Clear();
	for (int i = 0; i < Pontos.size(); i++) {
		Ponto3d *ponto3d = (Ponto3d*)Pontos[i];
		listbox->Items->Add(ponto3d->ToString());
	}
}

void Poliedro::Transladar(double dx, double dy, double dz) {
	for(int i = 0; i < Pontos.size(); i++) {
		Ponto3d *ponto3d = (Ponto3d*)Pontos[i];
		ponto3d->Transladar(dx, dy, dz);
	}
}

void Poliedro::Escalonar(double fx, double fy, double fz, bool homogenea) {
	if(homogenea) {
		EscalonamentoHomogeneo(fx, fy, fz);
    } else {
		for(int i = 0; i < Pontos.size(); i++) {
			Ponto3d *ponto3d = (Ponto3d*)Pontos[i];
			ponto3d->Escalonar(fx, fy, fz);
        }
	}
}

void Poliedro::EscalonamentoHomogeneo(double fx, double fy, double fz) {
	// o deslocamento usado será o ponto inicial * (-1)
	Ponto3d *aux3d = (Ponto3d*)Pontos[0];
	double dx = aux3d->X * (-1);
	double dy = aux3d->Y * (-1);
    double dz = aux3d->Z * (-1);
	// Transladar polígono para a origem
	vector<vector<double>> mat1 = {{1, 0, 0, 0}, {0, 1, 0, 0},
									{0, 0, 1, 0}, {dx, dy, dz, 1}};
	// Efetivamente escalonar o poligono
	vector<vector<double>> mat2 = {{fx, 0, 0, 0}, {0, fy, 0, 0},
									{0, 0, fz, 0}, {0, 0, 0, 1}};
	// Transladar a matriz de volta a posição original
	vector<vector<double>> mat3 = {{1, 0, 0, 0}, {0, 1, 0, 0},
									{0, 0, 1, 0}, {dx*-1, dy*-1, dz*-1, 1}};
	// Multiplicação das matrizes
	vector<vector<double>> aux = Matriz::Multiplicar(mat1, mat2);
	vector<vector<double>> homogenea = Matriz::Multiplicar(aux,mat3);
	// Aplicação do escalonamento em cada ponto
	for(int i = 0; i < Pontos.size(); i++) {
		Ponto3d *ponto3d = (Ponto3d*)Pontos[i];
		ponto3d->EscalonamentoHomogeneo(homogenea);
	}
}

void Poliedro::Rotacionar(double angulo, bool homogenea, int eixo) {
	if(homogenea) {
		RotacaoHomogenea(angulo, eixo);
	} else {
		for(int i = 0; i < Pontos.size(); i++) {
			Ponto3d *ponto3d = (Ponto3d*)Pontos[i];
			ponto3d->Rotacionar(angulo, eixo);
		}
	}
}

void Poliedro::RotacaoHomogenea(double angulo, int eixo) {
	 // O deslocamento usado será o ponto central * (-1)
	Ponto3d *ponto = PontoCentral();
	double dx = ponto->X * (-1);
	double dy = ponto->Y * (-1);
	double dz = ponto->Z * (-1);
	// Transladar polígono para que o ponto central seja na origem
	vector<vector<double>> mat1;
	mat1 = {{1,0,0,0}, {0,1,0,0}, {0,0,1,0}, {dx,dy,dz,1}};
	// Efetivamente rotacionar o poligono
	double radian = angulo * M_PI / 180;
	double coseno = cos(radian);
	double seno =  sin(radian);
	vector<vector<double>> mat2;
	if (eixo == 2)
		mat2 = {{coseno,seno,0,0}, {-seno,coseno,0,0}, {0,0,1,0}, {0,0,0,1}};
	else if (eixo == 1)
		mat2 = {{coseno,0,-seno,0}, {0,1,0,0}, {seno,0,coseno,0}, {0,0,0,1}};
	else
		mat2 = {{1,0,0,0}, {0,coseno,seno,0}, {0,-seno,coseno,0}, {0,0,0,1}};
	// Transladar a matriz de volta a posição original
	vector<vector<double>> mat3;
	mat3 = {{1,0,0,0}, {0,1,0,0}, {0,0,1,0}, {dx*-1,dy*-1,dz*-1,1}};

	// Multiplicação das matrizes
	vector<vector<double>> aux = Matriz::Multiplicar(mat1, mat2);
	vector<vector<double>> homogenea = Matriz::Multiplicar(aux, mat3);

	// Aplicação da rotação em cada ponto
	for(int i = 0; i < Pontos.size(); i++) {
		Ponto3d *aux3d = (Ponto3d*)Pontos[i];
		aux3d->RotacaoHomogenea(homogenea);
	}
}

Ponto3d* Poliedro::PontoCentral() {
	double somatorioX = 0;
	double somatorioY = 0;
	double somatorioZ = 0;
	for (int i = 0; i < Pontos.size(); i++) {
		Ponto3d *ponto3d = (Ponto3d*)Pontos[i];
		somatorioX += ponto3d->X;
		somatorioY += ponto3d->Y;
		somatorioZ += ponto3d->Z;
	}
	int size = Pontos.size();
	return new Ponto3d(somatorioX/size, somatorioY/size, somatorioZ/size);
}
