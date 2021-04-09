//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "HomePage.h"
#include "../models/Auxiliar.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMyForm *MyForm;
Auxiliar auxiliar;

String doubleToStr(double valor) {
	return FloatToStrF(valor, ffFixed, 12, 1);
}

void TMyForm::_limparEditsPontoCentral() {
	edXc->Text = "";
    edYc->Text = "";
}

void TMyForm::_atualizarWindow() {
	auxiliar.AtualizarEixos();
	auxiliar.DesenharPoligonos(img->Canvas, rgTipoReta->ItemIndex);
	auxiliar.AtualizarCoordenadasDosForms(edXwmin, edXwmax, edYwmin, edYwmax);
	_limparEditsPontoCentral();
}

void TMyForm::_redesenharEAtualizarPontosDoPoligono(int index) {
	auxiliar.DesenharPoligonos(img->Canvas, rgTipoReta->ItemIndex);
	auxiliar.MostrarPontosDeUmPoligono(index, lbPontos);
    _limparEditsPontoCentral();
}

bool _poligonoValidoSelecionado(int index, UnicodeString tipo) {
	if(index == -1) {
		ShowMessage("Selecione um polígono para " + tipo + ".");
		return false;
	} else if(index == 0 || index == 1) {
		ShowMessage("Não é possível " + tipo + " os eixos.");
		return false;
	} else if (index == 2) {
		ShowMessage("Não é possível " + tipo + " a área de clipping.");
		return false;
	}
    return true;
}

//---------------------------------------------------------------------------

__fastcall TMyForm::TMyForm(TComponent* Owner)
	: TForm(Owner)
{
	auxiliar.SalvarEixos();
	auxiliar.MostrarPoligonosDesenhados(lbPoligonos);
	_atualizarWindow();
}
//---------------------------------------------------------------------------

void __fastcall TMyForm::imgMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	lbViewport->Caption = "vp: (" + IntToStr(X) + ", " + IntToStr(Y) + ")";

	double xw = auxiliar.XViewportParaMundo(X);
	double yw = auxiliar.YViewportParaMundo(Y);
	lbMundo->Caption = "wd: (" + doubleToStr(xw) + ", " + doubleToStr(yw) + ")";
}
//---------------------------------------------------------------------------

void __fastcall TMyForm::lbPoligonosClick(TObject *Sender) {
	if(lbPoligonos->ItemIndex != -1)
		auxiliar.MostrarPontosDeUmPoligono(lbPoligonos->ItemIndex, lbPontos);
    _limparEditsPontoCentral();
}
//---------------------------------------------------------------------------

void __fastcall TMyForm::btDesenharPoligonoClick(TObject *Sender) {
	auxiliar.IniciarDesenhoPoligono();
}
//---------------------------------------------------------------------------

void __fastcall TMyForm::btDesenharCirculoClick(TObject *Sender) {
	auxiliar.IniciarDesenhoCirculo();
	_limparEditsPontoCentral();
}
//---------------------------------------------------------------------------

void __fastcall TMyForm::imgMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	if(Button == mbLeft && auxiliar.EstaDesenhandoPoligono()) {
		auxiliar.SalvarNovoPontoDoPoligono(X, Y);
		auxiliar.DesenharPoligonos(img->Canvas, rgTipoReta->ItemIndex);
		auxiliar.MostrarPoligonosDesenhados(lbPoligonos);
	} else if(Button == mbLeft && auxiliar.EstaDesenhandoCirculo()) {
		auxiliar.SalvarNovoPontoDoCirculo(X, Y);
		auxiliar.DesenharPoligonos(img->Canvas, rgTipoReta->ItemIndex);
		auxiliar.MostrarPoligonosDesenhados(lbPoligonos);
	} else if(Button == mbRight) {
		auxiliar.FinalizarDesenhoPoligono();
        auxiliar.FinalizarDesenhoDoCirculo();
	}
	_limparEditsPontoCentral();
}
//---------------------------------------------------------------------------

void __fastcall TMyForm::btAtualizarMundoClick(TObject *Sender) {
	auxiliar.AtualizarCoordenadasDeMundo(
		StrToFloat(edXwmin->Text), StrToFloat(edXwmax->Text),
		StrToFloat(edYwmin->Text), StrToFloat(edYwmax->Text)
	);
	_atualizarWindow();
	_limparEditsPontoCentral();
}
//---------------------------------------------------------------------------

