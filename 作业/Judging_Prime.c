#include <stdio.h>
#include <math.h>

/*int main()
{
    int a,b,c,d;
    printf_s("Please import 3 integers(for example 1,2,3)\n");
    scanf_s("%d,%d,%d",&a,&b,&c);
    printf_s("Max_num is %d\n.",(d=(a>b?a:b))>c?d:c);
    return 0;
}*/


int main()
{
    int n1,n2,x,isprime;
    printf_s("Please key in 2 different positive integers.\n(For example:1,10):");
    scanf_s("%d,%d",&n1,&n2);
    if (n1>n2) //changing 2 integers if wrong
    {
        int t;
        t=n1;n1=n2;n2=t;
    }
    for (x=n1;x<n2;x++) //cycling output from n1 to n2
    {
        isprime = 0;
        for (int yueshu = 2; (yueshu) <= sqrt(x); yueshu++)
        {
            if (x % yueshu == 0)
            {
                isprime = 1;//if isprime is 1,then the num is not the one.
                break;
            }

        }
        if (isprime == 0)
        printf("%d\n", x);
    }
    return 0;
}

/*int PanduanZhishu(int x) //judging whether x is a prime number,yes 1,not 0.
{
    for(int yueshu=2;(yueshu-1)<x;yueshu++)
        if (x%yueshu==0)
        {
            return 1;
            break;
        }
    return 0;
}*/