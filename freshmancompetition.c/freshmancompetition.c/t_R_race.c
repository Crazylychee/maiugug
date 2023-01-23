#define CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


/////龟兔
int main()
{
	int v1 = 0, v2 = 0, t = 0, time = 0, s = 0, l = 0, flag = 0;
	scanf("%d%d%d%d%d", &v1, &v2, &t, &s, &l);
	int s1 = 0, s2 = 0;
	while (s1 < l && s2 < l)
	{
		time++;
		s1 = v1 * (time - flag);
		s2 = v2 * time;
		if (s1 >= l && s2 < l)
		{
			printf("R\n");
			printf("%d", time);
			return 0;
		}
		if (s2 >= l && s1 < l)
		{
			printf("T\n");
			printf("%d", time);
			return 0;
		}
		if (s2 >= l&&s1 >= l)
		{
			printf("D\n");
			printf("%d", time);
			return 0;
		}
		while (s1 - s2 >= t)     ///改为while一直追不上
		{
			/////*time += s;
			////s2 = v2 * time;
			////flag++;*/
			for (int x = 1; x <= s; x++)
			{
				flag++;
				time++;
				s2 = time * v2;
				if (s2 >= l)
				{
					printf("T\n");
					printf("%d", time);
					return 0;
				}
			}
		}
		if (s2 >= l)
		{
			printf("T\n");
			printf("%d", time);
			return 0;
		}
	}
	return 0;
}