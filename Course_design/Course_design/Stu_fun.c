#include"CouElectSys.h"
struct student* Add_2(struct student *head1, struct cache *cp1)
{
	struct student *p1, *p;
	int n = 0; p = head1;
	p1 = (struct student *)malloc(SEN);
	show_1s(cp1->coursnum);
	printf("以上为选课列表\n请同学按\"学生学号 学生姓名 单个已选课程名\"\n的顺序输入：(输入0 0 0结束)\n");
	scanf("%ld %s %s", &p1->num2, p1->name3, p1->SlctCNum);
	if (p1->num2){
		cp1->studennum++;
		p1->SlctCSum = 1;
		p1->Liminum = Lmit;
		p1->next = NULL;
	}
		
		while (p1->num2 != 0)
		{
			n = n + 1; p = head1;
			if (n == 1){
				if (head1->num2 == 0)head1 = p1;
				else{
					while (p->next!=NULL)
					{
						p = p->next;
					}
					p->next = p1;
				}
			}
			else {
				while (p->next != NULL)//不是则找到尾节点
				{
					p = p->next;
				}
				p->next = p1;//让尾节点接上新节点

			}
			p1 = (struct student*)malloc(SEN);
			printf("请同学按\"学生学号 学生姓名 单个已选课程名\"\n的顺序输入：(输入0 0 0结束)\n");
			scanf("%ld %s %s", &p1->num2, p1->name3, p1->SlctCNum);
			if (p1->num2){ 
				cp1->studennum++;
				p1->SlctCSum = 1; 
				p1->Liminum = Lmit;
				p1->next = NULL;
			}
		}
		return head1;	
}
struct student *Delete_2(struct student *head1, struct cache *cp1)//撤销学生选课
{
	int num = 0;
	printf("请输入要撤销选课的学生学号：\n");
	scanf("%d", &num);
	struct student *p1, *p2;
	if (head1 == NULL)
	{
		printf("\nlist null!  \n");
		return(head1);
	}
	p1 = head1;
	while (num != p1->num2 && p1->next != NULL)
	{
		p2 = p1; p1 = p1->next;
	}
	if (num == p1->num2)
	{
		if (p1 == head1)head1 = p1->next;
		else p2->next = p1->next;
		printf("delete:%ld\n", num);
		cp1->studennum--;
	}
	else printf("%ld not been found! \n", num);
	return(head1);
}
void Search_2(struct student *head1)
{
	int a = 1;
	do{
		long num = 0;
		printf("请输入要查找的学号：\n");
		scanf("%ld", &num);
		struct student *p1, *p2;
		if (head1 == NULL)
		{
			printf("\nlist null!  \n");
		}
		p1 = head1; a = 0;
		while (p1->next != NULL)
		{
			if (num == p1->num2)
			{
				if (!a){ printf("查找的课程信息如下:\n"); printf("学号\t学生名字\t课程名称\t已选课程数量\t限选\n"); }
				printf("%ld\t%s\t\t%s\t\t%d\t\t%d\n\n", p1->num2, p1->name3, p1->SlctCNum, p1->SlctCSum, p1->Liminum); 
				a++;
			}
			p2 = p1; p1 = p1->next;
		}
		if (!a){
			printf("%ld not been found! \n", num);
		}
		printf("输入0结束查找\n");
		scanf("%d", &a);
		system("cls");
	} while (a);
}
void show_2(struct student* head1, int n)
{
	do{
		FILE *fp;
		fp = fopen("StudentInfo.txt", "r");
		if (fp == NULL){
			printf("fail to open!!");
		}
		printf("学号\t学生名字\t课程名称\t已选课程数量\t限选\n");
		for (int i = 0; i < n; i++)
		{
			fscanf(fp, "%ld %s %s %d %d", &StudInfo[i].num2,
				StudInfo[i].name3, StudInfo[i].SlctCNum, &StudInfo[i].SlctCSum,
				&StudInfo[i].Liminum);
			//fread(&CourInfo[i], LEN, 1, fp);
			printf("%ld\t%s\t\t%s\t\t%d\t\t%d\n", StudInfo[i].num2,
				StudInfo[i].name3, StudInfo[i].SlctCNum, StudInfo[i].SlctCSum,
				StudInfo[i].Liminum);
		}
		fclose(fp);
		printf("输入0返回上级菜单\n输入1重复当前操作\n");
		scanf("%d", &N1);
		if (N1 == 0){ system("cls"); menu3(); break; }
	} while (1);
}
void Update_2(struct student *head1,struct cache *cp1)//更新课程信息
{
	FILE *fp; struct student *p;
	p = head1;
	fp = fopen("StudentInfo.txt", "wb");
	if (fp == NULL)printf("fail to open!!");
	for (int i = 0; i < cp1->studennum; i++){
		if (p == NULL||p->num2==0)break;
		fprintf(fp, "%ld ", p->num2);
		fprintf(fp, "%s ", p->name3);
		fprintf(fp, "%s ", p->SlctCNum);
		fprintf(fp, "%d ", p->SlctCSum);
		fprintf(fp, "%d ", p->Liminum);
		p = p->next;
	}
	fclose(fp);
	FILE *fp1; struct cache *p1;
	p1 = cp1;
	fp1 = fopen("cache.txt", "wb");
	if (fp1 == NULL)printf("fail to open!!");
	//fwrite(p1, CEN, 1, fp1);
	fprintf(fp1, "%d %d %d", cp1->coursnum, cp1->teachenum,
		cp1->studennum);
	fclose(fp1);
	printf("添加选课成功!!!\n");
}
struct student* sort_2(struct cache *cp1, struct student *head1)
{
	struct student* pre, *cur, *next, *end, *p1, *p2;
	end = NULL;
	if (head1->num2 > head1->next->num2)
	{
		p1 = head1;
		p2 = head1->next;
		head1 = p2;
		p1->next = p2->next;
		p2->next = p1;
	}
	while (head1->next != end)
	{
		pre = head1, cur = pre->next, next = cur->next;
		for (; next != end; pre = pre->next, cur = cur->next, next = next->next)
		{
			if (cur->num2 > next->num2)
			{
				pre->next = next;
				cur->next = next->next;
				next->next = cur;
				struct student* temp = cur; cur = next; next = temp;
			}
		}
		if (cp1->coursnum == 2 && pre->num2>cur->num2)
		{
			pre->next = NULL;
			cur->next = pre;
			return cur;
		}
		end = cur;
	}
	return head1;
}
void show_1s(int n)
{
		FILE *fp;
		fp = fopen("CourseInfo.txt", "r");
		if (fp == NULL){
			printf("fail to open!!");
		}
		printf("老师姓名\t课程编号\t课程名称\t课程学分\t已选人数\t课程人数上限\n");
		for (int i = 0; i < n; i++)
		{
			fscanf(fp, "%s %ld %s %f %d %d", CourInfo[i].t1.name2,
				&CourInfo[i].num1, CourInfo[i].name1, &CourInfo[i].score,
				&CourInfo[i].SlctCpeo, &CourInfo[i].Peomax);
			//fread(&CourInfo[i], LEN, 1, fp);
			printf("%s\t\t%ld\t\t%s\t\t%.2f\t\t%d\t\t%d\n", CourInfo[i].t1.name2,
				CourInfo[i].num1, CourInfo[i].name1, CourInfo[i].score,
				CourInfo[i].SlctCpeo, CourInfo[i].Peomax);
		}
		fclose(fp);
}