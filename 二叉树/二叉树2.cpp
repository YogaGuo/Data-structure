#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
typedef struct BITNode{
	char data;
	struct BITNode *lchild,*rchild;
}BITNode,*BITree;
void CreateBITree(BITree &T)   //��������������������ַ���#��ʾ����
{
	
	 
	char ch;
	scanf("%c",&ch);
	if(ch=='#')    
		T=NULL;
	else{
		if(!(T=(BITNode*)malloc(sizeof(BITNode))))
		exit(0);
		T->data=ch;      //���ɸ����
		CreateBITree(T->lchild); //����������
		CreateBITree(T->rchild);}   //����������

}
 void LRD(BITree &T)     //����������
{
	if(T!=NULL)
	{
		LRD(T->lchild);
		LRD(T->rchild);
		printf("%c",T->data);
	}
 
}
void LDR(BITree &T)     //����������
{
	if(T!=NULL)
	{
		LDR(T->lchild);
		printf("%c",T->data);
		LDR(T->rchild);
	}
 
}
void DLR(BITree &T)    //����������
{
	if(T!=NULL)
	{
		printf("%c",T->data);
		DLR(T->lchild);
		DLR(T->rchild);
	}
 
}
int Sumleaf(BITree T,int &sum)   //ͳ��Ҷ�ӽ��
{
	
	if(T==NULL)     //��Ϊ�գ����ز���ʾ����
		return 0;
	else
	{
		Sumleaf(T->lchild,sum);
		if(!T->lchild&&!T->rchild)
        {
			sum++;
		}
		Sumleaf(T->rchild,sum);
		
		return 1;
	}
}
int Sumall(BITree T,int &sum)   //ͳ�����н��
{
	
    if(T==NULL)        //��Ϊ�գ����ز���ʾ����
		return 0;
	else
	{
		Sumall(T->lchild,sum);
		sum++;
		Sumall(T->rchild,sum);
	}
  	return 1;
}
int Deep(BITree T,int l,int &h)      //�����������
{
	if(T==NULL)       //��Ϊ�գ����ز���ʾ����
		return 0;
	else 
	{   
		    l=l+1;
	     	if(l>h)
		    	h=l;
	       	Deep(T->lchild,l,h);
	     	Deep(T->rchild,l,h);
	}
	return 1;
	
}

int OpertMenu()    //�˵�
{
	int i;
	printf("--------������������---------\n");
	printf("-0 �˳�\n"); printf("-1 ����\n");
	printf("-2 �������\n"); printf("-3 �������\n");
	printf("-4 �������\n"); printf("-5 ͳ��Ҷ�ӽ�����\n");
	printf(" -6 ͳ�ƽ�����\n"); printf("-7 ������������\n");
	printf("�����룺");
	scanf("%d",&i);
	return i;
}
void main()
{
	BITree T=NULL;
	int k,sum=0,l=0,h=0;
	while(1)
	{
		k=OpertMenu();
		switch(k)
		{
		case 0:
			exit(0);
			break;
        case 1:
			   fflush(stdin);
				printf("�������ַ��������ַ�#���ʾ������ɣ�\n");
               CreateBITree(T);
				printf("�������ɹ���\n");
				Sleep(1000);     //������ɺ󣬳���ͣ��1��
			break;
		case 2:
			DLR(T);
			Sleep(1000);      //�����ӡ��ɺ󣬳���ͣ��1��
			break;
		case 3:
			LDR(T);
			Sleep(1000);     //�����ӡ��ɺ󣬳���ͣ��1��
			break;
		case 4:
			LRD(T);
			Sleep(1000);       //�����ӡ��ɺ󣬳���ͣ��1��
            break;
		case 5:
			   Sumleaf(T,sum);
		     	if(sum)
				printf("Ҷ����Ϊ%d\n",sum);
				else
				printf("�޷�ͳ�ƣ����Ƚ���\n");
				Sleep(1000);       //Ҷ��ͳ����ɺ󣬳���ͣ��1��
			 break;
		case 6:
             Sumall(T,sum);
			 if(sum)
			 printf("�����Ϊ%d\n",sum);
			 else
			 printf("�޷�ͳ�ƽ���������Ƚ���\n");
			 Sleep(1000);    //�����ӡ��ɺ󣬳���ͣ��1��
			 break;
		case 7:
              Deep(T,l,h);
			  if(h)
				  printf("�������Ϊ%d\n",h);
			  else
				  printf("�޷��������\n");
			  Sleep(1000);   //���߼�����ɺ󣬳���ͣ��1��
			  break;
		default:
			printf("������������������\n");
		}
	}
}

    