#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool digit(string s, int i)
{
	if (s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4') return true;
	else return false;
}

void main()
{
	setlocale(LC_ALL, "rus");

	cout << "Введите строку" << endl;
	string s;
	getline(cin, s);
	stack<int> stk;

	for (int i = 0; i < s.size(); i++)
	{
		if (digit(s, i))
		{
			stk.push(s[i]-48);
		}
	}
}