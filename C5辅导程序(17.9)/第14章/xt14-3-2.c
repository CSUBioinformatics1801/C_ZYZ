#include "stdio.h"
    #include "string.h"
    #include "stdlib.h"
    #define MaxSize 20
    typedef struct guest_info
    {
        char name[8];                    //姓名 
        int  sum;                       //人数 
        char time[10];                   //用餐时间 
        int number;                     //编号 
        struct guest_info *next;
    } GuestLink,*Pointer;
    void Insert(Pointer *Head);            //函数声明 
    void Search(Pointer Head);
    void Update(Pointer Head);
    void Delete(Pointer *Head);
    void Show(Pointer Head);

    int main()
    {
        Pointer Head=NULL;                          //定义表头指针 
        int i;                     
        do                                          //显示一个简易菜单 
        {   printf ("\n");
            printf ("1---插入(Insert)\n");
            printf ("2---查询(Search)\n");
            printf ("3---修改(Update)\n");
            printf ("4---删除(Delete)\n");
            printf ("5---显示(Show)\n");
            printf ("6---退出(Exit)\n");
            scanf ("%d",&i);                          //接收用户的选择 
            switch(i)                                //调用对应的函数 
            {   case 1:Insert(&Head);
                     break;
                case 2: Search(Head);
                      break;
                case 3: Update(Head);
                      break;
                case 4: Delete(&Head);
                      break;
                case 5: Show(Head);
                      break;
                case 6: break;
                default:printf("错误选择！请重选");break;
           }
        } while (i!=6);
      return 0;
}

    void Insert(Pointer *Head)                        //插入函数的定义 
    {   int in_number;
        Pointer p,q,r;                               //说明变量 
        printf("请输入编号：");
        scanf("%d",&in_number);
        p=q=*Head;                               //查找符合条件的记录 
        while (p!=NULL)
        {   if (p->number== in_number)              //找到相同的编号 
            {   printf("已经有相同的编号：");return;}
            else
            {  q=p;p=p->next;}                    //走链 
        }
        r=(Pointer)malloc(sizeof(GuestLink));          //申请空间 
        r->next=NULL;                            //设置指针域 
        if (r==NULL)
        {    printf("分配空间失败！");return;}
        if(q==NULL)                             //原表为空表 
            *Head=r;                            //新结点作为头元素 
        else
        {   q->next=r;                          //在表尾插入元素 
        }
        r->number= in_number;                   //接收插入数据 
        printf("请输入姓名：");
        scanf("%s", r->name);
        printf("请输入人数：");
        scanf("%d",&r->sum);
        printf("请输入用餐时间：");
        scanf("%s", r->time);
}

    void Search(Pointer Head)                  //查找函数的定义 
    {   int flag=1;                           //设定标记变量的初值 
        int number;
        Pointer p;
        printf("请输入要查询的编号：");
        scanf("%d",&number);
        p=Head;                            //查找符合条件的记录 
        while (p!=NULL&&flag)
        {   if (p->number== number)   
            {   printf("姓名：%s",p->name);
                printf("人数：%d",p->sum);
                printf("用餐时间：%s",p->time);
                flag=0;                    //找到标记变量设为0 
            }
            else 
                p=p->next;                 //指针走到下一个结点 
        }
        if (flag)
            printf("没有查询到！！");
}

    void Update(Pointer Head)                //修改函数的定义 
    {   int flag=1;                         //设定标记变量的初值 
        int number;
        Pointer p;
        printf("请输入要修改的编号：");
        scanf("%d",&number);
        p=Head;                            //查找符合条件的记录 
        while (p!=NULL&&flag)
        {   if (p->number== number)   
            {   
                printf("请输入人数：");
                scanf("%d", p->sum);
                printf("请输入用餐时间：");
                scanf("%s", p->time);
                flag=0;
            }
            else 
                p=p->next;                   //指针走到下一个结点 
        }
        if (flag)
            printf("没有找到要修改的记录！！");
}

    void Delete(Pointer *Head)                  //删除函数的定义 
    {   int flag=1;
        int number;
        Pointer p,q;
        printf("请输入要删除数据的编号：");
        scanf("%d",&number);
        p=q=*Head;                         //查找符合条件的记录 
        while (p!=NULL&&flag)
        {   if (p->number== number)   
            {   
            if (p==*Head)                   //删除的是表头元素 
            {   *Head=p->next; free(p);}
                else
                {   q->next=p->next; free(p);}     //删除普通元素 
                flag=0;
            }
            else 
            {   q=p; p=p->next;}       //指针走到下一个结点，
                                   // q所指结点为p所指结点的前驱 
        }
        if (flag)
            printf("没有找到可以删除的数据！！");
}

    void Show(Pointer Head)                //列表显示数据 
    {   Pointer p;
        p=Head;
        while (p!=NULL)
        {   printf("姓名：%-10s",p->name);
            printf("人数：%-10d",p->sum);
            printf("用餐时间：%-10s",p->time);
            printf("编号：%-10d\n",p->number);
            p=p->next;
        }
    }
