#include "exceptions.h"
#include "defines.h"
#include <iostream>


extern std::vector<CScope> Scopes;
extern CStack stack;
extern int CurrentScope;

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
	std::cout << "Derived created" << std::endl;
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
	TRY{
		for (int i = stack.size(); i > size; i--) {
			CObject* obj = stack.back();
			stack.pop_back();
			delete obj;
		}
	}
	CurrentScope--;
	CATCH(-1){
		std::terminate();
	}
	ETRY;
	
}

CScope::CScope(int _stackSize) :
	stackSize(_stackSize)
{}
jmp_buf& CScope::GetEnv() {
	return env;
}
int CScope::SetEnv() {
	return setjmp(env);
}
int CScope::GetStackSize() const {
	return stackSize;
}
					
void f1() {
	CObject* o = new CObject;
	f2();
}

void f2() {
	CObject* o = new CObject;
	f3();
}

void f3() {
	CObject* o = new CObject;
	THROW(EXCEPTION1);
	std::cout << "after throw" << std::endl;
}