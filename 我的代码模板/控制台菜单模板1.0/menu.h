#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <windows.h>

typedef bool (*menu_func)();

//��ʾ�˵�
void MenuShow();
//��Ӳ˵�
void MenuAdd(menu_func func, const char* desc);
