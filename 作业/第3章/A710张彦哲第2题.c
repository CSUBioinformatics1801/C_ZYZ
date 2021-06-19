//!encoding: utf-8
//IDE: Clion 2019.2.1
//Architecture: Windows 10 SDK version 1903
//File Name: A710张彦哲第2题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/09/04 19:29
//TODO:
#include <stdio.h>
#include <math.h>
#include <assert.h>

int main()
{
    /*
 *Student ID:8305180710
 *Author name:张彦哲
 *Test number:2
 */
    double m,i[5],maxi=0;
    unsigned int dtype,besttype;
    printf_s("Supposing you gonna deposit a sum of money,\nthis program will help you optimize your interest.\nPlease input the money: ");
    scanf_s("%lf",&m);
    printf_s("Now you have %7.2f yuan to deposit,please choose a deposit type:\n",m);
    printf_s("(1)5 year fixed\n");
    printf_s("(2)Firstly a 2 year fixed, then turn it to 3 year fixed\n");
    printf_s("(3)Firstly a 3 year fixed, then turn it to 2 year fixed\n");
    printf_s("(4)one-year fixed for 5 times\n");
    printf_s("(5)current interest\n");
    printf_s("Input your type(1,2,3,4,5):\n");
    scanf_s("%u",&dtype);
    assert(dtype==1|dtype==2|dtype==3|dtype==4|dtype==5);
    //calculate all interest
    i[0]=1.0+0.03*5;
    i[1]=(1.0+0.021*2)*(1.0+0.0275*3);
    i[2]=(1.0+0.0275*3)*(1.0+0.021*2);
    i[3]=pow(1.0+0.015,5);
    i[4]=pow(1.0+0.0035,5*4);
    //get max interest
    for(int k=0;k<4;k++)
    {
        if (maxi<i[k])
        {
            maxi=i[k];
            besttype=k+1;
        }
    }
    if(dtype==besttype)
       printf_s("Congratulations!The type is the best!,you will get %8.2f yuan.\n",i[dtype-1]*m);
    else
       printf_s("You will get %8.2f yuan, but you can get more %8.2f yuan if you had chosen type %d.\n",i[dtype-1]*m,m*(maxi-i[dtype-1]),besttype);

    return 0;
}
