//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <math.h>
#include <conio.h>
#include <iostream.h>
//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{       double x, a, b, h, l, g, e, s, s1, f, r;
        int k, n;
        cout << "       Vvedite znachenie n:" << endl;
        cin >> n;
        a = 0.1;
        b = 1.0;
        h = 0.1;
        for (x = a; x <= b; x = x+h)
        {        cout << "  x = " << x;
                 s = 0;
                for (k = 1; k <= n; k ++)
                {
                        l = pow(-1,k+1);
                        g = pow(x,2*k+1);
                        e = 4*pow(k,2)-1;
                        s1 = l*(g/e);
                        s = s + s1;
                }
        f = ((1+pow(x,2))/2.)*atan(x)-(x/2.);
        r = fabs(f-s);
        cout << "  s = " << s << "  f = " << f << "  |f - s| = " << r << endl;
        }
        getch();
        return 0;
}
//---------------------------------------------------------------------------
