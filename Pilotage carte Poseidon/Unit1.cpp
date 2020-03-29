//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include "Unit1.h"
#include <stdio.h>
#include <vector>
#include "Windows.h"
#include "windows.h"
#include <stdlib.h>
#include <stdint.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vcl.h>
#pragma hdrstop
#include <winsock2.h>

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	ButtonChangeCompteur->Visible = false;
	ButtonOutput1ON->Visible = false;
	ButtonOutput1OFF->Visible = false;
	ButtonOutput2ON->Visible = false;
	ButtonOutput2OFF->Visible = false;
	Label5->Visible = false;
	Label6->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ConnexionClick(TObject *Sender)

{
	#if defined (WIN32)
		WSADATA WSAData;
		int erreur = WSAStartup(MAKEWORD(2,2), &WSAData);
	#else
		int erreur = 0;
	#endif

	SOCKADDR_IN sin;
	if(!erreur)
	{
		/* Création de la socket */
		sock = socket(AF_INET, SOCK_STREAM, 0);

		/* Configuration de la connexion */
		sin.sin_addr.s_addr = inet_addr("192.168.1.36");//ip du client test
		sin.sin_family = AF_INET;
		sin.sin_port = htons(502);//port

		/* Si le client arrive à se connecter */
		if(connect(sock, (SOCKADDR*)&sin, sizeof(sin)) != SOCKET_ERROR)
		{
            ButtonChangeCompteur->Visible = true;
			ButtonOutput1ON->Visible = true;
			ButtonOutput1OFF->Visible = true;
			ButtonOutput2ON->Visible = true;
			ButtonOutput2OFF->Visible = true;
			Label5->Visible = true;
			Label6->Visible = true;
			Label1->Caption = "Connecté";
			/*Timer1->Enabled = true;
			Timer2->Enabled = true;
			Timer3->Enabled = true;
			Timer4->Enabled = true;*/
			Timer5->Enabled = true;

			tcp_ = new tcp(sock);
		}
		else
		{
			Label1->Caption = "Erreur de connexion";
		}

	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonChangeCompteurClick(TObject *Sender)
{
	tcp_->TrameEnvoiWriteDebitZ();
	trameR = recv(sock, receiveWrite, sizeof(receiveWrite),0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonOutput1ONClick(TObject *Sender)
{
	tcp_->WriteDigitalOutput1ON();
	trameR = recv(sock, receiveWrite, sizeof(receiveWrite),0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonOutput1OFFClick(TObject *Sender)
{
	tcp_->WriteDigitalOutput1OFF();
	trameR = recv(sock, receiveWrite, sizeof(receiveWrite),0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonOutput2ONClick(TObject *Sender)
{
	tcp_->WriteDigitalOutput2ON();
	trameR = recv(sock, receiveWrite, sizeof(receiveWrite),0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonOutput2OFFClick(TObject *Sender)
{
	tcp_->WriteDigitalOutput2OFF();
	trameR = recv(sock, receiveWrite, sizeof(receiveWrite),0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer5Timer(TObject *Sender)
{
//Partie temperature
	tcp_->TrameEnvoiReadTemp();
	trame = recv(sock, receiveTemp, sizeof(receiveTemp),0);
	for (int i = 0; i < 6+receiveTemp[5]; i++)
	{
		vecteurTemp.push_back(receiveTemp[i]);
	}
	int16_t valeur1 = (vecteurTemp[9] << 8) | vecteurTemp[10]; //encode la temperature sur 16 bits
	temperature = ((float)valeur1)/10;  //conversion de la temperature en float

	Label2->Caption = temperature;
	std::fill_n(receiveTemp, 1024, 0);
	vecteurTemp.clear();

//Partie compteur
	tcp_->TrameEnvoiReadCompteur();
	trame1 = recv(sock, receiveCompteur, sizeof(receiveCompteur),0);
	for (int i = 0; i < 6+receiveCompteur[5]; i++)
	{
		vecteurCompteur.push_back(receiveCompteur[i]);
	}
	UINT32 valeur = (vecteurCompteur[9] << 24) | (vecteurCompteur[10] << 16) | (vecteurCompteur[11] << 8) | vecteurCompteur[12];

	Label3->Caption = valeur;
	std::fill_n(receiveCompteur, 1024, 0);
	vecteurCompteur.clear();

//Digital output1
	tcp_->ReadOutput1();
	trame2 = recv(sock, receiveOutput1, sizeof(receiveOutput1),0);
	for (int i = 0; i < 6+receiveOutput1[5]; i++)
	{
		vecteurOutput1.push_back(receiveOutput1[i]);
	}
	Output1 = vecteurOutput1[9];
	if (Output1)
	{
	   Label4->Caption ="La vanne 1 est ouverte" ;
	}
	else
	{
	  Label4->Caption ="La vanne 1 est fermé" ;
	}

	std::fill_n(receiveOutput1, 1024, 0);
	vecteurOutput1.clear();

//Digital output2
	tcp_->ReadOutput2();
	trame3 = recv(sock, receiveOutput2, sizeof(receiveOutput2),0);
	for (int i = 0; i < 6+receiveOutput2[5]; i++)
	{
		vecteurOutput2.push_back(receiveOutput2[i]);
	}
	Output2 = vecteurOutput2[9];
	if (Output2)
	{
	   Label7->Caption = "La vanne 2 est ouverte";
	}
	else
	{
	   Label7->Caption = "La vanne 2 est fermé";
	}

	std::fill_n(receiveOutput2, 1024, 0);
	vecteurOutput2.clear();

}
//---------------------------------------------------------------------------
