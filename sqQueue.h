//���³����Ѳ��Կ���
#ifndef SQQUEUE_H_INCLUDED
//#define SQQUEUE_H_INCLUDED
#define MAXQSIZE 100
typedef char ELemType;
typedef struct
{
    ELemType *base; //��̬�����ڴ�洢�ռ䣬������һ�����������Ԫ��
    int front;  //ͷָ��
    int rear; //βָ�룬���Ƕ�����ʵ��ֻ������,��ʾ��ͷ��βԪ�ص��±�
}SqQueue;
void InitQueue(SqQueue *q)  //��ʼ��һ������
{
    q->base=(ELemType *)malloc(MAXQSIZE*sizeof(ELemType));
    if(!q->base) exit(0);
    q->front=q->rear=0;
}
int QueueLength(SqQueue q)
{
    return (q.rear-q.front+MAXQSIZE)%MAXQSIZE;   //����г���
}
void EnQueue(SqQueue *q,ELemType e)   //��Ӳ���
{
    if((q->rear+1)%MAXQSIZE==q->front) return; //�ж϶���
    q->base[q->rear]=e;    //��Ԫ�ؼ����β
    q->rear=(q->rear+1)%MAXQSIZE;     //��βָ���һ
}
void DelQueue(SqQueue *q,ELemType *e)   //���Ӳ���
{
    if(q->rear == q->front) return;  //�ж϶����Ƿ�Ϊ��
    *e=q->base[q->front];    //�ȱ����ͷԪ��
    q->front=(q->front+1)%MAXQSIZE;  //��ͷָ��+1
}
int GetHead(SqQueue q)   //ȡ��ͷԪ��
{
    if(q.front==q.rear) return -1; //�ж��Ƿ�Ϊ��
    return q.base[q.front];  //����ͷָ�뼴��
}
bool QueueEmpty(SqQueue q)  //�ж϶���Ϊ��
{
    if(q.front==q.rear) return true;
    else return false;
}

#endif // SQQUEUE_H_INCLUDED
