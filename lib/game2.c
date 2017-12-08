void game2()
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

			print(2);

			for (int a = 0; a < or_num_stage; a++)
			{
				scanf("%d", &or_array1[a]);
			}

			int temp = verify(2);

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
