//!encoding: UTF-8
//IDE: Clion 2019.2.2
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第5题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/10/10 11:57
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *invertstring(char *a){
    char *inputstr=a; int strori=strlen(a);
    while(*inputstr)inputstr++;//移到末尾地址
    char *ivtdstr=inputstr;
    *(ivtdstr+1)='\0';
    while (*--inputstr && strori--){
        char temp=*inputstr;
        *ivtdstr++=temp;
    }
   // *ivtdstr='\0';
    return ivtdstr;
}
void printivtstr(char *b){
    char *inputstr=b;
    int strori=strlen(b);
    while(*inputstr){//移到末尾地址
      //  printf_s("%c,%x\n",*inputstr,inputstr);
        inputstr++;
    }
    puts("===");
    while(*--inputstr && strori--){
        printf_s("%c",*inputstr);
    }
}
int main(void){
    puts("This is a program that invert the string you've input:");
    char inputstr[100];gets_s(inputstr,100);
    puts("Inverted:");
   // printf_s("_strrev=%s\n",_strrev(inputstr));//这个函数会打乱inputstr指针，彻底反转
    //printf_s("invertstring=%s\n",invertstring(inputstr));
    printivtstr(inputstr);
    return 0;
}

