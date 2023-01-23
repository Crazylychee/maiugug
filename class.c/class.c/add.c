#define CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int Add(int a,int b);
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d%d", &a,&b);
	int sum = 0;

	sum = Add(a,b);
	printf("%d\n", sum);
	return 0;
}
int Add(int a,int b)
{
	int sum = 0;
	sum = a + b;

	return sum;
}