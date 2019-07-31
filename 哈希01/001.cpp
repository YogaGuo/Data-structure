#include<stdio.h>                                                   //��stdio.h��������������
#include<stdlib.h>                                                  //��stdlib.h��������������,calloc()��Ҫstdlib.h�ļ� 
#include<string.h>                                                                                             
#define INFEASIBLE -1
#define OVERFLOW -2
#define HASHSIZE 30
#define MAXSIZE  20                                                                        //�绰����¼����
#define MAX_SIZE 20                                                                            //���������
typedef struct
{
    char name[11];
    char tel[11];
    char adr[11];
}Record;

typedef struct
{                                            
    Record *elem;                                                       //����Ԫ�ش洢��ַ
    int count;                                                                    //��ǰ����Ԫ�ظ���
    int size;                                                                     //��ǰ����
}HashTable;

int Hash1(char s[])
{
    int i,m;
    i=strlen(s);
    m=i % HASHSIZE;
	return m;
}  
int Collision(int p,int &c)
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
    return 0;

}
int InitHash(HashTable &H)
{
    H.elem=(Record *)malloc((HASHSIZE)*sizeof(Record));
	if(!H.elem)
	  exit(OVERFLOW);
    H.size=HASHSIZE;
    H.count=0;
    for(int i=0;i<HASHSIZE;i++)
	{
	  H.elem[i].name[0]='\0';
	}
	return 1;

}
int CreateHash(HashTable &H,Record  r,int  Number)
{
	  int n,c,p;
	  c=0;
	  n=Hash1(r.name);
	  if(H.elem[n].name[0]!='\0')
	  {
	    while(H.elem[n].name[0]!='\0')
        {
            p=Collision(n,c);
			if(H.elem[p].name[0]!='\0')
			{
				continue;
			}
			else
			{
				H.elem[p]=r;                      //���ɢ�е�ַ������Ϣ����
		        H.count++;
				break;
			}
		}
	  }
	  else
	  {
        H.elem[n]=r;                      //���ɢ�е�ַ������Ϣ����
		H.count++;
	  }

	return 1;
}
int SearchHash(HashTable H,int &c)
{
	int i=0,n,p;
	c=0;
	char s[11];
	printf("������Ҫ���ҵ�����\n");
	scanf("%s",&s);
	p=Hash1(s);
	n=p;
	while((H.elem[n].name[0]!='\0') && (strcmp(s, H.elem[n].name)!=1))
		 n=Collision(p,c);
	if((strcmp(s, H.elem[n].name)==1))
		 {
			 printf("���ҳɹ�!\n");
			 printf("�û���Ϣ����:\n");
			 printf("����:%s",H.elem[n].name);
			 printf("�绰����:%s",H.elem[n].tel);
			 printf("��ϵ��ַ:%s",H.elem[n].adr);
			 return 1;
		 }
		  else
			 return 0;
}
 

int DisPlay(HashTable H)                                                            //��ӡ��¼
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
	}
	return 1;
}
int OperateMenu()
{
	int i;
	printf("\n-----------��ӭʹ�ñ�����--------------------------\n");
	printf("(0)---��ʼ����ϣ��\n");
    printf("(1)---������ϣ��              (2)---��ӡ����û���Ϣ      \n");
	printf("(3)---�����û���Ϣ            (4)---�˳�����          \n");
    printf("����ѡ����Ҫ���еĲ���\n");
	printf("\n-------------------------------\n");
    scanf("%d",&i);
    return i;
}
void main()
{
	int c, k,x=0;
    HashTable H;
	int num;
	Record r;
    H.elem=NULL;
    while(1)
	 {
	   k=OperateMenu();
    	switch(k)
		{

	    	case 0:
			     if(InitHash(H)==1)
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
                     scanf("%d",&num);
	                 for(int i=0;i<num;i++)
					 {
		                printf("���������%d����Ϣ������:\n",i+1);
			            scanf("%s",r.name);
		                printf("���������%d����Ϣ�ĵ绰:\n",i+1);
			            scanf("%s",r.tel);
		                printf("���������%d����Ϣ�ĵ�ַ:\n",i+1);
			            scanf("%s",r.adr);
					 
				     if(CreateHash(H,r,num)==1)
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
                    if(DisPlay(H)==1)
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
				     if(SearchHash(H,c)==1)
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
		
	 
