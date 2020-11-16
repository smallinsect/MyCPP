#include <stdio.h>

// ��������������ͬ���͵�ֵ
void Swap(void* pv1, void* pv2, int size) {
	char tmp;
	char* p1 = (char*)pv1;
	char* p2 = (char*)pv2;
	while (size--) {
		tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++;
		p2++;
	}
}

// 1.ð������ ��������
void BubbleSort(int a[], int n) {
	int size = sizeof(int);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (a[j] > a[j+1]) {
				Swap(&a[j], &a[j + 1], size);
			}
		}
	}
}

// 2.ѡ������ ��������
void SelectSort(int a[], int n) {
	int size = sizeof(int);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				Swap(&a[i], &a[j], size);
			}
		}
	}
}

void Println(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main() {
	int a[] = {8, 7, 6, 5, 4, 3, 2, 1, 0}, n = 9;
	//BubbleSort(a, n);
	SelectSort(a, n);
	Println(a, n);
	return 0;
}