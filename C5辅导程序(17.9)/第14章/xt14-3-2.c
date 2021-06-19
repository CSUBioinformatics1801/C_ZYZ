#include "stdio.h"
    #include "string.h"
    #include "stdlib.h"
    #define MaxSize 20
    typedef struct guest_info
    {
        char name[8];                    //���� 
        int  sum;                       //���� 
        char time[10];                   //�ò�ʱ�� 
        int number;                     //��� 
        struct guest_info *next;
    } GuestLink,*Pointer;
    void Insert(Pointer *Head);            //�������� 
    void Search(Pointer Head);
    void Update(Pointer Head);
    void Delete(Pointer *Head);
    void Show(Pointer Head);

    int main()
    {
        Pointer Head=NULL;                          //�����ͷָ�� 
        int i;                     
        do                                          //��ʾһ�����ײ˵� 
        {   printf ("\n");
            printf ("1---����(Insert)\n");
            printf ("2---��ѯ(Search)\n");
            printf ("3---�޸�(Update)\n");
            printf ("4---ɾ��(Delete)\n");
            printf ("5---��ʾ(Show)\n");
            printf ("6---�˳�(Exit)\n");
            scanf ("%d",&i);                          //�����û���ѡ�� 
            switch(i)                                //���ö�Ӧ�ĺ��� 
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
                default:printf("����ѡ������ѡ");break;
           }
        } while (i!=6);
      return 0;
}

    void Insert(Pointer *Head)                        //���뺯���Ķ��� 
    {   int in_number;
        Pointer p,q,r;                               //˵������ 
        printf("�������ţ�");
        scanf("%d",&in_number);
        p=q=*Head;                               //���ҷ��������ļ�¼ 
        while (p!=NULL)
        {   if (p->number== in_number)              //�ҵ���ͬ�ı�� 
            {   printf("�Ѿ�����ͬ�ı�ţ�");return;}
            else
            {  q=p;p=p->next;}                    //���� 
        }
        r=(Pointer)malloc(sizeof(GuestLink));          //����ռ� 
        r->next=NULL;                            //����ָ���� 
        if (r==NULL)
        {    printf("����ռ�ʧ�ܣ�");return;}
        if(q==NULL)                             //ԭ��Ϊ�ձ� 
            *Head=r;                            //�½����ΪͷԪ�� 
        else
        {   q->next=r;                          //�ڱ�β����Ԫ�� 
        }
        r->number= in_number;                   //���ղ������� 
        printf("������������");
        scanf("%s", r->name);
        printf("������������");
        scanf("%d",&r->sum);
        printf("�������ò�ʱ�䣺");
        scanf("%s", r->time);
}

    void Search(Pointer Head)                  //���Һ����Ķ��� 
    {   int flag=1;                           //�趨��Ǳ����ĳ�ֵ 
        int number;
        Pointer p;
        printf("������Ҫ��ѯ�ı�ţ�");
        scanf("%d",&number);
        p=Head;                            //���ҷ��������ļ�¼ 
        while (p!=NULL&&flag)
        {   if (p->number== number)   
            {   printf("������%s",p->name);
                printf("������%d",p->sum);
                printf("�ò�ʱ�䣺%s",p->time);
                flag=0;                    //�ҵ���Ǳ�����Ϊ0 
            }
            else 
                p=p->next;                 //ָ���ߵ���һ����� 
        }
        if (flag)
            printf("û�в�ѯ������");
}

    void Update(Pointer Head)                //�޸ĺ����Ķ��� 
    {   int flag=1;                         //�趨��Ǳ����ĳ�ֵ 
        int number;
        Pointer p;
        printf("������Ҫ�޸ĵı�ţ�");
        scanf("%d",&number);
        p=Head;                            //���ҷ��������ļ�¼ 
        while (p!=NULL&&flag)
        {   if (p->number== number)   
            {   
                printf("������������");
                scanf("%d", p->sum);
                printf("�������ò�ʱ�䣺");
                scanf("%s", p->time);
                flag=0;
            }
            else 
                p=p->next;                   //ָ���ߵ���һ����� 
        }
        if (flag)
            printf("û���ҵ�Ҫ�޸ĵļ�¼����");
}

    void Delete(Pointer *Head)                  //ɾ�������Ķ��� 
    {   int flag=1;
        int number;
        Pointer p,q;
        printf("������Ҫɾ�����ݵı�ţ�");
        scanf("%d",&number);
        p=q=*Head;                         //���ҷ��������ļ�¼ 
        while (p!=NULL&&flag)
        {   if (p->number== number)   
            {   
            if (p==*Head)                   //ɾ�����Ǳ�ͷԪ�� 
            {   *Head=p->next; free(p);}
                else
                {   q->next=p->next; free(p);}     //ɾ����ͨԪ�� 
                flag=0;
            }
            else 
            {   q=p; p=p->next;}       //ָ���ߵ���һ����㣬
                                   // q��ָ���Ϊp��ָ����ǰ�� 
        }
        if (flag)
            printf("û���ҵ�����ɾ�������ݣ���");
}

    void Show(Pointer Head)                //�б���ʾ���� 
    {   Pointer p;
        p=Head;
        while (p!=NULL)
        {   printf("������%-10s",p->name);
            printf("������%-10d",p->sum);
            printf("�ò�ʱ�䣺%-10s",p->time);
            printf("��ţ�%-10d\n",p->number);
            p=p->next;
        }
    }
