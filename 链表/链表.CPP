#include<stdio.h>
#include<stdlib.h>
typedef struct Lnode{
	int data;
	struct Lnode *next;
}*LinkList;

void InitList_L(LinkList &L)
{
	L=(LinkList)malloc(sizeof(Lnode));
	L->next=NULL;
}
void Create_L(LinkList &L)
{
	  int i,e,n;
       Lnode *p,*q;
	   p=L;
	   printf("请输入链表结点个数：");
	   scanf("%d",&n);
	   printf("请输入链表元素：");
	   for(i=0;i<n;i++)
	   {
		   q=(LinkList)malloc(sizeof(Lnode));   //创建节点用指针q指向
		   scanf("%d",&e);
		   q->data=e;
		   p->next=q;
		   p=q;
	   }
	    p->next=NULL;
		printf("链表创建成功!");
		
 }
 int Get_L(LinkList L,int i,int &e)
 {
	 Lnode *p;
	 p=L->next;
    int j=0;
	 while(p&&j<i)
	 {
		 p=p->next;
		 ++j;
	 }
	 if(!p||j>i)
	    return 0;
	    e=p->data;
		return e;
 }
 int ListInsert_L(LinkList &L,int i,int e)
 {       
	 Lnode *p,*s;
	 p=L;
	 int j=0;
	 while(p&&j<i-1)
	 {
		 p=p->next;
		 ++j;
	 }
	 if(!p||j>i-1)
		 return 0;
     s=(LinkList)malloc(sizeof(Lnode));
	 s->data=e;
	 s->next=p->next;
	 p->next=s;
	 return 1;
 }
 int ListDelet_L(LinkList &L,int i,int &e)
 {
	 Lnode *p,*q;
	 p=L;
	 int j=0;
	 while(p->next&&j<i-1)
	 {
		 p=p->next;
		 ++j;
	 }
	 if(!(p->next)||j>i-1)
		 return 0;
	 q=p->next;
	 p->next=q->next;
	 e=q->data;
	 free(q);
	 return  1;
 }
 void Display_L(LinkList &L)
 {
   Lnode *p;
   p=L->next;
   printf("新的链表为：");
   while(p)
   {
	   printf("%d",p->data);
	   p=p->next;
   }
   printf("\n");
   
 }
 int Destroy_L(LinkList &L)
 {
	 Lnode *p;
	 if(L==NULL)
		return 0;
	 while(L)
	 {
		 p=L->next;
		 free(L);
		 L=p;
	 }
	 return 1;
 }
 int OperatMenu()
 {
	 int i;
		 printf("--------请选择以下选项-----------\n");
		 printf("-0退出\n"); printf("-1 插入节点\n");
		 printf("-2 取值\n"); printf("-3 删除链表节点\n");
		 printf("-4 创建链表\n");printf("-5 销毁链表");
		 printf("请选择：");
		 scanf("%d",&i);
	      return i;
 }

 void main()
 {
	 LinkList L;
	 
     int k;
	 int i,e,j;
	
      while(1)
	  {
		  k=OperatMenu();
	    switch(k)
		{
    	 case 0:
		      exit(0);
	    	 break;
	     case 1:
		     printf("请输入你要插入链表的位置和数据：");
             scanf("%d",&i);
			 scanf("%d",&e);
				if(ListInsert_L(L,i,e))
				{
					printf("新的链表为\n：");
					Display_L(L);
				}
				else
					printf("无法插入");
			break;
	     case 2:
		     printf("请输入要取出节点的位置：");
			 scanf("%d",&i);
			 printf("节点数值为%d",e=Get_L(L,i,e));
		    break;
   	     case 3:
		     printf("请输入要删除节点的位置：");
		    scanf("%d",&i);
		   if( ListDelet_L(L,i,e))
		   {
			 printf("新的链表为：");
			 Display_L(L);
		   }
		  else
			 printf("无法删除!");
		   break;
	     case 4:
            InitList_L(L);
		    Create_L(L);
			Display_L(L);
	    	break;
		 case 5:
			 if(Destroy_L(L))
				 printf("销毁成功!");
			 else
				 printf("无法销毁!");
			 break;
        default:
		     printf("输入有误，请重新输入：");
		   break;

	 }
	 
	  }
 }

 
