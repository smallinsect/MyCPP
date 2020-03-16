#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <windows.h>

typedef bool (*menu_func)();

//显示菜单
void MenuShow();
//添加菜单
void MenuAdd(menu_func func, const char* desc);
