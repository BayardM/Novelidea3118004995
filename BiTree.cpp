#include <iostream>
#include "sqQueue-Tree.h"
#include "sqStack-Tree.h"
using namespace std;
//建立二叉树,约定用户用前序
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

//访问结点，看你干什么操作
void visit(char c)
{
    cout<<c<<endl;
}

//先序遍历二叉树
void PreOrderTraverse(BiTree T)
{
    if(T)
    {
        visit(T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
//中序遍历
void InOrderTraverse(BiTree T)
{
    if(T)
    {
        InOrderTraverse(T->lchild);
        visit(T->data);
        InOrderTraverse(T->rchild);
    }
}
//后序遍历
void PostOrderTraverse(BiTree T)
{
    if(T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        visit(T->data);

    }
}
//层序遍历
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

//非递归中序遍历
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
//非递归先序
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
//非递归后序
void NoPostOrderTraverse(BiTree T)
{
    BiTree p=T,pre=NULL;/*pre用于标记已访问过的节点*/
    sqStack s;
    InitStack(&s);
    while(!StackEmpty(&s))  //栈不空时循环
    {
        p=*s.top;//始终指向栈顶
    while(p!=NULL)
    {
            //判断当前节点是否有左右子树或者左右子树是否已经被访问过
        if((!p->lchild&&!p->rchild)||(pre&&(pre==p->lchild||pre==p->rchild)))
        {
            Pop(&s,&p); //当前节点出栈
            cout<<p->data<<endl;
            pre=p;//标记为已访问
        }
        //否则当前节点左右子树分别进栈
        else{
                if(p->lchild)
                   Push(&s,p->lchild);
                if(p->rchild)
                   Push(&s,p->rchild);
                   p=p->lchild;  //继续往下走
            }
    }

    }

}


//二叉树增加
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
//二叉树查询
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
//二叉树修改
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
    cout<<"修改后：";
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
//二叉树删除
void DelBiTree(BiTree T)
{

    BiTree p,q;
    sqStack s;
    InitStack(&s);
    p=T;
    char c;
    c=cin.get();
    cout<<"删除后：";
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
    cout<<"先序："<<endl;
    PreOrderTraverse(T);
    cout<<"中序："<<endl;
    InOrderTraverse(T);
    cout<<"后序："<<endl;
    PostOrderTraverse(T);
    cout<<"层序："<<endl;
    LevelOrder(T);
    cout<<"非递归中序："<<endl;
    NoInOrderTraverse(T);
    cout<<"非递归先序："<<endl;
    NoPreOrderTraverse(T);
    cout<<"非递归后序："<<endl;
    NoPostOrderTraverse(T);
    cin.get();
    int result;
    result=CheckBiTree(T);
    cout<<"查询结果："<<result<<endl;
    cin.get();
    cout<<"增加后：";
    T2=InsertBiTree(T);
    InOrderTraverse(T2);
    cin.get();
    T3=ChangeBiTree(T);
    InOrderTraverse(T3);
    cin.get();
    DelBiTree(T);
    return 0;
}
