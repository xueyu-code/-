#include "stdio.h"
#include "stdlib.h"

#define maixsize 50
#define true 1
#define false 0

typedef struct 
{
    int data[maixsize];
    int top;
}sqstack;

//��ʼ��ջ
void init_stack(sqstack *s)
{
    s->top=-1;
}
//��ջ
int push(sqstack *s,int x)
{
    if(s->top==maixsize-1)
     return false;
    s->data[++s->top]=x;
    return true;
}
//��ջ
int pop(sqstack *s,int *x)
{
    if (s->top==-1)
        return false;
    x=s->data[s->top--];
    return true;
}
//��ȡջ��Ԫ��
int gettop(sqstack *s)
{
    if(s->top==-1)
        return false;
    return s->data[s->top];
}

int main(void)
{
    sqstack test;
    int x=0;
    init_stack(&test);
    push(&test,0);
    push(&test,1);
    printf("answer is %d\n",gettop(&test));//��ӡδ��ջ֮ǰ��ջ��Ԫ��
    pop(&test,x);
    printf("now is %d\n",gettop(&test));//��ӡ��ջ���ջ��Ԫ��
    
}