#include"CouElectSys.h"
int main()
{
	 struct course coursenode;	struct course *head = &coursenode;
	 struct cache cache1; struct cache *cp1 = &cache1;
	 struct student studnode; struct student *head1 = &studnode;
	 head = Init(); cp1 = Init_1(cp1); head1 = Init_2();
	do{
		int input = 0, ent;
		int *p = &input;
		ent = apply(p,cp1,head);

		if (ent == 1)
		{
			ent = TeaInfer(p,cp1,head,head1);
		}
		else if (ent == 2)
			ent = StuInfer(p,cp1,head1);
		else if (ent == 0)break;
	} while (1);
	return 0;
}
