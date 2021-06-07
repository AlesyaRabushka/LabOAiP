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



//индивидуальное задание удаляет все элементы от мин до макс
void Indiv2 (Stack** top)
{
    Stack* t = *top;
    Stack* p = NULL;
    while (t != NULL)
    {
        if (t->info % 2 != 0)
        {
            p = t;
            t = t->next;
        }
        else
        if (t->info % 2 == 0)
        {
            if (p == NULL)
            {
                Stack* d = t;
                *top = d->next;
                delete d;
                t = *top;
                p = t;
            }
            else
            {
                Stack* d = t;
                t = d->next;
                delete d;
                p->next = t;
            }
        }
        
    }

}
void Indiv4(Stack** top)
{
    Stack* t = *top;
    Stack* k = *top;
    Stack* p = *top;
    t = t->next;
    
    while (t->next != NULL)
    {
        k = t;
        t = t->next;
    }
    if (t->next == NULL)
    {
        t->next = (*top)->next;
        k->next = p;
        p->next = NULL;
    }
    *top = t;
}
void Indiv5(Stack** top)
{
    Stack* t = *top;
    Stack* p = NULL;
    while (t != NULL)
    {
        
        if (t->info % 5 == 0  && t->info % 2 != 0)
        {
            if (p == NULL)
            {
                Stack* l = t;
                t = t->next;
                *top = t;
                p = NULL;
                delete l;
            }
            else
            {
                Stack* l = t;
                t = t->next;
                p->next = t;
                delete l;
            }
        }
        
        else
        {
            p = t;
            t = t->next;
        }
    }
}
void Indiv6(Stack** top)
{
    Stack* q = *top;
    int max, min;
    max = q->info;
    while (q != NULL)
    {
        if (q->info > max) max = q->info;
        q = q->next;
    }

    q = *top;
    min = q->info;
    while (q != NULL)
    {
        if (q->info < min) min = q->info;
        q = q->next;
    }

    
    Stack* t = *top;
    bool find = 0;

    while (t != NULL)
    {
        if (t->info == min)
        {
            find = 0;
            break;
        }
        if (t->info == max)
        {
            find = 1;
            break;
        }
        t = t->next;
    }

    t = *top;
    
    if (find == 0)
    {
        Stack* p = NULL;
        Stack* m2 = NULL;
        Stack* n = NULL;
        Stack* m1 = NULL;
        Stack* l = NULL;

        while (t->info != min)
        {
            p = t;
            t = t->next;
       }
        if (t->info == min)
        {
            m1 = t;
            t = t->next;
            l = t;
        }
        while (t->info != max)
        {
            n = t;
            t = t->next;
        }
        if (t->info == max)
        {
            m2 = t;
            Stack* k = t;
            
            m1->next = k->next;
            if (p == NULL)
            {
                *top = m2;
            }
            else
            {
                p->next = m2;
            }
            m2->next = l;
            if (n == NULL)
            {
                l->next = m1;
            }
            else
            {
                n->next = m1;
            }
            t = k;
        }
    }
  
    if (find == 1)
    {
        Stack* p = NULL;
        Stack* m2 = NULL;
        Stack* n = NULL;
        Stack* m1 = NULL;
        Stack* l = NULL;
        while (t->info != max)
        {
            p = t;
            t = t->next;
        }
        if (t->info == max)
        {
            m1 = t;
            t = t->next;
            l = t;
        }
        while (t->info != min)
        {
            n = t;
            t = t->next;
        }
        if (t->info == min)
        {
            m2 = t;
            Stack* k = t;

            m1->next = k->next;
            if (p == NULL)
            {
                *top = m2;
            }
            else
            {
                p->next = m2;
            }
            m2->next = l;
            if (n == NULL)
            {
                l->next = m1;
            }
            else
            {
                n->next = m1;
            }
            t = k;
        }
        while (t != NULL) t = t->next;
    }
}
void Indiv8(Stack** top)
{
    Stack* t = *top;
    Stack* q = *top;
    int min = q->info;
    q = q->next;
    while (q != NULL)
    {
        if (q->info < min) min = q->info;
        q = q->next;
    }
    t = t->next;
    Stack* n = NULL;
    while (t->info != min)
    {
        Stack* k = t;
        k->info = t->info;
        k->next = n;
    }

    print(n);
}
void Indiv11(Stack** top)
{
    Stack* t = *top;
    double sum = 0, k = 0;
    double s = 0;

    while (t != NULL)
    {
        k++;
        sum += t->info;
        t = t->next;
    }
    s = sum / k;
    t = *top;
    t->info = s;
}
void Indiv13(Stack** top)
{
    int max = 0;
    Stack* t = *top;
    max = t->info;
    t = t->next;
    while (t != NULL)
    {
        
        if (t->info > max) max = t->info;
        t = t->next;
    }
    
    t = *top;
    Stack* l = NULL;
    while (t->info != max)
    {
        l = t;
        t = t->next;
    }
    if (t->info == max)
    {
        if (l == NULL)
        {
            *top = t->next;
        }
        else
        {
            Stack* d = t;
            t = t->next;
            l->next = t;
            delete d;
        }
    }
}
void Indiv16(Stack** top)
{
    Stack* t = *top;
    double sum = 0, k = 0;
    double s = 0;

    while (t != NULL)
    {
        k++;
        sum += t->info;
        t = t->next;
    }
    s = sum / k;
   
    t = *top;
    while (t != NULL)
    {
        if (t->info % 2 == 0)
        {
            t->info = s;
        }
        t = t->next;
    }
}
void Indiv0(Stack** top)
{
    Stack* t = *top;

    while (t != NULL)
    {
        t->info = 1;
        t = t->next;
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
            Indiv0(&top);
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
