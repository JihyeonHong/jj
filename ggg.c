#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

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

void init(int stage)
{
	num_stage = stage + 1;
	or_num_stage = stage + 1;
	op_stage = stage;
	or_op_stage = stage;
	array1 = (int*)malloc(num_stage * sizeof(int));
	array2 = (int*)malloc(op_stage * sizeof(int));
	or_array1 = (int*)malloc(num_stage * sizeof(int));
	or_array2 = (int*)malloc(op_stage * sizeof(int));
}

void print(int game_num)
{
	int a = 0, b = 0;

	if (game_num == 1)
	{
		array1[0] = '_';

		a = 0, b = 0;
		for (int i = 0; i < or_num_stage + or_op_stage; i++)//print
		{
			if (i % 2 == 0)
				printf("%d ", or_array1[a++]);
			else if (or_array2[b] == PLUS)
				printf("+ ", or_array2[b++]);
			else if (or_array2[b] == MINUS)
				printf("- ", or_array2[b++]);
			else if (or_array2[b] == MULTI)
				printf("* ", or_array2[b++]);
			else if (or_array2[b] == DIVIDE)
				printf("/ ", or_array2[b++]);
		}
		printf("= %c\n", array1[0]);
	}

	else if (game_num == 2)
	{
		for (int i = 0; i < or_num_stage; i++)
		{
			or_array1[i] = '_';
		}

		a = 0, b = 0;
		for (int i = 0; i < or_num_stage + or_op_stage; i++)//print
		{
			if (i % 2 == 0)
				printf("%c ", or_array1[a++]);
			else if (or_array2[b] == PLUS)
				printf("+ ", or_array2[b++]);
			else if (or_array2[b] == MINUS)
				printf("- ", or_array2[b++]);
			else if (or_array2[b] == MULTI)
				printf("* ", or_array2[b++]);
			else if (or_array2[b] == DIVIDE)
				printf("/ ", or_array2[b++]);
		}
		printf("= %d\n", array1[0]);
	}

	else if (game_num == 3)
	{
		for (int i = 0; i < or_op_stage; i++)
		{
			or_array2[i] = '_';
		}

		a = 0, b = 0;
		for (int i = 0; i < or_num_stage + or_op_stage; i++)//print
		{
			if (i % 2 == 0)
				printf("%d ", or_array1[a++]);
			else
				printf("%c ", or_array2[b++]);
		}
		printf("= %d\n", array1[0]);
	}
}

int verify(int flag)
{
	count = 0;

	if (flag == 1)
	{
		int temp;
		scanf("%d", &temp);
		return temp;
	}

	else
	{
		for (int h = 0; h < stage; h++)
		{
			for (int i = 0; i < or_op_stage; i++)
			{
				if (or_array2[i] == MULTI)
				{
					or_array1[i] = or_array1[i] * or_array1[i + 1];

					for (int j = i + 1; j < or_num_stage; j++)
					{
						or_array1[j] = or_array1[j + 1];
					}
					for (int j = i + 1; j < or_op_stage; j++)
					{
						or_array2[j - 1] = or_array2[j];
					}
					or_num_stage--;
					or_op_stage--;
					count++;
					break;
				}

				else if (or_array2[i] == DIVIDE)
				{
					if ((or_array1[i] < or_array1[i + 1]) || (or_array1[i] % or_array1[i + 1] != 0))
					{
						return -1;
					}

					or_array1[i] = or_array1[i] / or_array1[i + 1];
					for (int j = i + 1; j < or_num_stage; j++)
						or_array1[j] = or_array1[j + 1];

					for (int j = i + 1; j < or_op_stage; j++)
						or_array2[j - 1] = or_array2[j];

					or_num_stage--;
					or_op_stage--;
					count++;
					break;
				}
			}

		}

		for (int h = 0; h < stage - count; h++)
		{
			for (int i = 0; i < or_op_stage; i++)
			{
				if (or_array2[i] == PLUS)
				{
					or_array1[i] = or_array1[i] + or_array1[i + 1];

					for (int j = i + 1; j < or_num_stage; j++)
					{
						or_array1[j] = or_array1[j + 1];
					}
					for (int j = i + 1; j < or_op_stage; j++)
					{
						or_array2[j - 1] = or_array2[j];
					}
					or_num_stage--;
					or_op_stage--;
					break;
				}

				else if (or_array2[i] == MINUS)
				{
					or_array1[i] = or_array1[i] - or_array1[i + 1];
					for (int j = i + 1; j < or_num_stage; j++)
						or_array1[j] = or_array1[j + 1];

					for (int j = i + 1; j < or_op_stage; j++)
						or_array2[j - 1] = or_array2[j];

					or_num_stage--;
					or_op_stage--;
					break;
				}
			}
		}

		return or_array1[0];
	}
}

