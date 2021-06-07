//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <iostream.h>
#include <conio.h>
#include <fstream>
//---------------------------------------------------------------------------
using namespace std;
#pragma argsused


    struct Shop {
    char name[50];
    int amount;
    char number[10];
    };

// 1 - создание записи----------------------------------------------------------
void GetInformation()
{
    int n;
    cout << "   Введите количество записей:" << endl;
    cin >> n;
    ofstream record("zapici.txt");
    Shop* sh = new Shop[n];

    if (record)
    {
        record << n << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "   Наименование изделия:" << endl;
            cin.ignore(100, '\n');
            gets(sh[i].name);
            record << sh[i].name << endl;

            cout << "   Количество:" << endl;
            cin >> sh[i].amount;
            record << sh[i].amount << endl;

            cout << "   Номер цеха:" << endl;
            cin >> sh[i].number;
            record << sh[i].number << endl;
        }
    }
    record.close();
}
//------------------------------------------------------------------------------
// 2 - просмотр-----------------------------------------------------------------
void ReadInformation()
{
    ifstream reading("zapici.txt");
    int n;
    string name = "";
    string amount = "";
    string number = "";
    string stroka = "";
    
    reading >> n;
    if (reading)
    {   getline(reading, stroka);
    cout << "           Информация: " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "   Наименование: ";
            getline(reading, name);
            cout << name << endl;

            cout << "   Количество: ";
            getline(reading, amount);
            cout << amount << endl;

            cout << "   Номер цеха: ";
            getline(reading, number);
            cout << number << endl;

            cout << "----------------------" << endl;
        }
    }
    reading.close();
}
//------------------------------------------------------------------------------

// количесвто первоначальных записей--------------------------------------------
int Number()
{
        int number;
        ifstream reading("zapici.txt");
        if(reading)
        {
                reading >> number;
        }
        return number;
}
//

// 3 - добавляем запись-----------------------------------------—
void AddInformation()
{
cout << " Введите количество записей: " << endl;
int n;
cin >> n;
Shop *sh = new Shop[n];

string number = "";
int num = Number() + n;

ofstream record("zapici.txt", ios::app);
ofstream record_("zapici.txt", ios::in); //для записи в начало файла

if (record_)
{
record_ << num << endl;
   if (record)
   {
        for (int i = 0; i < n; i++)
        {
        cout << "Наименование: " << endl;
        cin.ignore(100, '\n'); //пропустит 100 символов, если ранее не будет найден символ \n
        gets(sh[i].name);
        record << sh[i].name << endl;

        cout << "Количество: " << endl;
        cin >> sh[i].amount;
        record << sh[i].amount << endl;

        cout << "Номер цеха: " << endl;
        cin >> sh[i].number;
        record << sh[i].number << endl;
        }
   }
}
record_.close();
record.close();
}
//------------------------------------------------------------------------------
int main()
{

    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n, s;

    while (true)
    {
        cout << "      Выберите действие:" << endl;
        cout << "       Создать - 1" << endl << "       Просмотр - 2" << endl
            << "       Добавить - 3" << endl << "       Линйный поиск - 4" << endl
            << "       Прямой выбор - 5" << endl << "       QuickSort - 6" << endl
            << "       Двоичный поиск в отсортированном массиве - 7" << endl
            << "       Выход - 0" << endl;

        cin >> s;
        switch (s)
        {

        case 1:
            system("cls");
            GetInformation();
            break;


        case 2:
            system("cls");
            ReadInformation();
            break;


        case 3:
            system("cls");
            AddInformation();
            break;


        case 4:
            system("cls");
            break;


        case 5:
            system("cls");
            break;

        case 6:
            system("cls");
            break;

        case 7:
            system("cls");
            break;
        }
        if (s == 0)
            break;
    }
        getch();
        return 0;
}
//---------------------------------------------------------------------------

