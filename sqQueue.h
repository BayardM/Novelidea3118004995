//以下程序已测试可用
#ifndef SQQUEUE_H_INCLUDED
//#define SQQUEUE_H_INCLUDED
#define MAXQSIZE 100
typedef char ELemType;
typedef struct
{
    ELemType *base; //动态分配内存存储空间，即是用一个数组来存放元素
    int front;  //头指针
    int rear; //尾指针，但是二者其实都只是整数,表示队头队尾元素的下标
}SqQueue;
void InitQueue(SqQueue *q)  //初始化一个队列
{
    q->base=(ELemType *)malloc(MAXQSIZE*sizeof(ELemType));
    if(!q->base) exit(0);
    q->front=q->rear=0;
}
int QueueLength(SqQueue q)
{
    return (q.rear-q.front+MAXQSIZE)%MAXQSIZE;   //求队列长度
}
void EnQueue(SqQueue *q,ELemType e)   //入队操作
{
    if((q->rear+1)%MAXQSIZE==q->front) return; //判断队满
    q->base[q->rear]=e;    //新元素加入队尾
    q->rear=(q->rear+1)%MAXQSIZE;     //队尾指针加一
}
void DelQueue(SqQueue *q,ELemType *e)   //出队操作
{
    if(q->rear == q->front) return;  //判断队列是否为空
    *e=q->base[q->front];    //先保存队头元素
    q->front=(q->front+1)%MAXQSIZE;  //队头指针+1
}
int GetHead(SqQueue q)   //取队头元素
{
    if(q.front==q.rear) return -1; //判断是否为空
    return q.base[q.front];  //返回头指针即可
}
bool QueueEmpty(SqQueue q)  //判断队列为空
{
    if(q.front==q.rear) return true;
    else return false;
}

#endif // SQQUEUE_H_INCLUDED
