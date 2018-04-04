#include "Classes.h"
#include <iostream>

extern CStack stack;

CObject::CObject() {
	std::cout << "Object created" << std::endl;
	stack.Push(this);
}

CObject::~CObject() {
	std::cout << "Object destructed" << std::endl;
}

CDerived::~CDerived() {
	std::cout << "Derived destructed" << std::endl;
}

CDerived::CDerived() {
	std::cout << "Derived destructed" << std::endl;
	stack.Push(this);
}

void CStack::Push(CObject* obj) {
	stack.push_back(obj);
}

void CStack::Pop() {
	CObject* obj = stack.back();
	stack.pop_back();
	delete obj;
}

int CStack::size() const {
	return stack.size();
}

void CStack::Unwind(const int size) {
	for (int i = stack.size(); i > size; i--) {
		CObject* obj = stack.back();
		stack.pop_back();
		delete obj;
	}
}