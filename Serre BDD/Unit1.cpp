//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	std::string host = "192.168.1.26";
	std::string user = "root";
	std::string pass = "root";
	std::string db = "SerreEau";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{

	MYSQL_ROW row = NULL;
	MYSQL_RES *res = NULL;

	sock = mysql_init(0);
	char choice;
	string ConsoEauCourante, Date, str;
	sock = mysql_real_connect(sock, "192.168.1.26", "root", "root", "SerreEau", 0, NULL, 0);
	if (sock)
		Label1->Caption = "Connecté";
	else
		Label1->Caption = "Erreur de connection";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	std::string DateH = "2020-03-29 17:00:00";
	int LitreEaucourante = 8;
	int LitreEaurécup = 16;
	int ConsommationElectrique = 3;

	requete << "INSERT INTO Consommation (Date, ConsoEauCourante,ConsoEauRecup,ConsoElectrique) VALUES (""'"<< DateH <<"'"", "<< LitreEaucourante <<","<<LitreEaurécup <<", "<< ConsommationElectrique <<")";
	mysql_query(sock, requete.str().c_str());
}
//---------------------------------------------------------------------------

