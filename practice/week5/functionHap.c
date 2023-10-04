#include <stdio.h>

int hapf(int value);
void main()
{
	printf("1부터     10까지의 합은 %d\n", hapf(10)  );
	printf("1부터   100까지의 합은 %d\n", hapf(100)  );
	printf("1부터 1000까지의 합은 %d\n", hapf(1000));
}

int hapf(int value)
{
	int i = 1;
	int hap = 0;

	while (i <= value)
	{
		hap += i;
		i++;
	}
	
	return hap;
}