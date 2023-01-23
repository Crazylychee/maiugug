#include"CouElectSys.h"
int apply(int *a, struct cache *cp1, struct course *head)
{
	do{
		menu1();
		scanf("%d", a);
		while (*a>3 || *a <= 0)
		{
			system("cls");
			menu1();
			printf("error! please input the number again!\n\n");
			getchar();
			scanf("%d", a);
			system("cls");
		}
		switch (*a)
		{
		case Teacher:
			system("cls");
			//login_1(head);
			menu2();
			return 1;
		case Student:
			system("cls");
			menu3();
			return 2;
		case Exit:
			*a = 0;
			system("cls");
			return 0;
		default:
			printf("error! please input the number again!\n");
		}
	} while (1);
}
int TeaInfer(int *a, struct cache *cp1, struct course *head,struct student *head1)
{
	do
	{
		*a = 0;
		getchar();
		scanf("%d", a);
		system("cls");
		while (*a>9 || *a <= 0)
		{
			menu2();
			printf("error! please input the number again!\n\n");
			getchar();
			scanf("%d", a);
			system("cls");
		}//Gives the code the ability to check for errors
		switch ((int)*a)
		{
		case Add1:
			head = Add_1(head,cp1);
			menu2();
			break;
		case Delete1:
			head = Delete_1(head,cp1);
			menu2();
			break;
		case Search1:
			Search_1(head);
			menu2();
			break;
		case Show1:
			show_1(cp1->coursnum);
			break;
		case sort1:
			head = sort_1(cp1,head);
			break;
		case Update1:
			Update_1(cp1,head);
			menu2();
			break;
		case View:
			show_2(head1, cp1->studennum);
			break;
		case DelSlct:
			head1 = Delete_2(head1, cp1);
			break;
		case Return1:
			*a = 0;
			return 1;
		default:
			break;
		}
	} while (*a);
	*a = 0;
	return 0;
}
int StuInfer(int *a,struct cache *cp1, struct student *head1)
{
	do{
		*a = 0;
		getchar();
		scanf("%d", a);
		system("cls");
		while (*a>7 || *a<=0)
		{
			menu3();
			printf("error! please input the number again!\n\n");
			getchar();
			scanf("%d", a);
			system("cls");
		}//Gives the code the ability to check for errors
		switch ((int)*a)
		{
		case Add2:
			head1 = Add_2(head1,cp1);
			menu3();
			break;
		case Delete2:
			head1 = Delete_2(head1,cp1);
			menu3();
			break;
		case Search2:
			Search_2(head1);
			menu3();
			break;
		case Show2:
			show_2(head1,cp1->studennum);
			break;
		case Update2:
			Update_2(head1,cp1);
			menu3();
			break;
		case sort2:
			head1 = sort_2(cp1,head1);
			menu3();
			break;
		case Return2:
			return 1;
			*a = 0;
			break;
		default:
			break;
		}
	} while (*a);
	*a = 0;
	return 0;
}


