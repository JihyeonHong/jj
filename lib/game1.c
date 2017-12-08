

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "game1.h"

#define PLUS 43
#define MINUS 45
#define MULTI 42
#define DIVIDE 47

//#define stage 2

int stage;
int result;
int count = 0;
int num_stage;
int or_num_stage;
int op_stage;
int or_op_stage;
int *array1;
int *array2;
int *or_array1;
int *or_array2;

void game1()
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

			print(1);
			int temp = verify(1);

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
		}

		stage++;
		init(stage);
	}
}
