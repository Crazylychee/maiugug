//
// Created by yc on 2023/3/19.
//
#include "linkedList.h"
void menu()
{
    printf("*************************************\n");
    printf("****** Please input the number ******\n");
    printf("****** 0.InitList              ******\n");//
    printf("****** 1.DestroyList           ******\n");//
    printf("****** 2.InsertList            ******\n");//
    printf("****** 3.DeleteList            ******\n");//
    printf("****** 4.TraverseList          ******\n");//
    printf("****** 5.SearchList            ******\n");//
    printf("****** 6.ReverseList           ******\n");//
    printf("****** 7.IsLoopList            ******\n");//
    printf("****** 8.ReverseEvenList       ******\n");//
    printf("****** 9.FindMidNode          ******\n");
    printf("****** 10.Exit                ******\n");
    printf("*************************************\n");
}
Status InitList(LinkedList L)
{
    L= (LinkedList)malloc(LEN);
    if(L==NULL){
        printf("内存不足,请稍后再试!!");
        return OVERFLOW;
    }
    L->data = 0;L->next=NULL;
    return SUCCESS;
}

void DestroyList(LinkedList *L)
{
    LinkedList p = L;
    while(p)
    {
        p = p->next;
        free(L);
        L = p;
    }
}

Status InsertList(LNode *p, LNode *q)
{
    //就是将新节点链接到p之后
    if(p==NULL||q == NULL)
        return ERROR;
    q->next = p->next;
    p->next = q;

    return SUCCESS;
}

Status DeleteList(LNode *p, ElemType e)
{
    //排除不可取的情况,链表为空,
    if(p ==NULL||p->next == NULL)return ERROR;
    LinkedList q= p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return e;
}
void TraverseList(LinkedList L, void (*visit)(ElemType e))
{
    LinkedList p = L->next;
    while(p){
        visit(p->data);
        p=p->next;
    }
}
Status SearchList(LinkedList L, ElemType e)
{
    if(L->next == NULL) return ERROR;
    LinkedList p = L->next;
    while(p->data != e&&p != NULL){
        p=p->next;
    }
    return SUCCESS;
}
Status ReverseList(LinkedList L){
    //边界条件:如果是只有一个节点,或是空链表就不用操作
    if(!L || L->next) {
        return ERROR;
    }
    //step1: 先把后面的反了,递归实现
    L->next->next = L;
    L->next = NULL;
    return SUCCESS;
}
Status IsLoopList(LinkedList L)
{
    if(L ==NULL||L->next == NULL)
        return ERROR;
    LinkedList fast,slow;
    fast = slow = L;
    fast = fast ->next->next;
    slow = slow ->next;
    while(1){
        if(!fast||!slow)
            return ERROR;
        if(fast == slow)
            return SUCCESS;
        else{
            fast = fast->next->next;
            slow = slow->next;
        }
    }
}
LNode* ReverseEvenList(LinkedList L)
{
    if(L == NULL||L->next==NULL)
        return L;
    LinkedList q,p,o;
    p=L->next;L->next =NULL;
    q = o =NULL;
    while(p){
        q=p->next;
        p->next=o;
        o=p;
        p=q;
    }
    L->next = o;
    return L;
}
LNode* FindMidNode(LinkedList L)
{
    if(L==NULL||L->next==NULL)
        return L;
    LinkedList mid,fast;
    mid = fast = L;
    while(fast!=NULL)
    {
        if(fast->next==NULL)fast = fast ->next;
        else fast = fast ->next->next;
        mid = mid->next;
    }
    return mid;
}