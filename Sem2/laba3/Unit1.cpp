//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <conio.h>
#include <iostream.h>
#include <math.h>
//---------------------------------------------------------------------------
using namespace std;
#pragma argsused

double FunctionR(double x, int n)
{
        if(n == 0)
        {
                return 1;
        } else
          if(n % 2 == 0)
          {
                double y;
                y = FunctionR(x, n / 2);
                return y * y;
          }  else return x*FunctionR(x, n - 1);
}

double Function1(double x, int n)
{
        if(n == 0)
        return 1;
        else
        if(n % 2 == 0)
        {
                double y;
                y = pow(x, n / 2);
                return y * y;
        }     else return x*pow(x, n - 1);
}


int main(int argc, char* argv[])
{
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);

        int n, s;
        double x;
        while(true)
        {
        cout << "       �������� �����:" << endl;
        cout << "       ������� ������� - 1" << endl << "       ����������� ������� - 2" << endl
        << "       ����� - 0" << endl;
        cin >> s;
        switch(s)
        {
                case 1:
                cout << "       ������� ����� x:" << endl;
                cin >> x;
                cout << "       ������� ����� n:" << endl;
                cin >> n;
                cout << "���������: " << Function1(x, n) << endl;
                break;

                case 2:
                cout << "       ������� ����� x:" << endl;
                cin >> x;
                cout << "       ������� ����� n:" << endl;
                cin >> n;
                cout << "���������: " << FunctionR(x, n) << endl;
                break;
        }
                if(s == 0)
                break;
        }

        getch();
        return 0;
}
//---------------------------------------------------------------------------
 