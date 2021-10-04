#include<stdio.h>
#include<ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top]=x;
}

char pop()
{
    if(top==-1)
        return -1;  
    else
        return stack[top--];
}

int presedence(char x)
{
    if(x=='(')
        return 0;
    if(x=='+'||x=='-')
        return 1;
    else if(x=='*'||x=='/')
        return 2;
    else if(x=='^')
        return 3;
    return 0;
}

int main()
{
    char expression[100];
    char *a, x;
    printf("Enter the expression : ");
    scanf("%s",expression);
    printf("\n");
    a = expression;
    
    while(*a != '\0')
    {
        if(isalnum(*a))
            printf("%c ",*a);
        else if(*a == '(')
            push(*a);
        else if(*a == ')')
        {
            while((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while(presedence(stack[top]) >= presedence(*a))
                printf("%c ",pop());
            push(*a);
        }
        a++;
    }
    
    while(top != -1)
    {
        printf("%c ",pop());
    }
    return 0;
}