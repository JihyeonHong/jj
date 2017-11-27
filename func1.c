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

	char op[4]; int temp;
	for(int i=0; i<4; i++)
	{
		op[i]=(rand()%4)+43;
	}

	int result;


	result=num[0]op[0]num[1]


<<<<<<< HEAD
	printf("%d %c %d %c %d = %d\n",num[0], op[0], num[1], op[1], num[2], result);

=======
	printf("%d fff %c %d %c %d = %d\n",num[0], op[0], num[1], op[1], num[2], result);
	
>>>>>>> 11799250ae85cb403c852966860e95b2f987af40
}
