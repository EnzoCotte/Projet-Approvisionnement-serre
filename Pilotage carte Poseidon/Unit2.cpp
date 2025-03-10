//---------------------------------------------------------------------------

#pragma hdrstop
#include <winsock2.h>
#include "Unit2.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)

tcp::tcp(SOCKET sock)
{
	this->sock = sock;//constructeur
}
tcp::~tcp()
{
//destructeur
}

void tcp::TrameEnvoiReadCompteur()
{
	char buffer[12];
	buffer[0]=0x00;
	buffer[1]=0x00;
	buffer[2]=0x00;
	buffer[3]=0x00;
	buffer[4]=0x00;

	buffer[5]=0x06;
	buffer[6]=0xff;
	buffer[7]=0x04;   //code fonction

	buffer[8]=0x00;
	buffer[9]=0xCC;  //adresse

	buffer[10]=0x00;
	buffer[11]=0x02;

	send(sock, buffer, 12, 0);

}

void tcp::TrameEnvoiWriteDebitZ() //remet le compteur � zero pour l'adresse cibl�
{
	char buffer[17];
	buffer[0]=0x00;
	buffer[1]=0x00;
	buffer[2]=0x00;
	buffer[3]=0x00;
	buffer[4]=0x00;

	buffer[5]=0x0B;
	buffer[6]=0xff;
	buffer[7]=0x10;   //code fonction

	buffer[8]=0x00;
	buffer[9]=0xCD; //adresse

	buffer[10]=0x00;

	buffer[11]=0x02;

	buffer[12]=0x04;

	buffer[13]=0x00; //contenu
	buffer[14]=0x58; //contenu

	buffer[15]=0x00;
	buffer[16]=0x00;

	send(sock, buffer, 17, 0);
}

void tcp::TrameEnvoiReadTemp()
{
	char buffer[12];

	buffer[0] = 0x00;
	buffer[1] = 0x00;
	buffer[2] = 0x00;
	buffer[3] = 0x00;
	buffer[4] = 0x00;

	buffer[5] = 0x06; //nb de bit restant
	buffer[6] = 0xff; //adresse
	buffer[7] = 0x04; //code fonction

	buffer[8] = 0x00;
	buffer[9] = 0x64; //adresse

	buffer[10] = 0x00;
	buffer[11] = 0x01; //nb de registre demande

	send(sock, buffer, 12, 0);
}

void tcp::WriteDigitalOutput1ON()
{
	char buffer[12];

	buffer[0] = 0x00;
	buffer[1] = 0x00;
	buffer[2] = 0x00;
	buffer[3] = 0x00;
	buffer[4] = 0x00;

	buffer[5] = 0x06; //nb de bit restant
	buffer[6] = 0xff; //adresse
	buffer[7] = 0x05; //code fonction

	buffer[8] = 0x00;
	buffer[9] = 0xC7; //adresse

	buffer[10] = 0xFF; //etat a ecrire
	buffer[11] = 0x00;

	send(sock, buffer, 12, 0);
}

void tcp::WriteDigitalOutput1OFF()
{
	char buffer[12];

	buffer[0] = 0x00;
	buffer[1] = 0x00;
	buffer[2] = 0x00;
	buffer[3] = 0x00;
	buffer[4] = 0x00;

	buffer[5] = 0x06; //nb de bit restant
	buffer[6] = 0xff; //adresse
	buffer[7] = 0x05; //code fonction

	buffer[8] = 0x00;
	buffer[9] = 0xC7; //adresse

	buffer[10] = 0x00; //etat a ecrire
	buffer[11] = 0x00;

	send(sock, buffer, 12, 0);
}

void tcp::WriteDigitalOutput2ON()
{
	char buffer[12];

	buffer[0] = 0x00;
	buffer[1] = 0x00;
	buffer[2] = 0x00;
	buffer[3] = 0x00;
	buffer[4] = 0x00;

	buffer[5] = 0x06; //nb de bit restant
	buffer[6] = 0xff; //adresse
	buffer[7] = 0x05; //code fonction

	buffer[8] = 0x00;
	buffer[9] = 0xC8; //adresse

	buffer[10] = 0xFF; //etat a ecrire
	buffer[11] = 0x00;

	send(sock, buffer, 12, 0);
}

void tcp::WriteDigitalOutput2OFF()
{
	char buffer[12];

	buffer[0] = 0x00;
	buffer[1] = 0x00;
	buffer[2] = 0x00;
	buffer[3] = 0x00;
	buffer[4] = 0x00;

	buffer[5] = 0x06; //nb de bit restant
	buffer[6] = 0xff; //adresse
	buffer[7] = 0x05; //code fonction

	buffer[8] = 0x00;
	buffer[9] = 0xC8; //adresse

	buffer[10] = 0x00; //etat a ecrire
	buffer[11] = 0x00;

	send(sock, buffer, 12, 0);
}

void tcp::ReadOutput1()
{
	char buffer[12];
	buffer[0]=0x00;
	buffer[1]=0x00;
	buffer[2]=0x00;
	buffer[3]=0x00;
	buffer[4]=0x00;

	buffer[5]=0x08;
	buffer[6]=0xff;
	buffer[7]=0x01;   //code fonction

	buffer[8]=0x00;
	buffer[9]=0xC7;  //adresse

	buffer[10]=0x00;
	buffer[11]=0x01;

	send(sock, buffer, 12, 0);
}

void tcp::ReadOutput2()
{
	char buffer[12];
	buffer[0]=0x00;
	buffer[1]=0x00;
	buffer[2]=0x00;
	buffer[3]=0x00;
	buffer[4]=0x00;

	buffer[5]=0x08;
	buffer[6]=0xff;
	buffer[7]=0x01;   //code fonction

	buffer[8]=0x00;
	buffer[9]=0xC8;  //adresse

	buffer[10]=0x00;
	buffer[11]=0x01;

	send(sock, buffer, 12, 0);
}
