//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <iostream.h>
#include <conio.h>
#include <algorithm>
//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
        int i = 0, len, k = 0, m ;
        char s[100];
        cout << "       Vvedite stroky:" << endl;
        gets(s);
        len = strlen(s);
        int* a;
        a = new int[len];
        while (i < len)
        {
                if (s[i] != ' ' && i < len)
                {       a[k] = 0;
                        while(s[i] != ' ' && i < len)
                        {
                                a[k] *= 10;
                                a[k] = a[k] + (s[i]-48);
                                i = i + 1;
                        }
                        k++;
                        i++;
                }
         }
        sort(a, a+k);
        for (i = 0; i < k; i++)
                cout << a[i] << " ";
        getch();
        return 0;
}
//---------------------------------------------------------------------------
 