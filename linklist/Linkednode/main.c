#include "linkedList.h"
//主要实现交互界面,暂时用控制台文本化界面
int main() {
    int a=0;LinkedList L;int b=0;
    void (*e)(ElemType) = 0;
    LinkedList *q;

   //选择功能
    do
    {
        menu();
        //误输字符不会使程序奔溃
        scanf("%d", &a);
        system("cls");
        while (a>10 || a < 0)
        {
            menu();
            printf("error! please input the number again!\n\n");
            getchar();
            scanf("%d", &a);
            system("cls");
        }//Gives the code the ability to check for errors
        switch ((int)a) {
            case InitList1:
                if (!InitList(L))printf("内存不足,无法分配空间");
                menu();
                break;
            case DestroyList1:
                DestroyList(L);
//                menu();
                break;
            case InsertList1:

                q = (LNode *) malloc(LEN);
                if (L == NULL) {
                    printf("内存不足,请稍后再试!!");
                    return OVERFLOW;
                }
                    InsertList(L, q);
//                menu();
                    break;
                    case DeleteList1:
                        DeleteList(L, b);
                    break;
                    case TraverseList1:
                        TraverseList(L, e);
                    break;
                    case SearchList1:
                        SearchList(L, b);
//                menu();
                    break;
                    case ReverseList1:
                        if (ReverseList(L)) {
                            printf("只有一个节点无需反转");
                        } else {
                            printf("反转成功!!");
                        };
                    break;
                    case IsLoopList1:
                        IsLoopList(L);
                    break;
                    case ReverseEvenList1:
                        ReverseEvenList(L);
                    break;
                    case FindMidNode1:
                        FindMidNode(L);
                    break;
                    //有退出功能
                    case return1:
                        a = 0;
                        break;
                    default:
                        break;
                }
        }
     while (a!=10);
    return 0;
}
