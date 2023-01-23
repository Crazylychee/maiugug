#include"CouElectSys.h"
struct course* Init()
{
	FILE *fp;
	struct course *head;
	struct course *p1, *p2;
	int n = 0;
	fp = fopen("CourseInfo.txt", "r");
	if (fp == NULL){ printf("Cannot open file!");}
	//fseek(fp, 0, SEEK_SET);
	head =p1 = p2 = (struct course*)malloc(LEN);
	while (fscanf(fp, "%s %ld %s %f %d %d ", (p1->t1.name2), &p1->num1,
		p1->name1, &p1->score, &p1->SlctCpeo, &p1->Peomax) != -1)
	{
		if (head->next == NULL)
			head->next = p1;
		else
		{
			p2->next = p1;
		}
		p2 = p1;
		p1 = (struct course*)malloc(LEN);
		p1->next = NULL;
		p2->next = p1;
		n++;
	}
	if (!n)
	{
		*p1->t1.name2 = '\0';
		p1->num1 = 0;
		*p1->name1='\0';
		p1->score = 0.0;
		p1->SlctCpeo=0;
		p1->Peomax = 0;
		p1->next = NULL;
	}
	else{
		p1 = head;
		while (p1->next->next != NULL)
			p1 = p1->next;
		p1->next = NULL;
	}

	return head;
}
struct cache *Init_1(struct cache *cp1)	//打开缓存文件，录入关键参数
{
	FILE *fp1; 
	fp1 = fopen("cache.txt", "r+");
	if (fp1 == NULL)
		printf("fail to open !!\n");
	fscanf(fp1, "%d %d %d", &cp1->coursnum, &cp1->teachenum, &cp1->studennum);
	return cp1;
}
struct student *Init_2()
{
	FILE *fp;
	struct student *head1;
	struct student *p1, *p2;
	int n = 0;
	fp = fopen("StudentInfo.txt", "r");
	if (fp == NULL){ printf("Cannot open file!"); }
	//fseek(fp, 0, SEEK_SET);
	head1 = p1 = p2 = (struct student*)malloc(SEN);
	while (fscanf(fp, "%ld %s %s %d %d", &p1->num2, p1->name3,
		p1->SlctCNum, &p1->SlctCSum, &p1->Liminum) == 5)
	{
		if (head1->next == NULL)
			head1->next = p1;
		else
		{
			p2->next = p1;
		}
		p2 = p1;
		p1 = (struct student*)malloc(SEN);
		p1->next = NULL;
		p2->next = p1;
		n++;
	}
	if (!n)
	{
		p1->num2 = 0;
		*p1->name3 = '\0';
		*p1->SlctCNum = '\0';
		p1->SlctCSum = 0;
		p1->Liminum = Lmit;
		p1->next = NULL;
	}
	else{
		p1 = head1;
		while (p1->next->next != NULL)
			p1 = p1->next;
		p1->next = NULL;
	}
	return head1;
}