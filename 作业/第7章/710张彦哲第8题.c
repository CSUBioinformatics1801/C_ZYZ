//!encoding: UTF-8
//IDE: Clion 2019.2.2
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第8题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/10/10 11:57
#include <stdio.h>
#include <string.h>
#include <assert.h>
void printblank(char *a){
    assert(a!=NULL);
    char *getstr=a;
    for (int i = 0; i < strlen(a); i++) {
        printf_s("%c",*getstr++);
        if(i!=strlen(a))printf_s(" ");
    }
}
int main(void){
    puts("This is a program that print blank between numbers from string you've input:");
    char getstr[160];gets_s(getstr,159);
    printblank(getstr);
    return 0;
}

