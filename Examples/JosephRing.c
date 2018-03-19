#include <stdio.h>
#include <malloc.h>

/*构建结构体*/
typedef struct Node{
    int Num;
    struct Node *next;
}JoseNode, *PNode, *HNode;

/**********初始化循环单链表*********/
int JoseInit(HNode *h)
{
    if (!h)
    {
        printf("初始化链表错误！\n");
        return 0;
    }
    (*h)->next = (*h);//循环单链表
    return 1;

}

/*************单链表插入操作**********/
int JoseInsert(JoseNode *h, int pos, int x)
{
    PNode p=h,q;
    int i=1;
    if (pos == 1)/*尾插法*/
    {
        p->Num = x;
        p->next = p;
        return 1;
    }
    while(i<pos-1)
    {
        p=p->next;
        i++;
    }
    q=(PNode)malloc(sizeof(JoseNode));
    q->Num=x;
    q->next=p->next;
    p->next=q;
    return 1;
}

/*遍历*/
void TraverseList(HNode h, int M)
{
    int i = 0;
    PNode p = h;
    printf("参与的人的编号为：\n");
    while (i<M)
    {
        printf("%d\t", p->Num);
        p = p->next;
        i++;
    }
    printf("\n");
}
/**************出局函数****************/

int JoseDelete(HNode h, int M, int k)
{    int i;
    PNode p=h,q;
    while(M>1)
    {
        for(i=1;i<k-1;i++)
        {
            p=p->next;
        }
        
        q=p->next;
        p->next=q->next;
        printf("出局的人为：%d号\n",q->Num);
        free(q);

        p=p->next;
        M--;
    }
    printf("***************获胜者为：%d号***************",p->Num);
    return 1;
}


/***************************************/
int main()
{
    int i;//计数器
    int N;//参与的人数
    int k;//报数密码
    printf("请输入参与人数：");
    scanf("%d",&N);
    printf("请输入出局密码：");
    scanf("%d",&k);

/**************得到头结点****************/
    HNode h = ((HNode)malloc(sizeof(JoseNode)));

/***************初始化单链表************/
    JoseInit(&h);

/******将编号插入到循环单链表中******/
    for (i = 1; i <=N; i++)
    {
        JoseInsert(h, i, i);
    }
/**************遍历单链表***************/
    TraverseList(h,N);

/***************出局函数************/
    if(k > 1)
    JoseDelete(h, N, k);
    else
    {
        for(i = 1; i < N; i++)
            printf("出局的人为：%d号\n",i);
        printf("***************获胜者为：%d号***************",N);
    }

    printf("\n");
    printf("\n");
    return 0;
}
