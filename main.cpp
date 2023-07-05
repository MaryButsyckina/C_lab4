#include <math.h>
#include <exception>
#include <iostream>
#include <fstream>

using std::ofstream;
using std::ios;
using std::ifstream;
using std::cout;

struct Btree //структура бинарного дерева
{
	int value; //значение ячейки
	Btree* left, * right; //ссылка на левую и правую ячейку. В левой хранится меньшее значение, в правой - большее
};

/*
* ф-ия вставки вершины в дерево
* первый аргумент - значение, ктр нужно вставить
* второй аргумент - указатель на дерево
* возвращает указатель на дерево
*/
Btree* Insert(int val, Btree* tree);
/*
* ф-ия, выводящая на консоль бинарное дерево
* Аргумент - указатель на дерево
* Ничего не возвращает
*/
void Print_Btree(Btree* q, int level = 0);
/*
* ф-ия, создающая бинарный файл и заполняющая его рандомными
* целыми числами. файл рандомной величины.
* аргумент - путь к файлу
* ничего не возвращает
*/
void CreateBiFile(const char* path);
/*
* ф-ия, читающая бинарный файл с целыми чаислами.
* выводит числа на консоль.
* аргумент - путь к файлу.
* ничего не возвращает
*/
void ReadBiFile(const char* path);
/*
* ф-ия, сортирующая бинарный файл с целыми числами
* на положительные и отрицательные.
* аргумент - путь к файлу.
* возвращает указатель на массив из двух бинарных деревьев:
* первое из них содержит положительные числа, второе - отрицательные.
*/
void SortBiFile(const char* path, Btree* &pos, Btree* &neg);

int main()
{
	const char* path = "test.bin";
	CreateBiFile(path);
	ReadBiFile(path);

	Btree* positive = nullptr, *negative = nullptr;
	SortBiFile(path, positive, negative);

	Print_Btree(positive);
	Print_Btree(negative);
}

Btree* Insert(int val, Btree* tree)
{
	if (tree == nullptr)
	{
		tree = new Btree();
		tree->value = val;
		tree->left = nullptr;
		tree->right = nullptr;
	}
	else
	{
		if (val < tree->value) tree->left = Insert(val, tree->left);
		else if (val > tree->value) tree->right = Insert(val, tree->right);
	}
	return tree;
}
void Print_Btree(Btree* p, int level)
{
	if (p)
	{
		Print_Btree(p->left, level + 1);
		for (int i = 0;i < level;i++) cout << "   ";
		cout << p->value << std::endl;
		Print_Btree(p->right, level + 1);
	}
}
void CreateBiFile(const char* path)
{
	ofstream fout(path, ios::binary); //открываем или создаем файл
	int len = rand() % 50; //рандомная величина файлв
	for (int i = 0; i < len; i++)
	{
		int num = rand() % 1000 - 500; //рандомное значение
		fout.write((char*)(&num), sizeof(int)); //записываем его в файл
	}
	fout.close(); //закрываем файл
}
void ReadBiFile(const char* path)
{
	if (!path[0]) throw std::invalid_argument("Empty name"); //если имя пустое - ошибка
	ifstream fout(path, ios::binary); //открываем файл
	if (!fout) throw std::invalid_argument("No such file exist"); //если файл не открылся - ошибка
	while (1) //читаем файл, пока не дойдем до конца
	{
		int tmp;
		fout.read((char*)(&tmp), sizeof(int)); //чтение одного чисда
		if (fout.eof()) break; //если конец файла - выходим из цикла
		cout << tmp << "; "; //выводим на консоль
	}
	cout << std::endl;
	fout.close();
}
void SortBiFile(const char* path, Btree* &pos, Btree* &neg)
{
	if (!path[0]) throw std::invalid_argument("Empty name"); //если имя пустое - ошибка
	ifstream fout(path, ios::binary); //открываем файл
	if (!fout) throw std::invalid_argument("No such file"); //если файл не открылся - ошибка
	while (1) //читаем файл, пока не дойдем до конца
	{
		int temp; //временная переменная, в которую считываем число
		fout.read((char*)(&temp), sizeof(int)); //читаем
		if (fout.eof()) break; //если конец файла - выходим из цикла
		if (temp < 0) neg = Insert(temp, neg); //если число меньше нуля - добавляем его в негативное дерево
		else pos = Insert(temp, pos); //в противном случае - добавляем в положительное дерево
	}
}
