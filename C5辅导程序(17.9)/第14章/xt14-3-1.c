    #include "stdio.h"
    #include "string.h"
    #define MaxSize 20
    struct guest_info {  
        char name[8];                    //���� 
        int  sum;                       //���� 
        char time[10];                   //�ò�ʱ�� 
        int number;                     //��� 
    } GuestList[MaxSize];
    void Insert(int *);
    void Search(int );
    void Update(int);
    void Delete(int *);
    void Show(int);

    int main()
    {
        int i;                   
        int count=0;                  // countΪ����������¼�Ѿ��ǼǼ�¼���� 
        do                                          //��ʾһ�����ײ˵� 
        {   printf ("\n");
            printf ("1---����(Insert)\n");
            printf ("2---��ѯ(Search)\n");
            printf ("3---�޸�(Update)\n");
            printf ("4---ɾ��(Delete)\n");
            printf ("5---��ʾ(Show)\n");
            printf ("6---�˳�(Exit)\n");
            scanf ("%d",&i);                          //�����û���ѡ�� 
            switch(i)
            {   case 1:Insert(&count);                 //���ò������� 
                     break;
                case 2: Search(count);                //���ò�ѯ���� 
                      break;
                case 3: Update(count);               //�����޸����� 
                      break;
                case 4: Delete(&count);              //����ɾ������ 
                      break;
                case 5: Show(count);                //������ʾ���� 
                      break;
                case 6: break;
                default:printf("����ѡ������ѡ");break;
           }
        } while (i!=6);
        return 0;
}

    void Insert(int *count)
    {   int i, in_number;
        if (*count==MaxSize)
        {   printf("�ռ�������");return;}
        printf("�������ţ�");
        scanf("%d",&in_number);
        for (i=0;i<*count;i++)                          //���ҷ��������ļ�¼ 
           if  (GuestList[i].number==in_number)
           {   printf("�Ѿ�����ͬ�ı�ţ�");return;}
        GuestList[i].number= in_number;                //���ղ������� 
        printf("����������:");
        scanf("%s",GuestList[i].name);
        printf("������������");
        scanf("%d",&GuestList[i].sum);
        printf("�������ò�ʱ�䣺");
        scanf("%s",GuestList[i].time);
        (*count)++;
     }

    void Search(int count)
    {   int i,number,flag=1;                          //����һ����Ǳ��� 
        printf("������Ҫ��ѯ�ı�ţ�");
        scanf("%d",&number);
        for (i=0;i<count&&flag;i++)
           if  (GuestList[i].number==number)          //����������� 
           {   printf("������%s",GuestList[i].name);
               printf("������%d",GuestList[i].sum);
               printf("�ò�ʱ�䣺%s",GuestList[i].time);
               flag=0;                               //��Ǳ���ֵ�䷴ 
           }
           else
              printf("û�в�ѯ������");
}

    void Update(int count)
    {   int i,number, flag=1;                       //����һ����Ǳ��� 
        printf("������Ҫ�޸����ݵı�ţ�");
        scanf("%d",&number);
        for (i=0;i<count&&flag;i++)
           if  (GuestList[i].number==number)      //���������޸� 
           {
               printf("������������");
               scanf("%d",&GuestList[i].sum);
               printf("�������ò�ʱ�䣺");
               scanf("%s",GuestList[i].time);
               flag=0;                         //��Ǳ���ֵ�䷴ 
           }
           else
               printf("û�в�ѯ�������޸ĵ����ݣ���");
}

    void Delete(int *count)
    {   int i,j,number,flag=1;                     //����һ����Ǳ��� 
        printf("������Ҫɾ�����ݵı�ţ�");
        scanf("%d",&number);
        for (i=0;i<*count&&flag;i++)
        {   if  (GuestList[i].number==number)
           {   for (j=i;j<*count-1;j++)
                  GuestList[j]=GuestList[j+1];
                  flag=0;                      //��Ǳ���ֵ�䷴ 
                  (*count)--;
           }
           else
               printf("û�в�ѯ������ɾ�������ݣ���");
        }
}

    void Show(int count)                //�б���ʾ���� 
    {   int i;
        printf("\n");
        printf("     ���       ����        ����       �ò�ʱ��\n");
        for (i=0;i<count;i++)
        {    printf("%10d",GuestList[i].number);     //��ʾ���             
             printf("%12s",GuestList[i].name);       //��ʾ����  
             printf("%10d",GuestList[i].sum);        //��ʾ����  
             printf("%12s\n",GuestList[i].time); //��ʾ�ò�ʱ��   
        }
    }
