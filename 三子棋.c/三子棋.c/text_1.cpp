#define CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{

	int a = 0;
	int *pa = &a;
	int pa = 20;
	printf("%d\n", pa);
	return 0;
}