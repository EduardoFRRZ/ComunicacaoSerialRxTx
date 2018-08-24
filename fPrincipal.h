#ifndef fPrincipalH
#define fPrincipalH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdThreadComponent.hpp>

#include <registry.hpp> /* TRegistry para acessar o regedit */

#include "CPortaSerial.h"
#include <Vcl.ComCtrls.hpp>

// ---------------------------------------------------------------------------
class TfrmPrincipal : public TForm {
__published: // IDE-managed Components
	TGroupBox *gbxSerial;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TComboBox *cmbPorta;
	TComboBox *cmbVelocidade;
	TComboBox *cmbBitsDados;
	TComboBox *cmbParidade;
	TComboBox *cmbBitParada;
	TMemo *mmoRx;
	TLabel *Label6;
	TButton *btnLimparRx;
	TButton *btnListarPortas;
	TLabel *Label7;
	TEdit *edtTx;
	TButton *btnEnviar;
	TButton *btnAbrirPorta;
	TButton *btnFecharPorta;
	TLabel *lblStatus;
	TIdThreadComponent *thread;

	void __fastcall btnListarPortasClick(TObject *Sender);
	void __fastcall btnAbrirPortaClick(TObject *Sender);
	void __fastcall btnFecharPortaClick(TObject *Sender);
	void __fastcall threadRun(TIdThreadComponent *Sender);
	void __fastcall btnEnviarClick(TObject *Sender);
	void __fastcall btnLimparRxClick(TObject *Sender);

	// void __fastcall btnListarPortasClick(TObject *Sender);
	// void __fastcall btnAbrirPortaClick(TObject *Sender);
	// void __fastcall btnFecharPortaClick(TObject *Sender);
	// void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	// void __fastcall threadRun(TIdThreadComponent *Sender);
	// void __fastcall btnEnviarClick(TObject *Sender);
	// void __fastcall btnLimparRxClick(TObject *Sender);
	// void __fastcall FormShow(TObject *Sender);
private: // User declarations

	CPortaSerial *objPorta;
	String teste;
	AnsiString porta;
	AnsiString inByte;
	unsigned char byteRec;
	unsigned char outByte[10];
	double mv, temp;

public: // User declarations
	__fastcall TfrmPrincipal(TComponent* Owner);

	void ListarPortas(); /* listar portas COM do sistema */
	bool ConfigurarPorta(); /* definir configurações de operacao */
};

// ---------------------------------------------------------------------------
extern PACKAGE TfrmPrincipal *frmPrincipal;
// ---------------------------------------------------------------------------
#endif
