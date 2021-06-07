#include <windows.h>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>

using namespace std;


struct Shop {
    string name;
    int amount;
    int number;
};


//1 - создание
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
            cout << "   Наименование:" << endl;
            cin.ignore(100, '\n');
            getline(cin, sh[i].name);
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
    delete[] sh;
}

// 2 - просмотр
void ReadInformation()
{
    ifstream reading("zapici.txt");
    int n;
    

    reading >> n;
    if (reading)
    {
        Shop *sh = new Shop[n];
        cout << "       Информация:" << endl;
        for (int i = 0; i < n; i++)
        {
            reading.ignore(100, '\n');

            cout << "   Наименовние: ";
            getline(reading, sh[i].name);
            cout << sh[i].name << endl;

            cout << "   Количество: ";
            reading >> sh[i].amount;
            cout << sh[i].amount << endl;

            cout << "   Номер цеха: ";
            reading >> sh[i].number;
            cout << sh[i].number << endl;

            cout << "   ---------------" << endl;
        }
        delete[] sh;
    }
    reading.close();
}

// количество первоначальных записей
int Number()
{
    ifstream reading("zapici.txt");
    int num = 0;
    if (reading)
    {
        reading >> num;
    }
    reading.close();
    return num;
}

//3 - добавление
void AddInformation()
{
    cout << " Введите количество записей: " << endl;
    int n;
    cin >> n;
    int Num = Number();
    ifstream reading("zapici.txt");
    Shop* sh = new Shop[n + Num];
    if (reading)
    {
        for (int i = 0; i < Num; i++)
        {
            reading.ignore(100, '\n');
            getline(reading, sh[i].name);
            reading >> sh[i].amount;
            reading >> sh[i].number;
        }
    }
    reading.close();

    ofstream record("zapici.txt");
    if (record)
    {
        record << n + Num << endl;
        for (int i = 0; i < Num; i++)
        {
            record << sh[i].name << endl;
            record << sh[i].amount << endl;
            record << sh[i].number << endl;
        }
        for (int i = Num; i < n + Num; i++)
        {
            cout << "   Наименование:" << endl;
            cin.ignore(100, '\n');
            getline(cin, sh[i].name);
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
    delete[] sh;
}

//4 - сортировка прямым выбором
void Search1()
{
    ifstream reading("zapici.txt");
    ofstream record("search1.txt");
    ofstream Nom("nom.txt");
    int n, k;
    cout << "   Введите номер интересующего вас цеха:" << endl;
    cin >> k;

    if (reading)
    {
        if (record)
        {
            reading >> n;
            Shop* sh = new Shop[n];
            int nom = 0;

            for (int i = 0; i < n; i++)
            {
                reading.ignore(100, '\n');
                getline(reading, sh[i].name);
                reading >> sh[i].amount;
                reading >> sh[i].number;

                if (sh[i].number == k)
                {
                    nom += 1;
                    record << sh[i].name << endl;
                    record << sh[i].amount << endl;
                    record << sh[i].number << endl;
                }
            }
            Nom << nom;
            delete[] sh;
        }
    }
    reading.close();
    record.close();
    Nom.close();

}
void Sort1()
{
    ifstream reading("search1.txt");
    ifstream read("zapici.txt");
    ifstream nom("nom.txt");
    int n;

    if (read)
    {
        if (reading)
        {
            if (nom)
            {
                nom >> n;

                Shop* sh = new Shop[n];
                cout << "       Информация: " << endl;

                for (int i = 0; i < n; i++)
                {

                    getline(reading, sh[i].name);
                    reading >> sh[i].amount;
                    reading >> sh[i].number;
                    reading.ignore(100, '\n');
                }

                for (int i = 0; i < n - 1; i++)
                    for (int j = i + 1; j < n; j++)
                        if (sh[j].amount > sh[i].amount)
                            swap(sh[i], sh[j]);

                for (int i = 0; i < n; i++)
                {
                    cout << "   Наименование: " << sh[i].name << endl;
                    cout << "   Количество: " << sh[i].amount << endl;
                    cout << "   Номер цеха: " << sh[i].number << endl;
                    cout << "   ----------------------" << endl;
                }
                delete[] sh;
            }
        }
    }

    read.close();
    nom.close();
    reading.close();

}

//5 - QuickSort
void Search2()
{
    ifstream reading("zapici.txt");
    ofstream record("search2.txt");
    ofstream Nom("nom2.txt");
    int n, k;
    cout << "   Введите номер интересующего вас цеха:" << endl;
    cin >> k;

    if (reading)
    {
        if (record)
        {
            reading >> n;
            Shop* sh = new Shop[n];
            int nom = 0;

            for (int i = 0; i < n; i++)
            {
                reading.ignore(100, '\n');
                getline(reading, sh[i].name);
                reading >> sh[i].amount;
                reading >> sh[i].number;

                if (sh[i].number == k)
                {
                    nom += 1;
                    record << sh[i].name << endl;
                    record << sh[i].amount << endl;
                    record << sh[i].number << endl;
                }
            }
            Nom << nom;
            delete[] sh;
        }
    }
    reading.close();
    record.close();
    Nom.close();

}
/*void Sort2(Shop* sh, int begin, int end)
{
    int left, right, x;
    left = begin;
    right = end;
    x = sh[(left + right) / 2].amount;

        while (sh[left].amount > x)  left++;
        while (x > sh[right].amount) right--;
        if (left <= right)
        {
            swap(sh[left], sh[right]);
            left++;
            right--;
        }
        
    if (begin < right) Sort2(sh, begin, right);
    if (left < end) Sort2(sh, left, end);
}*/
void Sort2(Shop* sh, int begin, int end)
{
    int left = 0, right = 0;
    int x;
    left = begin;
    right = end;
    x = sh[(left + right) / 2].amount;

    while (left <= right)
    {

        while (sh[left].amount > x) left++;
        while (sh[right].amount < x) right--;

        if (left <= right)
        {
            swap(sh[left], sh[right]);
            left++;
            right--;
        }
    }

    if (begin < right) Sort2(sh, begin, right);
    if (left < end) Sort2(sh, left, end);
    
}

//двоичный поиск с цехом
void Search3()
{
    Search2();

    ifstream reading("search2.txt");
    ifstream nom2("nom2.txt");
    int n = 0;
    if (nom2)
    {
        nom2 >> n;
    }
    if (reading)
    {

        Shop* sh = new Shop[n];

        for (int i = 0; i < n; i++)
        {
            getline(reading, sh[i].name);
            reading >> sh[i].amount;
            reading >> sh[i].number;
            reading.ignore(100, '\n');
        }

        Sort2(sh, 0, n - 1);

        //двоичный поиск
        cout << "   Введите количество изделий:" << endl;
        int key, k = 0; 
        cin >> key;
        int begin = 0, right = n - 1;
        int m;

        cout << "     Информация:" << endl;

        while (begin < right)
        {
            m = (begin + right) / 2;
            if (sh[m].amount > key) begin = m + 1;
            else right = m;
        }
        if (sh[begin].amount != key)
        {
            cout << "   Товар не найден!" << endl;
            cout << endl;
        }
        else 
        {
            cout << "   Наименование: " << sh[begin].name << endl;
            cout << "   Количество: " << sh[begin].amount << endl;
            cout << "   Номер цеха: " << sh[begin].number << endl;
            cout << "   ----------------------" << endl;
        }
        delete[] sh;
    }
    nom2.close();
    reading.close();
}



int main()
{

    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    

    while (true)
    {
        int s;
        cout << "      Выберите действие:" << endl;
        cout << "       Создать - 1" << endl << "       Просмотр - 2" << endl
            << "       Добавить - 3" << endl << "       Прямой выбор - 4" << endl
            << "       Двоичный поиск - 5" << endl << "       QuickSort - 6" << endl 
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
            Search1();
            Sort1();
            break;

        case 5:
            system("cls");
            Search3();
            break;

        case 6:
            system("cls");
            Search2();

            ifstream reading("search2.txt");
            ifstream nom2("nom2.txt");
            int n5;
            if (nom2)
            {
                nom2 >> n5;
            }
            if (reading)
            {

                    Shop* sh = new Shop[n5];
                    cout << "       Информация: " << endl;

                    for (int i = 0; i < n5; i++)
                    {

                        getline(reading, sh[i].name);
                        reading >> sh[i].amount;
                        reading >> sh[i].number;
                        reading.ignore(100, '\n');
                    }

                    Sort2(sh, 0, n5 - 1);

                    for (int i = 0; i < n5; i++)
                    {
                        cout << "   Наименование: " << sh[i].name << endl;
                        cout << "   Количество: " << sh[i].amount << endl;
                        cout << "   Номер цеха: " << sh[i].number << endl;
                        cout << "   ----------------------" << endl;
                    }
                    delete[] sh;
            }
            nom2.close();
            reading.close();
            break;

        }

        if (s == 0)
            break;
    }

    return 0;
}