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

int stage;
int result;
int count;
int num_stage;
int or_num_stage;
int op_stage;
int or_op_stage;
int *array1;
int *array2;
int *or_array1;
int *or_array2;

void game4()
{
	int life = 3;
	printf("\n");
	for (int ss = 0; ss < 3; ss++)
	{
		printf("life : ");
		for (int h = 0; h < life; h++)
		{
			printf("♥ ");
		}
		printf("\n");

		int array[9] = { 0 };
		int array2[9] = { 0 };

		for (int i = 0; i < 9; i++)
		{
			array[i] = rand() % 50;

			for (int j = 0; j < i; j++)
			{
				if (array[i] == array[j])//중복검사
				{
					i--;
				}
			}
		}

		for (int i = 0; i < 9; i++)
		{
			array2[i] = array[i];//copy

			printf("%d ", array[i]);
			if ((i + 1) % 3 == 0)
			{
				printf("\n");
			}
		}

		printf("\n");
		//sorting 

		quickSort(array2, 0, 8);

		int key = 0, num = 0;
		for (int i = 0; i < 9; i++)
		{
			scanf("%d", &key);
			//key = getch();
			if (key == 7)
			{
				num = array[0];
			}
			if (key == 8)
			{
				num = array[1];
			}
			if (key == 9)
			{
				num = array[2];
			}
			if (key == 4)
			{
				num = array[3];
			}
			if (key == 5)
			{
				num = array[4];
			}
			if (key == 6)
			{
				num = array[5];
			}
			if (key == 1)
			{
				num = array[6];
			}
			if (key == 2)
			{
				num = array[7];
			}
			if (key == 3)
			{
				num = array[8];
			}
			if (num != array2[i])
			{
				printf("Fail\n\n");
				life--;
				printf("=========== GAME OVER ==========\n");
				break;
			}
		}
		printf("\n");
	}
}
