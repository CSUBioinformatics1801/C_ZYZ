    #include "stdio.h"
    #include "string.h"
    #define MaxSize 20
    struct guest_info {  
        char name[8];                    //姓名 
        int  sum;                       //人数 
        char time[10];                   //用餐时间 
        int number;                     //编号 
    } GuestList[MaxSize];
    void Insert(int *);
    void Search(int );
    void Update(int);
    void Delete(int *);
    void Show(int);

    int main()
    {
        int i;                   
        int count=0;                  // count为计数器，记录已经登记记录个数 
        do                                          //显示一个简易菜单 
        {   printf ("\n");
            printf ("1---插入(Insert)\n");
            printf ("2---查询(Search)\n");
            printf ("3---修改(Update)\n");
            printf ("4---删除(Delete)\n");
            printf ("5---显示(Show)\n");
            printf ("6---退出(Exit)\n");
            scanf ("%d",&i);                          //接收用户的选择 
            switch(i)
            {   case 1:Insert(&count);                 //调用插入运算 
                     break;
                case 2: Search(count);                //调用查询运算 
                      break;
                case 3: Update(count);               //调用修改运算 
                      break;
                case 4: Delete(&count);              //调用删除运算 
                      break;
                case 5: Show(count);                //调用显示运算 
                      break;
                case 6: break;
                default:printf("错误选择！请重选");break;
           }
        } while (i!=6);
        return 0;
}

    void Insert(int *count)
    {   int i, in_number;
        if (*count==MaxSize)
        {   printf("空间已满！");return;}
        printf("请输入编号：");
        scanf("%d",&in_number);
        for (i=0;i<*count;i++)                          //查找符合条件的记录 
           if  (GuestList[i].number==in_number)
           {   printf("已经有相同的编号：");return;}
        GuestList[i].number= in_number;                //接收插入数据 
        printf("请输入姓名:");
        scanf("%s",GuestList[i].name);
        printf("请输入人数：");
        scanf("%d",&GuestList[i].sum);
        printf("请输入用餐时间：");
        scanf("%s",GuestList[i].time);
        (*count)++;
     }

    void Search(int count)
    {   int i,number,flag=1;                          //设置一个标记变量 
        printf("请输入要查询的编号：");
        scanf("%d",&number);
        for (i=0;i<count&&flag;i++)
           if  (GuestList[i].number==number)          //检索到则输出 
           {   printf("姓名：%s",GuestList[i].name);
               printf("人数：%d",GuestList[i].sum);
               printf("用餐时间：%s",GuestList[i].time);
               flag=0;                               //标记变量值变反 
           }
           else
              printf("没有查询到！！");
}

    void Update(int count)
    {   int i,number, flag=1;                       //设置一个标记变量 
        printf("请输入要修改数据的编号：");
        scanf("%d",&number);
        for (i=0;i<count&&flag;i++)
           if  (GuestList[i].number==number)      //检索到则修改 
           {
               printf("请输入人数：");
               scanf("%d",&GuestList[i].sum);
               printf("请输入用餐时间：");
               scanf("%s",GuestList[i].time);
               flag=0;                         //标记变量值变反 
           }
           else
               printf("没有查询到可以修改的数据！！");
}

    void Delete(int *count)
    {   int i,j,number,flag=1;                     //设置一个标记变量 
        printf("请输入要删除数据的编号：");
        scanf("%d",&number);
        for (i=0;i<*count&&flag;i++)
        {   if  (GuestList[i].number==number)
           {   for (j=i;j<*count-1;j++)
                  GuestList[j]=GuestList[j+1];
                  flag=0;                      //标记变量值变反 
                  (*count)--;
           }
           else
               printf("没有查询到可以删除的数据！！");
        }
}

    void Show(int count)                //列表显示数据 
    {   int i;
        printf("\n");
        printf("     编号       姓名        人数       用餐时间\n");
        for (i=0;i<count;i++)
        {    printf("%10d",GuestList[i].number);     //显示编号             
             printf("%12s",GuestList[i].name);       //显示姓名  
             printf("%10d",GuestList[i].sum);        //显示人数  
             printf("%12s\n",GuestList[i].time); //显示用餐时间   
        }
    }
