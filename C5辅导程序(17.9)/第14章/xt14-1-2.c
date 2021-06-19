    #include "stdio.h"
    #include "process.h"
    #define SIZE 9
    typedef struct tax_st                         //˰�ʱ�ṹ������ 
      {long left;                                   //�������� 
       long right;                                  //�������� 
       int tax;                                    //˰�� 
       long deduct;                               //����۳��� 
    } TAX_LIST;

    void disp(TAX_LIST tax_list[])
      {double salary,s,tax,ff;                          //������� 
        int i;
        printf("������˰ǰ�۳�����");           //��ʾ�û�˰ǰ�۳��� 
        scanf("%lf",&ff);
        printf("�����������룺");                //��ʾ�û������� 
        scanf("%lf",&salary);                         //�����û������������ 
        if (salary>=0)                               //���������0����ʼ���� 
          { s=salary-ff;                            //����ȫ��Ӧ��˰���ö� 
            if (s<=0)
                tax=0;                            //С��0��˰��Ϊ0 
            else
              {for(i=0;i<8;i++)                   //�����������ݼ���˰�� 
                  {if (s<tax_list[i].right&&s>=tax_list[i].left)
                      tax=s*tax_list[i].tax/100.-tax_list[i].deduct;
                  }
               if (s>=tax_list[8].left)
                   tax=s*tax_list[8].tax/100.-tax_list[8].deduct;
              }
          }
        printf("Ӧ�ɸ�������˰����%.2lf\n ",tax);
    }

    int main()
      { FILE *fp;                                      //�����ļ�ָ�� 
        TAX_LIST tax_list [SIZE];                      //����ṹ������ 
        if ((fp=fopen("d:\\TAX.din","rb"))==NULL)      //����ļ�TAX.din                                          
          {printf("\ncannot open file\n");    
		   exit(1);                                    //���ļ�ʧ�ܣ��˳� 
          }
        if (fread(tax_list,sizeof(TAX_LIST),SIZE,fp)!=SIZE)              //��SIZE���ṹ��һ�ζ��������� 
          {printf("file write error\n");
           exit(1);                        //������ʧ�ܣ��˳� 
          }
        disp(tax_list);                      //����˰�� 
        fclose(fp) ;                         //�ر��ļ� 
        return 0;
     }
