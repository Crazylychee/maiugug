//
// Created by yc on 2023/3/19.
//
#include "linkedList.h"
void menu()
{
    printf("*************************************\n");
    printf("****** Please input the number ******\n");
    printf("****** 0.SListPrint            ******\n");//
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
    printf("destroy successfully!!\n");
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
    assert(p!=NULL);
    //�ų�Ϊ���һ���������
    if(p->next==NULL)
    {
        *e=p->data;
        p=NULL;
    }
    LinkedList cur;
    cur = p->next;
    *e=cur->data;
    p->next=cur->next;
    free(cur);
    return SUCCESS;
}
void TraverseList(LinkedList L, void (*visit)(ElemType e))
{
    SListPrint(L);
}
Status SearchList(LinkedList L, ElemType e)
{
    LinkedList p;
    if(L->next == NULL) return ERROR;
    p = Findnode(L);
    if(p==NULL){
        printf("can not find the number!!\n");
        return ERROR;
    }
    return SUCCESS;
}
Status ReverseList(LinkedList *L){
    //�߽�����:�����ֻ��һ���ڵ�,���ǿ�����Ͳ��ò���
    LinkedList cur = (*L);
    LinkedList newhead = NULL;
    while(cur){
        LinkedList next = cur->next;
        //ͷ�巨
        cur->next = newhead;
        newhead = cur;

        //����������
        cur =next;
    }
    (*L)=newhead;
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
    LinkedList slow,fast;
    slow = fast= *L;
    while(fast&&fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void test(LinkedList *L){
    LinkedList n1 = (LinkedList) malloc(NEN);
    LinkedList n2 = (LinkedList) malloc(NEN);
    LinkedList n3 = (LinkedList) malloc(NEN);
    LinkedList n4 = (LinkedList) malloc(NEN);
    LinkedList n5 = (LinkedList) malloc(NEN);
    LinkedList n6 = (LinkedList) malloc(NEN);

    n1->data = 3;
    n2->data = 5;
    n3->data = 2;
    n4 ->data = 8;
    n5->data = 6;
    n6->data = 7;
    n1->next=n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = NULL;

    *L = n1;
    return;
}
void SListPrint(LinkedList phead){
    LinkedList cur = phead;
    while(cur !=NULL){
        printf("%d->",cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

LinkedList Findnode(const LinkedList L){
    int input=0;
    scanf("%d",&input);
    LinkedList newnode;
    newnode = L;
    while(newnode->data!=input&&newnode->next!=NULL){
        newnode = newnode->next;
    }
    if(newnode->data==input)
    return newnode;
    else return NULL;
}
LinkedList InitList_1(int n)
{
    LinkedList  L= (LinkedList)malloc(NEN);
    if(L==NULL){
        printf("error!!\n");
        exit(1);
    }
    L->next=NULL;L->data = n;
    return  L;
}
void test_1(LinkedList *L){
    LinkedList n1 = (LinkedList) malloc(NEN);
    LinkedList n2 = (LinkedList) malloc(NEN);
    LinkedList n3 = (LinkedList) malloc(NEN);
    LinkedList n4 = (LinkedList) malloc(NEN);
    LinkedList n5 = (LinkedList) malloc(NEN);
    LinkedList n6 = (LinkedList) malloc(NEN);

    n1->data = 3;
    n2->data = 5;
    n3->data = 2;
    n4 ->data = 8;
    n5->data = 6;
    n6->data = 7;
    n1->next=n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n1;

    *L = n1;
    return;
}