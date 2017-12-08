#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void game4()
{
	int array[9] = { 0 };
	int array2[9] = { 0 };

	for (int i = 0; i < 9; i++)
	{
		array[i] = rand() % 50;

				for (int j = 0; j < i; j++)
				{
					if (array[i] == array[j])//중복검사
					{
						i--;
					}
				}
	}

	for (int i = 0; i < 9; i++)
	{
		array2[i] = array[i];//copy

		printf("%d ", array[i]);
		if ((i + 1) % 3 == 0)
		{
			printf("\n");
		}
	}

	printf("\n");
	//sorting 

	quickSort(array2, 0, 8);

	for (int i = 0; i < 9; i++)
	{
		printf("%d ", array2[i]);
		if ((i + 1) % 3 == 0)
		{
			printf("\n");
		}
	}
	
	int key = 0, num = 0;
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &key);
		//key = getch();
		if (key == 7)
		{
			num = array[0];
		}
		if (key == 8)
		{
			num = array[1];
		}
		if (key == 9)
		{
			num = array[2];
		}
		if (key == 4)
		{
			num = array[3];
		}
		if (key == 5)
		{
			num = array[4];
		}
		if (key == 6)
		{
			num = array[5];
		}
		if (key == 1)
		{
			num = array[6];
		}
		if (key == 2)
		{
			num = array[7];
		}
		if (key == 3)
		{
			num = array[8];
		}

		if (num == array2[i])
		{
			printf("good ");
		}
		else
		{
			printf("Fail\n");
			break;
		}
	}
	printf("\n");
}
