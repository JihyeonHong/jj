#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "makeeq.h"

#define PLUS 43
#define MINUS 45
#define MULTI 42
#define DIVIDE 47



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
