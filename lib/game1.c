void game1()
{
	int life = 3;

	stage = 1;
	init(stage);

	int testresult;

	for (int i = 1; i <= 3; i++)
	{
		printf("\n<<<<<<<<<<<<<<<<<< Stage%d >>>>>>>>>>>>>>>>>>\n\n", i);
		for (int j = 0; j < 3; j++)
		{
			printf("life : ");
			for (int h = 0; h < life; h++)
			{
				printf("♥ ");
			}
			printf("\n");
			testresult = makeeq();

			while (testresult < 0)
				testresult = makeeq();

			print(1);
			int temp = verify(1);

			if (result == temp)
				printf("Correct!\n\n");
			else
			{
				printf("Wrong!\n\n");
				life--;
				if (life == 0)
				{
					printf("=========== GAME OVER ==========\n");
					return;
				}
			}
		}

		stage++;
		init(stage);
	}
}
