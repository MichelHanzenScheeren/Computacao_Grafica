//---------------------------------------------------------------------------
#ifndef PoliedroH
#define PoliedroH
#include "Poligono.h"
#include "Matriz.h"
#include<Vcl.StdCtrls.hpp>
//---------------------------------------------------------------------------
class Poliedro : public Poligono {
	public:
		Poliedro(int, UnicodeString);
		void MostrarPontos(TListBox *);
		// TRABSFORMAÇÕES
		void Transladar(double, double, double);
		void Escalonar(double, double, double, bool);
		void EscalonamentoHomogeneo(double, double, double);
		void Rotacionar(double, bool, int);
		void RotacaoHomogenea(double, int);
		Ponto3d* PontoCentral();
};

#endif
