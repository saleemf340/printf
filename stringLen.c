#include "main.h"

int stringLen(char *c){
    
	int a = 0;

	while (*(c + a))
		a++;

	return (a);

}