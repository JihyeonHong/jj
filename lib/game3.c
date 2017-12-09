#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "game3.h"

#include "makeeq.h"
#include "print.h"
#include "verify.h"
#include "init.h"

void game3()
{
	int life = 3;
	stage = 1;
	init(stage);

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

			print(3);

			char sp;

			for (int i = 0; i < or_op_stage; i++)
				scanf("%c%c", &or_array2[i], &sp);

			int temp = verify(3);

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
