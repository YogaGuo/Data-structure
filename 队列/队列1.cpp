#include<stdio.h>
#include<stdlib.h>
typedef struct QNode{
	int data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;
int InitQueue(LinkQueue &Q)
{
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q.front)
		exit(0);
	Q.front->next=NULL;
	return 1;
}
int Destroy(LinkQueue &Q)
{
	if(Q.front==NULL)
	return 0;
	while(Q.front)
	{
		Q.rear=Q.front->next;
		free(Q.front);
		Q.front=Q.rear;
	}
	return 1;
}
int EnQueue(LinkQueue &Q,int e)
{
	QNode *p;
	p=(QueuePtr)malloc(sizeof(QNode));
	if(!p)
		exit(0);
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	return 1;
}
int DeQueue(LinkQueue &Q,int &e)
{
	QNode *p;
	if(Q.front==Q.rear)
		return 0;
	p=Q.front->next;
	e=p->data;
	Q.front->next=p->next;
	if(Q.rear==p)
		Q.rear=Q.front;
	free(p);
	return 1;
}
int QueueEmpty(LinkQueue &Q)
{
	if(Q.front==Q.rear)
		return 1;
	else
		return 0;
}
void CreateQueue(LinkQueue &Q)
{
	QNode *p,*q;
	p=Q.front;
	int n,e;
	printf("请输入队列长度：");
	scanf("%d",&n);
	printf("请输入队列元素：");
	for(int i=0;i<n;i++)
	{
		q=(QueuePtr)malloc(sizeof(QNode));
		scanf("%d",&e);
		q->data=e;
		p->next=q;
		p=q;
		Q.rear=q;
	}
	 p->next=NULL;
	 printf("队列创建成功!");
}
int ClearQueue(LinkQueue &Q)
{
	QNode *p;
	if(Q.front->next=NULL)
		return 0;
	p=Q.front->next;
	while(p)
	{
		Q.rear=p->next;
		free(p);
		p=Q.rear;
	}
	return 1;
}
void PrintQueue(LinkQueue &Q)
{
	QNode *p;
	p=Q.front->next;
	while(p)
	{
		printf("%d",p->data);
		p=p->next;
	}
}
int OpertMenu()
{
	int i;
	printf("-----------请输入要操作的选项-------------\n");
    printf("-0 建队列\n"); printf("-1 插入元素\n");
	printf("-2 删除队列元素\n"); printf("-3 判空\n");
	printf("-4 销毁队列\n");   printf("-5 清除队列元素\n");
	printf("-6 退出菜单\n");
	printf("请选择：");
	scanf("%d",&i);
	return i;
}
void main()
{
	LinkQueue Q;
	int e,k;
	while(1)
	{
			k=OpertMenu();
		switch(k)
		{
		case 0:
               InitQueue(Q);
			   CreateQueue(Q);
			   printf("队列为\n");
			   PrintQueue(Q);
			   break;
		case 1:
			  printf("请输入插入的元素：\n");
			  scanf("%d",&e);
			 if( EnQueue(Q,e))
			 {
				 printf("新的队列为：\n");
			     PrintQueue(Q);
			 }
			 else
				 printf("无法插入\n");
		    break;
		case 2:
			  if(DeQueue(Q,e))
			  { 
				  printf("出队列的元素为%d：",e);
			     printf("新的队列为：\n");
			     PrintQueue(Q);
			  }
			 else
				printf("无法删除！\n");
			break;
		case 3:
			if(QueueEmpty(Q))
				printf("队列为空\n");
			else
				printf("队列不为空\n");
			break;
		case 4:
              if(Destroy(Q))
				  printf("队列已销毁！\n");
			  else
				  printf("无法销毁队列！\n");
			break;
		case 5:
			  if(ClearQueue(Q))
				  printf("队列已清空\n");
			  else
				  printf("无法清空队列！\n");
			  break;
		case 6:
			 exit(0);
			 break;
		default:
			printf("输入有误！请重新输入：\n");
			break;
		}
	}
}






