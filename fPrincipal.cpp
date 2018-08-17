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
// ---------------------------------------------------------------------------
