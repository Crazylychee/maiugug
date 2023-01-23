#define CRT_SECURE_NO_WARNINGS 1
void menu1()//主菜单
{
	printf("*************************************\n");
	printf("**** The Course Selection System ****\n");
	printf("****                             ****\n");
	printf("****   Please input the number   ****\n");
	printf("****                             ****\n");
	printf("****      1.Teacher              ****\n");
	printf("****      2.Student              ****\n");
	printf("****      3.Exit                 ****\n");
	printf("*************************************\n\n");
}
void menu2()//教师菜单
{
	printf("*************************************\n");
	printf("****** Please input the number ******\n");
	printf("****** 1.Add                   ******\n");//增加课程
	printf("****** 2.Delete                ******\n");//删除选课
	printf("****** 3.Search                ******\n");//查找选课
	printf("****** 4.Show                  ******\n");//展示列表
	printf("****** 5.Sort                  ******\n");//编辑
	printf("****** 6.Update                ******\n");//register注册
	printf("****** 7.View                  ******\n");//查看学生选课
	printf("****** 8.DelSlct               ******\n");//删除学生选课
	printf("****** 9.Return                ******\n");//返回上一级菜单
	printf("*************************************\n");
}
void menu3()//学生菜单
{
	printf("*************************************\n");
	printf("****** Please input the number ******\n");
	printf("****** 1.Add                   ******\n");//增加选课
	printf("****** 2.Delete                ******\n");//删除选课
	printf("****** 3.Search                ******\n");//查找
	printf("****** 4.Show                  ******\n");//展示
	printf("****** 5.Updtate               ******\n");//更新
	printf("****** 6.Sort                  ******\n");//编辑
	printf("****** 7.Return                ******\n");//返回上一级
	printf("*************************************\n");
}