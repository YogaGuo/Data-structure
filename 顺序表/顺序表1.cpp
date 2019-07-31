#include<stdio.h>
#include<stdlib.h>
#define List_Init_size  100
#define List_Increment   10
typedef struct{
	int *a;
	int length;
	int listsize;}sqList;
int IniList_sq(sqList &L)
{
	L.a=(int*)malloc(List_Init_size*sizeof(int));
	if(!L.a)  exit(0);
	L.length=0;
	L.listsize=List_Init_size;
	return 1;
}
int Listinsert_sq(sqList &L,int i,int &e)
{
	int *q,*p;
	if(i<1||i>L.length+1) return 0;
	if(L.length>=L.listsize)
	{
		
		int* newbase=(int*)realloc(L.a,(L.listsize+List_Increment)*sizeof(int));
		if(newbase==NULL) exit(0);
		L.a=newbase;
		L.listsize=L.listsize+List_Increment;
	}
	   q=&L.a[i-1];
	   p=&(L.a[L.length-1]);
         for(p;p>=q;--p) 
		      *(p+1)=*p;
	            *q=e;
	             ++L.length;
	              return 1;
}
int ListDelete_sq(sqList &L,int i,int &e)
{
	int *q,*p;
	if(i<1 || i>L.length) return 0;
	p=&L.a[i-1];
	e=*p;
	q=L.a+L.length-1;
	for(++p;p<=q;p++) *(p-1)=*p;
	--L.length;
	return 1;
}
int Get_sq(sqList &L,int i,int &e)
{
	if(i<1 || i>L.length) return 0;
	e=L.a[i-1];
	return e;
}
void Display_sq(sqList &L)
{  int i;
	for(i=0;i<L.length;i++)
		printf("%d\t",L.a[i]);
}
int OperateMenu()
{   int k;
    printf("��ѡ������Ҫ�Ĳ�����0-�˳���1-���룬2-ȡֵ��3-ɾ����4-����˳���\n");
	     scanf("%d",&k);
         return k;
}
int Create_sq(sqList &L)
{
	int n,j;
	printf("������Ԫ�ظ�����");
     scanf("%d",&n);
	 L.length=n;
	 printf("������Ԫ�أ�");
	 for(j=0;j<L.length;j++)
	 { scanf("%d",&L.a[j]);
	 }
	 printf("�����ɹ�!\n");
	return 0;
}
void main()
{
		int j,e,n;
		int data1=0;
		sqList L;
	 
        while(1)
		{
			  data1=OperateMenu();
	        switch(data1)
			{
                         case 0:
                                exit(0);
	                        break;
                         case 1:
	                          printf("������Ҫ�����λ�ú�Ԫ�أ�");
		                      scanf("%d",&j);
							  scanf("%d",&e);
	                           if(Listinsert_sq(L,j,e))
							   {
		                           printf("�µ�˳���");
			                       Display_sq(L);
							   }
	                           else
		                           printf("�޷����룺");
                             break;
                          case 2:
	                           printf("����������ȡԪ�ص�λ�ã�");
	                           scanf("%d",&j);
	                           printf("��ȡ��Ԫ��Ϊ��%d", Get_sq(L,j,e));
                	         break;
			              case 3:
                	           printf("������Ҫɾ����λ�ã�");
	                           scanf("%d",&j);
	                           if(ListDelete_sq(L,j,e))
							   {
	                	          printf("�µ�˳���Ϊ��");
		                          Display_sq(L);
							   }
	                           else
	                	           printf("�޷�ɾ����");
                              break;
						  case 4:
							     IniList_sq(L); 
							     Create_sq(L);
								 printf("˳���Ϊ��");
								 Display_sq(L);
							 break;
                          default:
                	              printf("������������������!\n");
					         break; 
			}
								  
								  
								 	
		}
}
