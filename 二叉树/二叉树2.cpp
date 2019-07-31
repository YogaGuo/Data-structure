#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
typedef struct BITNode{
	char data;
	struct BITNode *lchild,*rchild;
}BITNode,*BITree;
void CreateBITree(BITree &T)   //建树，按先序次序输入字符，#表示空树
{
	
	 
	char ch;
	scanf("%c",&ch);
	if(ch=='#')    
		T=NULL;
	else{
		if(!(T=(BITNode*)malloc(sizeof(BITNode))))
		exit(0);
		T->data=ch;      //生成根结点
		CreateBITree(T->lchild); //构造左子树
		CreateBITree(T->rchild);}   //构造右子树

}
 void LRD(BITree &T)     //后序遍历输出
{
	if(T!=NULL)
	{
		LRD(T->lchild);
		LRD(T->rchild);
		printf("%c",T->data);
	}
 
}
void LDR(BITree &T)     //中序遍历输出
{
	if(T!=NULL)
	{
		LDR(T->lchild);
		printf("%c",T->data);
		LDR(T->rchild);
	}
 
}
void DLR(BITree &T)    //先序遍历输出
{
	if(T!=NULL)
	{
		printf("%c",T->data);
		DLR(T->lchild);
		DLR(T->rchild);
	}
 
}
int Sumleaf(BITree T,int &sum)   //统计叶子结点
{
	
	if(T==NULL)     //树为空，返回并提示建树
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
int Sumall(BITree T,int &sum)   //统计所有结点
{
	
    if(T==NULL)        //树为空，返回并提示建树
		return 0;
	else
	{
		Sumall(T->lchild,sum);
		sum++;
		Sumall(T->rchild,sum);
	}
  	return 1;
}
int Deep(BITree T,int l,int &h)      //计算树的深度
{
	if(T==NULL)       //树为空，返回并提示建树
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

int OpertMenu()    //菜单
{
	int i;
	printf("--------请输入操作序号---------\n");
	printf("-0 退出\n"); printf("-1 建树\n");
	printf("-2 先序输出\n"); printf("-3 中序输出\n");
	printf("-4 后序输出\n"); printf("-5 统计叶子结点个数\n");
	printf(" -6 统计结点个数\n"); printf("-7 计算二叉树深度\n");
	printf("请输入：");
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
				printf("请输入字符，输入字符#则表示输入完成：\n");
               CreateBITree(T);
				printf("树创建成功！\n");
				Sleep(1000);     //建树完成后，程序停顿1秒
			break;
		case 2:
			DLR(T);
			Sleep(1000);      //先序打印完成后，程序停顿1秒
			break;
		case 3:
			LDR(T);
			Sleep(1000);     //中序打印完成后，程序停顿1秒
			break;
		case 4:
			LRD(T);
			Sleep(1000);       //后序打印完成后，程序停顿1秒
            break;
		case 5:
			   Sumleaf(T,sum);
		     	if(sum)
				printf("叶子数为%d\n",sum);
				else
				printf("无法统计！请先建树\n");
				Sleep(1000);       //叶子统计完成后，程序停顿1秒
			 break;
		case 6:
             Sumall(T,sum);
			 if(sum)
			 printf("结点数为%d\n",sum);
			 else
			 printf("无法统计结点数！请先建树\n");
			 Sleep(1000);    //先序打印完成后，程序停顿1秒
			 break;
		case 7:
              Deep(T,l,h);
			  if(h)
				  printf("树的深度为%d\n",h);
			  else
				  printf("无法计算深度\n");
			  Sleep(1000);   //树高计算完成后，程序停顿1秒
			  break;
		default:
			printf("输入有误，请重新输入\n");
		}
	}
}

    