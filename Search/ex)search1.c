#include <stdio.h>


int bsearch(int *a, int n, int v)
{
	int l = 0, r = n - 1, m = 0;
	while (l <= r) 
		{
		m = l + ((r - l) >> 1);
		if (a[m] > v)
		{
			r = m - 1;
		}
		else if (a[m] < v)
		{
			l = m + 1;
		}
		else
		{
			return m;
		}
	}
	return -1;
}
int main(int argc, char **argv)
{
	int data[100];
	int i = 0, index = -1;
	for (; i < 100; i++)
	{
		data[i] = i + 10;
	}
	index = bsearch(data, 100, 44);
	printf("Find index = %d value = %d\n", index, data[index]);
	return 0;
}
