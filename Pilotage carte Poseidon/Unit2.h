//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
#include <Windows.h>
#include <winsock2.h>

class tcp
{
	private :
	SOCKET sock;
	public :
	tcp(SOCKET sock);
	~tcp();
	void WriteDigitalOutput2ON();
	void WriteDigitalOutput2OFF();

	void WriteDigitalOutput1ON();
	void WriteDigitalOutput1OFF();

	void TrameEnvoiReadCompteur();
	void TrameEnvoiWriteDebitZ();
	void TrameEnvoiReadTemp();

	void ReadOutput1();
	void ReadOutput2();
};
//---------------------------------------------------------------------------
#endif
