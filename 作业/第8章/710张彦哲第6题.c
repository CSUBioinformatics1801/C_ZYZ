//!encoding: UTF-8
//IDE: Clion 2019.2.2
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第4题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/10/10 11:57
#include <stdio.h>
#include <string.h>
#include <assert.h>
int get_string_length(char *store_point,unsigned int n){
    assert(n>0);
    int length=0;
    while (*store_point){
        length++;
        store_point++;
    }
    return length;
}
int main(void){
   puts("This is a program that count the length from you've input:");
   char store_str[100];gets_s(store_str,100);char *store_point=store_str;
   printf_s("True length by strlen=%d\n",strlen(store_str));
   printf_s("Length from get_string_length=%d\n",get_string_length(store_point,strlen(store_str)));
    return 0;
}

