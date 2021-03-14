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
double a, b, h, x, s, s1, f, r;
        int n, k;
        a = StrToFloat(Edit1 -> Text);
        b = StrToFloat(Edit2 -> Text);
        h = StrToFloat(Edit3 -> Text);
        n = StrToFloat(Edit4 -> Text);
        Memo1 -> Lines -> Add("Pri n = " + FloatToStr(n) + ":");
        for (x = a; x <= b; x += h)
        {       s = 0;
                for(k = 1; k <= n; k ++)
                {
                        s1 = pow(-1,k+1)*pow(x,2*k+1)/(4*pow(k,2)-1);
                        s = s + s1 ;
                }
        f = ((1+pow(x,2))/2.)*atan(x)-(x/2.);
        r = fabs(f - s);
        Memo1 -> Lines -> Add("x = " + FloatToStr(x) + "  s = "
        + FloatToStr(s) + "  f = " + FloatToStr(f) +
        "  |f - s| = " + FloatToStr(r));
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        Edit1 -> Text = "0,1";
        Edit2 -> Text = "1,0";
        Edit3 -> Text = "0,1";
        Edit4 -> Text = "900";
        Memo1 -> Clear();
        Memo1 -> Lines -> Add("Лабораторная работа №3");
}
//---------------------------------------------------------------------------

