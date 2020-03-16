#pragma once


template<class T>
class SmartPointer {
public:
	SmartPointer() {
	}
	SmartPointer(T* p) {
		this->p = p;
	}
	~SmartPointer(){
		if (p != nullptr) {
			delete p;
		}
	}
	T operator*() {
		return *p;
	}

private:
	T *p = nullptr;
};
