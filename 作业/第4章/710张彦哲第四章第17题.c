//!encoding: utf-8
//IDE: Clion 2019.2.1
//Architecture: Windows 10 SDK version 1903
//File Name: A710张彦哲第17题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/09/22 16:30
#include <stdio.h>

int main(){
    char a1[3]={'A','B','C'},a2[3]={'X','Y','Z'};
    puts("A ping-pang contest,A PK B:");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if((a1[i]=='A'&& a2[j]=='X')||(a1[i]=='C' && (a2[j]=='X'||a2[j]=='Z')));
            else printf_s("%c VS %c\n",a1[i],a2[j]);

        }
    }
    return 0;
}
