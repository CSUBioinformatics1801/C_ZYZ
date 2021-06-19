//!encoding: ASCII
//IDE: Clion 2019.2.1
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第11题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/09/25 22:45
#include <stdio.h>
int main(void) {
    char *what="* * * * *";
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < i; ++j) {
            printf_s(" ");
        }
       printf_s("%s\n",what);
    }

    return 0;
}
/*
 * 题目：输出以下图案：
 *           * * * * *
 *              * * * * *
 *                  * * * * *
 *                     * * * * *
 *                        * * * * *
 *                           * * * * *
 * 思路：2个循环打印就行了，很简单
 */
