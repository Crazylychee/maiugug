#define CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	scanf("%d%d%d", &a,&b,&c);
	if (a > b&&b > c)
	{
		printf("%d\n", a);
	}
	else if (b > a&& b > c)
	{
		printf("%d\n",b);
	}
else
	printf("%d\n", c);

	return 0;
}