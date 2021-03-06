//---------------------------------------------------------------------------

#ifndef HomePageH
#define HomePageH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TMyForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *MyPanel;
	TImage *img;
	TLabel *lbViewport;
	TLabel *lbMundo;
	TPanel *Panel1;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TEdit *edXwmin;
	TEdit *edYwmax;
	TEdit *edYwmin;
	TEdit *edXwmax;
	TButton *btAtualizarMundo;
	TButton *btnZerarCoordenadas;
	TPanel *Panel2;
	TLabel *Label3;
	TButton *btDesenharPoligono;
	TLabel *Label4;
	TListBox *lbPoligonos;
	TListBox *lbPontos;
	TLabel *Label6;
	TPanel *Panel3;
	TLabel *Label1;
	TLabel *Label2;
	TButton *btUp;
	TButton *btDown;
	TButton *btLeft;
	TButton *btRight;
	TLabel *Label5;
	TButton *btIn;
	TButton *btOut;
	TLabel *Label7;
	TEdit *edIncremento;
	TPanel *Panel4;
	TLabel *Label13;
	TRadioGroup *rgTipoReta;
	TButton *btnRedesenhar;
	TPanel *Panel5;
	TLabel *Label14;
	TButton *btDesenharCirculo;
	TPanel *Panel6;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *Label17;
	TEdit *edDeslocamentoX;
	TEdit *edDeslocamentoY;
	TButton *btTransladar;
	TPanel *Panel7;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label20;
	TEdit *edFatorX;
	TEdit *edFatorY;
	TButton *btEscalonar;
	TPanel *Panel8;
	TLabel *Label21;
	TLabel *Label22;
	TEdit *edAngulo;
	TButton *btRotacionar;
	TPanel *Panel9;
	TLabel *Label23;
	TCheckBox *cbEixoX;
	TCheckBox *cbEixoY;
	TButton *btRefletir;
	TPanel *Panel10;
	TLabel *Label24;
	TLabel *Label25;
	TLabel *Label26;
	TEdit *edXc;
	TEdit *edYc;
	TButton *btPontoCentral;
	TCheckBox *cbEscalonamento;
	TCheckBox *cbRotacao;
	TPanel *Panel11;
	TLabel *Label27;
	TButton *btnClipping;
	TPanel *Panel12;
	TLabel *Label28;
	TButton *btApagar;
	void __fastcall imgMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall lbPoligonosClick(TObject *Sender);
	void __fastcall btDesenharPoligonoClick(TObject *Sender);
	void __fastcall imgMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall btAtualizarMundoClick(TObject *Sender);
	void __fastcall btnZerarCoordenadasClick(TObject *Sender);
	void __fastcall btInClick(TObject *Sender);
	void __fastcall btOutClick(TObject *Sender);
	void __fastcall btUpClick(TObject *Sender);
	void __fastcall btDownClick(TObject *Sender);
	void __fastcall btRightClick(TObject *Sender);
	void __fastcall btLeftClick(TObject *Sender);
	void __fastcall btnRedesenharClick(TObject *Sender);
	void __fastcall btDesenharCirculoClick(TObject *Sender);
	void __fastcall btTransladarClick(TObject *Sender);
	void __fastcall btEscalonarClick(TObject *Sender);
	void __fastcall btRotacionarClick(TObject *Sender);
	void __fastcall btRefletirClick(TObject *Sender);
	void __fastcall btPontoCentralClick(TObject *Sender);
	void __fastcall btnClippingClick(TObject *Sender);
	void __fastcall btApagarClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TMyForm(TComponent* Owner);
	void _atualizarWindow();
	void _redesenharEAtualizarPontosDoPoligono(int);
    void _limparEditsPontoCentral();
};
//---------------------------------------------------------------------------
extern PACKAGE TMyForm *MyForm;
//---------------------------------------------------------------------------
#endif
