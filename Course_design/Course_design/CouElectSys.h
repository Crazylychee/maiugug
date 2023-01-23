#define CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<malloc.h>
#define CEN sizeof(struct cache)
#define LEN sizeof(struct course)
#define SEN sizeof(struct student)
#define Lmit 2
#define NAME_MAX 10//名称最大值
#define NUM_MAX 8//学号最大
#define COUR_CMAX 2//选课最大数
#define COUR_TMAX 4//老师创建课程最大值
#define TEAC_MAX 6
#define STU_MAX 30
//函数的声明
	//初始化函数
struct course *Init();
struct cache *Init_1(struct cache *cp1);
struct student *Init_2();
	//菜单函数
void menu1();
void menu2();
void menu3();
	//操作函数
int apply(int *a,struct cache *cp1, struct course *head);
int TeaInfer(int *a, struct cache *cp1, struct course *head, struct student *head1);
int StuInfer(int *a, struct cache *cp1, struct student *head1);


	//老师端功能函数
void login_1(struct course *head);//老师登录，添加老师
struct course* Add_1(struct course *head, struct cache *cp1);//添加课程
struct course* Delete_1(struct course *head, struct cache*cp1);//删除课程
void Search_1(struct course *head);//查找信息
void show_1(int n);//展示全部信息
struct course* sort_1(struct cache *cp1, struct course *head);//按课程编号排序信息
void Update_1(struct cache *cp1, struct course *head);//更新课程信息



	//学生端功能函数
struct student* Add_2(struct student *head1,struct cache *cp1);//增加选课
struct student *Delete_2(struct student *head1, struct cache *cp1);//删除选课
void Search_2(struct student*head1);//查找选课
void show_2(struct student *head1, int n);//展示已选课程
void Update_2(struct student *head1, struct cache *cp1);
struct student* sort_2(struct cache *cp1, struct student *head1);
void show_1s(int n);
	//枚举变量
enum choice1
{
	Extra,//加多一个使对应数字正确
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
struct teacher//教师信息结构体
{
	char name2[NAME_MAX];
	struct teacher* next;
}t1;
struct course//课程信息结构体
{
	struct teacher t1;
	long num1;
	char name1[NAME_MAX];
	float score;
	int SlctCpeo;//课程已选人数
	int Peomax;//课程人数上限
	struct course * next;
}CourInfo[100];

struct student//学生信息结构体
{
	long num2;//学号
	char name3[NAME_MAX];//姓名
	char SlctCNum[NAME_MAX];//已选课程名
	int SlctCSum;//已选课程数量
	int Liminum;
	struct student * next;
}StudInfo[50];
struct cache
{
	int coursnum;
	int teachenum;
	int studennum;
};
