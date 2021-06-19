//!encoding: UTF-8
//IDE: Clion 2019.2.2
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第7题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/10/10 11:57
#include <stdio.h>
char vowels[159];
void etcvl(char *a){
    char *getstr=a;
    unsigned int getvl=0;
    while(*getstr){
        if(*getstr=='a'||*getstr=='e'||*getstr=='i'||*getstr=='o'||*getstr=='u')vowels[getvl++]=*getstr;
        getstr++;
    }
}
int main(void){
    puts("This is a program that extract vowels from string you've input:");
    char getstr[160];gets_s(getstr,159);
    etcvl(getstr);
    printf_s("vowels=%s",vowels);
    return 0;
}

