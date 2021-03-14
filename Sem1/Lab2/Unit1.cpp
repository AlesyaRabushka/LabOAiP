//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <math.h>
#include <conio.h>
#include <iostream.h>
//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{       double b, z, x, a, c, d, rez, f;
        int n;
        cout << "       Vvedite znachenia a, b, z:" << endl;
        cin >> a >> b >> z;
        if (z > 0)
        {
                x = pow(z,1/2);
                cout << "       z > 0, x = pow(z,1/2)" << endl;
        } else
        {
                x = pow(z,2)/2;
                cout << "       z <= 0, x = pow(z,2)/2" << endl;
        }
        cout << "       Vyberite f(x):" << endl;
        cout << "       0 - f = 2*x" << endl;
        cout << "       1 - f = x*x" << endl;
        cout << "       2 - f = x/3" << endl;
        cin >> n;
        switch (n)
        {
                case 0: f = 2*x; break;
                case 1: f = x*x; break;
                case 2: f = x/3; break;
        }

        c = f/cos(x);
        d = log(fabs(tan(x/2)));
        rez = b*c + a*d;
        cout << "       y = b*f/cos(x) + a*log(fabs(tan(x/2)))" << endl;
        cout << "       Resyltat:" << endl;
        cout << rez;
        getch();
        return 0;
}
//---------------------------------------------------------------------------
 