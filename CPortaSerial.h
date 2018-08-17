// ---------------------------------------------------------------------------

#ifndef CPortaSerialH
#define CPortaSerialH

#include<windows.h>
//#include<Classes.h>

// ---------------------------------------------------------------------------
class CPortaSerial {

private:
	HANDLE hPorta;
	bool abertura;
	COMMTIMEOUTS commTimeouts;

	bool _fastcall GetAberta();
	HANDLE _fastcall getHandle();

public:
	CPortaSerial(char *porta);
	~CPortaSerial();

	DCB config;

	unsigned char _fastcall ReceberByte();
	bool _fastcall TransmitirByte();
	bool _fastcall LerConfigPorta();
	bool _fastcall SetConfigPorta();

	__property bool xAberta = (read = GetAberta);

};

#endif
