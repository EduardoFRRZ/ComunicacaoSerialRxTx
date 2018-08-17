// ---------------------------------------------------------------------------

#pragma hdrstop

#include "CPortaSerial.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

CPortaSerial::CPortaSerial(char *porta){
    hPorta = CreateFile(porta, GENERIC_READ | GENERIC_WRITE , 0 , NULL, OPEN_EXISTING, 0, NULL);

    if (hPorta == INVALID_HANDLE_VALUE)
        aberta = false;
    else
        aberta = true;

}
	
    
CPortaSerial::~CPortaSerial(){
    CloseHandle(hPorta);
    aberta = false;
}
