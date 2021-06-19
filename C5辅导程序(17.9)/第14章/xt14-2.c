
    #include "stdio.h"
    #include "string.h"
    #include "conio.h"
    #include "math.h"
    #define SIZE 300
    typedef struct student                           //学生数据结构体声明
    {   int number;                                  //学号 
        int score[3];                                //平时、期末和总评成绩 
    } STUDENT;
    typedef enum boolen                              //枚举定义 
    {   False,True
    } FLAG;
    int accept_data(STUDENT stu[],int grade[]);        //输入数据函数声明 
    void show_data(STUDENT stu[],int sum,int grade[]); //输出所有学生的序号、平时成绩、
                 //期末成绩和总评成绩函数说明 
    void draw(int grade[]);                          //画直方图函数声明 
    void count(int *max,int *min,double *pass,double ave[],double f[],STUDENT stu[],int sum);
    void show_data2(int max,int min,double pass,double ave[],double f[]);   //显示期末考试成绩的及格率、最高分、最低分以及平时、期末和总评成绩的平均分和标准差函数说明 

    int main()
    {   int sum,max,min;                 //数据定义 
        double pass=0;
        int grade[11]={0};
        STUDENT stu[SIZE];
        double ave[SIZE],f[SIZE];
        sum=accept_data(stu,grade);      //输入数据(sum为总人数)  
        show_data(stu,sum,grade);        //输出所有学生的序号、平时成绩、期末成绩和总评成绩 
        draw(grade);                     //画模拟直方图 
        count(&max,&min,&pass,ave,f,stu,sum); //计算期末考试成绩的及格率最高分、最低分以及平时、期末和总评成绩的平均分和标准差 
        show_data2(max,min,pass,ave,f);       //显示期末考试成绩的最高分、最低分以及平时、期末和总评成绩的平均分和标准差 
       return 0;
}

    int accept_data(STUDENT stu[],int grade[])
     {  int i=0,sum=0,temp,a1,a2;
        FLAG flag;
        printf("\n请输入计算总评成绩时使用平时成绩与期末成绩的比例,用整数表示");
        scanf("%d%d",&a1,&a2);                //接收计算总评成绩的比例 
        while (i<SIZE)
        {
            printf("\n请输入学号:");
            scanf("%d",&stu[i].number);         //输入学号 
            if  (stu[i].number==-1)             //序号是-1则跳出循环 
              { sum=i;                         //sum记录的是输入的人数 
                break;
              }
            printf("\n请输入学生的平时成绩和期末成绩:");
            flag=True;
            while (flag==True)            //重复读入两个成绩，读到正确的为止 
              {scanf("%d%d",&stu[i].score[0], &stu[i].score[1]);
               if (stu[i].score[0]<=100&& stu[i].score[0]>=0&&\stu[i].score[1]<=100&& stu[i].score[1]>=0)
                 flag=False;         //输入的两个成绩合理 
               else
                 printf("\n\007错误数据! 请再次输入学生的平时成绩和期末成绩:");     //输入的两个成绩不合理 
              }
            temp=(int)(1.0*a1/100*stu[i].score[0]+1.0*a2/100* stu[i].score[1        //计算总评成绩 
            stu[i].score[2]=temp;         //总评成绩存入数组 
            temp=(stu[i].score[1])/10;    //计算分数段 
            if (temp==10)                //分数段存入数组 
                grade[10]++;             //100分存入数组元素grade[10] 
            else
                grade[temp+1]++;     //90~99分存入数组元素grade[9]，80~89分存入数组元素grade[8]，70~79分存入数组元素grade[7]，依次类推 
            i++;
        }
        return sum;                   //返回人数 
}

    void show_data(STUDENT stu[],int sum,int grade[])
      {
        int i,j;
        for (i=0;i<sum;i++)         //输出所有学号、平时、期末和总评成绩 
          { printf("%4d",stu[i].number);   //输出所有学号 
            for (j=0;j<3;j++)             //输出三个成绩 
            printf("%4d ", stu[i].score[j]);
            printf("\n");
          }
        for (i=1;i<=10;i++)                  //输出分数的分布情况 
            printf(" %d ",grade[i]);
      }

    void count(int *max,int *min,double *pass,double ave[],double f[],STUDENT stu[],int sum)
     {  int i,j, p_sum=0;
        int total[3];
        double temp;
        *max=*min=stu[0].score[1];            //设卷面成绩的最高分、最低分初值 
        if (stu[0].score[1]>=60)
            p_sum++;
        for (i=1;i<sum;i++)
        {   if  ((stu[i].score[1])>*max)         //若高于最高分，将其覆盖 
                *max=stu[i].score[1];
            if  ((stu[i].score[1])<*min)         //若低于最低分，将其覆盖 
               *min=stu[i].score[1];
            if (stu[i].score[1]>=60)
                p_sum++;                   //计算及格的人数 
        }
        *pass=(1.0*p_sum/sum)*100;          //计算及格率 
        for (i=0;i<=2;i++)                    //平时、期末、总评的初值设置为0 
            total[i]=0;
        for (j=0;j<3;j++)                     //求平时、期末、总评三个总分 
            for (i=0;i<sum;i++)
             {
               total[j]=total[j]+stu[i].score[j];
             }
        for (j=0;j<3;j++)                 //求平时、期末、总评三个平均分 
         { ave[j]=total[j]/sum;         
         }
        for (j=0;j<3;j++)                 //求平时、期末、总评标准差 
         { f[j]=0;                     //标准差初值设置为0     
           for (i=0;i<sum;i++)          //计算标准差   
            {
              temp=stu[i].score[j]-ave[j];
              f[j]=f[j]+temp*temp;
            }
           f[j]=sqrt(fabs(f[j])/sum);
        }
     }

    void show_data2(int max,int min, double pass,double ave[],double f[])
            //输出期末及格率、最高分、最低分以及平时、期末、总评的平均分和标准差 
    {   int j;
        char str1[3][20]={"平时成绩平均分","期末成绩平均分","总评成绩平均分"};
        char str2[3][20]={" 平时成绩标准差","期末成绩标准差","总评成绩标准差"};
        printf("\n 及格率=%6.2f %%  最高分= %d  最低分 =%d\n",pass, max,min); 
                //输出期末及格率、最高分、最低分 
        for (j=0;j<3;j++)
             //循环三次分别输出平时、期末、总评的平均分和标准差 
            printf("\n %s = %6.2f %s =%6.2f\n",str1[j],ave[j],str2[j],f[j]);
}

    void draw(int grade[])              //输出模拟直方图 
    {   int i, j,max,k,temp,x;
        char screen[22][44];      //定义一个字符型数组，用来表示屏幕的输出 
        printf("\n模拟直方图\n");
        max=0;
        for (i=1;i<=10;i++)            //寻找分数段中人数最多的 
           if (grade[i]>max)
               max=grade[i];
        for (i=1;i<=10;i++)
        {   grade[i]=(int)(20.0*grade[i]/max+0.5);     //计算显示时应该输出的*号的个数 
        }
        for (i=0;i<=21;i++)                       //先将输出的所有点清零 
            for(j=0;j<=41;j++)
                screen[i][j]=0;
        //画x轴                                
        for( i = 0; i <=41; i++)                     //x轴的所有点设置为符号- 
            screen[21][i] = '-';
        screen[21][41] = 'X';                      //显示X字样 
        //画y轴 
        screen[0][0] = 'Y';                        //显示Y字样 
        for( i = 1; i <=21; i++)                    //y轴的所有点设置为符号|  
            screen[i][0] = '|';
        //将符合条件的点(x,y)赋值为星号 
        k=1;
        for (x=1;x<=10;x++,k=k+4)               //x控制输出的行，k控制输出的列 
        {   temp=grade[x];                     // temp取分数的值 
            if (temp!=0)                       
                for (i=1;i<=temp;i++)            //分数不为0，赋值为星号 
                {
                   for(j=1;j<=4;j++)            //该分数段的每行对应4个星号 
                   {    screen[20-i+1][j+k]='*';
                   }
                }
        }
        //输出数组，在屏幕上画图 
        for( i = 0; i <=21; i++)
        {   for( j = 0; j <=41; j++)
                if (screen[i][j]!=0)              //数组内容不为0，输出数组中的内容 
                    printf("%c",screen[i][j]);
                else
                    printf(" ");                //否则输出空格 
            printf("\n");
        }
        printf("  0  10  20  30  40  50  60  70  80  90  100\n");   //输出分数段 
        getch();
    }
