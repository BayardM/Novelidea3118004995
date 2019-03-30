//以下程序已测试可用
#ifndef QNODE_H_INCLUDED
//#define QNODE_H_INCLUDED
#define MAXQSIZE 100    //最大队列长度
using namespace std;
typedef int ELemType;
typedef struct QNode  //链队列的类型定义
{
    ELemType data;
    struct QNode *next;
}QNode,*QueuePtr;
typedef struct
{
    QueuePtr front;
    QueuePtr rear;

}LinkQueue; //两个放在一起
 void InitQueue(LinkQueue *q)   //初始化一个队列
{
    q->front=q->rear=(QueuePtr)malloc(sizeof(QNode)) ;
    if(!q->front) exit(0);
    q->front->next=NULL;   //头指针置空
}
void DestroyQueue(LinkQueue *q)  // 销毁队列
{
    while(q->front)
    {q->rear=q->front->next;
        delete(q->front);
        q->front=q->rear;
        } //可以不用新的指针，直接将p改为rear也行
}
void EnQueue(LinkQueue *q,ELemType e)  //入队
{
    QueuePtr p;
    p=(QueuePtr)malloc(sizeof(QNode));  //申请一个指针放好新的元素
    if(p==NULL) exit(0);
    p->data=e;p->next=NULL;
    q->rear->next=p;
    q->rear=p;
}
void DelQueue(LinkQueue *q,ELemType e)  //出队
{
    QueuePtr p;
    if(q->front==q->rear) return;
    p=q->front->next;
    e=p->data;
    q->front->next=p->next;
    if(q->rear==p)//特殊情况：当p和尾指针重合的时候
    {
        q->rear=q->front;
    }
    delete p;
}
bool QueueEmpty(LinkQueue q)  //判空
{
    if(q.front==q.rear) return true;
    else return false;
}
ELemType GetHead(LinkQueue *q,ELemType &e)  //取出队头元素
{
    if(q->front==q->rear) return -1;
    e=q->front->next->data;
    return e;
}
void showQueue(LinkQueue *q) //遍历元素
{
     QueuePtr p;
    if(QueueEmpty(*q)) { cout<<"队列空"<<endl;}
    else {
        while(!QueueEmpty(*q))
        {
            p=q->front->next;
            cout<<p->data<<endl;
            q->front->next=p->next;
        }
        }
}


#endif // QNODE_H_INCLUDED
