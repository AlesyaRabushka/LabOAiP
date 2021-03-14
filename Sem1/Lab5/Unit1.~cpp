//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <conio.h>
#include <iostream.h>
//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
        randomize();
        int n, k, s = 0;
        cout << "       Vvedite razmer massiva:" << endl;
        cin >> n;
        int* a = new int[n];
        cout << "       Vyberite sposob vvoda:\n 0 - klaviatyra\n 1 - randomno" << endl;
        cin >> k;
        if (k == 0)
        {
                cout << "       Vvedite elementy massiva:" << endl;
                for(int i = 0;i < n; i ++)
                        cin >> a[i];
        }       else  {   cout << "     Elementy massiva:" << endl;
                          for(int i = 0; i < n; i ++)
                               { a[i] = random(21)-10;
                                cout << a[i] << ' ';  }
                       }
        cout << endl;
        int f = 0;
        for(int i = n - 1; i > 0; i --)
                if (a[i] == 0)
                { f = 1;
                 break;
                } else
                {
                        s += a[i];
                }
                if (f == 0)
                cout << "Net nylei" << endl;
                if (f == 1)
        cout << "       Summa ravna:" <<  s;
        delete[] a;
        getch();
        return 0;
}
//---------------------------------------------------------------------------
