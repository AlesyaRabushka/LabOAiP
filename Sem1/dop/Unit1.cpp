//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <conio.h>
#include <iostream.h>
#include <cstring>
//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
        string s, smallest;
        int len, end = 0, start = 0, minLength, currentLength;

        cout << "       Vvedite stroky:" << endl;
        getline(cin, s);
        len = s.length();
        minLength = len;

        while (end <= len)
        {
                if (s[end] != ' ' && s[end] != '\0')
                end++;
                else
                {
                        currentLength = end - start;
                        if (currentLength <= minLength)
                        {
                                smallest = s.substr(start, currentLength);
                                minLength = currentLength;
                        }
                        end++;
                        start = end;
                }

        }
        
        cout << "       Samoe korotkoe slovo:" << endl;
        cout << smallest;
        getch();
        return 0;
}
//---------------------------------------------------------------------------
 