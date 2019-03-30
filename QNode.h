//���³����Ѳ��Կ���
#ifndef QNODE_H_INCLUDED
//#define QNODE_H_INCLUDED
#define MAXQSIZE 100    //�����г���
using namespace std;
typedef int ELemType;
typedef struct QNode  //�����е����Ͷ���
{
    ELemType data;
    struct QNode *next;
}QNode,*QueuePtr;
typedef struct
{
    QueuePtr front;
    QueuePtr rear;

}LinkQueue; //��������һ��
 void InitQueue(LinkQueue *q)   //��ʼ��һ������
{
    q->front=q->rear=(QueuePtr)malloc(sizeof(QNode)) ;
    if(!q->front) exit(0);
    q->front->next=NULL;   //ͷָ���ÿ�
}
void DestroyQueue(LinkQueue *q)  // ���ٶ���
{
    while(q->front)
    {q->rear=q->front->next;
        delete(q->front);
        q->front=q->rear;
        } //���Բ����µ�ָ�룬ֱ�ӽ�p��ΪrearҲ��
}
void EnQueue(LinkQueue *q,ELemType e)  //���
{
    QueuePtr p;
    p=(QueuePtr)malloc(sizeof(QNode));  //����һ��ָ��ź��µ�Ԫ��
    if(p==NULL) exit(0);
    p->data=e;p->next=NULL;
    q->rear->next=p;
    q->rear=p;
}
void DelQueue(LinkQueue *q,ELemType e)  //����
{
    QueuePtr p;
    if(q->front==q->rear) return;
    p=q->front->next;
    e=p->data;
    q->front->next=p->next;
    if(q->rear==p)//�����������p��βָ���غϵ�ʱ��
    {
        q->rear=q->front;
    }
    delete p;
}
bool QueueEmpty(LinkQueue q)  //�п�
{
    if(q.front==q.rear) return true;
    else return false;
}
ELemType GetHead(LinkQueue *q,ELemType &e)  //ȡ����ͷԪ��
{
    if(q->front==q->rear) return -1;
    e=q->front->next->data;
    return e;
}
void showQueue(LinkQueue *q) //����Ԫ��
{
     QueuePtr p;
    if(QueueEmpty(*q)) { cout<<"���п�"<<endl;}
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
