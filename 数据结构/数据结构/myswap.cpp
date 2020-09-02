
#include "myswap.h"

void swap1(int* px, int* py) {
	int t = *px;
	*px = *py;
	*py = t;
}

void swap2(int& x, int& y) {
	int t = x;
	x = y;
	y = t;
}

template<class T>
void swap3(T& x, T& y) {
	T t = x;
	x = y;
	y = t;
}