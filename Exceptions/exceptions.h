#pragma once
#include <iostream>
#include <setjmp.h>
#include <vector>
#include <list>

class CObject {
public:
	virtual ~CObject();
	CObject();
};

class CDerived : public CObject {
public:
	~CDerived();
	CDerived();
};

class CStack {
public:
	void Push(CObject* obj);
	void Pop();
	int size() const;
	void Unwind(const int size);
private:
	std::list<CObject*> stack;
};

class CScope {
public:
	CScope(int _stackSize);
	jmp_buf& GetEnv();
	int SetEnv();
	int GetStackSize() const;

	jmp_buf env;
private:
	int stackSize;
};

void f1();
void f2();
void f3();

#define TRY  \
	Scopes.emplace_back(stack.size()); \
	CurrentScope++; \
	switch (Scopes[CurrentScope].SetEnv()) { \
		case 0:	   \

#define CATCH(x) break; case x:
#define THROW(x) {\
	stack.Unwind(Scopes[CurrentScope].GetStackSize()); \
	CurrentScope--;\
	longjmp(Scopes[CurrentScope + 1].env, x);  \
	}
#define ETRY }

#define EXCEPTION1 (42)
#define EXCEPTION2 (1)
