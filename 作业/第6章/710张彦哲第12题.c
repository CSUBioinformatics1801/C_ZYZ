//!encoding: ASCII
//IDE: Clion 2019.2.1
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第12题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/09/25 23:03
#include <stdio.h>
int main(void) {
    puts("This is a program that encrypt the string you've input, now please input a string:");
    char origin[61],trans[61];   //60 chars + '\0'
    gets_s(origin,60); //input
    int i=0;
    for (int k=0;k<60;k++){
        if ((origin[k]<='z'&& origin[k]>='a')|| (origin[k]<='Z'&& origin[k]>='A'))
            i++;
    }//i is the length of the word,so that to lower circulation times
    printf_s("Ciphertext:  ");
    for (int k=0;k<i;k++){
        if(origin[k]<='Z'&& origin[k]>='A')trans[k]=155-origin[k];
        else if(origin[k]<='z'&& origin[k]>='a')trans[k]=219-origin[k];
        else trans[k]='*';
        printf_s("%c",trans[k]);
    }
    puts("\n* means the character cannot be encrypted.");
    return 0;
}
/*
 * 题目：输入文字后，翻译密码：
 *A to Z,a to z, B to Y,b to y,....
 * 思路：很简单，对应每个数组元素对着ASCII转换
 */
