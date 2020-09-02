#pragma once

void swap1(int*, int*);

#define SWAP(x, y, t) ((t)=(x),(x)=(y),(y)=(t))

void swap2(int&, int&);

template<class T>
void swap3(T&, T&);