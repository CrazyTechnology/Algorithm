#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

#define MAXSIZE 20
#define TRUE 1
#define OK 1
#define ERROR 0

typedef  int ElemType;

//线性表
typedef  struct {
    ElemType length;
    ElemType  data[MAXSIZE];
}SqList;
//获取元素
int GetElem(SqList L,int i,ElemType * e){
    if(L.length==0||i<0||i>L.length-1)
        return ERROR;
    e=L.data[i];
    return OK;
}

//插入元素
int ListInsert(SqList L,int i,ElemType e){
    int k;
    if(i>=L.length-1||i<0)
        return ERROR;
    if(i<L.length-1){
        //从最后一个元素后移1位
        for(k=L.length-1;k>=i;k--){
            L.data[k+1]=L.data[k];
        }
    }
    L.data[i]=e;
    L.length ++;
    return OK;
}


//删除操作
int ListDelete(SqList L,int i,ElemType *e){
    int k;
    if(i>L.length-1||i<0)
        return ERROR;
    e=L.data[i];
    if(i<L.length-1){
        for(k=i;k<L.length-1;k++)
//            L.data[k]=L.data[k+1];   不能这么写，处理最后一位的时候会下标越界
            L.data[k-1]=L.data[k];
    }
    L.length--;
    return OK;
}


//链表
typedef struct Node{
    ElemType  data;
    struct Node * next;
} Node;
typedef struct Node  * LinkList; //定义linkedList


 int GetLinkElem(LinkList L,int i,ElemType *e){
     int j=1;
     LinkList p;
     p=L->next;  //让p指向L的第一个节点
     while (p&&j<i){
         //p不为null，且j<i时循环继续，直到j>=i
        p=p->next;
        j++;
     }
     if(!p||j>i)
         return ERROR;
     //找到j=i的情况就是需要查找的值
     e=p->data;
     return OK;
 }


 int InsertLinkElem(LinkList * L,int i,ElemType e){
     int j=1;
     LinkList p,s;
     p=*L;
     while (p||j<i){
         p=p->next;
         j++;
     }
     if(!p||j>i){
         return ERROR;//第i个元素不存在
     }
     s =(LinkList)malloc(sizeof(Node)); //新节点
     s->data=e;
     s->next=p->next;
     p->next=s;
     return OK;

 }

int DelLinkElem(LinkList * L,int i,ElemType *e){
    int j=1;
    LinkList p,q;
    p=*L;
    while (p->next&&j<i){
        //插入操作的判断条件是p!=null,p.next 可以查找到替换节点的前一个节点
        p=p->next;
        ++j;
    }
    if(!p->next||j>i)
        return ERROR;
    q=p->next;
    p->next=q->next;
    e=q->data;
    free(q);
    return  OK;

}


//头插法
void createListHead(LinkList * L,int n){
     //头插法，产生的所有新节点插入头节点之后，长度位n
     LinkList p;
     int i;
     srand(time(0)); //随机数种子
     *L=(LinkList)malloc(sizeof(Node));  //先建立带有头节点的单链表
    (*L)->next=NULL;
    for(i=0;i<n;i++){
        p=(LinkList)malloc(sizeof(Node));
        p->data=rand()%100+1;
        p->next=(*L)->next;
        (*L)->next=p;
    }
 }


//尾插法
void createListTail(LinkList*L,int n){
     LinkList p,r;
    int i;
    srand(time(0)); //随机数种子
    *L=(LinkList)malloc(sizeof(Node));//初始化第一个节点
    r=*L;
    for(i=0;i<n;i++){
      p=(LinkList *)malloc(sizeof(Node));
      p->data=rand()%100+1;
      r->next=p;
      r=p;
    }
    r->next=NULL;
 }


 //线性栈
 typedef struct {
     int data [MAXSIZE];
     int top; //指针
 }Stack;

 //入栈操作

 int insertStack(Stack * stack,int ele){
     if(stack->top>MAXSIZE-1)
         return ERROR;
     stack->top++;
     stack->data[stack->top]=ele;
     return OK;

 }

 //出栈操作
 int popStack(Stack *s,int * ele){
     if(s->top==-1)
         return ERROR;
    ele= s->data[s->top];
    s->top--;
     return ele;
 }


 //链表栈

 typedef struct StackNode{
     int data;
     struct StackNode * next;
 }StackNode ,*LinkStackPrt;

 typedef struct LinkStack{
     LinkStackPrt  top;
     int count;
 }LinkStack;

int push(LinkStack *L, int ele){
    LinkStackPrt s=malloc(sizeof(StackNode));
    s->data=ele;//新节点负值
    s->next=L->top; //将原来的头节点赋值给新节点的next节点
    L->top=s;//指针上移一位
    L->count++; //数量加一
    return OK;
}

int pop(LinkStack *L, int * ele){
    LinkStackPrt p; //定义一个p节点
    ele= L->top->data; //获取第一个栈顶元素的值
    p=L->top; //把栈顶元素赋值给p
    L->top=L->top->next; //top指针下移一位
    free(p);    //释放栈顶节点
    L->count--; //长度-1
    return ele;
}

//二叉树节点定义，有左右孩子指针，有data数据
typedef  struct BiTNode{
    int data;
    struct  BinTNode *lchild,* rchild; //左右孩子指针
}BiTNode,*BiTree;

//前序遍历
void PreOrderTraers(BiTree T){
    if(T==NULL)
        return ;
    printf("%c",T->data);
    PreOrderTraers(T->lchild); //先遍历左子树
    PreOrderTraers(T->rchild);//在遍历右子树
}

//前序遍历
void InOrderTraers(BiTree T){
    if(T==NULL)
        return ;
    InOrderTraers(T->lchild); //先遍历左子树
    printf("%c",T->data); //显示节点数据，可以改为对其他节点对操作
    InOrderTraers(T->rchild);//在遍历右子树
}

//后续遍历，先遍历左节点。然后右节点。最后根节点
void PostOrderTraers(BiTree T){
    if(T==NULL)
        return ;
    PostOrderTraers(T->lchild); //先遍历左子树
    PostOrderTraers(T->rchild);//在遍历右子树
    printf("%c",T->data); //显示节点数据，可以改为对其他节点对操作
}


//建立树结构，也是利用了递归的原理
void createBiTree(BiTree *T){
    int ch;
    scanf("%c",&ch);
    if(ch=='#')
        *T=NULL;
    else{
        *T=(BiTree)malloc(sizeof(BiTNode));
        if(!*T)
            exit(OVERFLOW);
        (*T)->data=ch;
        createBiTree(&(*T)->lchild);
        createBiTree(&(*T)->rchild);
    }
}



//线索二叉树
typedef enum {Link,Thread} PointerTag; //link=0表示指向左右孩子指针
typedef struct BiThrNode{
    int data;
    struct BiThrNode *lchild,*rchild;
    PointerTag LTag;
    PointerTag RTag;
}BiThrNode,*BiThrTree;

int main() {

    return 0;
}



