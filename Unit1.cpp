//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int x=8;
int y=8;
int punktGracz1=0;
int punktGracz2=0;
int ilosc_odbic=0;
AnsiString imieGracza1="";
AnsiString imieGracza2="";

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
   Application->MessageBox("Witaj w grze PingPong \n \n Lewy gracz steruje wciskaj¹c klawisze A oraz Z. \n Prawy gracz steruje wciskaj¹c strzaki do góry i w dó³. \n \n Dla urozmaicenia zabawy: \n Kiedy odbijesz pi³kê na srodku paletki, wówczas zmienisz jej k¹t odbicia i pi³ka przyspieszy \n Im d³u¿ej odbijasz tym pi³ka szybciej przemieszcza siê. \n Mo¿esz dowolnie zmieniac pole gry. \n \n Mi³ej zabawy! ", "PingPong", MB_OK);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DownTimerP1Timer(TObject *Sender)
{
if(Paletka1->Top+Paletka1->Height<Form1->Height-50) Paletka1->Top +=10;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::UpTimerP1Timer(TObject *Sender)
{
 if(Paletka1->Top>10) Paletka1->Top -=10;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
 if (Key== 0x41) UpTimerP1->Enabled=true ;
if (Key== 0x5A) DownTimerP1->Enabled=true ;
 if (Key== VK_UP) UpTimerP2->Enabled=true ;
if (Key== VK_DOWN) DownTimerP2->Enabled=true ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
 if (Key== 0x41) UpTimerP1->Enabled=false ;
if (Key== 0x5A) DownTimerP1->Enabled=false ;
 if (Key== VK_UP) UpTimerP2->Enabled=false ;
if (Key== VK_DOWN) DownTimerP2->Enabled=false ;
}
//------------------------------------z---------------------------------------

void __fastcall TForm1::DownTimerP2Timer(TObject *Sender)
{
if(Paletka2->Top+Paletka2->Height<Form1->Height-50) Paletka2->Top +=10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::UpTimerP2Timer(TObject *Sender)
{
 if(Paletka2->Top>10) Paletka2->Top -=10;
}
//---------------------------------------------------------------------------




void __fastcall TForm1::pilkaTimer(TObject *Sender)
{

if((b->Top<0)||(b->Top+72>Form1->Height))
{
 x=-x;

  }
if ((b->Left<=Paletka1->Left+Paletka1->Width)&&(b->Top+b->Width/2>=Paletka1->Top)&&(b->Top+b->Width/2<=Paletka1->Top+Paletka1->Height))
{
y=-y;
if(pilka->Interval>=3)
 pilka->Interval-=2;

b->Picture->LoadFromFile("img/ballred.bmp") ;
ilosc_odbic++;
}
else if ((b->Left+32>=Paletka2->Left)&&(b->Top+b->Width/2>=Paletka2->Top)&&(b->Top+b->Width/2<=Paletka2->Top+Paletka2->Height))

{
y=-y;
if(pilka->Interval>=3)
 pilka->Interval-=2;

b->Picture->LoadFromFile("img/ballyellow.bmp") ;
ilosc_odbic++;
}
else if(b->Left<Paletka1->Left+Paletka1->Width)
{
pilka->Enabled=false;
b->Visible=false;
Wynik->Caption="Punkt dla "+ imieGracza2;
punktGracz2++ ;
wynikLiczby->Caption= IntToStr(punktGracz1)+":"+IntToStr(punktGracz2);
iloscOdbic->Caption= "Ilosc odbic: "+ IntToStr(ilosc_odbic);
  Wynik->Visible=true;

  wynikLiczby->Visible=true;
  iloscOdbic->Visible=true;
  nastepnaRunda-> Visible=true;
  NowaGra2->Visible=true;
}
else if(b->Left+32>Paletka2->Left)
{
pilka->Enabled=false;
b->Visible=false;
Wynik->Caption="Punkt dla "+ imieGracza1;
punktGracz1++    ;
wynikLiczby->Caption= IntToStr(punktGracz1)+":"+IntToStr(punktGracz2);
iloscOdbic->Caption= "Ilosc odbic: "+IntToStr(ilosc_odbic);
Wynik->Visible=true;
  wynikLiczby->Visible=true;
  iloscOdbic->Visible=true;
  nastepnaRunda-> Visible=true;
        NowaGra2->Visible=true;

}

 b->Top-=x ;
b->Left-=y ;

}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button1Click(TObject *Sender)
{    Application->ProcessMessages();
        b->Visible=true;
  pilka->Enabled=true;
  Button1->Visible=false;
  InfoPingPong->Visible=false;
   InfoGracz1->Visible=false;
   InfoGracz2->Visible=false;
   imieGracza1=EditGracz1->Text;
   imieGracza2=EditGracz2->Text;
   EditGracz1->Visible=false;
   EditGracz2->Visible=false;

}
//---------------------------------------------------------------------------



void __fastcall TForm1::nastepnaRundaClick(TObject *Sender)
{
b->Left=480;
b->Top=80;
ilosc_odbic=0;
y=-y ;
if (y<0)
{
 y=-8;
}
else
y=8;

if (x<0)
{
 x=-8;
}
else
x=8;
b->Visible=true;
pilka->Enabled=true;
Wynik->Visible=false;
wynikLiczby->Visible=false;
iloscOdbic->Visible=false;
nastepnaRunda->Visible=false;
NowaGra2->Visible=false;
b->Picture->LoadFromFile("img/ballwhite.bmp") ;
}
//---------------------------------------------------------------------------









void __fastcall TForm1::NowaGra2Click(TObject *Sender)
{
  int wartosc=Application->MessageBox("Czy jestes pewien? ", "Gra od nowa?", MB_YESNO);
  if (wartosc==6)
  {
   NowaGra2->Visible=false;
   Wynik->Visible=false;
wynikLiczby->Visible=false;
nastepnaRunda->Visible=false;
iloscOdbic->Visible=false;
   InfoGracz1->Visible=true;
   InfoGracz2->Visible=true;
       EditGracz1->Text="Gracz1";
   EditGracz2->Text="Gracz2";
      EditGracz1->Visible=true;
   EditGracz2->Visible=true;
   b->Left=480;
b->Top=80;
 x=8; y=8;
 punktGracz1=0;
 punktGracz2=0;
 ilosc_odbic=0;
imieGracza1="";
imieGracza2="";
b->Picture->LoadFromFile("img/ballwhite.bmp") ;
   Button1->Visible=true;
  }
}
//---------------------------------------------------------------------------



