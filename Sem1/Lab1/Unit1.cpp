//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream.h>
#include <math.h>
#include <conio.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{       const double PI = 3.1415926;
        cout << "       Vvedite znachenia x, y, z:" << endl;
        double x, y, z;
        cin >> x >> y >> z;
        double a = pow(2,pow(y,x));
        double b = pow(pow(3,x),y);
        double c = y*(atan(z)- PI/6);
        double d = fabs(x) + (1/(pow(y,2)+1));
        cout << "       Resyltat:" << endl;
        cout << a + b - c/d;
        getch();
        return 0;
}
//---------------------------------------------------------------------------
 