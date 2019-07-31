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
    printf("请选择你需要的操作：0-退出，1-插入，2-取值，3-删除，4-创建顺序表\n");
	     scanf("%d",&k);
         return k;
}
int Create_sq(sqList &L)
{
	int n,j;
	printf("请输入元素个数：");
     scanf("%d",&n);
	 L.length=n;
	 printf("请输入元素：");
	 for(j=0;j<L.length;j++)
	 { scanf("%d",&L.a[j]);
	 }
	 printf("创建成功!\n");
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
	                          printf("请输入要插入的位置和元素：");
		                      scanf("%d",&j);
							  scanf("%d",&e);
	                           if(Listinsert_sq(L,j,e))
							   {
		                           printf("新的顺序表：");
			                       Display_sq(L);
							   }
	                           else
		                           printf("无法插入：");
                             break;
                          case 2:
	                           printf("请输入所获取元素的位置：");
	                           scanf("%d",&j);
	                           printf("获取的元素为：%d", Get_sq(L,j,e));
                	         break;
			              case 3:
                	           printf("请输入要删除的位置：");
	                           scanf("%d",&j);
	                           if(ListDelete_sq(L,j,e))
							   {
	                	          printf("新的顺序表为：");
		                          Display_sq(L);
							   }
	                           else
	                	           printf("无法删除：");
                              break;
						  case 4:
							     IniList_sq(L); 
							     Create_sq(L);
								 printf("顺序表为：");
								 Display_sq(L);
							 break;
                          default:
                	              printf("输入有误，请重新输入!\n");
					         break; 
			}
								  
								  
								 	
		}
}
