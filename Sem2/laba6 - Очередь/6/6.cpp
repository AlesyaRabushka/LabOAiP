#include <iostream>

using namespace std;

struct List
{
    int info;
    List* prev;
    List* next;
};

//создаем первый элемент
void Create(List** begin, List** end,  int val)
{
    List* t = new List;
    t->info = val;
    t->prev = NULL;
    t->next = NULL;
    *begin = t;
    *end = t;
}

//добавляем элементы
void AddE(List** end, int e)
{
    List* t = new List;
    t->info = e;
    t->next = NULL;
    t->prev = *end;
    (*end)->next = t;
    *end = t;
}
void AddB(List** begin, int vall)
{
    List* q = new List;
    q->info = vall;
    q->next = *begin;
    q->prev = NULL;
    (*begin)->prev = q;
    *begin = q;
}

//вывод элементов на экран
void PrintB(List* begin)
{
    List* q = begin;
    cout << "\t";
    while (q != NULL)
    {
        cout << q->info << " ";
        q = q->next;
    }
    cout << endl;
}
void PrintE(List* end)
{
    List* q = end;
    cout << "\t";
    while (q != NULL)
    {
        cout << q->info << " ";
        q = q->prev;
    }
    cout << endl;
}

//ищем мин и макс
int Mini(List* begin)
{
    List* q = begin;
    int min;
    min = q->info;
    q = q->next;
    while (q != NULL)
    {
        if (q->info < min)
        {
            min = q->info;
        }
        q = q->next;
    }
    return min;
}
int Maxi(List* begin)
{
    List* q = begin;
    int max;
    max = q->info;
    q = q->next;
    while (q != NULL)
    {
        if (q->info > max)
        {
            max = q->info;
        }
        q = q->next;
    }
    return max;
}

//индивидуальное задание
void Indiv(List** begin, List** end)
{
    int min, max;
    min = Mini(*begin);
    max = Maxi(*begin);
    int first = 0, k;
    List* q = *begin;
    List* b = *begin;
    List* e = *end;
    
    
    //ищем, что стоит первым
    while (q != NULL)
    {
        if (q->info == min)
        {
            first = 1;
            break;
        }
        if (q->info == max)
        {
            first = 2;
            break;
        }
        q = q->next;
    }

    //если первый min
    if (first == 1) 
    {
        q = *begin;
        int k = 0;
        List* p = NULL;
        while (q->info != min)
        {
            p = q;
            q = q->next;
        }
        if (q->info == min)
        {
            q->prev = p;
            p = q;
            q = q->next;
        }
        while (q->info != max)
        {
            k++;
            List* l = q;
            q = q->next;
            delete l;
        }
        if (q->info == max)
        {
            q->prev = p;
            p->next = q;
            p = q;
            q = q->next;
        }
        while (q != NULL)
        {
            q = q->next;
        }
        cout << "\t" << "Количество удаленных элементов: " << k << endl;
    }
 
    //если первый max
    if (first == 2) 
    {
        q = *begin;
        int k = 0;
        List* p = NULL;
        while (q->info != max)
        {
            p = q;
            q = q->next;
        }
        if (q->info == max)
        {
            q->prev = p;
            p = q;
            q = q->next;
        }
        while (q->info != min)
        {
            k++;
            List* l = q;
            q = q->next;
            delete l;
        }
        if (q->info == min)
        {
            q->prev = p;
            p->next = q;
            p = q;
            q = q->next;
        }
        while (q != NULL)
        {
            q = q->next;
        }
        cout << "\t" << "Количество удаленных элементов: " << k << endl;
    }

}

//удаление
void Delete(List** begin, List** end)
{
    List* q = *begin;
    while (*begin != NULL)
    {
        List* l = *begin;
        *begin = (*begin)->next;
        delete l;
    }
    *end = NULL;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    List* begin = NULL;
    List* end = NULL;
    int s;

    while (true)
    {
        cout << "\t" << "Выберите действие:" << endl;
        cout << "\t" << "1 - Создать список" << endl;
        cout << "\t" << "2 - Просмотр с начала" << endl;
        cout << "\t" << "3 - Просмотр с конца" << endl;
        cout << "\t" << "4 - Добавить в начало" << endl;
        cout << "\t" << "5 - Добавить в конец" << endl;
        cout << "\t" << "6 - Удалить список" << endl;
        cout << "\t" << "7 - Индивидуальное задание" << endl;
        cout << "\t" << "0 - Выход" << endl;
        cin >> s;

        switch (s)
        {
        case 1: //создание
            system("cls");
            int a[20];
            int n;
            cout << "\t" << "Введите размеры списка:" << endl;
            cin >> n;
            int p;
            //cout << "\t" << "Элементы списка:" << endl;
            p = rand() % 40 - 20;
            //cin >> p;
            Create(&begin, &end, p);
            for (int i = 0; i < n-1; i++)
            {
               // cin >> a[i];
                a[i] = rand() % 40 - 20;
                AddE(&end, a[i]);
            }
            break;

        case 2: //просмотр с начала
            system("cls");
            if (begin == NULL)
            {
                cout << "\t" << "Нет элементов!" << endl;
                cout << endl;
            }
            else
            {
                cout << "\t" << "Список:" << endl;
                PrintB(begin);
            }
            break;

        case 3: //просмотр с конца
            system("cls");
            if (end == NULL)
            {
                cout << "\t" << "Нет элементов!" << endl;
                cout << endl;
            }
            else
            {
                cout << "\t" << "Список:" << endl;
                PrintE(end);
            }
            break;

        case 4: //добавление в начало
            system("cls");
            int b[20];
            int m;
            if (begin == NULL)
            {
                cout << "\t" << "Нет элементов!" << endl;
                cout << endl;
            }
            else
            {
                cout << "\t" << "Введите количество элементов:" << endl;
                cin >> m;
                //cout << "\t" << "Введите элементы:" << endl;
                for (int i = 0; i < m; i++)
                {
                    //cin >> b[i];
                    b[i] = rand() % 40 - 20;
                    AddB(&begin, b[i]);
                }
            }
            break;

        case 5: //добавление в конец
            system("cls");
            int e[20];
            int l;
            if (end == NULL)
            {
                cout << "\t" << "Нет элементов!" << endl;
                cout << endl;
            }
            else
            {
                cout << "\t" << "Введите количество элементов:" << endl;
                cin >> l;
                //cout << "\t" << "Введите элементы:" << endl;
                for (int i = 0; i < l; i++)
                {
                    //cin >> e[i];
                    e[i] = rand() % 40 - 20;
                    AddE(&end, e[i]);
                }
            }
            break;

        case 6: //удаление
            system("cls");
            Delete(&begin, &end);
            break;

        case 7:
            system("cls");
           // cout << Mini(begin) << endl;
           // cout << Maxi(begin) << endl;
            Indiv(&begin, &end);
            break;
        }
        if (s == 0)
        {
            Delete(&begin, &end);
            break;
        }
    }
}
