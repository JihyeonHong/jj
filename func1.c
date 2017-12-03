#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PLUS 1000
#define MINUS 1001
#define MULTI 1002
#define DIVIDE 1003

void func1(int stage)
{
	srand(time(NUMLL)); //random_number
	
	int num=stage*2+3;
	int *array = (int*)malloc(num*sizeof(int));

	for(int i=0; i<num-1; i++)//number
	{
		if(i%2==0)//even number(number)
		{
			array[i] = rand()%11;
		}
		else//openration
		{
			array[i] = rand()%4 + 1000;
		}
	}
	for (int i = 0; i< num-1; i++)
	{
		if(i==num-2)
			printf("= ",array[i]);
		else if(array[i]==PLUS)
			printf("+ ", array[i]);
		else if(array[i]==MINUS)
			printf("- ", array[i]);
		else if(array[i]==DIVIDE)
			printf("/ ", array[i]);
		else
			printf("%d ", array[i]);

	}

}
