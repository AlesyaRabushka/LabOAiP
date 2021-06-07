#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;

struct Stack
{
    int info;
    Stack* next;
};

//создание
void create(Stack** top, int k) //принимает указатель на вершину и добвляемый элемент
{
    Stack* q; //наш новый элемент
    q = new Stack(); //выделяем память
    q -> info = k; //-> значит, что мы записываем число в info
    if (top == NULL) //если след вершины нет, то есть это первый элемент стека
    {
        *top = q; //вершиной стека будет новый элемент
    }
    else //если стек не пустой
    {
        q->next = *top; //проводим связь от нового элемента к вершине, кладем книгу на вершину стопки
                       //заносим указатель на вершину
        *top = q; //обозначаем, что вершиной является новый элемент
    }
}

//добавление
void Add(Stack** top, int l)
{
    Stack* p = new Stack();
    p->info = l;
    p->next = *top;
    *top = p;
}

//удаление
void Delete(Stack** top) //принимает вершину и значение для удаления
{
    while (*top != NULL)
    {
        Stack* p = *top;
        *top = (*top)->next;
        delete p;
    }
}  
//указатель на указатель потому что если бы мы ввели в функцию только указатель на вершину,
//то «Стек» создавался и изменялся только внутри функции, в главной функции вершина бы как была,
//так и оставалась NULL. Передавая указатель на указатель мы изменяем вершину *top в главной функции.

//поиск максимального и минимального
int Maxi(Stack* top)
{
    Stack* q = top;
    int max;
    max = (top)->info;
    while (top = top->next)
    {
        if (top->info > max) max = top->info;
    }
    return max;
}
int Mini(Stack* top)
{
    Stack* q = top;
    int min;
    min = (top)->info;
    while (top = top->next)
    {
        if (top->info < min) min = top->info;
    }
    return min;
}
//вывод элементов стека
void print(Stack* top) //указатель на вершину стека
{
    Stack* q = top; //устанавливаем указатель на вершину
    while (q != NULL) // пока q не пустой, то есть пока не конец списка
    {
        cout << q->info << " ";
        q = q->next; //передвигаем указатель на след элемент
    }
    cout << endl;
}

//сортировка 1 РАБОТАЕТ! но не сортирует первый элемент, только с 2мя функциями
void Add1(Stack** top, int l)
{
    Stack* t = new Stack();
    t->info = l;
    t->next = *top;
    *top = t;
}
void Delete1(Stack** top)
{
    Stack* t = *top;

    *top = t->next;
    delete t;
}
void Sort1(Stack** top)
{
        Stack* t = NULL, * t1, * r;
        if ((*top)->next->next == NULL) return; //так много некстов потому, что первый элемент не сортируется
        while ((*top)->next->next != t)
        {
            for (t1 = *top; t1->next->next != t; t1 = t1->next)
                if (t1->next->info > t1->next->next->info) {
                    r = t1->next->next;
                    t1->next->next = r->next;
                    r->next = t1->next;
                    t1->next = r;
                }
            t = t1->next;
        }
}


//сортировка 2 РАБОТАЕТ!
void Sort2(Stack* top)
{
    if (top == NULL)
    {
        cout << "\t" << "Нет элементов!" << endl;
    }
    else
    {
        Stack* t = NULL;
        Stack* t1;
        int m;
        while (top->next != t)
        {
            for (t1 = top; t1->next != t; t1 = t1->next)
            {
                if (t1->info > t1->next->info)
                {
                    m = t1->info;
                    t1->info = t1->next->info;
                    t1->next->info = m;
                }

            }
            t = t1;
        }
    }
}

//индивидуальное задание удаляет все элементы от мин до макс
void Indiv4(Stack** top)
{

    if (*top == NULL)
    {
        cout << "\t" << "Нет элементов!" << endl;
    }
    else
    {
        int min, max, k;
        min = Mini(*top);
        max = Maxi(*top);
        bool first = 0;
        Stack* q = *top;
        Stack* p = NULL;


        while (q != NULL)
        {
            if (q->info == min)
            {
                first = 1;
                break;
            }
            if (q->info == max)
            {
                first = 0;
                break;
            }
            q = q->next;
        }


        q = *top;
        if (first == 1)
        {
            k = 0;
            while (q->info != min)
            {
                q = q->next;
            }
            if (q->info == min)
            {
                p = q;
                q = q->next;
            }
            while (q->info != max)
            {
                k++;
                Stack* l = q;
                q = l->next;
                delete l;
                p->next = q;
            }
            if (q->info == max)
            {
                q = q->next;
            }
            while (q != NULL)
            {
                q = q->next;
            }
        }
        if (first == 0)
        {
            q = *top;
            k = 0;
            while (q->info != max)
            {
                q = q->next;
            }
            if (q->info == max)
            {
                p = q;
                q = q->next;
            }
            while (q->info != min)
            {
                k++;
                Stack* l = q;
                q = l->next;
                delete l;
                p->next = q;
            }
            if (q->info == min)
            {
                q = q->next;
            }
            while (q != NULL)
            {
                q = q->next;
            }
        }

        cout << '\t' << "Количество удаленных элементов: " << k << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    Stack* top = NULL;
    int a[100];
    int n, k = 0;
    while (true)
    {
        cout << "   Выберите действие:" << endl;
        cout << "   1 - Создание нового списка" << endl << "   2 - Просмотр" << endl << "   3 - Добавление элемента" << endl << "   4 - Удаление" << endl;
        cout << "   5 - Решение индивидуального задания" << endl << "   6 - Сортировка перестановкой соседних элементов" << endl
            << "   7 - Сортировка перестановкой информации соседних элементов" << endl;
        cout << "   0 - Выход" << endl;
        int s;
        cin >> s;
        switch (s)
        {
        case 1: //создание  РАБОТАЕТ
            system("cls");
            if (top != NULL)
            {
                cout << "   Требуется отчистка памяти!" << endl;
                break;
            }
            cout << "Размер списка: " << endl;
            cin >> n;
            //cout << "Элементы:" << endl;
            for (int i = 0; i < n; i++)
            {
                k++;
               // cin >> a[i];
                a[i] = rand() % 40 -20;
                create(&top, a[i]);
            }
            break;
            
        case 2: //вывод на экран  РАБОТАЕТ
            system("cls");
            if (top == NULL)
            {
                cout << "\t" << "Нет элементов!" << endl;
            }
            else
            {
                cout << "   Список:" << endl;
                print(top);
                cout << "" << endl;
            }
            break;

        case 3: //добавление РАБОТАЕТ
            system("cls");
            int l, ln;
            cout << "   Введите количество добавляемых элементов:" << endl;
            cin >> ln;
            for (int i = 0; i < ln; i++)
            {
                l = rand() % 40 - 20;
                Add(&top, l);
            }
            break;

        case 4:  //удаление стека РАБОТАЕТ
            system("cls");
            Delete(&top);
            cout << "   Стек удалён!" << endl;
            cout << "" << endl;
            break;

        case 5: //индивидуальное задание
            system("cls");
            Indiv4(&top);
            break;

        case 6: //сортировка перестановкой info
            system("cls");
            Sort2(top);
            break;

        case 7: //сортировка перестановкой элементов
            system("cls");
            if (top == NULL)
            {
                cout << "\t" << "Нет элементов!" << endl;
            }
            else
            {
                Add(&top, 5);
                Sort1(&top);
                Delete1(&top);
            }
            break;
        }
        if (s == 0)
        {
            Delete(&top);
            break;
        }
    }
    return 0;
}
