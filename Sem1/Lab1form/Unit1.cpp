//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <math.h>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        double x, y, z, a, b, c, d, rez, PI;
        PI = 3.1415926;
        x = StrToFloat(Edit1 -> Text);
        y = StrToFloat(Edit2 -> Text);
        z = StrToFloat(Edit3 -> Text);
        a = pow(2,pow(y,x));
        b = pow(pow(3,x),y);
        c = y * (atan(z) - PI/6);
        d = fabs(x) + (1 / (pow(y,2) + 1));
        rez = a + b - (c/d);
        Memo1 -> Lines -> Add("??? x = " + FloatToStrF(x,ffFixed,7,3)
        + "; y = " + FloatToStrF(y,ffFixed,7,3)
        + "; z = " + FloatToStrF(z,ffFixed,8,7));
        Memo1 -> Lines -> Add("????????? = " + FloatToStr(rez));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        Edit1 -> Text = "3,251";
        Edit2 -> Text = "0,325";
        Edit3 -> Text = "0,466E-4";
        Memo1 -> Clear();
        Memo1 -> Lines -> Add("???????????? ?????? ?1");
}
//---------------------------------------------------------------------------
 