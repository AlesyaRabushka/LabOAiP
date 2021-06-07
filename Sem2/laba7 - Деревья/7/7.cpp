#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;
int kol;

struct Tree
{
	int info;
	string name;
	Tree* left = NULL;
	Tree* right = NULL;
}*root;

//копирование элементов дерева в массив
void Copy(Tree* root, Tree* sort, int& k)
{
	if (root != NULL)
	{
		sort[k] = *root;
		k++;
		Copy(root->left, sort, k);
		Copy(root->right, sort, k);
	}
}
//построение сбалансированного дерева
void Add(int, string);
void MakeBalance(Tree** root, int n, int k, Tree* sort)
{
	if (n == k)
		return;
	else
	{
		int m = (n + k) / 2;
		Add(sort[m].info, sort[m].name);
		MakeBalance(&(*root)->left, n, m, sort);
		MakeBalance(&(*root)->right, m + 1, k, sort);
	}
}

//добавление листиков
Tree* AddList(int key, string name)
{
	Tree* t = new Tree;
	t->info = key;
	t->name = name;
	t->left = t->right = NULL;
	return t;
}
void Add(int key, string name)
{
	kol++;
	Tree* t = root;
	Tree* t_prev = root;
	if (root == NULL)
	{
		root = AddList(key, name);
	}
	else
	{
		while (t != NULL)
		{
			t_prev = t;
			if (t->info == key)
			{
				kol--;
				cout << "\t" << "Такой элемент уже существует!" << endl;
				return;
			}
			if (key < t->info)
			{
				t = t->left;
			}
			else t = t->right;
		}
		if (key < t_prev->info)
		{
			t_prev->left = AddList(key, name);
		}
		else
		{
			t_prev->right = AddList(key, name);
		}
	}
}
void Add1()
{
	cout << "\t" << "Введите количество записей:" << endl;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int key1;
		string name1 = "";
		cout << "\t" << "Введите наименование:" << endl;
		cin.ignore(100, '\n');
		getline(cin, name1);
		cout << "\t" << "Введите количество:" << endl;
		cin >> key1;
		Add(key1, name1);
	}

}

//вывод деревца на экран
void Print(Tree* root, int level)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		if (root != NULL)
		{
			Print(root->right, level + 1);
			for (int i = 0; i < level; i++)
			{
				cout << "  ";
			}
			cout << root->info << endl;
			Print(root->left, level + 1);
			return;
		}
	}
}

// удаление дерева
void Delete(Tree** root)
{
	if (*root != NULL)
	{
		Delete(&(*root)->left);
		Delete(&(*root)->right);
		delete* root;
		*root = NULL;
	}
}

// удаление элемента дерева
void Del(Tree* root, int key)
{
	Tree* t = root, * prev_t = NULL, * new_t, * prev_new_t;
	while (t != NULL && t->info != key)
	{
		prev_t = t;
		if (t->info > key) t = t->left;
		else t = t->right;
	}
	if (t == NULL)
	{
		cout << "\t" << "Нет такого элемента!" << endl;
	}

	if (t->right == NULL) new_t = t->left;
	if (t->left == NULL) new_t = t->right;
	else
	{
		prev_new_t = t;
		new_t = t->left;
		while (new_t->right != NULL)
		{
			prev_new_t = new_t;
			new_t = new_t->right;
		}

		if (prev_new_t == t) new_t->right = t->right;
		else
		{
			new_t->right = t->right;
			prev_new_t->right = new_t->left;
			new_t->left = prev_new_t;
		}
	}
	if (t == root) root = new_t;
	else
	{
		if (t->info < prev_t->info) prev_t->left = new_t;
		else prev_t->right = new_t;
	}
	delete t;
}

//поиск по ключу
void Search(Tree* root, int key)
{
	Tree* t = root;
	while (t)
	{
		if (t->info == key)
		{
			cout << "\t" << "Наименование: " << endl << "\t" << t->name << endl;
			cout << "\t" << "Количество: " << endl << "\t" << t->info << endl;
			cout << endl;
			break;
		}
		else
		{
			if (key < t->info && t->left != NULL)
			{
				t = t->left;
			}
			if (key < t->info && t->left == NULL)
			{
				cout << "\t" << "Нет такого элемента!" << endl;
				cout << endl;
				break;
			}

			if (key > t->info && t->right != NULL)
			{
				t = t->right;
			}
			if (key > t->info && t->right == NULL)
			{
				cout << "\t" << "Нет такого элемента!" << endl;
				cout << endl;
				break;
			}
		}
	}


}

