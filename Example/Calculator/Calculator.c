#include <stdio.h>

int main()
{
   double number1 = 0.0;
   double number2 = 0.0;
   char operation;

   printf("\nEnter the calculation\n");
   scanf("%lf%c%lf",&number1,&operation,&number2);

   switch(operation)
   {
      case '+':
           printf("=%lf\n",number1+number2);
          break;
      case '-':
           printf("=%lf\n",number1-number2);
          break;
      case '*':
           printf("=%lf\n",number1*number2);
          break;
      case '/':
           if(number2==0)
            printf("\n\n\aDavision by zero error!\n");
           else
            printf("=%lf\n",number1/number2);
          break;
      case '%':
           if((long)number2==0)
             printf("\n\n\aDavision by zero error!\n");
           else
             printf("=%ld\n",(long)number1%(long)number2);
           break;
      default:
          printf("\n\n\aDavision by zero error!\n");
          break;
    }
    return 0;
}
