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
