#include "stdio.h"
#include "stdlib.h"

#define true 1
#define false 0

#define maixsize 5
typedef struct 
{
    /* data */
    int data[maixsize];
    int top0;
    int top1;//栈底是maixsize-1
}share_stack;

//初始化共享栈
void init_share_stack(share_stack *s)
{
    s->top0=-1;
    s->top1=maixsize;//此时1号是空栈，指向不存在的位置
}

//判断共享栈是否满
int empty_share(share_stack *s)
{
    if(s->top1==s->top0+1)
        return true;
    else
        return false;
}
//给1号栈 入栈
int push_top1(share_stack *s,int x)
{
    if(s->top1==s->top0+1)
        return false;
    s->data[--s->top1]=x;
    return true;
}
//给0号栈入栈 
int push_top0(share_stack *s,int x)
{
    if(s->top1==s->top0+1)
        return false;
    s->data[++s->top0]=x;
    return true;
}
//给1号栈 出栈
int pop_top1(share_stack *s,int *x)
{
    if(s->top1==maixsize)
        return false;
    x=s->data[s->top1++];
    return true;
}
//给0号栈 出栈
int pop_top0(share_stack *s,int *x)
{
    if(s->top0==-1)
        return false;
    x=s->data[s->top0--];
    return true;
}
//获取指定栈的栈顶元素
int gettop(share_stack *s,int top_num)
{
    if (top_num==1)
    {
        if(s->top1==maixsize)
            return false;
        return s->data[s->top1];
    }

    if (top_num==0)
    {
        if(s->top0==-1)
            return false;
        return s->data[s->top0];
    }
    
    
}

int main()
{
    share_stack test;
    int x=0;
    init_share_stack(&test);
    push_top0(&test,0);
    push_top0(&test,1);
    // pop_top0(&test,&x);
    printf("0 stack top is %d\n",gettop(&test,0));
    push_top1(&test,0);
    push_top1(&test,1);
    push_top1(&test,2);
    // push_top1(&test,3);  //该语句检测栈满是否会继续入栈
    // pop_top1(&test,&x);
    printf("1 stack top is %d\n",gettop(&test,1));
}