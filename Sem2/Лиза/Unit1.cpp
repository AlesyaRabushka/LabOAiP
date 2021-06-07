//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"

#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
double a, b, h, y_min, y_max;
int n;
double fun1(double r)
{
       double r1 = 1 + 2*pow(r,2);
       double r2 = exp(r);
       return r1 * r2;
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        Edit1->Text = "-3,14";
        Edit2->Text = "3,14";
        Edit3->Text = "50";
}
//---------------------Задаём начальные значения------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
          double x, r;
          a = StrToFloat(Edit1->Text);
          b = StrToFloat(Edit2->Text);
          n = StrToFloat(Edit3->Text);
          h = (b - a) / n;        //шаг
          y_min = y_max = fun1(a);
          for(x = a + h; x <= b; x += h)
          {
                r = fun1(x);
                if(y_min > r) y_min = r;
                if(y_max < r) y_max = r;
          }
}
//--------------------Строим график в Chart-------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        Chart1->Series[0]->Clear();
        for(double x = a; x <= b; x += h)
        {
                Chart1->Series[0]->AddXY(x, fun1(x));
        }

}
//---------------------Строим график в Image------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
        int xmax, ymax, x0, y0, xt, yt;
        double hx, hy, x;
        Image1->Canvas->Pen->Color=clBlack;
        xmax = Image1->Width;     //координаты правого нижнего угла
        ymax = Image1->Height;
        Image1->Canvas->Rectangle(0, 0, xmax, ymax);
        y0 = ymax/2;       //середина холста
        x0 = xmax/2;

        Image1->Canvas->MoveTo(0, y0);
        Image1->Canvas->LineTo(xmax, y0);
        Image1->Canvas->MoveTo(x0, 0);
        Image1->Canvas->LineTo(x0, ymax);
        Image1->Canvas->Pen->Color = clBlue;
        Image1->Canvas->Pen->Width = 2;

        //поиск шагов по x и y
        hx = (b-a)/xmax;
        hy = (y_max - y_min)/ymax;

        Image1->Canvas->MoveTo(ceil(x0+a/hx), ceil(y0-fun1(a)/hy));

        for(x = a; x <= b; x += h)
        {
            Image1->Canvas->LineTo(ceil(x0+x/hx), ceil(y0-fun1(x)/hy));
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{

int xmax, ymax, x0, y0;
       xmax = Image2->Width;     //координаты правого нижнего угла
        ymax = Image2->Height;
       for(int x = 0; x < 60;)
       {
                Image2->Canvas->Pen->Color = clWhite;
                Image2->Canvas->Brush->Color=clWhite;
                x+=5;

        Image2->Canvas->Pen->Color=clBlack;
        Image2->Canvas->Brush->Color=clRed;
        Image2->Canvas->Ellipse(x,x+10,x+30,x+40);


        Repaint();            //обновление картинки на экране
        Sleep(90);
        Image2->Canvas->Brush->Color=clWhite;
        Image2->Canvas->Rectangle(0, 0, xmax, ymax);
       }

       for(int x = 190; x > 110;)
       {
       x-=5;
       Image2->Canvas->Pen->Color=clBlack;
        Image2->Canvas->Brush->Color=clYellow;

                Image2->Canvas->Rectangle(x,x-10,x-30,x-40);
                Repaint();
                Sleep(90);
                Image2->Canvas->Brush->Color=clWhite;
        Image2->Canvas->Rectangle(0, 0, xmax, ymax);
       }



        Image2->Canvas->Brush->Color=clWhite;
        Image2->Canvas->Rectangle(0, 0, xmax, ymax);


          Image2->Canvas->Brush->Color=clBlue;

        Image2->Canvas->Rectangle(0, 0, xmax, ymax);

        Repaint();
        Sleep(300);

         Image2->Canvas->Brush->Color = clWhite;

        Image2->Canvas->Rectangle(0, 0, xmax, ymax);
        Repaint();
        Sleep(300);

            Image2->Canvas->Brush->Color=clBlue;

          Image2->Canvas->Rectangle(30, 30, 180, 180);
        Repaint();
        Sleep(300);

         Image2->Canvas->Brush->Color = clWhite;

        Image2->Canvas->Rectangle(50, 50, 160, 160);
        Repaint();
        Sleep(300);

            Image2->Canvas->Brush->Color=clBlue;
            
        Image2->Canvas->Rectangle(60, 60, 140, 140);
        Repaint();
        Sleep(300);

         Image2->Canvas->Brush->Color = clWhite;

        Image2->Canvas->Rectangle(80, 80, 120, 120);
        Repaint();
        Sleep(300);





}
//---------------------------------------------------------------------------

