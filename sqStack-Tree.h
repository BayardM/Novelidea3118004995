//���³����Ѳ��Կ���
#ifndef H_INCLUDED
//#define ˳��ջ_H_INCLUDED
#define STACK_SIZE 50
#define STACK_ADD 10
typedef BiTNode* ElemType;
typedef struct {
    ElemType *top;
    ElemType *base;
    int stackSize;
}sqStack;
void InitStack(sqStack *s)  //��ʼ��
{
    s->base = (ElemType *)malloc(STACK_SIZE * sizeof(ElemType));
    if(!s->base)
        exit(0);
    s->top=s->base;
    s->stackSize=STACK_SIZE;
}
void Push(sqStack *s,ElemType e)   //��ջ
{
    if(s->top-s->base>=s->stackSize)
    {
        s->base = (ElemType *)realloc(s->base,(STACK_SIZE+STACK_ADD) * sizeof(ElemType));
    }
    if(!s->base) exit(0);
    *(s->top) = e;
    s->top++;
}
void Pop(sqStack *s,ElemType *e)  //��ջ
{
    if(s->top==s->base)
        return;
    *e=*--(s->top);
}
int StackLen(sqStack s)  //ջ����
{
    return (s.top-s.base);
}
bool StackEmpty(sqStack *s)
{
    if(s->top==s->base)
        return true;
    else return false;
}
#endif // ˳��ջ_H_INCLUDED
