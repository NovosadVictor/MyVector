#include <iostream>
#include "myiterator.h"
#include "vectorclass.h"

void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();

int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	system("pause");
	return 0;
}

void test1()
{
	std::cout << "Test 1: " << std::endl;
	vector<int> v(5);
	for (size_t i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}
void test2()
{
	std::cout << "Test 2: " << std::endl;
	vector<char> vc;
	vc.push_back('a');
	vc.push_back('b');
	for (size_t i = 0; i < vc.size(); ++i)
		std::cout << vc[i] << " ";
	std::cout << std::endl;

}
void test3()
{
	std::cout << "Test 3: " << std::endl;
	vector<double> v;
	v.push_back(3.14);
	v.push_back(5);
	v.push_back(7.3);
	v.push_back(12);
	v.push_back(34);
	for (size_t i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";
	std::cout << std::endl;
	v.pop_back();
	for (size_t i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}
void test4()
{
	std::cout << "Test 4: Size: " << std::endl;
	vector<char> v(10);
	for (size_t i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";
	std::cout << std::endl;
	std::cout << v.size() << std::endl;
}
void test5()
{
	std::cout << "Test 5: []" << std::endl;
	vector<int> v(7);
	for (size_t i = 0; i < v.size(); ++i)
		v[i] = i*i;
	for (size_t i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}
void test6()
{
	std::cout << "Test 6: " << std::endl;
	vector<char> v;
	v.push_back('a');
	v.push_back('b');
	v.push_back('c');
	v.push_back('d');
	v.push_back('e');
	v.push_back('f');
	std::cout << v.front() << ", " << --v.back() << std::endl;
}
void test7()
{
	std::cout << "Test 7: begin end " << std::endl;
	vector<int> v(7);
	for (auto i = v.begin(); i != v.end(); ++i)
	{
		*i = rand() % 200;
		std::cout << *i << " ";
	}
	std::cout << std::endl;
}
void test8()
{
	std::cout << "Test 8: swap " << std::endl;
	vector<int> v1(5);
	vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v1.swap(v2);
	for (size_t i = 0; i < v1.size(); ++i)
		std::cout << v1[i] << " ";
	std::cout << std::endl;
	for (size_t i = 0; i < v2.size(); ++i)
		std::cout << v2[i] << " ";
	std::cout << std::endl;
}
