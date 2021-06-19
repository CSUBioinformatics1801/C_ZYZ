//!encoding: utf-8
//IDE: Clion 2019.2.1
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第8题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/09/15 15:52
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *test(float x){
  static char result[100];
    if    (x>=90.0 && x<=100.0)strcpy_s(result,100,"Excellent! You get an A!");
    else if(x>=80.0 && x<90.0)strcpy_s(result,100,"Well done! You get a B.");
    else if(x>=70.0 && x<80.0)strcpy_s(result,100,"You finally get a C.");
    else if(x>=60.0 && x<70.0)strcpy_s(result,100,"Work harder! You get the D!");
    else if(x>=0.0  && x<=60.0)strcpy_s(result,100,"Junk! How could you failed the exam! It's E! Try once again!");
    else strcpy_s(result,50,"Please input right number between 0 and 100!");
    return result;
}
int main(){
    float input_x;
    char *mark;
    int n=0;
    tryagain:
    if (n<10) {
        puts("Please input an number,the program will output its mark.");
        puts("Please input your score:");
        scanf_s("%f", &input_x);
        mark=test(input_x);
        printf_s("%s\n",mark);
        n++;//防止无穷循环
        goto tryagain;
    }
    return 0;
}
