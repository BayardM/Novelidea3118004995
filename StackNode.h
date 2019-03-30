//���³����Ѳ��Կ���
#ifndef STACKNODE_H_INCLUDED
//#define STACKNODE_H_INCLUDED
using namespace std;
typedef int SElemType;
typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
}StackNode,*LinkStack;  //��StackNode�����Ľ�����Ͷ���һ��ָ������
//LinkStack S;//��S��ʾջ��ָ��ڵ��ָ������
LinkStack InitStack()  //����һ����ջ��ջͷָ����Ϊ��
{
    LinkStack s=(LinkStack)malloc(sizeof(StackNode));
    if(s==NULL)
    {
        return 0;
    }
    else
    {
        s->next=NULL;
    }
    return s;
}
bool StackEmpty(LinkStack s) //�жϿ�ջ
{
    if(s->next==NULL) return true;
    else return false;
}
void Push(LinkStack s,SElemType e)  //��ջ����
{
    LinkStack p;
    p=(LinkStack)malloc(sizeof(StackNode));//�����µ��ڴ�ռ�
    if(p==NULL) return ;
    p->data=e;  // ���½ڵ���������Ϊe
    p->next=s->next;//���½ڵ����ջ��
    s->next=p;   // �޸�ջ��ָ���ȥ
}
void Pop(LinkStack s,SElemType *e)  //��ջ
{
    LinkStack p;
    if(s==NULL) return;  //�п�
    p=s->next;  //����pͬʱָ��ջ�����
     *e=p->data;  //�ȸ�����e����
    s->next=p->next;//ջ��ָ������
    delete p;
}
void showStack(LinkStack s)  //����Ԫ��
{
    LinkStack p=s->next;
    if(StackEmpty(s))
    {
        cout<<"ջ��"<<endl;
        return;
    }
    else {
        while(!StackEmpty(s))
            {
                cout<<p->data<<endl;
                p=p->next;
            }
    }
}


#endif // STACKNODE_H_INCLUDED
