//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *Paletka1;
        TImage *Paletka2;
        TTimer *DownTimerP1;
        TTimer *UpTimerP1;
        TTimer *UpTimerP2;
        TTimer *DownTimerP2;
        TImage *b;
        TTimer *pilka;
        TButton *Button1;
        TLabel *InfoPingPong;
        TLabel *InfoGracz1;
        TLabel *InfoGracz2;
        TEdit *EditGracz1;
        TEdit *EditGracz2;
        TLabel *Wynik;
        TLabel *wynikLiczby;
        TLabel *iloscOdbic;
        TButton *nastepnaRunda;
        TButton *NowaGra2;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall DownTimerP1Timer(TObject *Sender);
        void __fastcall UpTimerP1Timer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall DownTimerP2Timer(TObject *Sender);
        void __fastcall UpTimerP2Timer(TObject *Sender);
        void __fastcall pilkaTimer(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall nastepnaRundaClick(TObject *Sender);
        void __fastcall NowaGra2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 