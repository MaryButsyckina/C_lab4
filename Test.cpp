#include "Test.h"
#include "BiFile.h"
#include <iostream>
namespace test
{
	//using bifile::CreateBiFile;
	//using bifile::ReadBiFile;
	//using bifile::SortBiFile;
	//using std::cout;
	//using btree::Btree;

	//int TestAll()
	//{

	//}

	//int testCreateBiFile1()
	//{
	//	tests++;
	//	cout << "Testing CreateFile.\n";
	//	const char* path = "test.bin";
	//	try
	//	{
	//		CreateBiFile(path);
	//		cout << "\tTest passed.\n";
	//		passed_tests++;
	//		return 0;
	//	}
	//	catch(...)
	//	{
	//		cout << "\tHandled unknown error.\n";
	//		return 1;
	//	}
	//}
	//int testCreateBiFile2()
	//{
	//	tests++;
	//	cout << "Testing CreateFile. Empty name.\n";
	//	const char* path = "";
	//	try
	//	{
	//		CreateBiFile(path);
	//		cout << "\tDidn't catch the error.\n";
	//		return 1;
	//	}
	//	catch (std::invalid_argument)
	//	{
	//		cout << "\tTest passed.\n";
	//		passed_tests++;
	//		return 0;
	//	}
	//	catch (...)
	//	{
	//		cout << "\tHandled unknown error.\n";
	//		return 1;
	//	}
	//}
	//int testReadBiFile1()
	//{
	//	cout << "Testing ReadBiFile.\n";
	//	tests++;
	//	const char* path = "test.bin";
	//	try
	//	{
	//		ReadBiFile(path);
	//		cout << "\tIf output is correct enter 0, else 1: ";
	//		int num;
	//		std::cin >> num;
	//		if (num)
	//		{
	//			cout << "\tWrong output.\n";
	//			return 1;
	//		}
	//		else
	//		{
	//			cout << "\tTest passed.\n";
	//			passed_tests++;
	//			return 0;
	//		}
	//	}
	//	catch(...)
	//	{
	//		cout << "\tHandled unknown error.\n";
	//		return 1;
	//	}
	//}
	//int testReadBiFile2()
	//{
	//	cout << "Testing ReadBiFile. Empty name.\n";
	//	tests++;
	//	const char* path = "";
	//	try
	//	{
	//		ReadBiFile(path);
	//		cout << "\t Didn't catch the error.\n";
	//		return 1;
	//	}
	//	catch(std::invalid_argument)
	//	{
	//		cout << "\tTest passed.\n";
	//		passed_tests++;
	//		return 0;
	//	}
	//	catch (...)
	//	{
	//		cout << "\tHandled unknown error.\n";
	//		return 1;
	//	}
	//}
	//int testReadBiFile3()
	//{
	//	cout << "Testing ReadBiFile. File does not exist.\n";
	//	tests++;
	//	const char* path = "aksjldf.bin";
	//	try
	//	{
	//		ReadBiFile(path);
	//		cout << "\t Didn't catch the error.\n";
	//		return 1;
	//	}
	//	catch (std::invalid_argument)
	//	{
	//		cout << "\tTest passed.\n";
	//		passed_tests++;
	//		return 0;
	//	}
	//	catch (...)
	//	{
	//		cout << "\tHandled unknown error.\n";
	//		return 1;
	//	}
	//}
	//int testSortBiFile1()
	//{
	//	const char* path = "test1.bin";
	//	Btree* positive = nullptr;
	//	Btree* negative = nullptr;
	//	try
	//	{
	//		SortBiFile(path, positive, negative);
	//	}
	//	catch(...)
	//	{
	//		cout << "\tHandled unknown error.\n";
	//		return 1;
	//	}
	//}
	//int testSortBiFile2()
	//{
	//}
	//int testSortBiFile3()
	//{
	//}
}