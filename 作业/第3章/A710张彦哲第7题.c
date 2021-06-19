//!encoding: utf-8
//IDE: Clion 2019.2.1
//Architecture: Windows 10 SDK version 1903
//File Name: A710张彦哲第7题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/09/06 00:15
#include <stdio.h>
#include <assert.h>
#include <math.h>
#define PI 3.1415926535

int main()
{
    /*
    *Student ID:8305180710
    *Author name:张彦哲
    *Test number:7
    */
    printf_s("This is a program that help calculate "
             "sphere surface,sphere volume,cylinder volume,cylinder surface.\n"
             "What are you going to do? \n"
             "To get a sphere,input 1.\n"
             "To get a cylinder,input 2.\n");
    unsigned int rtype;
    wrongnum:
    printf_s("Type=");
    scanf_s("%d",&rtype,1);
    assert(rtype<=10000 && rtype>=0);
    double r,h;
    switch (rtype) {
        case 1:
            printf_s("Please input the radius:\n"
                     "radius=");
            scanf_s("%lf", &r,1);
            printf_s("The circumference is %5.2lf,the surface is %5.2lf, the volume is %5.2lf.",
                    r * 2 * PI,PI*4*pow(r,2), PI * pow(r, 3) * 4 / 3);
            break;
        case 2:
            printf_s("Please input the radius and height:\n"
                     "radius=");
            scanf_s("%lf", &r,1);
            printf_s("height=");
            scanf_s("%lf",&h,1);
            printf_s("The cylinder volume is %5.2lf,the cylinder surface is %5.2lf.",h*pow(r,2)*PI,pow(r,2)*PI+h*PI*2*r);
            break;
        default:
            printf_s("Oops! You just input a wrong number.Try again:\n");
            goto wrongnum;
    }
    return 0;
}
