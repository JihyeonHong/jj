#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PLUS 1000
#define MINUS 1001
#define MULTI 1002
#define DIVIDE 1003

#define stage 3

int count = 0;
int num_stage = stage + 1;
int or_num_stage = stage + 1;
int op_stage = stage;
int or_op_stage = stage;
int *array1 = (int*)malloc(num_stage * sizeof(int));
int *array2 = (int*)malloc(op_stage * sizeof(int));
int *or_array1 = (int*)malloc(num_stage * sizeof(int));
int *or_array2 = (int*)malloc(op_stage * sizeof(int));

int makeeq()
{
	num_stage = stage + 1;
	op_stage = stage;
	count = 0;

	for (int i = 0; i < num_stage; i++)
		array1[i] = rand() % 10 + 1;
	for (int i = 0; i < op_stage; i++)
		array2[i] = rand() % 4 + 1000;

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

	return array1[0];
}
