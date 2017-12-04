#include <stdio.h>

void main()
{	
	int gamenum;
	printf("find best numberking!!!!!! \n");
	printf("select the number(1,2,3,4)\n");
	scanf("%d",&gamenum);
	if(gamenum==1)
	{	
		game1();
	}
	if(gamenum==2)
	{	
		game2();
	}
	if(gamenum==3)
	{	
		game3();
	}
	if(gamenum==4)
	{	
		game4();
	}
}
