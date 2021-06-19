
    #include "stdio.h"
    #include "string.h"
    #include "conio.h"
    #include "math.h"
    #define SIZE 300
    typedef struct student                           //ѧ�����ݽṹ������
    {   int number;                                  //ѧ�� 
        int score[3];                                //ƽʱ����ĩ�������ɼ� 
    } STUDENT;
    typedef enum boolen                              //ö�ٶ��� 
    {   False,True
    } FLAG;
    int accept_data(STUDENT stu[],int grade[]);        //�������ݺ������� 
    void show_data(STUDENT stu[],int sum,int grade[]); //�������ѧ������š�ƽʱ�ɼ���
                 //��ĩ�ɼ��������ɼ�����˵�� 
    void draw(int grade[]);                          //��ֱ��ͼ�������� 
    void count(int *max,int *min,double *pass,double ave[],double f[],STUDENT stu[],int sum);
    void show_data2(int max,int min,double pass,double ave[],double f[]);   //��ʾ��ĩ���Գɼ��ļ����ʡ���߷֡���ͷ��Լ�ƽʱ����ĩ�������ɼ���ƽ���ֺͱ�׼���˵�� 

    int main()
    {   int sum,max,min;                 //���ݶ��� 
        double pass=0;
        int grade[11]={0};
        STUDENT stu[SIZE];
        double ave[SIZE],f[SIZE];
        sum=accept_data(stu,grade);      //��������(sumΪ������)  
        show_data(stu,sum,grade);        //�������ѧ������š�ƽʱ�ɼ�����ĩ�ɼ��������ɼ� 
        draw(grade);                     //��ģ��ֱ��ͼ 
        count(&max,&min,&pass,ave,f,stu,sum); //������ĩ���Գɼ��ļ�������߷֡���ͷ��Լ�ƽʱ����ĩ�������ɼ���ƽ���ֺͱ�׼�� 
        show_data2(max,min,pass,ave,f);       //��ʾ��ĩ���Գɼ�����߷֡���ͷ��Լ�ƽʱ����ĩ�������ɼ���ƽ���ֺͱ�׼�� 
       return 0;
}

    int accept_data(STUDENT stu[],int grade[])
     {  int i=0,sum=0,temp,a1,a2;
        FLAG flag;
        printf("\n��������������ɼ�ʱʹ��ƽʱ�ɼ�����ĩ�ɼ��ı���,��������ʾ");
        scanf("%d%d",&a1,&a2);                //���ռ��������ɼ��ı��� 
        while (i<SIZE)
        {
            printf("\n������ѧ��:");
            scanf("%d",&stu[i].number);         //����ѧ�� 
            if  (stu[i].number==-1)             //�����-1������ѭ�� 
              { sum=i;                         //sum��¼������������� 
                break;
              }
            printf("\n������ѧ����ƽʱ�ɼ�����ĩ�ɼ�:");
            flag=True;
            while (flag==True)            //�ظ����������ɼ���������ȷ��Ϊֹ 
              {scanf("%d%d",&stu[i].score[0], &stu[i].score[1]);
               if (stu[i].score[0]<=100&& stu[i].score[0]>=0&&\stu[i].score[1]<=100&& stu[i].score[1]>=0)
                 flag=False;         //����������ɼ����� 
               else
                 printf("\n\007��������! ���ٴ�����ѧ����ƽʱ�ɼ�����ĩ�ɼ�:");     //����������ɼ������� 
              }
            temp=(int)(1.0*a1/100*stu[i].score[0]+1.0*a2/100* stu[i].score[1        //���������ɼ� 
            stu[i].score[2]=temp;         //�����ɼ��������� 
            temp=(stu[i].score[1])/10;    //��������� 
            if (temp==10)                //�����δ������� 
                grade[10]++;             //100�ִ�������Ԫ��grade[10] 
            else
                grade[temp+1]++;     //90~99�ִ�������Ԫ��grade[9]��80~89�ִ�������Ԫ��grade[8]��70~79�ִ�������Ԫ��grade[7]���������� 
            i++;
        }
        return sum;                   //�������� 
}

    void show_data(STUDENT stu[],int sum,int grade[])
      {
        int i,j;
        for (i=0;i<sum;i++)         //�������ѧ�š�ƽʱ����ĩ�������ɼ� 
          { printf("%4d",stu[i].number);   //�������ѧ�� 
            for (j=0;j<3;j++)             //��������ɼ� 
            printf("%4d ", stu[i].score[j]);
            printf("\n");
          }
        for (i=1;i<=10;i++)                  //��������ķֲ���� 
            printf(" %d ",grade[i]);
      }

    void count(int *max,int *min,double *pass,double ave[],double f[],STUDENT stu[],int sum)
     {  int i,j, p_sum=0;
        int total[3];
        double temp;
        *max=*min=stu[0].score[1];            //�����ɼ�����߷֡���ͷֳ�ֵ 
        if (stu[0].score[1]>=60)
            p_sum++;
        for (i=1;i<sum;i++)
        {   if  ((stu[i].score[1])>*max)         //��������߷֣����串�� 
                *max=stu[i].score[1];
            if  ((stu[i].score[1])<*min)         //��������ͷ֣����串�� 
               *min=stu[i].score[1];
            if (stu[i].score[1]>=60)
                p_sum++;                   //���㼰������� 
        }
        *pass=(1.0*p_sum/sum)*100;          //���㼰���� 
        for (i=0;i<=2;i++)                    //ƽʱ����ĩ�������ĳ�ֵ����Ϊ0 
            total[i]=0;
        for (j=0;j<3;j++)                     //��ƽʱ����ĩ�����������ܷ� 
            for (i=0;i<sum;i++)
             {
               total[j]=total[j]+stu[i].score[j];
             }
        for (j=0;j<3;j++)                 //��ƽʱ����ĩ����������ƽ���� 
         { ave[j]=total[j]/sum;         
         }
        for (j=0;j<3;j++)                 //��ƽʱ����ĩ��������׼�� 
         { f[j]=0;                     //��׼���ֵ����Ϊ0     
           for (i=0;i<sum;i++)          //�����׼��   
            {
              temp=stu[i].score[j]-ave[j];
              f[j]=f[j]+temp*temp;
            }
           f[j]=sqrt(fabs(f[j])/sum);
        }
     }

    void show_data2(int max,int min, double pass,double ave[],double f[])
            //�����ĩ�����ʡ���߷֡���ͷ��Լ�ƽʱ����ĩ��������ƽ���ֺͱ�׼�� 
    {   int j;
        char str1[3][20]={"ƽʱ�ɼ�ƽ����","��ĩ�ɼ�ƽ����","�����ɼ�ƽ����"};
        char str2[3][20]={" ƽʱ�ɼ���׼��","��ĩ�ɼ���׼��","�����ɼ���׼��"};
        printf("\n ������=%6.2f %%  ��߷�= %d  ��ͷ� =%d\n",pass, max,min); 
                //�����ĩ�����ʡ���߷֡���ͷ� 
        for (j=0;j<3;j++)
             //ѭ�����ηֱ����ƽʱ����ĩ��������ƽ���ֺͱ�׼�� 
            printf("\n %s = %6.2f %s =%6.2f\n",str1[j],ave[j],str2[j],f[j]);
}

    void draw(int grade[])              //���ģ��ֱ��ͼ 
    {   int i, j,max,k,temp,x;
        char screen[22][44];      //����һ���ַ������飬������ʾ��Ļ����� 
        printf("\nģ��ֱ��ͼ\n");
        max=0;
        for (i=1;i<=10;i++)            //Ѱ�ҷ��������������� 
           if (grade[i]>max)
               max=grade[i];
        for (i=1;i<=10;i++)
        {   grade[i]=(int)(20.0*grade[i]/max+0.5);     //������ʾʱӦ�������*�ŵĸ��� 
        }
        for (i=0;i<=21;i++)                       //�Ƚ���������е����� 
            for(j=0;j<=41;j++)
                screen[i][j]=0;
        //��x��                                
        for( i = 0; i <=41; i++)                     //x������е�����Ϊ����- 
            screen[21][i] = '-';
        screen[21][41] = 'X';                      //��ʾX���� 
        //��y�� 
        screen[0][0] = 'Y';                        //��ʾY���� 
        for( i = 1; i <=21; i++)                    //y������е�����Ϊ����|  
            screen[i][0] = '|';
        //�����������ĵ�(x,y)��ֵΪ�Ǻ� 
        k=1;
        for (x=1;x<=10;x++,k=k+4)               //x����������У�k����������� 
        {   temp=grade[x];                     // tempȡ������ֵ 
            if (temp!=0)                       
                for (i=1;i<=temp;i++)            //������Ϊ0����ֵΪ�Ǻ� 
                {
                   for(j=1;j<=4;j++)            //�÷����ε�ÿ�ж�Ӧ4���Ǻ� 
                   {    screen[20-i+1][j+k]='*';
                   }
                }
        }
        //������飬����Ļ�ϻ�ͼ 
        for( i = 0; i <=21; i++)
        {   for( j = 0; j <=41; j++)
                if (screen[i][j]!=0)              //�������ݲ�Ϊ0����������е����� 
                    printf("%c",screen[i][j]);
                else
                    printf(" ");                //��������ո� 
            printf("\n");
        }
        printf("  0  10  20  30  40  50  60  70  80  90  100\n");   //��������� 
        getch();
    }
