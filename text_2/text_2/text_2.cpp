#define CRT_SECURE_NO_WARNINGS 1
#include"Add.h"
#include<stdio.h>
int main()
{
	int a = 23;
	int b = 34;
	int c = Add(a, b);
	printf("%d\n",c);
	return 0;
}