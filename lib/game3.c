void game3()
{
	stage = 1;
	init(stage);

	int testresult;

	for (int i = 1; i <= 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			testresult = makeeq();

			while (testresult < 0)
				testresult = makeeq();

			print(3);

			char sp;

			for (int i = 0; i < or_op_stage; i++)
				scanf("%c%c", &or_array2[i], &sp);

			int temp = verify(3);

			if (result == temp)
				printf("correct!\n");
			else
				printf("wrong!\n");

			init(stage);
		}

		stage++;
		init(stage);
	}
}
