#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "game2.h"

#define PLUS 43
#define MINUS 45
#define MULTI 42
#define DIVIDE 47

void game2()
{
	stage = 1;
	init(stage);

	int life = 3;


	int testresult;

	for (int i = 1; i <= 3; i++)
	{
		printf("\n<<<<<<<<<<<<<<<<<< Stage%d >>>>>>>>>>>>>>>>>>\n\n", i);

		for (int j = 0; j < 3; j++)
		{
			printf("life : ");
			for (int h = 0; h < life; h++)
			{
				printf("♥ ");
			}
			printf("\n");

			testresult = makeeq();

			while (testresult < 0)
				testresult = makeeq();

			print(2);

			for (int a = 0; a < or_num_stage; a++)
			{
				scanf("%d", &or_array1[a]);
			}

			int temp = verify(2);

			if (result == temp)
				printf("Correct!\n\n");
			else
			{
				printf("Wrong!\n\n");
				life--;
				if (life == 0)
				{
					printf("=========== GAME OVER ==========\n");
					return;
				}
			}

			init(stage);
		}

		stage++;
		init(stage);
	}
}
