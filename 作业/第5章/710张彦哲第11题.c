//!encoding: ASCII
//IDE: Clion 2019.2.1
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第11题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/09/15 16:33
#include <stdio.h>
#include <math.h>

int main(){
    double la,height,g,rebht,allht;
    unsigned int times;
    puts("This is a program that calculate rebound height of a falling ball after some times.");
    puts("Please input the height(m):");
    scanf_s("%lf",&height);
    puts("Please input times(more than 1):");
    scanf_s("%d", &times,1);
    while(times==0){
        puts("Times should't be 0, please input again:");
        scanf_s("%d", &times,1);
    }
    rebht=fabs(height)*pow(0.5,times);
    allht=fabs(height)*(3-pow(0.5,times-2));
    printf_s("%lf,%lf",rebht,allht);
//计算下面所需时间
//    char latitude[30];
//    char deg[]={0xa1,0xe3,0};//This is "°"
//    printf_s("And current latitude(for example N30%s04'25.93\"):",deg);
//    /*
//     * "°"is not among ASCII，thus it can't be printed by %c. Change as sprintf() or %s. In gb2312: 0xa1e3
//     * "°"是gb2312储存的，用2个字节，第一个0xa1,第二个0xe3,第三个0，为什么有第三个？
//     * "°"在char中的10进制储存;[-95,-29]，16进制储存：ffffffa1,ffffffe3,补码-(5*16+15)
//     */
//    gets_s(latitude,30);//input original latitude as a string，这个数组最后有一个0
//
//    //C语言居然没有正则表达式!!!坑!以下实现伪正则表达式
//    int getdu=0,getd=0,getdd=0,getp=0; //0 means not found,
//    for(int i=0;i<30;i++){
//        if(latitude[i]==-95 && latitude[i+1]==-29)getdu=i;//get "°" position
//        else if(latitude[i]==39 && latitude[i+1]!=39)getd=i;//"'" is 39 ascii
//        else if(latitude[i]==39 && latitude[i+1]==39)getdd=i;
//        else if(latitude[i]==46 && latitude[i+1]>=48 && latitude[i+1]<=57)//"." is 46 in ascii
//    }

//下面是测试部分
//    char fuck[50];
//gets_s(fuck,50);
//for(int j=0;j<30;j++){
//printf_s("%d\n",fuck[j]);}
    return 0;
}
/*
 * 一个球从100m自由落体，每次落地反弹高度为原来的一半，求第10次落地反弹高度，以及整个的运动距离
 * 理论依据：g=9.7803(1+0.0053024sin²ψ-0.000005sin²2ψ) m/s² （1979修订公式）
 * 思路：输入维度，计算g值；忽略高度变化，忽略空气阻力
 */