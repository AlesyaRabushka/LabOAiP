#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

//функция
double fun(double x)
{
	return pow(x, 3)+10*pow(x,2)-50;
}
//производная
double proiz(double x)
{
	return 3 * pow(x, 2) + 20*x;
}

//деление пополам
double Del_2(double x0, double x1, double ex)
{
	double x2, y2, y0;

	while (fabs(x1 - x0) < ex)
	{
		x2 = (x0 + x1) / 2;
		y2 = fun(x2);
		if (fun(x0) * fun(x2) > 0)
		{
			x0 = x2;
			y0 = y2;
		}
		else x1 = x2;
	}
	return (x0 + x1) / 2;
}

//метод простых итераций
double Iter(double x0, double k, double ex)
{
	double x = 0;
	
	while(fabs(x - x0) > ex)
	{
		x = x0 + k * fun(x0);
		if (fabs(x - x0) < ex)
		{
			break;
		}
		x0 = x;
	}
	return x;
}

//метод Ньютона
double Newton(double x0, double ex)
{
	double x = 0;

	while (fabs(x - x0) > ex)
	{
		x = x0 - fun(x0) / proiz(x0);
		if (fabs(x - x0) < ex)
		{
			break;
		}
		x0 = x;
	}
	return x;
}

//метод секущих
double Sek(double x0, double ex, double q)
{
	double x = 0;

	while (fabs(x - x0) > ex)
	{
		x = x0 - q * fun(x0) / (fun(x0) - fun(x0 - q));
		if (fabs(x - x0) < ex)
		{
			break;
		}
		x0 = x;
	}
	return x;
}

//метод Вегстейна
double Veg(double x0, double x1, double ex)
{
	double x2 = x0, y0, y1,d;
	y0 = fun(x0);
	y1 = fun(x1);

	do
	{
		x2 = x1 - y1 * (x1 - x0)/(y1 - y0);
		d = fabs(x1 - x2);
		x0 = x1;
		x1 = x2;
		y0 = y1;
		y1 = fun(x2);
	} while (d > ex);
	return x2;
}


int main()
{
	setlocale(LC_ALL, "rus");

	int a, b, s;
	double h, ex, x;
			system("cls");
			cout << "Введите начало отрезка: ";
			cin >> a;
			cout << "Введите конец отрезка: ";
			cin >> b;
			cout << "Введите шаг: ";
			cin >> h;
			cout << "Введите точность: ";
			cin >> ex;

			system("cls");

			cout << "\t" << "Данные:" << endl;
			cout << "\t" << "Отрезок: " << "[" << a << ", " << b << "]" << endl;
			cout << "\t" << "Шаг: " << h << endl;
			cout << "\t" << "Точность: " << ex << endl;
			cout << "\t" << "-----------------------" << endl;

			cout << "\t" << "Метод Вегстейна:" << endl;
			cout << endl;
			int find4 = 0;

			for (x = a; x <= b; x += h)
			{
				if (fun(x) * fun(x + h) < 0)
				{
					find4++;
					//cout << "\t" << "Корень №" << find4 << " = " << Veg(x, x + h, ex) <<  endl;
					cout << "\t" << "Корень №" << find4 << " = " << Veg(x, x + h, ex) << "\t" << "Функция = " << fun(Veg(x, x + h, ex)) << endl;
				}
			}
			if (find4 == 0) cout << "\t" << "На заданном отрезке нет корней!" << endl;
			cout << endl;

	return 0;
}