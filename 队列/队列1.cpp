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
	printf("��������г��ȣ�");
	scanf("%d",&n);
	printf("���������Ԫ�أ�");
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
	 printf("���д����ɹ�!");
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
	printf("-----------������Ҫ������ѡ��-------------\n");
    printf("-0 ������\n"); printf("-1 ����Ԫ��\n");
	printf("-2 ɾ������Ԫ��\n"); printf("-3 �п�\n");
	printf("-4 ���ٶ���\n");   printf("-5 �������Ԫ��\n");
	printf("-6 �˳��˵�\n");
	printf("��ѡ��");
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
			   printf("����Ϊ\n");
			   PrintQueue(Q);
			   break;
		case 1:
			  printf("����������Ԫ�أ�\n");
			  scanf("%d",&e);
			 if( EnQueue(Q,e))
			 {
				 printf("�µĶ���Ϊ��\n");
			     PrintQueue(Q);
			 }
			 else
				 printf("�޷�����\n");
		    break;
		case 2:
			  if(DeQueue(Q,e))
			  { 
				  printf("�����е�Ԫ��Ϊ%d��",e);
			     printf("�µĶ���Ϊ��\n");
			     PrintQueue(Q);
			  }
			 else
				printf("�޷�ɾ����\n");
			break;
		case 3:
			if(QueueEmpty(Q))
				printf("����Ϊ��\n");
			else
				printf("���в�Ϊ��\n");
			break;
		case 4:
              if(Destroy(Q))
				  printf("���������٣�\n");
			  else
				  printf("�޷����ٶ��У�\n");
			break;
		case 5:
			  if(ClearQueue(Q))
				  printf("���������\n");
			  else
				  printf("�޷���ն��У�\n");
			  break;
		case 6:
			 exit(0);
			 break;
		default:
			printf("�����������������룺\n");
			break;
		}
	}
}






