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

	for (int i = 0; i < lista->Count - 1; i++) {
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

     return objPorta->SetarConfigPorta();

  }

   else
     ShowMessage("Erro em ler config. da porta");


   return false;

}
// ---------------------------------------------------------------------------
