//!encoding: ASCII
//IDE: Clion 2019.2.1
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第8题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/09/18 17:16
#include <stdio.h>
#include <math.h>
int main(){
    puts("This is a program that calculate all the 'Narcissi few':");
    for(int hundred=1;hundred<=9;hundred++){
        for(int decade=0;decade<10;decade++){
            for(int unit=0;unit<10;unit++){
                if(unit+decade*10+hundred*100==pow(unit,3)+pow(decade,3)+pow(hundred,3)){
                    //whether it is a Narcissi number
                    printf_s("%d\n",unit+decade*10+hundred*100);
                }
            }
        }
    }
    return 0;
}