int makeeq()
{
	num_stage = stage + 1;
	op_stage = stage;
	count = 0;

	for (int i = 0; i < num_stage; i++)
		array1[i] = rand() % 10 + 1;
	for (int i = 0; i < op_stage; i++)
	{
		int temp = rand() % 6 + 42;

		if (temp == 44 || temp == 46)
			i--;

		else
			array2[i] = temp;
	}

	for (int i = 0; i < num_stage; i++)
		or_array1[i] = array1[i];
	for (int i = 0; i < op_stage; i++)
		or_array2[i] = array2[i];

	for (int h = 0; h < stage; h++)
	{
		for (int i = 0; i < op_stage; i++)
		{
			if (array2[i] == MULTI)
			{
				array1[i] = array1[i] * array1[i + 1];

				for (int j = i + 1; j < num_stage; j++)
				{
					array1[j] = array1[j + 1];
				}
				for (int j = i + 1; j < op_stage; j++)
				{
					array2[j - 1] = array2[j];
				}
				num_stage--;
				op_stage--;
				count++;
				break;
			}

			else if (array2[i] == DIVIDE)
			{
				if ((array1[i] < array1[i + 1]) || (array1[i] % array1[i + 1] != 0))
				{
					return -1;
				}

				array1[i] = array1[i] / array1[i + 1];
				for (int j = i + 1; j < num_stage; j++)
					array1[j] = array1[j + 1];

				for (int j = i + 1; j < op_stage; j++)
					array2[j - 1] = array2[j];

				num_stage--;
				op_stage--;
				count++;
				break;
			}
		}

	}

	for (int h = 0; h < stage - count; h++)
	{
		for (int i = 0; i < op_stage; i++)
		{
			if (array2[i] == PLUS)
			{
				array1[i] = array1[i] + array1[i + 1];

				for (int j = i + 1; j < num_stage; j++)
				{
					array1[j] = array1[j + 1];
				}
				for (int j = i + 1; j < op_stage; j++)
				{
					array2[j - 1] = array2[j];
				}
				num_stage--;
				op_stage--;
				break;
			}

			else if (array2[i] == MINUS)
			{
				array1[i] = array1[i] - array1[i + 1];
				for (int j = i + 1; j < num_stage; j++)
					array1[j] = array1[j + 1];

				for (int j = i + 1; j < op_stage; j++)
					array2[j - 1] = array2[j];

				num_stage--;
				op_stage--;
				break;
			}
		}
	}

	result = array1[0];
	return result;
}

void game1()
{
	stage = 1;
	init(stage);

	int testresult;

	for (int i = 1; i <= 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			testresult = makeeq();

			while (testresult < 0)
				testresult = makeeq();

			print(1);
			int temp = verify(1);

			if (result == temp)
				printf("Correct!\n\n");
			else
				printf("Wrong!\n\n");
		}

		stage++;
		init(stage);
	}
}

void game2()
{
	stage = 1;
	init(stage);

	int testresult;

	for (int i = 1; i <= 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
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
				printf("Wrong!\n\n");

			init(stage);
		}

		stage++;
		init(stage);
	}
}

void game3()
{
	stage = 1;
	init(stage);

	int testresult;

	for (int i = 1; i <= 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
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
				printf("Wrong!\n\n");

			init(stage);
		}

		stage++;
		init(stage);
	}
}

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

//	else 
//		game4();

}
