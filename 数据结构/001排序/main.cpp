#include <stdio.h>
#include <stdlib.h>

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

// 3.�������� ��������
void InsertSort(int a[], int n) {
	int size = sizeof(int);
	for (int i = 1; i < n; i++) {
		int tmp = a[i];
		int j = i - 1;
		for ( ; j >= 0; j--) {
			if (a[j] > tmp) {
				a[j + 1] = a[j];
			}
		}
		a[j + 1] = tmp;
	}
}

// 4.�鲢���� ��������
void MergeSort(int a[], int l, int r) {
	if (l == r) {
		return;
	}
	int mid = (l + r) >> 1;
	MergeSort(a, l, mid);
	MergeSort(a, mid + 1, r);
	int* p = (int*)malloc((r - l + 1) * sizeof(int));
	int pos = 0;
	int i = l;
	int j = mid + 1;
	while (i <= mid && j <= r) {
		if (a[i] < a[j]) {
			p[pos] = a[i];
			i++;
		}
		else {
			p[pos] = a[j];
			j++;
		}
		pos++;
	}
	while (i <= mid) {
		p[pos] = a[i];
		i++;
		pos++;
	}
	while (j <= r) {
		p[pos] = a[j];
		j++;
		pos++;
	}
	for (pos = 0; l <= r; pos++, l++) {
		a[l] = p[pos];
	}
	free(p);
}

// 5.�������� ��������

// 6.Ͱ���� ��������

// 7.ϣ������ ��������

// 8.������ ��������

void Println(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main() {
	int a[] = {8, 7, 6, 5, 4, 3, 2, 1, 0}, n = 9;
	//BubbleSort(a, n);
	//SelectSort(a, n);
	//InsertSort(a, n);
	MergeSort(a, 0, n - 1);
	Println(a, n);
	return 0;
}