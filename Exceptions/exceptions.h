#pragma once
#include <iostream>
#include <setjmp.h>
#include "Classes.h"

extern CStack stack;
int StackSize = 0;
jmp_buf env;

#define TRY StackSize = stack.size(); switch (setjmp(env)) { case 0:
#define CATCH(x) break; case x:
#define THROW(x) stack.Unwind(StackSize); longjmp(env, x)

#define ETRY }

#define EXCEPTION1 (42)
#define EXCEPTION2 (1)

void f1();
void f2();
void f3();


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
