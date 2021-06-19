//!encoding: UTF-8
//IDE: Clion 2019.2.2
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第4题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/10/10 11:57
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int b[5][5];
void transpose(int a[5][5]){
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            b[i][j]=a[j][i];
        }
    }
}
int main(void){
    int a[5][5];
    srand((unsigned)time(NULL));
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            a[i][j]=rand()%100+1;
        }
    }
    puts("Origin:\n====================================");
    for(int i=0;i<5;i++){
        for (int j = 0; j < 5; ++j) {
            printf_s("%d\t",a[i][j]);
        }
        puts("");
    }
    transpose(a);
    puts("====================================\ntransposing...");
    puts("transposed:\n====================================");
    for(int i=0;i<5;i++){
        for (int j = 0; j < 5; ++j) {
            printf_s("%d\t",b[i][j]);
        }
        puts("");
    }
    puts("====================================\nSuccessful transposed.");
    return 0;
}

