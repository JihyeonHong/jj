void game2()
{
	print(2);

	for (int i = 0; i < or_num_stage; i++)
	{
		scanf("%d", &or_array1[i]);
	}

	int temp = verify(2);

	if (result == temp)
		printf("correct!\n");
	else
		printf("wrong!\n");
}
