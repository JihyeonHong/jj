// Verify the answer

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PLUS 1000
#define MINUS 1001
#define MULTI 1002
#define DIVIDE 1003

int verify()
{
	for (int h = 0; h < stage; h++)
	{
		for (int i = 0; i < or_op_stage; i++)
		{
			if (array2[i] == MULTI)
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

			else if (array2[i] == MINUS)
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
