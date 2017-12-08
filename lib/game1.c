void game1()
{
	stage = 1;
	init(stage);

	for (int i = 1; i <= 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int testresult = makeeq();

			while (testresult < 0)
				testresult = makeeq();

			print(1);
			int temp = verify(1);

			if (result == temp)
				printf("correct!\n");
			else
				printf("wrong!\n");
		}

		stage++;
		init(stage);
	}
}
