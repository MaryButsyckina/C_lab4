#include <fstream>
#include <iostream>
#include "BiFile.h"
namespace bifile
{
	//using std::ofstream;
	//using std::ios;
	//using std::ifstream;
	//using std::cout;

	//void CreateBiFile(const char* path)
	//{
	//	ofstream fout(path, ios::binary);
	//	int len = rand() % 50;
	//	for (int i = 0; i < len; i++)
	//	{
	//		int num = rand() % 1000 - 500;
	//		fout.write((char*)(&num), sizeof(int));
	//	}
	//	fout.close();
	//}
	//void ReadBiFile(const char* path)
	//{
	//	ifstream fout(path, ios::binary);
	//	while (1)
	//	{
	//		int tmp;
	//		fout.read((char*)(&tmp), sizeof(int));
	//		if (fout.eof()) break;
	//		cout << tmp << "; ";
	//	}
	//}
	//void SortBiFile(const char* path, Btree* pos, Btree* neg)
	//{
	//	ifstream fout(path, ios::binary);
	//	while (1)
	//	{
	//		int temp;
	//		fout.read((char*)(&temp), sizeof(int));
	//		if (fout.eof()) break;
	//		if (temp < 0) Insert(temp, neg);
	//		else Insert(temp, pos);
	//	}
	//}
}