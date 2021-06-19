//!encoding: utf-8
//IDE: Clion 2019.2.1
//Architecture: Windows 10 SDK version 1903
//File Name: A710张彦哲第4题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/09/04 21:38
//TODO:
#include <stdio.h>
#include <math.h>

int main()
{
    /*
 *Student ID:8305180710
 *Author name:张彦哲
 *Test number:4
 */
    char c1,c2;
    c1=97;c2=98;
    printf_s("c1=%c,c2=%c\n",c1,c2);
    printf_s("c1=%d,c2=%d\n",c1,c2);
    return 0;
}
/*output:
c1=a,c2=b
c1=97,c2=98

进程已结束，退出代码 0

 *Answer:
 * (1)In ASCII,each number correspond to a character.
 * The 97th is "a" while the 98th is "b".
 * Therefore, if we output 97/98 by %c, we output the correspondent character, and they are "a"&"b".
 * And if we do by %d, we output decimal integers, they are 97&98.
 *
 * (2)If we change c1 to 197 and c2 to 198, the new output is
"c1=?c2=?
c1=-59,c2=-58

进程已结束，退出代码 0".
 * The number in ASCII range from 0 to 127. So, 197 or 198 are invalid in ASCII, nothing can be output by %c.
 * Also a char in RAM holds 8 placeholders, from 00000000 to 11111111, equals to -128 to 127.And it's a circle.
 * If a char is assigned a number that is bigger than 127,it will overflow.
 * Let's take 197 for example, after 1st circle:197-127=70,in 2nd circle:70-128-1=-59
 *
 * (3)output:
c1=a,c2=b
c1=97,c2=98

进程已结束，退出代码 0
 * Although char holds 1 placeholder while int holds 4 placeholders in 64bit compiler.
 * Whether 197 in char or in int will not differentiate output.
 */