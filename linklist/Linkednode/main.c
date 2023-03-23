//#include <dvec.h>
//#include "linkedList.h"
////主要实现交互界面,暂时用控制台文本化界面
//int main() {
//    ElemType b;
//    int a=0;LinkedList L;
////    void (*e)(ElemType) = 0;
//    LinkedList *q;
//
////    InitList(&L);
////    L = ListTailInsert(&L);
////    *L = ListHeadInsert(*L);
//    //选择功能
//    do
//    {
//        menu();
//        //误输字符不会使程序奔溃
//        scanf("%d", &a);
//        switch ((int)a) {
//            case DestroyList1:
//                DestroyList(L);
////                menu();
//                break;
//            case InsertList1:
//                q = (LNode *) malloc(LEN);
//                if (L == NULL) {
//                    printf("error");
//                    return OVERFLOW;
//                }
//                    InsertList(L, q);
////                menu();
//                    break;
//
//            case DeleteList1:
////                        DeleteList(L, &b);
//                    break;
//                    case TraverseList1:
////                        TraverseList(L, e);
//                    break;
//                    case SearchList1:
//                        SearchList(L, b);
////                menu();
//                    break;
//                    case ReverseList1:
//                        if (ReverseList(L)) {
//                            printf("reverse successfully");
//                        } else {
//                            printf("fail to reverse ");
//                        };
//                    break;
//                    case IsLoopList1:
//                        IsLoopList(L);
//                    break;
//                    case ReverseEvenList1:
//                        ReverseEvenList(L);
//                    break;
//                    case FindMidNode1:
//                        FindMidNode(L);
//                    break;
//                    case return1:
//                        a = 10;
//                        break;
//                    default:
//                        break;
//                }
//        }
//     while (a!=10);
//    return 0;
//}
