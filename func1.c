#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void func1()
{
	srand(time(NUMLL));

	int num[4];
	for(int i=0; i<4; i++)
	{
		num[i]=rand()%11;
	}

	int op[4]; int temp;
	for(int i=0; i<4; i++)
	{
		op[i]=rand()%4;
	}

	
}
