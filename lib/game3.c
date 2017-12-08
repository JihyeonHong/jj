void game3()
{
	print(3);

	char sp;

	for (int i = 0; i < or_op_stage; i++)
		scanf("%c%c", &or_array2[i], &sp);

	int temp = verify(3);

	if (result == temp)
		printf("correct!\n");
	else
		printf("wrong!\n");
}
