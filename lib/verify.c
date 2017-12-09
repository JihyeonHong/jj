#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "verify.h"

#define PLUS 43
#define MINUS 45
#define MULTI 42
#define DIVIDE 47

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
