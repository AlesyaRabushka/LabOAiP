//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <conio.h>
#include <iostream.h>
//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{       int n, m, **a, i, j;
        cout << "       Vvedite kolichestvo strok i stolbcov:" << endl;
        cin >> n >> m;
        a = new int* [n];
        for (i = 0; i < n; i++)
        {
                a[i] = new int[m];
        }

        
        cout << "       Vvedite elementy matrizy:" << endl;
        for (i = 0; i < n; i++)
        {
                for (j = 0; j < m; j++)
                {
                        cin >> a[i][j];
                }
        }
        
        int *num, max;
        num = new int [n];
        for (i = 0; i < n; i++)
        {       max = a[i][0];
                for (j = 0; j < m; j++)
                {
                        if (a[i][j] > max)
                        {
                                max = a[i][j];
                        }
                        num[i] = max;
                }
        }

        int t;
        for (i = 0; i < n-1; i++)
        {
                for (j = i + 1; j < n; j++)
                {
                        if (num[j] < num[i])
                        {
                                t = num[j];
                                num[j] = num[i];
                                num[i] = t;

                                int* mest = a[j];
                                a[j] = a[i];
                                a[i] = mest;        
                        }
                }
        }


        cout << "Itogovaya matriza:" << endl;
        for (i = 0; i < n; i++)
        {
                for (j =0; j < m; j++)
                {
                        cout << a[i][j] << ' ';

                }
                cout << endl;
        }
        getch();
        return 0;
}
//---------------------------------------------------------------------------
