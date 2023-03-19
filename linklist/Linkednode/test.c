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
    printf("****** 7.IsLoopList            ******\n");//�ж�ʱ��
    printf("****** 8.ReverseEvenList       ******\n");//
    printf("****** 9.FindMidNode          ******\n");
    printf("****** 10.Exit                ******\n");
    printf("*************************************\n");
}
//ͷ�巨����������:ֻ������ָ��
LinkedList ListHeadInsert(LinkedList p){
    LinkedList p1;
    int input=0,cnt=0;
    printf("(����999999����)��������������: \n");
    scanf("%d",&input);
    while(input!=999999){
        p1 = (LinkedList) malloc(NEN);
        //����ͷ�巨�Ĳ����൱���Ǵ�ƿ�Ƿ�ˮ,ÿ�ζ��Ƕ�ͷ�ڵ�.
        //��һ�μ����NULLҲ������һ���ڵ�ͺ������
        //1.������ӽڵ�(����������)
        p1->data = input;
        //2.�����½ڵ㵽ͷ�ڵ�֮��,����������һ
        p1->next = p->next;
        cnt++;
        //�Ͽ�ͷ�ڵ�,�����°�ͷ�ڵ�ӵ��½ڵ��ͷͷ
        p->next = p1;
        //����������һ������
        scanf("%d",&input);
    }
    p->data=cnt;
    return p;
}
//β�巨����������:��Ҫ����ָ��
LinkedList ListTailInsert(LinkedList p){
    LinkedList p2;
    LinkedList p1= p2 = p;
    int input=0,cnt=0;
    printf("(����999999����)��������������: \n");
    scanf("%d",&input);
    while(input!=999999){
        p1 = (LinkedList) malloc(NEN);
        //����β�巨�Ĳ����൱���Ǵ�ƿ�Ƿ�ˮ,ÿ�ζ��Ƕ�ͷ�ڵ�.
        //��һ�μ����NULLҲ������һ���ڵ�ͺ������
        //1.������ӽڵ�(����������)
        p1->data = input;
        //2.�����½ڵ㵽ͷ�ڵ�֮��,����������1
        p2->next = p1;
        cnt++;
        p2=p1;//p2ָ���µı�β�ڵ�(��Զ����p2ָ�����һ���ڵ�)
        //����������һ������
        scanf("%d",&input);
    }
    p2->next=NULL;
    p->data=cnt;
    return p;
}
Status InitList(LinkedList *L)
{
    (*L)= (LinkedList)malloc(NEN);
    if(L==NULL){
        printf("error!!\n");
        return OVERFLOW;
    }
    (*L)->next=NULL;(*L)->data = 0;
    printf("make successfully\n");
    return SUCCESS;
}

void DestroyList(LinkedList *L)
{
    LinkedList p = *L;
    while(p)
    {
        p = p->next;
        free(*L);
        *L = p;
    }
    printf("destroy successfully!!");
}

Status InsertList(LNode *p, LNode *q)
{
    //���ǽ��½ڵ����ӵ�p֮��
    if(p==NULL||q == NULL)
        return ERROR;
    q->next = p->next;
    p->next = q;

    return SUCCESS;
}

Status DeleteList(LNode *p, ElemType *e)
{
    //�ų�����ȡ�����,����Ϊ��,
    if(p ==NULL||p->next == NULL)return ERROR;
    LinkedList q= p->next;
    *e = q->data;
    p->next = q->next;
    free(q);
    return *e;
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
Status ReverseList(LinkedList *L){
    //�߽�����:�����ֻ��һ���ڵ�,���ǿ�����Ͳ��ò���
    if(!(*L) || (*L)->next) {
        return ERROR;
    }
    //step1: �ȰѺ���ķ���,�ݹ�ʵ��
    (*L)->next->next = (*L);
    (*L)->next = NULL;
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
LNode* ReverseEvenList(LinkedList *L)
{
    if((*L) == NULL||(*L)->next==NULL)
        return (*L);
    LinkedList q,p,o;
    p=(*L)->next;(*L)->next =NULL;
    q = o =NULL;
    while(p){
        q=p->next;
        p->next=o;
        o=p;
        p=q;
    }
    (*L)->next = o;
    return L;
}
LNode* FindMidNode(LinkedList *L)
{
    if((*L)==NULL||(*L)->next==NULL)
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