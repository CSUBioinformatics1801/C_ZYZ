    #include "stdio.h"
    #include "process.h"
    #define SIZE 9
    typedef struct tax_st                            //˰�ʱ����ݽṹ���� 
      {long left;                                    //�������� 
        long right;                                  //�������� 
        int tax;                                     //˰�� 
        long deduct;                                 //����۳��� 
      }TAX_LIST;

    void acceptdata(TAX_LIST tax_list[])
    {   int i;
        for (i=0;i<SIZE;i++)                         //���ռ������������ 
        {   printf("Please enter data:");
            scanf("%ld", &tax_list[i].left);         //������������ 
            scanf("%ld", &tax_list[i].right);        //������������ 
            scanf("%d", &tax_list[i].tax);           //����˰�� 
            scanf("%ld", &tax_list[i].deduct);       //��������۳��� 
        }
    }

    int main()
    {
        FILE *fp;
        TAX_LIST tax_list [SIZE];
        if ((fp=fopen("d:\\TAX.din","wb"))==NULL)   //���ļ�TAX.din 
        {   printf("\ncannot open file\n");
            exit(1);                                //��ʧ���˳� 
        }
        acceptdata(tax_list);                      //���ú����Ӽ��̽������� 
        if (fwrite(tax_list,sizeof(TAX_LIST),SIZE,fp)!=SIZE)
                    //������tax_list�Ľṹ����һ��д���ļ� 
        printf("file write error\n");
        fclose(fp);                               //�ر��ļ� 
        return 0;
    }
