#include <stdio.h>
#include <stdlib.h>

#include <limits.h>

#include <iostream>
using namespace std;

void fun1() {
	int a, b;
	cout << "请输入两个整数，整数之间用空格隔开，按回车结束输入" << endl;
	cin >> a >> b;
	if (a < b) {
		cout << a << " " << b << endl;
	}
	else {
		cout << b << " " << a << endl;
	}
}


void fun2(int n) {
	int cnt = -1;
	for (int i = 1; i <= n; ++i) {
		cnt += 2;
		for (int j = 1; j <= cnt; ++j) {
			cout << i << " ";
		}
		cout << endl;
	}
}

int main(int argc, char *argv[]) {

	//int n;
	//while (cin >> n) {
	//	fun2(n);
	//}

	//puts("hello world");

	//int $hello = 1;

	//printf按照%d,%f解析，不是该类型，都不能解析。
	//printf("%d\n", 10.3);
	//printf("%lf\n", 10);

	//与数据长度有关系
	//unsigned short sh = 65535;//65535
	//unsigned short sh = 65535+1;//0 数据溢出
	//printf("%d\n", sh);

	//short num = -1;
	//printf("%d\n", num);
	//printf("%u\n", num);

	//3x+2y-7z=5(0<=x,y,z<=100)
	//int x, y, z;
	//for (x = 0; x <= 100; x++) {
	//	for (y = 0; y <= 100; y++) {
	//		if ((3*x+2*y-5)%7 != 0) {
	//			continue;
	//		}
	//		z = (3 * x + 2 * y - 5) / 7;
	//		if (z >= 0 && z <= 100) {
	//			cout << "x=" << x << " y=" << y << " z=" << z << endl;
	//		}
	//	}
	//}

	system("pause");
	return 0;
}
