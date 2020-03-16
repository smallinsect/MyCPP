
#include "menu.h"

struct Menu {
	menu_func func;//����
	char desc[64];//����
};

int iMenu;//��¼�˵�����
Menu myMenu[32];//�˵�ʵ��

//��ʾ�˵�
void MenuShow() {
	printf("+");
	for (int i = 0; i < 62; ++i) {
		printf("-");
	}
	printf("+\n");
	for (int i = 0; i < iMenu; ++i) {
		printf("| ");
		printf("%2d.%-58s|\n", i, myMenu[i].desc);
	}
	printf("+");
	for (int i = 0; i < 62; ++i) {
		printf("-");
	}
	printf("+\n");
}

//��Ӳ˵�
void MenuAdd(menu_func func, const char *desc){
	myMenu[iMenu].func = func;
	strcpy(myMenu[iMenu].desc, desc);
	iMenu ++;
}
