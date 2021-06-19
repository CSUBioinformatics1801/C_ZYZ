//!encoding: utf-8
//IDE: Clion 2019.2.1
//Architecture: Windows 10 SDK version 1903
//File Name: A710张彦哲第3题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/09/04 19:54
//TODO:
#include <stdio.h>
#include <math.h>

int main()
{
    /*
  *Student ID:8305180710
  *Author name:张彦哲
  *Test number:3
  */
    double d,p,r=0.01;
   int m;
   printf_s("This is a program that can calculate when you can pay off loan from bank.\nPlease input debut:\n");
   scanf_s("%lf",&d);
   printf_s("How much would like to repay per month?\n");
   scanf_s("%lf",&p);
   printf_s("calculating...current monthly interest rate is %3.2f%%\n",r);
   m=ceil(log10(p/(p-d*r))/log10(1.0+r));
   if(m<600 && m>0)//in case m is larger than 21474836473 and turns into a minus
       printf_s("Your loan will be paid off in %d mouths.",m);
   else
       printf_s("Oops! Your loan may never be paid off in your lifetime!");
   return 0;
}
