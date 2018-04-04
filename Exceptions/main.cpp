#include <iostream>
#include <setjmp.h>
#include <stdlib.h>
#include "exceptions.h"
#include "Classes.h"



CStack stack;

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