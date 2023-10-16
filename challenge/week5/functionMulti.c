#include <stdio.h>

int multiF(int value);
void main()
{
	printf("1부터     2까지의 곱은 %d\n", multiF(2));
	printf("1부터   3까지의 곱은 %d\n", multiF(3));
	printf("1부터 5까지의 곱은 %d\n", multiF(5));
}

int multiF(int value)
{
	int i;
	int gop = 1;

	for (i = 1; i <= value; i = i + 1)
	{
		gop = gop * i;
	}

	return gop;
}
