#define CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<malloc.h>
#define CEN sizeof(struct cache)
#define LEN sizeof(struct course)
#define SEN sizeof(struct student)
#define Lmit 2
#define NAME_MAX 10//�������ֵ
#define NUM_MAX 8//ѧ�����
#define COUR_CMAX 2//ѡ�������
#define COUR_TMAX 4//��ʦ�����γ����ֵ
#define TEAC_MAX 6
#define STU_MAX 30
//����������
	//��ʼ������
struct course *Init();
struct cache *Init_1(struct cache *cp1);
struct student *Init_2();
	//�˵�����
void menu1();
void menu2();
void menu3();
	//��������
int apply(int *a,struct cache *cp1, struct course *head);
int TeaInfer(int *a, struct cache *cp1, struct course *head, struct student *head1);
int StuInfer(int *a, struct cache *cp1, struct student *head1);


	//��ʦ�˹��ܺ���
void login_1(struct course *head);//��ʦ��¼�������ʦ
struct course* Add_1(struct course *head, struct cache *cp1);//��ӿγ�
struct course* Delete_1(struct course *head, struct cache*cp1);//ɾ���γ�
void Search_1(struct course *head);//������Ϣ
void show_1(int n);//չʾȫ����Ϣ
struct course* sort_1(struct cache *cp1, struct course *head);//���γ̱��������Ϣ
void Update_1(struct cache *cp1, struct course *head);//���¿γ���Ϣ



	//ѧ���˹��ܺ���
struct student* Add_2(struct student *head1,struct cache *cp1);//����ѡ��
struct student *Delete_2(struct student *head1, struct cache *cp1);//ɾ��ѡ��
void Search_2(struct student*head1);//����ѡ��
void show_2(struct student *head1, int n);//չʾ��ѡ�γ�
void Update_2(struct student *head1, struct cache *cp1);
struct student* sort_2(struct cache *cp1, struct student *head1);
void show_1s(int n);
	//ö�ٱ���
enum choice1
{
	Extra,//�Ӷ�һ��ʹ��Ӧ������ȷ
	Teacher,
	Student,
	Exit
};
enum choice2
{
	Extra1,
	Add1,
	Delete1,  
	Search1, 
	Show1,  
	sort1, 
	Update1,
	View, 
	DelSlct,
	Return1, 
};
enum choice3
{
	Extra2,
	Add2, 
	Delete2,
	Search2, 
	Show2,   
	Update2, 
	sort2,
	Return2, 
};
int N1, N2, kk1, kk2, kk3;
struct course * head1;
struct student * head2;
struct teacher//��ʦ��Ϣ�ṹ��
{
	char name2[NAME_MAX];
	struct teacher* next;
}t1;
struct course//�γ���Ϣ�ṹ��
{
	struct teacher t1;
	long num1;
	char name1[NAME_MAX];
	float score;
	int SlctCpeo;//�γ���ѡ����
	int Peomax;//�γ���������
	struct course * next;
}CourInfo[100];

struct student//ѧ����Ϣ�ṹ��
{
	long num2;//ѧ��
	char name3[NAME_MAX];//����
	char SlctCNum[NAME_MAX];//��ѡ�γ���
	int SlctCSum;//��ѡ�γ�����
	int Liminum;
	struct student * next;
}StudInfo[50];
struct cache
{
	int coursnum;
	int teachenum;
	int studennum;
};
