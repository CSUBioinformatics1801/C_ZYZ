//!encoding: utf-8
//IDE: Clion 2019.2.1
//Architecture: Windows 10 SDK version 1903
//File Name: A710张彦哲第1题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/09/04 19:08
//TODO:
#include <stdio.h>
#include <math.h>

int main()
{
    /*
 *Student ID:8305180710
 *Author name:张彦哲
 *Test number:1
 */
    double p,r=0.07;
    int n;
    printf_s("If you want to predict future economy growth of China, \nplease input the year(an absolute integer): ");
    scanf_s("%d",&n);
    if (n==0){n+=1};
    n=abs(n);  //in case the user wrongly input a minus
    p=pow((1.0+r),n);
    printf_s("The economy of China will grow %7.2f%% in %d years.(Supposing growth %3.2f%% per year)\n",p*100,n,r*100);
    return 0;
}
