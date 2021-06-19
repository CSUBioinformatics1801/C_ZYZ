//!encoding: UTF-8
//IDE: Clion 2019.2.2
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第5题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/11/2 00:45
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
unsigned int st_num_a;
void initiate_a(void){
    srand((unsigned)(time(NULL)));
    st_num_a=rand()%28+3;//假设这个班存在3~30人；年龄都在18~22岁
}
typedef struct node{
    unsigned int Student_ID;
    char *name;
    char *sex;
    unsigned int age;
    struct node *next_node;
}Student_node;
struct names{
    char name[10];
}rand_names[30]={"William","Daniel","Olivia","James","Noah",
                 "Sophia","Madison","Dylan","Tyler","Eliza",
                 "Sarah","Brandon","Jessica","Angel","Lily",
                 "Ira","Gavin","Carter","Alex","Sofia",
                 "Addison","Jake","Aaron","Whitney","Joshua",
                 "Joyce","Park","Alita","Hugo","Victor"};
struct sexes{
    char gender[7];
}rand_sexes[2]={"Male","Female"};
void print_each_score_type_standard(unsigned int Student_ID,char *name,char *sex,unsigned int age){
    printf_s("%u\t%s\t%s\t%u\n",Student_ID,name,sex,age);
}
void puts_line(){
    puts("===========================================================");
}
Student_node *create_linked_lists_a(unsigned int a) {
    assert(a >= 3);
    puts_line();
    puts("Class A:\nSt_ID\tSt_name\tSex\tAge");
    Student_node *head_a = (Student_node *) malloc(sizeof(Student_node));//a头节点指针
    head_a->Student_ID = 1;//初始化a班头节点
    head_a->name=rand_names[rand()%30].name;//0~29
    head_a->sex=rand_sexes[rand()%2].gender;//0male,1female
    head_a->age=rand()%5+18;//18~18+5
    head_a->next_node = NULL;
    print_each_score_type_standard(head_a->Student_ID,head_a->name,head_a->sex,head_a->age);
    Student_node *Cycle_point_a = head_a;

    for (unsigned int i = 2; i <= a - 1; ++i) {//初始化a班的中间节点
        Student_node *body_a = (Student_node *) malloc(sizeof(Student_node));
        body_a->Student_ID = i;
        body_a->name=rand_names[rand()%30].name;//0~29
        body_a->sex=rand_sexes[rand()%2].gender;//0male,1female
        body_a->age=rand()%5+18;//18~18+5
        body_a->next_node = NULL;
        print_each_score_type_standard(body_a->Student_ID,body_a->name,body_a->sex,body_a->age);
        Cycle_point_a->next_node = body_a;
        Cycle_point_a = Cycle_point_a->next_node;
    }

    Student_node *tail_a = (Student_node *) malloc(sizeof(Student_node));
    tail_a->Student_ID = a;//初始化a班尾节点
    tail_a->name=rand_names[rand()%30].name;
    tail_a->sex=rand_sexes[rand()%2].gender;//0male,1female
    tail_a->age=rand()%5+18;//18~18+5
    tail_a->next_node = NULL;
    print_each_score_type_standard(tail_a->Student_ID,tail_a->name,tail_a->sex,tail_a->age);
    Cycle_point_a->next_node=tail_a;
    puts_line();
    return head_a;
}
//Student_node *delete(Student_node *head_a, unsigned int st_id){
//    assert(head_a!=NULL);
//    Student_node *cycle_a=head_a;
//    for (unsigned int i = 0; i < st_num_a; ++i) {
//        if(cycle_a->Student_ID==st_id){
//
//        }
//    }
//}
Student_node  *Delete(Student_node *head, unsigned int st_id){
    unsigned int count=st_num_a;
    if(head == NULL){//detect null lists
        puts("Null lists!");
        return NULL;
    }
    Student_node *p, *q;//p前q后
    p = head;
    q = p->next_node;
    while(q != NULL){
        if(q->Student_ID == st_id){
            p->next_node = q->next_node;
            free(q);
            printf_s("Wiping out %u successfully!",st_id);
            return head;// q = p->next_node;
        }else{
            p = p->next_node;
            q = q->next_node;
            count--;
            puts("else");
        }
    }
    if (count<=2){
        printf_s("There's no No.%u in the list!",st_id);
        return NULL;
    }
//    if(head != NULL && head->Student_ID == st_id){
//        q = head;//todo
//        head = q->next_node;
//        free(q);
//        printf_s("Wiping out %u successfully!",st_id);
//        return head;
//    }
    return head;
}

int main(void){
    puts("This is a program that integrate 2 classes final exam scores.");
    initiate_a();
    printf_s("Student number in class A: %d\n",st_num_a);
    Student_node *head_a=create_linked_lists_a(st_num_a);
    puts("Input the st_id of whom you want to kick out:");
    unsigned int st_id;scanf_s("%d",&st_id);
    Delete(head_a,st_id);
    return 0;
}