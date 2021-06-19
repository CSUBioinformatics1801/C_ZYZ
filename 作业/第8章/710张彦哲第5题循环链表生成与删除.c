//!encoding: UTF-8
//IDE: Clion 2019.2.2
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第5题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/11/2 00:45
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct node{
    unsigned int number;//people's ID
    struct node *next;
}person;
person *initLink(unsigned int n){//初始化链表
    assert(n>=2);
    person *head=(person*)malloc(sizeof(person));//头节点指针
    head->number=1;
    head->next=NULL;
    person *cyclic=head;//用于循环的指针
    for (unsigned int i=2; i<=n; i++) {//定义中间节点
        person *body=(person*)malloc(sizeof(person));
        body->number=i;
        body->next=NULL;
        cyclic->next=body;
        cyclic=cyclic->next;
    }
    cyclic->next=head;//首尾相连
    return head;
}
void find_and_kill_K(person *head,unsigned int k,unsigned int m){
    person *tail=head;//找到链表第一个结点的上一个结点，为删除操作做准备
    while (tail->next!=head) {//循环到尾节点
        tail=tail->next;
    }
    person *p=head;//从头开始找到编号为k的人
    while (p->number!=k) {
        tail=p;
        p=p->next;
    }//从编号为k的人开始，只有符合p->next==p时，说明链表中除了p结点，所有编号都出列了
    while (p->next!=p) {//找到从p报数1开始，报m的人，并且还要知道数m-1的人的位置tail，方便做删除操作
        for (unsigned int i=1; i<m; i++) {
            tail=p;
            p=p->next;
        }
        tail->next=p->next;//从链表上将p结点摘下来
        printf_s("Removing player:%d\n",p->number);
        free(p);//把该人kill掉
        p=tail->next;//继续使用p指针指向出列编号的下一个编号，循环继续
    }
    printf_s("Winner:%d\n",p->number);
    free(p);//最后1个
}
void puts_line(){
    puts("=======================================");
}
int main(void) {
    puts("-This is a program that plays a game:\n-Several players surround a table, players number off one by one.\n-Who numbered a predetermined number will be removed out.\n-And it turns over and over again to the last player(winner).");
    printf_s("Input players number:\n");
    unsigned int n;scanf_s("%d",&n);
    person *head=initLink(n);
    printf_s("Input a integer, will start from the ranked player(1<x<%d):\n",n);
    unsigned int k;scanf_s("%d",&k);assert(k>=1);
    printf_s("Input a integer, player who counts it will be removed:\n");
    unsigned int m;scanf_s("%d",&m);assert(m<n);
    puts_line();
    find_and_kill_K(head, k, m);
    puts_line();
    return 0;
}