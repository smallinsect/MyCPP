#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <limits.h>

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#include <boost/scoped_ptr.hpp>
#include <boost/scoped_array.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/shared_array.hpp>
#include <boost/weak_ptr.hpp>

#include "SmartPointer.hpp"

class MyString {
private:
	char* m_str;
public:
	MyString(const char* pstr) {
		cout << "构造函数" << endl;
		int len = strlen(pstr);
		m_str = new char[len + 1];
		strcpy(m_str, pstr);
	}
	~MyString(){
		cout << "析构函数" << endl;
		delete m_str;
	}
};

class Test {
public:
	Test() {
		cout << "Test()" << endl;
	}
	~Test(){
		cout << "~Test()" << endl;
	}
};

void go() {
	MyString str = "ABDCE";//RAII避免内存泄露，一般情况下，堆上的内存当做栈上使用
	SmartPointer<Test> p(new Test);
	*p;
}

void show(boost::shared_ptr<int> sptr) {
	cout << *sptr << endl;
}

int main(int argc, char *argv[]) {

	go();
	//system("pause");
	
	//独享智能指针
	boost::scoped_ptr<int> p(new int);//独有的内存，不能共享给别的变量。
	*p = 12;
	cout << *p.get() << endl;
	p.reset(new int);//重置内存，之前的内存被释放
	*p.get() = 15;
	cout << *p << endl;

	//数组 独享内存
	boost::scoped_array<int> pp(new int[10]);
	*pp.get() = 1;
	pp[3] = 3;
	pp.reset(new int[5]);//重置内存，之前内存被释放


	//共享智能指针
	vector<boost::shared_ptr<int>> v;
	boost::shared_ptr<int> p1(new int(11));
	boost::shared_ptr<int> p2(new int(22));
	v.push_back(p1);
	v.push_back(p2);
	
	for_each(v.begin(), v.end(), show);

	//weak_ptr 弱智能指针

	cin.get();
	return 0;
}
