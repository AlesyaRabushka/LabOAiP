//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <conio.h>
#include <iostream.h>
#include <algorithm>
//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{       string s;
        cout << "       Vvedite stroky:" << endl;
        getline(cin, s);

        int i = 0, k = 0;
        int* a;
        a = new int[s.length()];     /*s.length - ????? ??????*/

        while (i < s.length())
        {
                if (s[i] != ' '  && i < s.length())
                {
                        a[k] = 0;
                                while (s[i] != ' ' && i < s.length())
                                {
                                        a[k] *= 10;
                                        a[k] += ((int)s[i] - 48);   /*48 - ??? ????*/
                                        i = i + 1;
                                }
                        k++ ;
                        i++ ;
                }

         }

        sort(a, a+k);
        for (i = 0; i < k; i++)
        {
                cout << a[i] << " ";
        }

        delete []a;
        getch();
        return 0;
}
//---------------------------------------------------------------------------
 