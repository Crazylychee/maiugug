#include"CouElectSys.h"
struct course* Add_1(struct course *head,struct cache *cp1)//老师课程的添加
{
	struct course *p1, *p2, *p;
	int n = 0; p = head;
	p1 = p2 = (struct course *)malloc(LEN);//链表的添加就是在最后一个节点后添加新节点
	printf("请老师按\"老师姓名 课程编号 课程名称 课程学分 课程人数上限\"\n的顺序输入：(输入0 0 0 0 0结束)\n");//逗号不能用，因为会被%s吃掉
	scanf("%s %ld %s %f %d", p1->t1.name2,&p1->num1, p1->name1, &p1->score, &p1->Peomax);
	if (p1->num1){//根据num1是否为零来初始化SletCpeo
		cp1->coursnum++;
		p1->SlctCpeo = 0;
		p1->next = NULL;//让新节点尾部安全
	}
	while (p1->num1 != 0)//进入添加节点循环
	{
		n = n + 1; p = head;
		if (n == 1){//如果是第一次添加
			if (head->num1 == 0)head = p1;//头节点为空则代替头节点
			else{
				while (p->next!= NULL)//不是则找到尾节点
				{
					p = p->next;
				}
				p->next = p1;//让尾节点接上新节点
			}
		}
		else {
			while (p->next != NULL)//不是则找到尾节点
			{
				p = p->next;
			}
			p->next = p1;//让尾节点接上新节点
		
		}
		p1 = (struct course*)malloc(LEN);//开辟新空间
		printf("请老师按\"老师姓名 课程编号 课程名称 课程学分 课程人数上限\"\n的顺序输入：(输入0 0 0 0 0结束)\n");
		scanf("%s %ld %s %f %d", p1->t1.name2, &p1->num1, p1->name1, &p1->score, &p1->Peomax);
		if (p1->num1){
			cp1->coursnum++;
			p1->SlctCpeo = 0;
			p1->next = NULL;//让新节点尾部安全
		}
	}
	return head;
}
struct course *Delete_1(struct course *head, struct cache *cp1)//删除课程
{
	show_1s(cp1->coursnum);
	int num = 0;
	printf("请输入要删除的课程编号\n");
	scanf("%d", &num);
	struct course *p1, *p2;
	if (head == NULL)
	{
		printf("\nlist null!  \n");
		return(head);
	}
	p1 = head;
	while (num != p1->num1 && p1->next != NULL)
	{
		p2 = p1; p1 = p1->next;
	}
	if (num == p1->num1)
	{
		if (p1 == head)head = p1->next;
		else p2->next = p1->next;
		printf("delete:%ld\n", num);
		cp1->coursnum--;
	}
	else printf("%ld not been found! \n", num);
	return(head);
}

void show_1(int n)
{
	do{
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
		printf("输入0返回上级菜单\n输入1重复当前操作\n");
		scanf("%d", &N1);
		if (N1 == 0){ system("cls"); menu2(); break; }
	} while (1);
}
void Update_1(struct cache *cp1,struct course *head)//更新课程信息
{
	FILE *fp; struct course *p;
	p = head;
	fp = fopen("CourseInfo.txt", "wb");
	if (fp == NULL)printf("fail to open!!");
	for (int i = 0; i < cp1->coursnum;i++){
		if (p == NULL)break;
		fprintf(fp, "%s ", p->t1.name2);
		fprintf(fp, "%ld ", p->num1);
		fprintf(fp, "%s ", p->name1);
		fprintf(fp, "%f ", p->score);
		fprintf(fp, "%d ", p->SlctCpeo);
		fprintf(fp, "%d ", p->Peomax);
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
	printf("添加课程成功!!!\n");
}
void Search_1(struct course *head)
{
	int a = 1;
	do{
		long num = 0;
		printf("请输入要查找的课程号：\n");
		scanf("%ld", &num);
		struct course *p1, *p2;
		if (head == NULL)
		{
			printf("\nlist null!  \n");
		}
		p1 = head; a = 0;
		while (p1->next != NULL)
		{
			if (num == p1->num1)
			{
				if (!a){ printf("查找的课程信息如下:\n"); printf("老师姓名\t课程编号\t课程名称\t课程学分\t已选人数\t课程人数上限\n"); }
				printf("%s\t\t%ld\t\t%s\t\t%.2f\t\t%d\t\t%d\n", p1->t1.name2, p1->num1, p1->name1, p1->score, p1->SlctCpeo,p1->Peomax);
				a++;
			}
			p2 = p1; p1 = p1->next;
		}
		if(!a)printf("%ld not been found! \n", num);
		printf("输入0结束查找\n");
		scanf("%d", &a);
		system("cls");
	} while (a);
}

struct course* sort_1(struct cache *cp1, struct course *head)
{
	struct course* pre, *cur, *next, *end, *p1, *p2;
	end = NULL;
	if (head->num1 > head->next->num1)
	{
		p1 = head;                
		p2 = head->next;
		head = p2;                
		p1->next = p2->next;    
		p2->next = p1;          
	}
	while (head->next != end)
	{
		pre = head, cur = pre->next, next = cur->next;
		for (; next != end; pre = pre->next, cur = cur->next, next = next->next)
		{
			if (cur->num1 > next->num1) 
			{
				pre->next = next;
				cur->next = next->next;
				next->next = cur;
				struct course* temp = cur; cur = next; next = temp;
			}
		}
		if (cp1->coursnum==2&&pre->num1>cur->num1) 
			{
				pre->next = NULL;
				cur->next = pre;
				return cur;
			}
		end = cur;
	}
	return head;
}
void Cancel_l()
{}
void Teacher_s()
{}
//int find(struct course* head, char *t)
//{
//	struct course *p;
//	p = head;
//	while (!(strcmp(p->t1.name2, t)))
//	{
//		p = p->next;
//		if (p->next ==NULL)break;
//	}
//	if (p->next==NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}
//}