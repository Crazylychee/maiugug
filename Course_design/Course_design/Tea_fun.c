#include"CouElectSys.h"
struct course* Add_1(struct course *head,struct cache *cp1)//��ʦ�γ̵����
{
	struct course *p1, *p2, *p;
	int n = 0; p = head;
	p1 = p2 = (struct course *)malloc(LEN);//�������Ӿ��������һ���ڵ������½ڵ�
	printf("����ʦ��\"��ʦ���� �γ̱�� �γ����� �γ�ѧ�� �γ���������\"\n��˳�����룺(����0 0 0 0 0����)\n");//���Ų����ã���Ϊ�ᱻ%s�Ե�
	scanf("%s %ld %s %f %d", p1->t1.name2,&p1->num1, p1->name1, &p1->score, &p1->Peomax);
	if (p1->num1){//����num1�Ƿ�Ϊ������ʼ��SletCpeo
		cp1->coursnum++;
		p1->SlctCpeo = 0;
		p1->next = NULL;//���½ڵ�β����ȫ
	}
	while (p1->num1 != 0)//������ӽڵ�ѭ��
	{
		n = n + 1; p = head;
		if (n == 1){//����ǵ�һ�����
			if (head->num1 == 0)head = p1;//ͷ�ڵ�Ϊ�������ͷ�ڵ�
			else{
				while (p->next!= NULL)//�������ҵ�β�ڵ�
				{
					p = p->next;
				}
				p->next = p1;//��β�ڵ�����½ڵ�
			}
		}
		else {
			while (p->next != NULL)//�������ҵ�β�ڵ�
			{
				p = p->next;
			}
			p->next = p1;//��β�ڵ�����½ڵ�
		
		}
		p1 = (struct course*)malloc(LEN);//�����¿ռ�
		printf("����ʦ��\"��ʦ���� �γ̱�� �γ����� �γ�ѧ�� �γ���������\"\n��˳�����룺(����0 0 0 0 0����)\n");
		scanf("%s %ld %s %f %d", p1->t1.name2, &p1->num1, p1->name1, &p1->score, &p1->Peomax);
		if (p1->num1){
			cp1->coursnum++;
			p1->SlctCpeo = 0;
			p1->next = NULL;//���½ڵ�β����ȫ
		}
	}
	return head;
}
struct course *Delete_1(struct course *head, struct cache *cp1)//ɾ���γ�
{
	show_1s(cp1->coursnum);
	int num = 0;
	printf("������Ҫɾ���Ŀγ̱��\n");
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
		printf("��ʦ����\t�γ̱��\t�γ�����\t�γ�ѧ��\t��ѡ����\t�γ���������\n");
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
		printf("����0�����ϼ��˵�\n����1�ظ���ǰ����\n");
		scanf("%d", &N1);
		if (N1 == 0){ system("cls"); menu2(); break; }
	} while (1);
}
void Update_1(struct cache *cp1,struct course *head)//���¿γ���Ϣ
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
	printf("��ӿγ̳ɹ�!!!\n");
}
void Search_1(struct course *head)
{
	int a = 1;
	do{
		long num = 0;
		printf("������Ҫ���ҵĿγ̺ţ�\n");
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
				if (!a){ printf("���ҵĿγ���Ϣ����:\n"); printf("��ʦ����\t�γ̱��\t�γ�����\t�γ�ѧ��\t��ѡ����\t�γ���������\n"); }
				printf("%s\t\t%ld\t\t%s\t\t%.2f\t\t%d\t\t%d\n", p1->t1.name2, p1->num1, p1->name1, p1->score, p1->SlctCpeo,p1->Peomax);
				a++;
			}
			p2 = p1; p1 = p1->next;
		}
		if(!a)printf("%ld not been found! \n", num);
		printf("����0��������\n");
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