//!encoding: UTF-8
//IDE: Clion 2019.2.2
//Architecture: Windows 10 SDK version 1903
//File Name: 710�����ܵ�5��.c
//Author: Sean Peldom Zhang
//Create Time: 2019/11/2 00:45
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
//��Ŀ���ϲ���������ѧ��˳��
unsigned int st_num_a,st_num_b;
void initiate_a_b(void){
    srand((unsigned)(time(NULL)));
    st_num_a=rand()%28+3;
    st_num_b=rand()%28+3;//each class has 3 to 30 students;
}
struct scores{
    int Physics;
    int Chemistry;
    int Biology;
};
typedef struct node{
    unsigned int Student_ID;//a��ȫΪ2n-1��b��ȫΪ2n����ʹa��bӦ�ò�ͬҲ�����ظ�
    char *name;//����û��ϵ������������������
    struct scores subject;
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
void print_each_score_type_standard(unsigned int Student_ID,char *name,int Physics,int Chemistry,int Biology){
    printf_s("%u\t%s\t%d\t%d\t%d\n",Student_ID,name,Physics,Chemistry,Biology);
}
void puts_line(){
    puts("===========================================================");
}
Student_node *create_linked_lists_a(unsigned int a) {
    assert(a >= 3);
    puts_line();
    puts("Class A:\nSt_ID\tSt_name\tPhysics\tChem\tBiology");
    Student_node *head_a = (Student_node *) malloc(sizeof(Student_node));//aͷ�ڵ�ָ��
    head_a->Student_ID = 1;//��ʼ��a��ͷ�ڵ�
    head_a->name=rand_names[rand()%30].name;//0~29
    head_a->subject.Physics = rand() % 100 + 1;
    head_a->subject.Chemistry = rand() % 100 + 1;
    head_a->subject.Biology = rand() % 100 + 1;
    head_a->next_node = NULL;
    print_each_score_type_standard(head_a->Student_ID,head_a->name,head_a->subject.Physics,head_a->subject.Chemistry,head_a->subject.Biology);
    Student_node *Cycle_point_a = head_a;

    for (unsigned int i = 2; i <= a - 1; ++i) {//��ʼ��a����м�ڵ�
        Student_node *body_a = (Student_node *) malloc(sizeof(Student_node));
        body_a->Student_ID = 2*i-1;
        body_a->name=rand_names[rand()%30].name;
        body_a->subject.Physics = rand() % 100 + 1;
        body_a->subject.Chemistry = rand() % 100 + 1;
        body_a->subject.Biology = rand() % 100 + 1;
        body_a->next_node = NULL;
        print_each_score_type_standard(body_a->Student_ID,body_a->name,body_a->subject.Physics,body_a->subject.Chemistry,body_a->subject.Biology);
        Cycle_point_a->next_node = body_a;
        Cycle_point_a = Cycle_point_a->next_node;
    }

    Student_node *tail_a = (Student_node *) malloc(sizeof(Student_node));
    tail_a->Student_ID = 2*a-1;//��ʼ��a��β�ڵ�
    tail_a->name=rand_names[rand()%30].name;
    tail_a->subject.Physics = rand() % 100 + 1;
    tail_a->subject.Chemistry = rand() % 100 + 1;
    tail_a->subject.Biology = rand() % 100 + 1;
    tail_a->next_node = NULL;
    print_each_score_type_standard(tail_a->Student_ID,tail_a->name,tail_a->subject.Physics,tail_a->subject.Chemistry,tail_a->subject.Biology);
    Cycle_point_a->next_node=tail_a;
    puts_line();
    return head_a;
}
Student_node *create_linked_lists_b(unsigned int b) {
    assert(b>=3);
    puts_line();
    puts("Class B:\nSt_name\tSt_ID\tPhysics\tChem\tBiology");
    Student_node *head_b=(Student_node*)malloc(sizeof(Student_node));//bͷ�ڵ�ָ��
    head_b->Student_ID=2;//��ʼ��b��ͷ�ڵ�
    head_b->name=rand_names[rand()%30].name;//0~29
    head_b->subject.Physics=rand()%100+1;
    head_b->subject.Chemistry=rand()%100+1;
    head_b->subject.Biology=rand()%100+1;
    head_b->next_node=NULL;
    print_each_score_type_standard(head_b->Student_ID,head_b->name,head_b->subject.Physics,head_b->subject.Chemistry,head_b->subject.Biology);
    Student_node *Cycle_point_b=head_b;

    for (unsigned int i = 2; i <= b-1; ++i) {//��ʼ��b���м�ڵ�
        Student_node *body_b=(Student_node*)malloc(sizeof(Student_node));
        body_b->Student_ID=i*2;
        body_b->next_node=NULL;
        body_b->name=rand_names[rand()%30].name;
        body_b->subject.Physics=rand()%100+1;
        body_b->subject.Chemistry=rand()%100+1;
        body_b->subject.Biology=rand()%100+1;
        print_each_score_type_standard(body_b->Student_ID,body_b->name,body_b->subject.Physics,body_b->subject.Chemistry,body_b->subject.Biology);
        Cycle_point_b->next_node=body_b;
        Cycle_point_b=Cycle_point_b->next_node;
    }

    Student_node *tail_b = (Student_node *) malloc(sizeof(Student_node));
    tail_b->Student_ID = b*2;//��ʼ��b��β�ڵ�
    tail_b->name=rand_names[rand()%30].name;
    tail_b->subject.Physics = rand() % 100 + 1;
    tail_b->subject.Chemistry = rand() % 100 + 1;
    tail_b->subject.Biology = rand() % 100 + 1;
    tail_b->next_node = NULL;
    print_each_score_type_standard(tail_b->Student_ID,tail_b->name,tail_b->subject.Physics,tail_b->subject.Chemistry,tail_b->subject.Biology);
    Cycle_point_b->next_node=tail_b;
    puts_line();
    return head_b;
}
Student_node *integrate(Student_node *head_a,Student_node *head_b){//����a����������õģ�b���ǣ���b��һ����a��
    assert(head_a!=NULL && head_b!=NULL);//����ab�����ǿձ�
    Student_node *cycle_b=head_b,*cycle_a=head_a;
    for (unsigned int j=1;j<=st_num_b;j++){//ѭ��b�Σ��������нڵ�
        head_b=head_b->next_node;//���ڽ���cycle_b֪��ԭhead����ͬ�ڼ�����head�������µ�head,head_b������NULL
        printf_s("cycle_b%d\n",cycle_b->Student_ID);
        if(head_a->Student_ID>cycle_b->Student_ID){//���b��a�ĵ�һ����С����b�����Ĳ�����a��ͷ����������һ�����ᷢ��
            head_a->next_node=cycle_b;
            cycle_b->next_node=cycle_a->next_node;
            printf_s("before\n");
           // goto insert_jump;//�����м�
        }else{
            while(cycle_a->next_node!=NULL && cycle_a->Student_ID < cycle_b->Student_ID){//cycle_a�������1���ڵ�
                //����1~n-1��
                if(cycle_a->next_node->Student_ID>cycle_b->Student_ID){//���м����
                    cycle_b->next_node=cycle_a->next_node;//�Ȳ��
                    cycle_a->next_node=cycle_b;//�ٲ�ǰ
                    printf_s("a%d,b%d,a%d\n",cycle_a->Student_ID,cycle_b->Student_ID,cycle_b->next_node->Student_ID);
                }
                printf_s("%d ",cycle_a->Student_ID);
                cycle_a=cycle_a->next_node;//��1��������

                if(cycle_a->next_node->next_node==NULL && cycle_a->next_node->Student_ID < cycle_b->Student_ID){//���ͣ��n-1����nС���䣬��Ҫ����n��
                    cycle_a->next_node->next_node=cycle_b;
                    cycle_b->next_node=NULL;
                    puts("jump\n");
                    goto insert_jump;//�������
                }
            }
        }
        insert_jump:
        cycle_b=head_b;//��ʼ��cycle_b
        cycle_a=head_a;//��ʼ��cycle_a
    }
    puts("");
    return head_a;
}
void print_integrated_linked_lists(Student_node *head_integrate){
    Student_node *cycle_itg=head_integrate;
    puts_line();
    puts("Class A+B:\nSt_ID\tSt_name\tPhysics\tChem\tBiology");
    for (unsigned int i = 0; i < st_num_a+st_num_b; ++i) {
        print_each_score_type_standard(cycle_itg->Student_ID,cycle_itg->name,cycle_itg->subject.Physics,cycle_itg->subject.Chemistry,cycle_itg->subject.Biology);
        if(cycle_itg->next_node!=NULL)cycle_itg=cycle_itg->next_node;
    }
    puts_line();
}
int main(void){
    puts("This is a program that integrate 2 classes final exam scores.");
    initiate_a_b();
    printf_s("Student number in class A: %d\nStudent number in class B: %d\n",st_num_a,st_num_b);
    Student_node *head_a=create_linked_lists_a(st_num_a);
    Student_node *head_b=create_linked_lists_b(st_num_b);
    puts("Integrating...");
    Student_node *head_integrate=integrate(head_a,head_b);
    print_integrated_linked_lists(head_integrate);
    return 0;
}