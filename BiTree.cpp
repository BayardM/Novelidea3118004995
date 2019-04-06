#include <iostream>
#include "sqQueue-Tree.h"
#include "sqStack-Tree.h"
using namespace std;
//����������,Լ���û���ǰ��
void CreateBiTree(BiTree *T)
{
    char c;
    c=cin.get();
    if('#'==c)
    {
        *T=NULL;
    }
    else
    {
        *T=(BiTNode *)malloc(sizeof(BiTNode));
        (*T)->data=c;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}

//���ʽ�㣬�����ʲô����
void visit(char c)
{
    cout<<c<<endl;
}

//�������������
void PreOrderTraverse(BiTree T)
{
    if(T)
    {
        visit(T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
//�������
void InOrderTraverse(BiTree T)
{
    if(T)
    {
        InOrderTraverse(T->lchild);
        visit(T->data);
        InOrderTraverse(T->rchild);
    }
}
//�������
void PostOrderTraverse(BiTree T)
{
    if(T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        visit(T->data);

    }
}
//�������
void LevelOrder(BiTNode *b)
{
    BiTNode *p;
    SqQueue qu;
    InitQueue(&qu);
    EnQueue(&qu,b);
    while(!QueueEmpty(qu))
            {
                DelQueue(&qu,&p);
                cout<<p->data<<endl;
                if(p->lchild!=NULL) EnQueue(&qu,p->lchild);
                if(p->rchild!=NULL) EnQueue(&qu,p->rchild);
            }
}

//�ǵݹ��������
void NoInOrderTraverse(BiTree T)
{
    BiTree p,q;
    sqStack s;
    InitStack(&s);
    p=T;
    while(p||!StackEmpty(&s))
    {
        if(p)
        {
            Push(&s,p);
            p=p->lchild;
        }
        else
        {
                Pop(&s,&q);
                cout<<q->data<<endl;
                p=q->rchild;
        }
    }
}
//�ǵݹ�����
void NoPreOrderTraverse(BiTree T)
{
    BiTree p,q;
    sqStack s;
    InitStack(&s);
    p=T;
    while(p||!StackEmpty(&s))
    {
        while(p)
        {
            cout<<p->data<<endl;
            Push(&s,p);
            p=p->lchild;
        }
        if(!StackEmpty(&s))
        {
            Pop(&s,&q);
            p=q->rchild;
        }
    }
}
//�ǵݹ����
void NoPostOrderTraverse(BiTree T)
{
    BiTree p=T,pre=NULL;/*pre���ڱ���ѷ��ʹ��Ľڵ�*/
    sqStack s;
    InitStack(&s);
    while(!StackEmpty(&s))  //ջ����ʱѭ��
    {
        p=*s.top;//ʼ��ָ��ջ��
    while(p!=NULL)
    {
            //�жϵ�ǰ�ڵ��Ƿ������������������������Ƿ��Ѿ������ʹ�
        if((!p->lchild&&!p->rchild)||(pre&&(pre==p->lchild||pre==p->rchild)))
        {
            Pop(&s,&p); //��ǰ�ڵ��ջ
            cout<<p->data<<endl;
            pre=p;//���Ϊ�ѷ���
        }
        //����ǰ�ڵ����������ֱ��ջ
        else{
                if(p->lchild)
                   Push(&s,p->lchild);
                if(p->rchild)
                   Push(&s,p->rchild);
                   p=p->lchild;  //����������
            }
    }

    }

}


//����������
BiTree InsertBiTree(BiTree T)
{
    BiTree p=T,q;
    char c;
    c=cin.get();
    //if(p!= NULL) { p=p->lchild;InsertBiTree(p,c);}
        while(T!=NULL)
            {
                q=T;
                T=T->lchild;
            }
             q->lchild=(BiTNode *)malloc(sizeof(BiTNode));
             q->lchild->data=c;
             q->lchild->lchild=NULL;
             q->lchild->lchild=NULL;
    return p;
}
//��������ѯ
int CheckBiTree(BiTree T)
{
  BiTree p,q;
    sqStack s;
    InitStack(&s);
    p=T;
    char c;
    c=cin.get();
    while(p||!StackEmpty(&s))
    {
        if(p)
        {
            Push(&s,p);
            p=p->lchild;
        }
        else
        {
                Pop(&s,&q);
                 p=q->rchild;
                if(q->data==c)
                {
                    if(p==NULL) {p=q;break;}
                    else break;
                }
        }
    }
    if(p!=NULL) return 1;
    else return 0;
}
//�������޸�
BiTree ChangeBiTree(BiTree T)
{

    BiTree p,q;
    sqStack s;
    InitStack(&s);
    p=T;
    char c,afc;
    c=cin.get();
    cin.get();
    afc=cin.get();
    cout<<"�޸ĺ�";
    while(p||!StackEmpty(&s))
    {
        if(p)
        {
            Push(&s,p);
            p=p->lchild;
        }
        else
        {
                Pop(&s,&q);
                 p=q->rchild;
                if(q->data==c)
                {
                    q->data=afc;
                    break;
                }
        }
    }
    return T;
}
//������ɾ��
void DelBiTree(BiTree T)
{

    BiTree p,q;
    sqStack s;
    InitStack(&s);
    p=T;
    char c;
    c=cin.get();
    cout<<"ɾ����";
    while(p||!StackEmpty(&s))
    {

          if(p)
        {
            Push(&s,p);
            p=p->lchild;
        }
        else
        {
                Pop(&s,&q);
                if(q->data!=c)
                {cout<<q->data<<endl;
                p=q->rchild;}
                else
                {
                    p=q->rchild;
                    delete q;
                }
        }
    }
}
int main()
{

    BiTree T,T2,T3;
    CreateBiTree(&T);
    cout<<"����"<<endl;
    PreOrderTraverse(T);
    cout<<"����"<<endl;
    InOrderTraverse(T);
    cout<<"����"<<endl;
    PostOrderTraverse(T);
    cout<<"����"<<endl;
    LevelOrder(T);
    cout<<"�ǵݹ�����"<<endl;
    NoInOrderTraverse(T);
    cout<<"�ǵݹ�����"<<endl;
    NoPreOrderTraverse(T);
    cout<<"�ǵݹ����"<<endl;
    NoPostOrderTraverse(T);
    cin.get();
    int result;
    result=CheckBiTree(T);
    cout<<"��ѯ�����"<<result<<endl;
    cin.get();
    cout<<"���Ӻ�";
    T2=InsertBiTree(T);
    InOrderTraverse(T2);
    cin.get();
    T3=ChangeBiTree(T);
    InOrderTraverse(T3);
    cin.get();
    DelBiTree(T);
    return 0;
}
