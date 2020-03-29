//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>

#include "Unit2.h"
#include <Vcl.ExtCtrls.hpp>
#include <vector>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Composants gérés par l'EDI
	TButton *Connexion;
	TLabel *Label1;
	TButton *ButtonChangeCompteur;
	TButton *ButtonOutput1ON;
	TButton *ButtonOutput1OFF;
	TButton *ButtonOutput2ON;
	TButton *ButtonOutput2OFF;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TTimer *Timer5;
	void __fastcall ConnexionClick(TObject *Sender);
	void __fastcall ButtonChangeCompteurClick(TObject *Sender);
	void __fastcall ButtonOutput1ONClick(TObject *Sender);
	void __fastcall ButtonOutput1OFFClick(TObject *Sender);
	void __fastcall ButtonOutput2ONClick(TObject *Sender);
	void __fastcall ButtonOutput2OFFClick(TObject *Sender);
	void __fastcall Timer5Timer(TObject *Sender);
private:	// Déclarations utilisateur
	SOCKET sock;
	tcp* tcp_;
	int trame;
	int trame1;
	int trame2;
	int trame3;
	int trameR;
	UINT8 receiveCompteur[1024];
	UINT8 receiveTemp[1024];
	UINT8 receiveOutput1[1024];
	UINT8 receiveOutput2[1024];
	UINT8 receiveWrite[1024];

	std::vector <UINT8> vecteurCompteur;
	std::vector <UINT8> vecteurTemp;
	std::vector <UINT8> vecteurOutput1;
	std::vector <UINT8> vecteurOutput2;
	float temperature;
	bool Output1;
	bool Output2;
public:		// Déclarations utilisateur
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
