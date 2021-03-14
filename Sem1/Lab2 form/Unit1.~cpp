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
        double a, b, z, x, c, d, f, rez;
        int n;
        a = StrToFloat(Edit1 -> Text);
        b = StrToFloat(Edit2 -> Text);
        z = StrToFloat(Edit3 -> Text);
        if ( z > 0)
        {
                x = pow(z,1/2);
                Memo1 -> Lines -> Add("z > 0, x = pow(z,1/2)");
        } else
        {
                x = pow(z,2)/2;
                Memo1 -> Lines -> Add("z <= 0, x = pow(z,2)/2");
        }
        switch (RadioGroup1 -> ItemIndex)
        {
                case 0: f = 2*x; break;
                case 1: f = x*x; break;
                case 2: f = x/3; break;
        }
        c = f/cos(x);
        d = log(fabs(tan(x/2)));
        rez = b*c + a*d;
        Memo1 -> Lines -> Add("При z =" + FloatToStrF(z,ffFixed,8,6)
        + " x =" + FloatToStrF(x,ffFixed,8,6));
        Memo1 -> Lines -> Add("y = b*f/cos(x) + a*log(fabs(tan(x/2)))" );
        Memo1 -> Lines -> Add("Результат: " + FloatToStrF(rez,ffFixed,8,6));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        Edit1 -> Text = "2";
        Edit2 -> Text = "3";
        Edit3 -> Text = "1,5";
        Memo1 -> Clear();
        Memo1 -> Lines -> Add("Лабораторная №2");
}
//---------------------------------------------------------------------------
 