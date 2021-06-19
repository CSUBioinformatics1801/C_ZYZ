//!encoding: utf-8
//IDE: Clion 2019.2.1
//Architecture: Windows 10 SDK version 1903
//File Name: A710张彦哲第10题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/09/22 13:37
#include <stdio.h>
int main()
{
    puts("This is a program that help you calculate allowance from your performance.\nPlease input your benefit this year:");
    double bef;int type;scanf_s("%lf",&bef);
    enum beftype{lessthan100k=0,from100kto200k=1,from200kto400k=2,from400kto600k=3,from600kto1m=4,morethan1m=5};
    if(bef<1E6)type=lessthan100k;
    else if(bef<=2E6)type=from100kto200k;
    else if(bef<=4E6)type=from200kto400k;
    else if(bef<=6E6)type=from400kto600k;
    else if(bef<=1E7)type=from600kto1m;
    else type=morethan1m;
    double alwced[6]={bef/10,(bef-1E6)*0.075,(bef-2e6)*0.05,(bef-4e6)*0.03,(bef-6e6)*0.015,(bef-1e7)*0.01};
    double alwce[6];
    for (int i = 0; i < 6; i++) {
        if(i==0)alwce[0]=alwced[0];
        else alwce[i]=alwce[i-1]+alwced[i];
        printf_s("%lf\n",alwce[i]);
    }
    switch(type){
        case lessthan100k:puts("How could you earn so much less!");break;
        case from100kto200k:puts("It that all?Work harder!");break;
        case from200kto400k:puts("Try better next year,your can be better.");break;
        case from400kto600k:puts("Well done!");break;
        case from600kto1m:puts("Nice work this year!");break;
        case morethan1m:puts("Unparalleled!");break;
        default:;
    }
    printf_s("Your allowances are %-.2lf this year.",alwce[type]);
    return 0;
}
