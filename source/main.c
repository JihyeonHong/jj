#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "header.h"
int main()
{
	srand(time(1));

	char enter;
	int gamenum;

	printf("find best numberking!!!!!! \n");
	printf("select the number(1,2,3,4) : ");
	scanf("%d%c", &gamenum, &enter);

	if (gamenum == 1)
		game1();

	else if (gamenum == 2)
		game2();

	else if (gamenum == 3)
		game3();

	else
		game4();
}
