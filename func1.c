#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void func1(int stage)
{
	srand(time(NUMLL)); //random_number
	//malloc 2*number+3
	int num[20];
	for(int i=0; i<stage; i++)//number
	{
		num[i]=rand()%11;
	}

	char op[4]; int temp;
	for(int i=0; i<4; i++)//operation
	{
		op[i]=(rand()%4)+43;
	}

	int result;


	printf("%d %c %d %c %d = %d\n",num[0], op[0], num[1], op[1], num[2], result);

}
