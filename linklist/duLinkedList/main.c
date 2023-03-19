#include "duLinkedList.h"
//主要实现交互界面,暂时用控制台文本化界面
int main() {
    int a=0;DuLNode *L;
    void (*b)(ElemType) = 0;
    void (*e)(ElemType) = 0;
    DuLNode *q;

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
            case 1:
                if (!InitList_DuL(L))printf("内存不足,无法分配空间");
                menu();
                break;
            case 2:
                DestroyList_DuL(L);
//                menu();
                break;
            case 3:

                q = (DuLNode *) malloc(LEN);
                if (L == NULL) {
                    printf("内存不足,请稍后再试!!");
                    return OVERFLOW;
                }
                InsertBeforeList_DuL(L, q);
//                menu();
                break;
            case 4:
                InsertAfterList_DuL(L, q);
                break;
            case 5:
                DeleteList_DuL(L, e);
                break;
            case 6:
                TraverseList_DuL(L, b);
//                menu();
                break;
            default:
                break;
        }
    }
    while (a!=10);
    return 0;
}
