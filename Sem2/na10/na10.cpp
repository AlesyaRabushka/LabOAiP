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
    q->info = k; //-> значит, что мы записываем число в info
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




void Indiv6(Stack* top)
{
    Stack* q = top;
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



    Stack* t = top;
    Stack* p = NULL;

    while (t->info != max)
    {
        t = t->next;
    }
    if (t->info == max)
    {
        p = t;
        t = t->next;
    }
    if (t != NULL)
    {
        Stack* l = t;
        t = t->next;
        p->next = t;
        delete l;
    }
}
void Indiv7(Stack** top)
{
    Stack* q = *top;
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



    Stack* t = *top;
    Stack* f = *top;
    Stack* p = NULL;
    if (max == t->info)
    {
        cout << "\t" << "Нельзя переставить!" << endl;
        cout << endl;
    }
    else
    {
        *top = (*top)->next;
        while (t->info != max)
        {
            t = t->next;
        }
        if (t->info == max)
        {
            p = t;
            t = t->next;
        }
         p->next = f;
        f->next = t;
    }
}


int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    Stack* top = NULL;
    Stack* nech = NULL;
    Stack* ch = NULL;

    int a[100];
    int n, k = 0;
    while (true)
    {
        cout << "   Выберите действие:" << endl;
        cout << "   1 - Создание нового списка" << endl << "   2 - Просмотр" << endl << "   3 - Добавление элемента" << endl << "   4 - Удаление" << endl;
        cout << "   5 - Решение индивидуального задания" << endl;
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
            cout << "Элементы:" << endl;
            for (int i = 0; i < n; i++)
            {
                k++;
                cin >> a[i];
                //a[i] = rand() % 40 - 20;
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
            cout << "Элементы:" << endl;
            for (int i = 0; i < ln; i++)
            {
                cin >> l;
                //l = rand() % 40 - 20;
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
            Indiv7(&top);
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