void __fastcall TMyForm::btnZerarCoordenadasClick(TObject *Sender) {
	auxiliar.AtualizarCoordenadasDeMundo(-250, 250, -250, 250);
	_atualizarWindow();
}
//---------------------------------------------------------------------------

void __fastcall TMyForm::btInClick(TObject *Sender) {
	auxiliar.Zoom("in", StrToFloat(edIncremento->Text));
    _atualizarWindow();

}
//---------------------------------------------------------------------------

void __fastcall TMyForm::btOutClick(TObject *Sender) {
	auxiliar.Zoom("out", StrToFloat(edIncremento->Text));
	_atualizarWindow();
}
//---------------------------------------------------------------------------

void __fastcall TMyForm::btUpClick(TObject *Sender) {
	auxiliar.Move("up", StrToFloat(edIncremento->Text));
	_atualizarWindow();
}
//---------------------------------------------------------------------------

void __fastcall TMyForm::btDownClick(TObject *Sender) {
	auxiliar.Move("down", StrToFloat(edIncremento->Text));
	_atualizarWindow();
}
//---------------------------------------------------------------------------

void __fastcall TMyForm::btRightClick(TObject *Sender) {
	auxiliar.Move("right", StrToFloat(edIncremento->Text));
	_atualizarWindow();
}
//---------------------------------------------------------------------------

void __fastcall TMyForm::btLeftClick(TObject *Sender) {
	auxiliar.Move("left", StrToFloat(edIncremento->Text));
	_atualizarWindow();
}
//---------------------------------------------------------------------------

void __fastcall TMyForm::btnRedesenharClick(TObject *Sender) {
	auxiliar.DesenharPoligonos(img->Canvas, rgTipoReta->ItemIndex);
    _limparEditsPontoCentral();
}
//---------------------------------------------------------------------------

void __fastcall TMyForm::btTransladarClick(TObject *Sender) {
	int index = lbPoligonos->ItemIndex;
	if (_poligonoValidoSelecionado(index, "transladar")) {
		double dx = StrToFloat(edDeslocamentoX->Text);
		double dy = StrToFloat(edDeslocamentoY->Text);
		auxiliar.Transladar(index, dx, dy);
		_redesenharEAtualizarPontosDoPoligono(index);
	}
}
//---------------------------------------------------------------------------


void __fastcall TMyForm::btEscalonarClick(TObject *Sender) {
	int index = lbPoligonos->ItemIndex;
	if (_poligonoValidoSelecionado(index, "escalonar")) {
		double fx = StrToFloat(edFatorX->Text);
		double fy = StrToFloat(edFatorY->Text);
		auxiliar.Escalonar(index, fx, fy, cbEscalonamento->Checked);
		_redesenharEAtualizarPontosDoPoligono(index);
	}
}
//---------------------------------------------------------------------------

void __fastcall TMyForm::btRotacionarClick(TObject *Sender) {
	int index = lbPoligonos->ItemIndex;
	if(_poligonoValidoSelecionado(index, "rotacionar")) {
		double angulo = StrToFloat(edAngulo->Text);
		auxiliar.Rotacionar(index, angulo, cbRotacao->Checked);
		_redesenharEAtualizarPontosDoPoligono(index);
	}
}
//---------------------------------------------------------------------------

