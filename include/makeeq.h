#ifndef MAKEEQ_H
#define MAKEEQ_H

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

void makeeq();

#endif
