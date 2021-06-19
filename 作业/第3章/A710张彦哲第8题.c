//!encoding: utf-8
//IDE: Clion 2019.2.1
//Architecture: Windows 10 SDK version 1903
//File Name: A710张彦哲第8题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/09/07 00:12
#include <stdio.h>


int main()
{
/*
 *Student ID:8305180710
 *Author name:张彦哲
 *Test number:8
 */
    int c1,c2;
    c1=getchar();//change char input in stdin to int
    c2=getchar();
    putchar(c1);//output the ASCII of a int(from 0 to 127) into stdout
    putchar(c2);
    return 0;
}
/*
 * Ques1:Whether c1 & c2 should be defined as char, int, or both?
 * Ans1: int is better, but defining as char doesn't bring any bugs. Because getchar() return stdin as int.
 *
 * Ques2:What you should do if you'd like to get the ASCII of c1 and c2?
 * Ans2:Use: printf_s("c1=%d,c2=%d",c1,c2);
 *
 * Ques3:Is "char c1,c2;" the same as "int c1,c2;"?
 * Ans3:NO. But they are substitutable in this program.
 */