void __fastcall TMyForm::btRefletirClick(TObject *Sender) {
	if(!cbEixoX->Checked && !cbEixoY->Checked) {
		ShowMessage("Selecione pelo menos um eixo para refletir.");
	} else {
		int index = lbPoligonos->ItemIndex;
		if(_poligonoValidoSelecionado(index, "refletir")) {
			int eixoX = cbEixoX->Checked ? -1 : 1;
			int eixoY = cbEixoY->Checked ? -1 : 1;
			auxiliar.Refletir(index, eixoY, eixoX);
			_redesenharEAtualizarPontosDoPoligono(index);
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TMyForm::btPontoCentralClick(TObject *Sender) {
	int index = lbPoligonos->ItemIndex;
	if(_poligonoValidoSelecionado(index, "exibir ponto central")) {
		Ponto2d ponto = auxiliar.PontoCentral(index);
		edXc->Text = FloatToStr(ponto.X);
		edYc->Text = FloatToStr(ponto.Y);
		auxiliar.PintarPontoCentral(img->Canvas, ponto);
	}
}
//---------------------------------------------------------------------------

void __fastcall TMyForm::btnClippingClick(TObject *Sender) {
	auxiliar.AplicarClipping();
	auxiliar.DesenharPoligonos(img->Canvas, rgTipoReta->ItemIndex);
    auxiliar.MostrarPoligonosDesenhados(lbPoligonos);
}
//---------------------------------------------------------------------------

void __fastcall TMyForm::btApagarClick(TObject *Sender) {
	int index = lbPoligonos->ItemIndex;
	if(_poligonoValidoSelecionado(index, "apagar")) {
		auxiliar.ApagarPoligono(index);
		auxiliar.DesenharPoligonos(img->Canvas, rgTipoReta->ItemIndex);
		auxiliar.MostrarPoligonosDesenhados(lbPoligonos);
		lbPontos->Clear();
	}
}
//---------------------------------------------------------------------------

bool _poligonoValidoParaCurva(int index) {
	if(index == -1) {
		ShowMessage("Selecione um polígono para criação da curva.");
		return false;
	} else if(index == 0 || index == 1) {
		ShowMessage("Não é possível criar uma curva dos eixos.");
		return false;
	} else if (index == 2) {
		ShowMessage("Não é possível criar uma curva da área de clipping.");
		return false;
	}
	return true;
}
//---------------------------------------------------------------------------

void __fastcall TMyForm::btCasteljauClick(TObject *Sender)
{
	int index = lbPoligonos->ItemIndex;
	if(_poligonoValidoParaCurva(index)) {
		auxiliar.AplicarCasteljau(index, StrToFloat(edCasteljau->Text));
		auxiliar.DesenharPoligonos(img->Canvas, rgTipoReta->ItemIndex);
		auxiliar.MostrarPoligonosDesenhados(lbPoligonos);
	}
}
//---------------------------------------------------------------------------


void __fastcall TMyForm::btHermiteClick(TObject *Sender)
{
	int index = lbPoligonos->ItemIndex;
	if(_poligonoValidoParaCurva(index)) {
		auxiliar.AplicarHermite(index, StrToFloat(edHermite->Text));
		auxiliar.DesenharPoligonos(img->Canvas, rgTipoReta->ItemIndex);
		auxiliar.MostrarPoligonosDesenhados(lbPoligonos);
	}
}
//---------------------------------------------------------------------------
void __fastcall TMyForm::btBezierClick(TObject *Sender)
{
	int index = lbPoligonos->ItemIndex;
	if(_poligonoValidoParaCurva(index)) {
		auxiliar.AplicarBezier(index, StrToFloat(edBezier->Text));
		auxiliar.DesenharPoligonos(img->Canvas, rgTipoReta->ItemIndex);
		auxiliar.MostrarPoligonosDesenhados(lbPoligonos);
	}
}
//---------------------------------------------------------------------------

void __fastcall TMyForm::btBSplineClick(TObject *Sender)
{
	int index = lbPoligonos->ItemIndex;
	if(_poligonoValidoParaCurva(index)) {
		auxiliar.AplicarBSpline(index, StrToFloat(edBSpline->Text));
		auxiliar.DesenharPoligonos(img->Canvas, rgTipoReta->ItemIndex);
		auxiliar.MostrarPoligonosDesenhados(lbPoligonos);
	}
}
//---------------------------------------------------------------------------

void __fastcall TMyForm::btForwardDifferenceClick(TObject *Sender)
{
    int index = lbPoligonos->ItemIndex;
	if(_poligonoValidoParaCurva(index)) {
		auxiliar.AplicarBSplineFwDif(index, StrToFloat(edBSpline->Text));
		auxiliar.DesenharPoligonos(img->Canvas, rgTipoReta->ItemIndex);
		auxiliar.MostrarPoligonosDesenhados(lbPoligonos);
	}
}
//---------------------------------------------------------------------------

