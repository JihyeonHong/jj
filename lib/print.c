void print(int game_num)
{
	int a = 0, b = 0;

	if (game_num == 1)
	{
		array1[0] = '_';

		a = 0, b = 0;
		for (int i = 0; i < or_num_stage + or_op_stage; i++)//print
		{
			if (i % 2 == 0)
				printf("%d ", or_array1[a++]);
			else if (or_array2[b] == PLUS)
				printf("+ ", or_array2[b++]);
			else if (or_array2[b] == MINUS)
				printf("- ", or_array2[b++]);
			else if (or_array2[b] == MULTI)
				printf("* ", or_array2[b++]);
			else if (or_array2[b] == DIVIDE)
				printf("/ ", or_array2[b++]);
		}
		printf("= %c\n", array1[0]);
	}

	else if (game_num == 2)
	{
		for (int i = 0; or_array1[i] != NULL; i++)
		{
			or_array1[i] = '_';
		}

		a = 0, b = 0;
		for (int i = 0; i < or_num_stage + or_op_stage; i++)//print
		{
			if (i % 2 == 0)
				printf("%c ", or_array1[a++]);
			else if (or_array2[b] == PLUS)
				printf("+ ", or_array2[b++]);
			else if (or_array2[b] == MINUS)
				printf("- ", or_array2[b++]);
			else if (or_array2[b] == MULTI)
				printf("* ", or_array2[b++]);
			else if (or_array2[b] == DIVIDE)
				printf("/ ", or_array2[b++]);
		}
		printf("= %d\n", array1[0]);
	}

	else if (game_num == 3)
	{
		for (int i = 0; or_array2[i] != NULL; i++)
		{
			or_array2[i] = '_';
		}

		a = 0, b = 0;
		for (int i = 0; i < or_num_stage + or_op_stage; i++)//print
		{
			if (i % 2 == 0)
				printf("%d ", or_array1[a++]);
			else 
				printf("%c ", or_array2[b++]);
		}
		printf("= %d\n", array1[0]);
	}
}
