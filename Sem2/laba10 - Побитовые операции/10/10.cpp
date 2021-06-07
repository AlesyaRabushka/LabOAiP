#include <iostream>

using namespace std;

int AND(int a, int b)
{
	return a & b;
}

int OR(int a, int b)
{
	return a | b;
}

int XOR(int a, int b)
{
	return a ^ b;
}

int main()
{
	setlocale(LC_ALL, "rus");
	/*cout << "\t" << "Введите данные:" << endl;
	int a, b;
	cin >> a >> b;
	while (true)
	{


		cout << "\t" << "Выберите действие:" << endl;
		cout << "\t" << "1 - &" << endl;
		cout << "\t" << "2 - |" << endl;
		cout << "\t" << "3 - ^" << endl;
		int s;
		cin >> s;

		switch (s)
		{
		case 1:
			cout << AND(a, b) << endl;
			break;

		case 2:
			cout << OR(a, b) << endl;
			break;

			case 3:
			cout << XOR(a, b) << endl;
			break;
		}
	}*/
	//int b = (23 ^ (15 & 136)) | (74 & 8);
	int b = 15 >> 3 ^ 48 & 25 | 15 >> 4 ^ 3;
	cout << b << endl;
	return 0;
}