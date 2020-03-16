
#include "menu.h"

struct Menu {
	menu_func func;//函数
	char desc[64];//描述
};

int iMenu;//记录菜单数量
Menu myMenu[32];//菜单实体

//显示菜单
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

//添加菜单
void MenuAdd(menu_func func, const char *desc){
	myMenu[iMenu].func = func;
	strcpy(myMenu[iMenu].desc, desc);
	iMenu ++;
}
