//以下程序已测试可用
#ifndef STACKNODE_H_INCLUDED
//#define STACKNODE_H_INCLUDED
using namespace std;
typedef int SElemType;
typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
}StackNode,*LinkStack;  //用StackNode这样的结点类型定义一个指针类型
//LinkStack S;//以S表示栈，指向节点的指针类型
LinkStack InitStack()  //构造一个空栈，栈头指针置为空
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
bool StackEmpty(LinkStack s) //判断空栈
{
    if(s->next==NULL) return true;
    else return false;
}
void Push(LinkStack s,SElemType e)  //入栈操作
{
    LinkStack p;
    p=(LinkStack)malloc(sizeof(StackNode));//申请新的内存空间
    if(p==NULL) return ;
    p->data=e;  // 将新节点数据域置为e
    p->next=s->next;//将新节点插入栈顶
    s->next=p;   // 修改栈顶指针回去
}
void Pop(LinkStack s,SElemType *e)  //出栈
{
    LinkStack p;
    if(s==NULL) return;  //判空
    p=s->next;  //再让p同时指向栈顶结点
     *e=p->data;  //先给变量e保存
    s->next=p->next;//栈顶指针下移
    delete p;
}
void showStack(LinkStack s)  //遍历元素
{
    LinkStack p=s->next;
    if(StackEmpty(s))
    {
        cout<<"栈空"<<endl;
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
