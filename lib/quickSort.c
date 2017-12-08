void quickSort(int x[], int L, int R)
{
	int i = L, j = R, tmp;
	int pivot = x[(L + R) / 2];

	while (i <= j)
	{
		while (x[i] < pivot)
			i++;
		while (x[j] > pivot)
			j--;

		if (i <= j)
		{
			tmp = x[i];
			x[i] = x[j];
			x[j] = tmp;
			i++, j--;
		}
	}

	if (L < j)
		quickSort(x, L, j);
	if (i < R)
		quickSort(x, i, R);

}
