#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "game4.h"
#include "init.h"
#include "makeeq.h"
#include "verify.h"
#include "print.h"
#include "quickSort.h"

#define PLUS 43
#define MINUS 45
#define MULTI 42
#define DIVIDE 47

int main()
{
	srand(time(NULL));

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
