#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define PLUS 1000
#define MINUS 1001
#define MULTI 1002
#define DIVIDE 1003

#define stage 3

int main()
{
	srand(time(NULL));

	int count = 0;
	int num_stage = stage + 1;
	int op_stage = stage;
	int *array1 = (int*)malloc(num_stage * sizeof(int));
	int *array2 = (int*)malloc(op_stage * sizeof(int));

	for (int i = 0; i < num_stage; i++)
		array1[i] = rand() % 10 + 1;
	for (int i = 0; i < op_stage; i++)
		array2[i] = rand() % 4 + 1000;

	int a = 0, b = 0;
	for (int i = 0; i < num_stage + op_stage; i++)//print
	{
		if (i % 2 == 0)
			printf("%d ", array1[a++]);
		else if (array2[b] == PLUS)
			printf("+ ", array2[b++]);
		else if (array2[b] == MINUS)
			printf("- ", array2[b++]);
		else if (array2[b] == MULTI)
			printf("* ", array2[b++]);
		else if (array2[b] == DIVIDE)
			printf("/ ", array2[b++]);
	}

	//printf("\n");


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
					printf("\n");
					return 0;
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

//	printf("\n");


/*	a = 0, b = 0;
	for (int i = 0; i < num_stage + op_stage; i++)//print
	{
		if (i % 2 == 0)
			printf("%d ", array1[a++]);
		else if (array2[b] == PLUS)
			printf("+ ", array2[b++]);
		else if (array2[b] == MINUS)
			printf("- ", array2[b++]);
		else if (array2[b] == MULTI)
			printf("* ", array2[b++]);
		else if (array2[b] == DIVIDE)
			printf("/ ", array2[b++]);
	}
*/
	///////////  + -
	for (int h = 0; h < stage-count; h++)
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

	printf("= %d\n", array[0]);


}

