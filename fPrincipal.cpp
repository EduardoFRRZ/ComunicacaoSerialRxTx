// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fPrincipal.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmPrincipal *frmPrincipal;

// ---------------------------------------------------------------------------
__fastcall TfrmPrincipal::TfrmPrincipal(TComponent* Owner) : TForm(Owner) {
}
// ---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btnListarPortasClick(TObject *Sender) {
	ListarPortas();
}
// ---------------------------------------------------------------------------

void TfrmPrincipal::ListarPortas() {
	TRegistry *registro = new TRegistry;
	TStringList *lista = new TStringList;

	registro->RootKey = HKEY_LOCAL_MACHINE;
	registro->OpenKey("HARDWARE\\DEVICEMAP\\SERIALCOMM", false);
	registro->GetValueNames(lista);
	cmbPorta->Items->Clear();

	for (int i = 0; i < lista->Count; i++) {
		cmbPorta->Items->Add(registro->ReadString(lista->Strings[i]));
	}

	if (cmbPorta->Items->Count > 0) {
		cmbPorta->ItemIndex = 0;
	}

	registro->CloseKey();

	delete(registro, lista);
};
bool TfrmPrincipal::ConfigurarPorta()
{
  if(objPorta->LerConfigPorta())
  {

    /* configurar baudrate
    opcoes no combobox:
    4800
    9600
    19200
    38400
    57600
    115200
    128000
	*/
	switch(cmbVelocidade->ItemIndex)
    {
       case 0: objPorta->config.BaudRate = CBR_4800; break;
       case 1: objPorta->config.BaudRate = CBR_9600; break;
       case 2: objPorta->config.BaudRate = CBR_19200; break;
       case 3: objPorta->config.BaudRate = CBR_38400; break;
       case 4: objPorta->config.BaudRate = CBR_57600; break;
       case 5: objPorta->config.BaudRate = CBR_115200; break;
       case 6: objPorta->config.BaudRate = CBR_128000; break;

       default:
       break;
    }

     /* paridade
     None
    Even
    Odd
    Mark
    */
    switch(cmbParidade->ItemIndex)
    {
        case 0: objPorta->config.Parity = NOPARITY; break;
        case 1: objPorta->config.Parity = EVENPARITY; break;
        case 2: objPorta->config.Parity = ODDPARITY; break;
        case 3: objPorta->config.Parity = MARKPARITY; break;
        default: break;

    }

    /* stopbit
    1
    2
    */
    switch(cmbBitParada->ItemIndex)
    {
       case 0: objPorta->config.StopBits = ONESTOPBIT; break;
       case 1: objPorta->config.StopBits = TWOSTOPBITS; break;
       default: break;
    }

     /* byte size */
     switch(cmbBitsDados->ItemIndex)
     {
         case 0: objPorta->config.ByteSize = 8; break;
         case 1: objPorta->config.ByteSize = 9; break;
         default: break;
         }

     return objPorta->SetConfigPorta();

  }

   else
     ShowMessage("Erro em ler config. da porta");


   return false;

}
// ---------------------------------------------------------------------------



void __fastcall TfrmPrincipal::btnAbrirPortaClick(TObject *Sender)
{
	porta = cmbPorta->Text; // Pega endereço da porta COM selecionada

	objPorta = new CPortaSerial(porta.c_str());

	if(objPorta->xAberta){ // Se conseguiu abrir a porta

		if(ConfigurarPorta()){ // Configurar velocidade etc...

			// Definir estado da interface gráfica
			btnAbrirPorta->Enabled = false;
			btnFecharPorta->Enabled = true;
			lblStatus->Caption = "Conectado";
			lblStatus->Font->Color = clGreen;
			lblStatus->Alignment = taCenter;
			thread->Active = true; // Habilitar leitura da porta
		}
		else{
			ShowMessage("Não foi possivel configurar a porta");
			delete(objPorta);
		}
		edtTx->SetFocus();
	}
	else{
		ShowMessage("Não foi possivel abrir a porta selecionada");
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btnFecharPortaClick(TObject *Sender)
{
	thread->Active = false;
	delete(objPorta);

	// Questão visual da interface
	btnFecharPorta->Enabled = false;
	btnAbrirPorta->Enabled = true;
	lblStatus->Caption = "Desconectado";
	lblStatus->Font->Color = clRed;
	lblStatus->Alignment = taCenter;
}
//---------------------------------------------------------------------------


void __fastcall TfrmPrincipal::threadRun(TIdThreadComponent *Sender)
{
  if(mmoRx->Lines->Count > 5000) // Controle de impressão do form
	mmoRx->Clear();

	byteRec = objPorta->ReceberByte();
	inByte = byteRec; // Facilitar comparação tratamento

	if(inByte.Length() >= 1 && inByte != "0")
		mmoRx->Lines->Add(inByte);

		Sleep(200);

        //CONTINUA
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btnEnviarClick(TObject *Sender)
{
    strcpy(outByte,AnsiString(edtTx->Text).c_str());

    if(btnAbrirPorta->Enabled == false)
    {
        thread->Active = false;

        objPorta->TransmitirByte(outByte[0]);


        mmoRx->Lines->Add("<" + edtTx->Text.SubString(0,1) + ">");

        /* adicionar caracter enviado */
       //    mmoRx->Text = mmoRx->Text + "<" + edtTx->Text.SubString(0,1) + ">";

        thread->Active = true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btnLimparRxClick(TObject *Sender)
{
    mmoRx->Clear();
}
//---------------------------------------------------------------------------

