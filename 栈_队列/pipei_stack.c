#include "stdio.h"
#include "stdlib.h"

#define maixsize 50
#define true 1
#define false 0
//用顺序栈的思想实现 括号匹配
typedef struct 
{
    char data[maixsize];
    int top;
}sqstack;

//初始化栈
void init_stack(sqstack *s)
{
    s->top=-1;
}
//入栈
int push(sqstack *s,char x)
{
    if(s->top==maixsize-1)
     return false;
    s->data[++s->top]=x;
    return true;
}
//出栈
char pop(sqstack *s)
{
    if (s->top==-1)
        return false;
    return s->data[s->top--];
    
}
//获取栈顶元素
char gettop(sqstack *s)
{
    if(s->top==-1)
        return false;
    return s->data[s->top];
}
//输入括号序列 入栈
int kuohao_push(sqstack *s)
{
    char temp_push='0';
    char temp_pop='0';
    printf("请输入一串50个字符之内的括号序列\n");
    printf("括号序列以小写字母p结束\n");

    while (!('p'==(scanf("%c",&temp_push),temp_push)))
    {
        switch (temp_push)
        {
        case '[':push(&s,temp_push);break;
        case '(':push(&s,temp_push);break;
        case '{':push(&s,temp_push);break;

        case ')':
                    if (pop(&s)=='(')
                    {
                        return true;
                    }
                    break;
        case '}':
                    if(pop(&s)=='{')
                    return true;
                    break;
        case ']':
                    if(pop(&s)=='[')
                    return true;
                    break;
        default:
            break;
        }
        
    }
    // printf("top is %d\n",s->top);
    if(s->top!=-1)
        return false;
    else
    return true;
}
int main(void)
{
    sqstack test;
    int x=0;
    init_stack(&test);
    if(!kuohao_push(&test))
    printf("err\n");
    printf("%d\n",test.top);

    
}