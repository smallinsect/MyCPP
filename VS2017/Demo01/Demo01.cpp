/*********************************
**函数比较的函数指针的类型定义
**	typedef double(*lpcomp)(void*, void*);
**任意两个相同类型交换数据
**	void mySwap(void *v1, void *v2, uint size);
**任意数组排序 选择排序
**	void mySort(void *start, void *end, uint size, lpcomp comp); 
*******************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned int uint;
//函数比较的函数指针的类型定义
typedef double(*lpcomp)(void*, void*);
//任意两个相同类型交换数据
void mySwap(void *v1, void *v2, uint size);
//任意数组排序 选择排序
void mySort(void *start, void *end, uint size, lpcomp comp);

struct FRUIT {
	double grade;
	char name[64];
};
//数组的比较函数
double com1(void *v1, void *v2) {
	int *i1 = (int*)v1;
	int *i2 = (int*)v2;
	return *i1 - *i2;
}
//结构的比较函数 grade比较
double com2(void *v1, void *v2) {
	FRUIT *fruit1 = (FRUIT*)v1;
	FRUIT *fruit2 = (FRUIT*)v2;
	return fruit1->grade - fruit2->grade;
}

//结构的比较函数 name比较
double com3(void *v1, void *v2) {
	FRUIT *fruit1 = (FRUIT*)v1;
	FRUIT *fruit2 = (FRUIT*)v2;
	return strcmp(fruit1->name, fruit2->name);
}

int main(int argc, char *argv[]) {
	
	int arr[10] = { 988,49,90,26,329,611,302,338,279,209 };
	puts("\n***************打印数组元素***************************");
	for (int i = 0; i < 10; ++i) {
		printf("%d ", arr[i]);
	}
	//升序
	mySort(arr, arr+10, sizeof(int), com1);
	puts("\n***************打印排序后的数组元素 升序***************************");
	for (int i = 0; i < 10; ++i) {
		printf("%d ", arr[i]);
	}
	puts("\n******************************************");

	struct FRUIT fruits[10] = {
		{55.300000,"japple",},
		{67.909091,"iapple",},
		{33.333333,"happle",},
		{34.076923,"gapple",},
		{36.428571,"fapple",},
		{53.866667,"eapple",},
		{29.250000,"dapple",},
		{12.235294,"capple",},
		{53.777778,"bapple",},
		{54.766778,"aapple",}
	};
	puts("\n***************打印结构体元素***************************");
	for (int i = 0; i < 10; ++i) {
		printf("%lf %s\n", fruits[i].grade, fruits[i].name);
	}

	//按grade升序
	mySort(fruits, fruits+10, sizeof(FRUIT), com2);
	puts("\n***************打印排序后的结构体元素 按grade升序***************************");
	for (int i = 0; i < 10; ++i) {
		printf("%lf %s\n", fruits[i].grade, fruits[i].name);
	}
	puts("\n******************************************");

	//按name升序
	mySort(fruits, fruits + 10, sizeof(FRUIT), com3);
	puts("\n***************打印排序后的结构体元素 按name升序***************************");
	for (int i = 0; i < 10; ++i) {
		printf("%lf %s\n", fruits[i].grade, fruits[i].name);
	}
	puts("\n******************************************");
	system("pause");
	return 0;
}
//任意两个相同类型交换数据
void mySwap(void *v1, void *v2, uint size) {
	for (char *ch1 = (char *)v1, *ch2 = (char *)v2; size--; ++ch1, ++ch2) {
		char temp = *ch1;
		*ch1 = *ch2;
		*ch2 = temp;
	}
}
//任意数组排序 选择排序
void mySort(void *start, void *end, uint size, lpcomp comp) {
	for (char *ch1 = (char*)start; ch1 < (char*)end; ch1 += size) {
		for (char *ch2 = ch1 + size; ch2 < (char*)end; ch2 += size) {
			if (comp(ch1, ch2) > 0) {
				mySwap(ch1, ch2, size);
			}
		}
	}
}