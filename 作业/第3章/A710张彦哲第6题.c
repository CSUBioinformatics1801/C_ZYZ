//!encoding: utf-8
//IDE: Clion 2019.2.1
//Architecture: Windows 10 SDK version 1903
//File Name: A710张彦哲第6题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/09/05 21:52
#include <stdio.h>

int main()
{
    /*
 *Student ID:8305180710
 *Author name:张彦哲
 *Test number:6
 */
    printf_s("This is a program that encode each character, \n"
             "translating them into 4 latter than original one.\n"
             "Please input a word:\n");
    char origin[41],trans[41];   //No word holds more than 40 chars,and 40 chars + '\0'
    gets_s(origin,40); //input
    int i=0;
    for (int k=0;k<40;k++){
        if ((origin[k]<='z'&& origin[k]>='a')| (origin[k]<='Z'&& origin[k]>='A'))
            i++;
    }//i is the length of the word,so that to lower circulation times
//FIXME    printf_s("%d\n",i);
//    system("pause");
//    char *sp="pointer";
//    printf("%s,%c,%c\n",sp,*sp,*(sp+2));
//    int i=strlen(sp);
//    printf_s("%d",i);
//    char origin[];
//    origin=(char *)malloc(sizeof(char));
//    scanf_s("%s\n",origin);
   for(int k=0;k<i;k++)
    {
        if (origin[k]>='a' && origin[k]<='z')//this char is uppercase
        {
            if (origin[k] + 4 <= 'z')
                trans[k] = origin[k] + 4;
            else
               trans[k]=origin[k]-22;
        }
        else //this char is capital
            {
            if (origin[k] + 4 <= 'Z')
                trans[k] = origin[k] + 4;
            else
                trans[k]=origin[k]-22;
            }
        printf_s("%c",trans[k]);
    };
    return 0;
}
