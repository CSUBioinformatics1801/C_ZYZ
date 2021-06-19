//!encoding: UTF-8
//IDE: Clion 2019.2.2
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第4题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/10/10 11:57
#include <stdio.h>
#include <string.h>
char *invert_point;
void invert_str(char store_str[100],unsigned int n){
   invert_point=&store_str[n-1];
    for (unsigned int i = 0; i <n ; ++i) {
        printf_s("%c",*invert_point);
        invert_point--;
    }
}
int main(void){
   puts("This is a program that invert what you've input:");
   char store_str[100];gets_s(store_str,100);
   unsigned int n=strlen(store_str);
   invert_str(store_str,n);

    return 0;
}

