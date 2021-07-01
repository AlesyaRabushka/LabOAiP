#include <iostream>;

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int n, m;
	cout << "Введите количество строк:" << endl;
	cin >> n;
	cout << "Введите количество столбцов:" << endl;
	cin >> m;

	int** Mas;
	Mas = new int* [n];
	for (int i = 0; i < n; i++)
	{
		Mas[i] = new int[m];
	}

	cout << "Введите элементы матрицы:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> Mas[i][j];
		}
	}

	
//---------------------------------
	int max = 0;
	int* mas = new int[n];
	for (int i = 0; i < n; i++)
	{
		max = Mas[i][0];
		for (int j = 1; j < m; j++)
		{
			if (Mas[i][j] > max) 
			{
				max = Mas[i][j];
			}
		}
		mas[i] = max;
	}

	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (mas[i] > mas[j]) swap(Mas[i], Mas[j]);
		}
	}
//--------------------------------
	cout << "Матрица: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << Mas[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}