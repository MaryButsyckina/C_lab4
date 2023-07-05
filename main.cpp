#include <math.h>
#include <exception>
#include <iostream>
#include <fstream>

using std::ofstream;
using std::ios;
using std::ifstream;
using std::cout;

struct Btree //��������� ��������� ������
{
	int value; //�������� ������
	Btree* left, * right; //������ �� ����� � ������ ������. � ����� �������� ������� ��������, � ������ - �������
};

/*
* �-�� ������� ������� � ������
* ������ �������� - ��������, ��� ����� ��������
* ������ �������� - ��������� �� ������
* ���������� ��������� �� ������
*/
Btree* Insert(int val, Btree* tree);
/*
* �-��, ��������� �� ������� �������� ������
* �������� - ��������� �� ������
* ������ �� ����������
*/
void Print_Btree(Btree* q, int level = 0);
/*
* �-��, ��������� �������� ���� � ����������� ��� ����������
* ������ �������. ���� ��������� ��������.
* �������� - ���� � �����
* ������ �� ����������
*/
void CreateBiFile(const char* path);
/*
* �-��, �������� �������� ���� � ������ ��������.
* ������� ����� �� �������.
* �������� - ���� � �����.
* ������ �� ����������
*/
void ReadBiFile(const char* path);
/*
* �-��, ����������� �������� ���� � ������ �������
* �� ������������� � �������������.
* �������� - ���� � �����.
* ���������� ��������� �� ������ �� ���� �������� ��������:
* ������ �� ��� �������� ������������� �����, ������ - �������������.
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
	ofstream fout(path, ios::binary); //��������� ��� ������� ����
	int len = rand() % 50; //��������� �������� �����
	for (int i = 0; i < len; i++)
	{
		int num = rand() % 1000 - 500; //��������� ��������
		fout.write((char*)(&num), sizeof(int)); //���������� ��� � ����
	}
	fout.close(); //��������� ����
}
void ReadBiFile(const char* path)
{
	if (!path[0]) throw std::invalid_argument("Empty name"); //���� ��� ������ - ������
	ifstream fout(path, ios::binary); //��������� ����
	if (!fout) throw std::invalid_argument("No such file exist"); //���� ���� �� �������� - ������
	while (1) //������ ����, ���� �� ������ �� �����
	{
		int tmp;
		fout.read((char*)(&tmp), sizeof(int)); //������ ������ �����
		if (fout.eof()) break; //���� ����� ����� - ������� �� �����
		cout << tmp << "; "; //������� �� �������
	}
	cout << std::endl;
	fout.close();
}
void SortBiFile(const char* path, Btree* &pos, Btree* &neg)
{
	if (!path[0]) throw std::invalid_argument("Empty name"); //���� ��� ������ - ������
	ifstream fout(path, ios::binary); //��������� ����
	if (!fout) throw std::invalid_argument("No such file"); //���� ���� �� �������� - ������
	while (1) //������ ����, ���� �� ������ �� �����
	{
		int temp; //��������� ����������, � ������� ��������� �����
		fout.read((char*)(&temp), sizeof(int)); //������
		if (fout.eof()) break; //���� ����� ����� - ������� �� �����
		if (temp < 0) neg = Insert(temp, neg); //���� ����� ������ ���� - ��������� ��� � ���������� ������
		else pos = Insert(temp, pos); //� ��������� ������ - ��������� � ������������� ������
	}
}
