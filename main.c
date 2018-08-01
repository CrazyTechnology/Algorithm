#include <stdio.h>
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






int main() {

    return 0;
}


