//
// Created by yc on 2023/3/19.
//
#include "duLinkedList.h"
void menu()
{
    printf("*************************************\n");
    printf("****** Please input the number ******\n");
    printf("****** 1.InitList_DuL          ******\n");//
    printf("****** 2.DestroyList_DuL       ******\n");//
    printf("****** 3.InsertBeforeList_DuL  ******\n");//
    printf("****** 4.InsertAfterList_DuL   ******\n");//
    printf("****** 5.DeleteList_DuL        ******\n");//
    printf("****** 6.TraverseList_DuL      ******\n");//
    printf("*************************************\n");//

}
Status InitList_DuL(DuLinkedList L){
    L = (DuLinkedList)malloc(sizeof(DuLNode));
    if(!L)
    {
        return OVERFLOW;
    }
    L->prior = L->next = NULL;
    printf("Successfully initialize a DuLinkedList!\n");
    return SUCCESS;
}
void DestroyList_DuL(DuLinkedList *L){
    DuLinkedList p;
    p = L;
    while(p)
    {
        p = p->next;
        free(L);
        L = p;
    }
}

Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q)
{
    DuLinkedList pnext = p;
    int i = 1;
    int n;

    while((i<n) && (pnext != NULL))
    {
        i++;
        pnext = pnext->next;

    }
    if(pnext == NULL)
    {
        return ERROR;
    }
    else
    {
        q = (DuLinkedList)malloc(sizeof(DuLNode));
        printf("Please input the data of the inserted node:");
        scanf("%d", &q->data);

        q->next = pnext->next;
        if(n = 0)
        {
            pnext->next = q;
            q->next = NULL;
        }
        else
        {
            pnext->next = q;
            pnext->next->prior = q;
            q->prior = pnext;
        }
    }
    return SUCCESS;
}

Status InsertAfterList_DuL(DuLNode *p, DuLNode *q){
    DuLinkedList pnext = p;
    int i = 1;
    int n;

    while((i<n) && (pnext != NULL))
    {
        i++;
        pnext = pnext->next;

    }

    if(pnext == NULL)
    {
        return ERROR;
    }
    else
    {
        q = (DuLinkedList)malloc(sizeof(DuLNode));
        printf("Please input the data of the inserted node:");
        scanf("%d", &q->data);

        q->next = pnext->next;
        if(n = 0)
        {
            pnext->next = q;
            q->next = NULL;
        }
        else
        {
            pnext->next = q;
            pnext->next->prior = q;
            q->prior = pnext;
        }
    }
    return SUCCESS;

}

Status DeleteList_DuL(DuLNode *L, ElemType *e){
    if(L == NULL || L->next == NULL)
    {
        return ERROR;
    }
    DuLinkedList q, pre;
    q = L->next;
    while(q->data != e)
    {
        pre = q;
        q = q->next;
    }
    pre->next = q->next;
    free(q);
    printf("Successfully delete node!\n");
    return SUCCESS;
}

void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)){
    DuLinkedList p = L->next;
    while(p)
    {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
}