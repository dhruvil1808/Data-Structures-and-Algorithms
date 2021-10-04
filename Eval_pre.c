#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
 
#define LIMIT 100
int stack[LIMIT];
      int a=0;
 
void push(int stack[], int num)
{
      if(a == LIMIT)
      {
            printf("\nStack Overflow\n");
            exit(-1);
      }
      else
      {
            stack[a++]=num;
      }
}
 
int pop(int stack[])
{ 
      int num;
      if(a < 0)
      {
            printf("\nStack Underflow\n");
            exit(-1);
      }
      num=stack[--a];
      return num;
}
 

 
int find_operator(char ch)
{
      switch(ch)
      {
            case '%': return 20;
            case '/': return 20; 
            case '*': return 20;
            case '-': return 20;
            case '$': return 20;
            case '+': return 20;
            default : return 10;
      }
}
 
int main()
{
      int x, y, element, length, count;
      char  expression[LIMIT];
      
      printf("\nEnter Prefix Expression:\t");
      scanf("%s", expression);
      length = strlen(expression);
      for(count = length - 1; count >= 0; count--)
      {
            if(expression[count] == '\0'||expression[count] == ' ')
            {
                  continue;
            }
            switch(find_operator(expression[count]))
            {
                case 20 : 
                            x = pop(stack);
                            y = pop(stack);
                            int result;
                            switch(expression[count])
                            {
                             case '-': result = x - y;
                                break;
                             case '*': result = x * y;
                                break;
                             case '%': result = x % y;
                                break;
                             case '/': result = x / y;
                                break;
                             case '+': result = x + y;
                                break;
                             case '$': result = pow(x, y);
                                break;
                            }
                            push(stack, result);
                break;
                
                case 10 : 
                            element = expression[count] - '0';
                            push(stack, element);
                break;
            }
      }
      printf("\nEvaluation of Prefix Expression:\t %d\n", stack[0]);
      return 0 ;
}