//индивидуальное
int Indiv(Tree* root)
{
	int kol = 0;
	if (root == NULL) return 0;
	if ((root->left == NULL && root->right != NULL) || (root->right == NULL && root->left != NULL))
	{
		kol = 1;
	}
	return kol + Indiv(root->left) + Indiv(root->right);
}

//вывод прямой обход
void PrintP(Tree* root)
{
	Tree* t = root;
	if (t)
	{
		cout << "\t" << "Наименование:" << endl;
		cout << "\t" << t->name << endl;
		cout << "\t" << "Количество:" << endl;
		cout << "\t" << t->info << endl;
		cout << "\t" << "-------------" << endl;
		PrintP(t->left);
		PrintP(t->right);
	}
}

//вывод обратный обход
void PrintO(Tree* root)
{
	Tree* t = root;
	if (t)
	{
		PrintO(t->left);
		PrintO(t->right);
		cout << "\t" << "Наименование:" << endl;
		cout << "\t" << t->name << endl;
		cout << "\t" << "Количество:" << endl;
		cout << "\t" << t->info << endl;
		cout << "\t" << "-------------" << endl;
		return;
	}
}

//вывод по возрастанию ключа
void Sort(Tree* sort)
{
	for (int i = 0; i < kol; i++)
	{
		cout << "\t" << "Наименование:" << endl;
		cout << "\t" << sort[i].name << endl;
		cout << "\t" << "Количество:" << endl;
		cout << "\t" << sort[i].info << endl;
		cout << "\t" << "-------------" << endl;
	}
	delete[] sort;
}
void PrintV(Tree* root)
{
	Tree* sort = new Tree[kol];
	int k = 0;
	Copy(root, sort, k);
	for (int i = 0; i < kol; i++)
	{
		for (int j = i + 1; j < kol; j++)
		{
			if (sort[i].info > sort[j].info)
			{
				swap(sort[i].info, sort[j].info);
			}
		}
	}
	Sort(sort);
}


int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (true)
	{
		cout << "\t" << "Выберите действие:" << endl;
		cout << "\t" << "1 - Создать запись" << endl;
		cout << "\t" << "2 - Вывести дерево" << endl;
		cout << "\t" << "3 - Добавить записи" << endl;
		cout << "\t" << "4 - Удалить узел" << endl;
		cout << "\t" << "5 - Удалить дерево" << endl;
		cout << "\t" << "6 - Найти информацию по ключу" << endl;
		cout << "\t" << "7 - Индивидуальное задание" << endl;
		cout << "\t" << "8 - Сбалансировать дерево" << endl;
		cout << "\t" << "9 - Вывод на экран: Прямой обход" << endl;
		cout << "\t" << "10 - Вывод на экран: Обратный обход" << endl;
		cout << "\t" << "11 - Вывод на экран: По возрастанию ключа" << endl;
		cout << "\t" << "0 - Выход" << endl;
		int s;
		cin >> s;

		switch (s)
		{
		case 1: //создаём 
			system("cls");
			Add1();
			break;

		case 2: //вывод дерева на экран
			system("cls");
			Print(root, 0);
			break;

		case 3: //добавление листа
			system("cls");
			Add1();
			break;

		case 4: //удаление элемента по ключу
			system("cls");
			int key4;
			cout << "\t" << "Введите ключ для удаления:" << endl;
			cin >> key4;
			Del(root, key4);
			break;

		case 5://удаление дерева
			system("cls");
			Delete(&root);
			cout << "\t" << "Дерево удалено!" << endl;
			cout << endl;
			break;

		case 6: //поиск информации по ключу
			system("cls");
			cout << "\t" << "Введите ключ для поиска:" << endl;
			int key6;
			cin >> key6;
			Search(root, key6);
			break;

		case 7://индивидуальное задание
			system("cls");
			cout << "\t" << "Количество узлов с одним потомком:" << endl;
			cout << "\t" << Indiv(root) << endl;
			break;

		case 9://прямой обход
			system("cls");
			PrintP(root);
			break;

		case 10://обратный обход
			system("cls");
			PrintO(root);
			break;

		case 11://обход по возрастанию ключа
			system("cls");
			PrintV(root);
			break;

		case 8://сбалансировать дерево
			system("cls");
			Tree* sort = new Tree[kol];
			int amount = kol;
			int k = 0;

			Copy(root, sort, k);
			for (int i = 0; i < amount; i++)
			{
				for (int j = i + 1; j < amount; j++)
				{
					if (sort[i].info > sort[j].info)
					{
						swap(sort[i].info, sort[j].info);
					}
				}
			}

			Delete(&root);
			kol = 0;
			MakeBalance(&root, 0, amount, sort);
			delete[] sort;
			break;
		}
		if (s == 0)
		{
			break;
		}
	}

	return 0;
}