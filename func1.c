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

	for(int i=0; i<num; i++)//number
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
	

	int result;


	printf("%d %c %d %c %d = %d\n",num[0], op[0], num[1], op[1], num[2], result);

}
