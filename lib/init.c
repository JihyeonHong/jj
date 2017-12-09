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
