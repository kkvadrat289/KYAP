#include <iostream>
#include <setjmp.h>
#include <stdlib.h>
#include "exceptions.h"
#include <vector>

CStack stack;
int StackSize = 0;
jmp_buf env;
std::vector<CScope> Scopes;
int CurrentScope = -1;

int main() {
	std::cout << "Bugaga!" << std::endl;

	TRY{
		f1();
	}
	CATCH(EXCEPTION1) {
		std::cout << "Got exception " << std::endl;
	}
	ETRY;
	

	return 0;
}