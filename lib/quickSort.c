#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "game1.h"
#include "init.h"
#include "makeeq.h"
#include "verify.h"
#include "print.h"


#define PLUS 43
#define MINUS 45
#define MULTI 42
#define DIVIDE 47

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

void quickSort(int x[], int L, int R)
{
	int i = L, j = R, tmp;
	int pivot = x[(L + R) / 2];

	while (i <= j)
	{
		while (x[i] < pivot)
			i++;
		while (x[j] > pivot)
			j--;

		if (i <= j)
		{
			tmp = x[i];
			x[i] = x[j];
			x[j] = tmp;
			i++, j--;
		}
	}

	if (L < j)
		quickSort(x, L, j);
	if (i < R)
		quickSort(x, i, R);

}
