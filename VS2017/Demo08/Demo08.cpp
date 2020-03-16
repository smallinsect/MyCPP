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
		cout << "���캯��" << endl;
		int len = strlen(pstr);
		m_str = new char[len + 1];
		strcpy(m_str, pstr);
	}
	~MyString(){
		cout << "��������" << endl;
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
	MyString str = "ABDCE";//RAII�����ڴ�й¶��һ������£����ϵ��ڴ浱��ջ��ʹ��
	SmartPointer<Test> p(new Test);
	*p;
}

void show(boost::shared_ptr<int> sptr) {
	cout << *sptr << endl;
}

int main(int argc, char *argv[]) {

	go();
	//system("pause");
	
	//��������ָ��
	boost::scoped_ptr<int> p(new int);//���е��ڴ棬���ܹ������ı�����
	*p = 12;
	cout << *p.get() << endl;
	p.reset(new int);//�����ڴ棬֮ǰ���ڴ汻�ͷ�
	*p.get() = 15;
	cout << *p << endl;

	//���� �����ڴ�
	boost::scoped_array<int> pp(new int[10]);
	*pp.get() = 1;
	pp[3] = 3;
	pp.reset(new int[5]);//�����ڴ棬֮ǰ�ڴ汻�ͷ�


	//��������ָ��
	vector<boost::shared_ptr<int>> v;
	boost::shared_ptr<int> p1(new int(11));
	boost::shared_ptr<int> p2(new int(22));
	v.push_back(p1);
	v.push_back(p2);
	
	for_each(v.begin(), v.end(), show);

	//weak_ptr ������ָ��

	cin.get();
	return 0;
}
