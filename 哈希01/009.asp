 
#include<stdio.h>                                                   //��stdio.h��������������
#include<stdlib.h>                                                  //��stdlib.h��������������,calloc()��Ҫstdlib.h�ļ� 
#include<string.h>                                                                                             
#define TRUE  1                                                   //�Ժ������״̬�������Ԥ����
#define FALSE 0
#define OK    1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define HASHSIZE 30
#define MAXSIZE  20                                                                        //�绰����¼����
#define MAX_SIZE 20                                                                            //��������󳤶�
typedef char NA[MAX_SIZE];
typedef int Status;

typedef struct
{
    NA name;
    NA tel;
    NA adr;
}Record;

typedef struct
{                                            
    Record *elem;                                                       //����Ԫ�ش洢��ַ
    int count;                                                                    //��ǰ����Ԫ�ظ���
    int size;                                                                     //��ǰ����
}HashTable;

int Hash1(NA s)
{
    int i,m;
    i=strlen(s);
    m=i % HASHSIZE;
	return m;
}  
Status ChongTu(int p,int &c)
{
	int i,q;
    i=c/2+1;
    while(i<HASHSIZE)
    {
        if(c%2==0)
        {
            c++;
            q=(p+i*i) % HASHSIZE;
				return q;
        }
        else
        { 
			c++;
            q=(p-i*i) % HASHSIZE;
				return q;
        }
    }
    return ERROR;

}
Status InitHash(HashTable &H)
{
    H.elem=(Record *)malloc((HASHSIZE)*sizeof(Record));
	if(!H.elem)
	  exit(OVERFLOW);
    H.size=HASHSIZE;
    H.count=0;
    for(int i=0;i<HASHSIZE;i++)
	{
	  H.elem[i].name[0]='\0';
	  H.elem[i].adr[0]='\0';
	  H.elem[i].tel[0]='\0';
	}
	return OK;

}
Status CreateHash(HashTable &H,Record  a,int  Number)
{
	  int n,c,p;
	  c=0;
	  n=Hash1(a.name);
	  if(H.elem[n].name[0]!='\0')
	  {
	    while(H.elem[n].name[0]!='\0')
        {
            p=ChongTu(n,c);
			if(H.elem[p].name[0]!='\0')
			{
				continue;
			}
			else
			{
				H.elem[p]=a;                      //���ɢ�е�ַ������Ϣ����
		        H.count++;
				break;
			}
		}
	  }
	  else
	  {
        H.elem[n]=a;                      //���ɢ�е�ַ������Ϣ����
		H.count++;
	  }

	return OK;
}
Status SearchHash(HashTable H,int &c)
{
	int i=0,n,p;
	c=0;
	NA	s;
	printf("������Ҫ���ҵ�����\n");
	scanf("%s",&s);
	p=Hash1(s);
	n=p;
	while((H.elem[n].name[0]!='\0') && (strcmp(s, H.elem[n].name)==1))
	{
		 n=ChongTu(p,c);
		 if((H.elem[n].name[0]!='\0') && (strcmp(s, H.elem[n].name)==0))
		 {
			 printf("���ҳɹ�!\n");
			 printf("�û���Ϣ����:\n");
			 printf("����:%s",H.elem[n].name);
			 printf("�绰����:%s",H.elem[n].tel);
			 printf("��ϵ��ַ:%s",H.elem[n].adr);
	 		 return OK;
		 }
	}
    if((H.elem[n].name[0]!='\0') && (strcmp(s, H.elem[n].name)==0))
	{
		printf("���ҳɹ�!\n");
	    printf("�û���Ϣ����:\n");
		printf("����:%s",H.elem[n].name);
		printf("�绰����:%s",H.elem[n].tel);
		printf("��ϵ��ַ:%s",H.elem[n].adr);
		return OK;
	}
	return ERROR;
}

Status DisPlay(HashTable H)                                                            //��ӡ��¼
{
	int i;
	for(i=0;i<HASHSIZE;i++)
	{
		if(H.elem[i].name[0]!='\0')
		{	
		printf("\n�ڹ�ϣ����λ��Ϊ:%d\t",i);
        printf("����:%s\t",H.elem[i].name);
        printf("�绰����:%s\t",H.elem[i].tel);
	    printf("��ϵ��ַ:%s\n",H.elem[i].adr);
	
		}
		else
			continue;
	}
	return OK;
}
Status OperateMenu()
{
	int i;
	printf("\n-----------��ӭʹ�ñ�����--------------------------\n");
	printf("(0)---��ʼ����ϣ��\n");
    printf("(1)---������ϣ��              (2)---��ӡ����û���Ϣ      \n");
	printf("(3)---�����û���Ϣ            (4)---�˳�����          \n");
    printf("����ѡ����Ҫ���еĲ���\n");
	printf("---------------------------------------------------\n");
   scanf("%d",&i);
   return i;
}
void main()
{
	int c, y,x=0;
    HashTable H;
	int Number;
	Record a;
    H.elem=NULL;
    while(1)
	 {
	   y=OperateMenu();
    	switch(y)
		{

	    	case 0:
			     if(InitHash(H)==OK)
					 printf("�ɹ�����\n");
				 else
                     printf("����ִ�д���\n");
			     break;
	    	case 1:
			     if(!H.elem)
			         printf("δ������ϣ��\n");
                 else
				 {
					 printf("��������Ҫ¼�����Ϣ��:\n");
                     scanf("%d",&Number);
	                 for(int i=0;i<Number;i++)
					 {
		                printf("���������%d����Ϣ������:\n",i+1);
			            scanf("%s",a.name);
		                printf("���������%d����Ϣ�ĵ绰:\n",i+1);
			            scanf("%s",a.tel);
		                printf("���������%d����Ϣ�ĵ�ַ:\n",i+1);
			            scanf("%s",a.adr);
					 
				     if(CreateHash(H,a,Number)==OK)
					     printf("�ɹ�����\n");
				     else
                         printf("����ִ�д���\n");
					 }
				 }
			     break;
	    	case 2:
		         if(!H.elem)
			             printf("δ������ϣ��\n");
			     else
				 {
                    if(DisPlay(H)==OK)
					     printf("��ӡ�ɹ�\n");
	                else
                         printf("����ִ�д���\n");
				 }
		         break;
	         case 3:
			     if(!H.elem)
			             printf("δ������ϣ��\n");
				 else
				 {
				     if(SearchHash(H,c)==OK)
					     printf("��ӡ���\n");
				     else
                         printf("����ʧ��!���˲�����\n");
				 }
			     break;
				 
	        case 4:
			     printf("ллʹ��!");
			     exit(0);
				 break;
	    	default:
			     printf("��������������\n");
			     break;
		}
	 }
}
		
	 
