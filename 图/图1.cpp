#include<stdio.h>
#include<stdlib.h>
#define INFINITY 65535
#define MAX_VERTEX_NUM  7
 int  visited[ MAX_VERTEX_NUM ];
typedef struct ArcCell{
	int  adj;
	int  *info;
}ArcCell,AdjMatrix[MAX_VERTEX_NUM] [MAX_VERTEX_NUM];
typedef struct{
	char vexs[MAX_VERTEX_NUM];
	AdjMatrix arcs;
	int vexnum,arcnum;
}MGraph;
int LocateVex(MGraph G,char v)
{
	 int i;
	 for(i=0;i<G.vexnum;i++)
	 {
		 if(v==G.vexs[i])
			return i;
	 }
	 return -1;
 }
void CreateAN(MGraph &G)
{
	char v1,v2;
	int w,i,j,k,n,m;
	printf("�����붥����������");
	scanf("%d %d",&n,&m);
	G.vexnum=n;
	G.arcnum=m;
	printf("���붥���һά��������");
	fflush(stdin);
	for( i=0;i<G.vexnum;i++)
	{
		scanf("%c",&G.vexs[i]);
	}                                                                                                                                       
  	for( i=0;i<G.vexnum;i++)
	{
		for( j=0;j<G.vexnum;j++)	
			G.arcs[i][j].adj=INFINITY;
	}
	for( k=0;k<G.arcnum;++k)
		{ 
			printf("����һ�������������������Ȩֵ��");
			fflush(stdin);
			scanf("%c%c",&v1,&v2);
			scanf("%d",&w);
			i=LocateVex(G,v1);
			j=LocateVex(G,v2);
			G.arcs[i][j].adj=w;
			G.arcs[j][i]=G.arcs[i][j];
		}
}
void Print1(MGraph G)
{
	int i,j;
	printf("�������ϢΪ:\n");
	for(i=0;i<G.vexnum;i++)
		printf("%c",G.vexs[i]);
	printf("\n����ڽӾ���:\n");
	printf("\t");
		for(i=0;i<G.vexnum;i++)
	{
			printf("\n");
		for(j=0;j<G.vexnum;j++)
			if(G.arcs[i][j].adj==65535)
		    	printf("%d\t",0);
			else
				printf("%d\t",G.arcs[i][j].adj);
	}

}
void DFS(MGraph G,int i)
{
	int j;
	printf("%c",G.vexs[i]);
	visited[i]=1;
	for(j=0;j<G.vexnum;j++)
		if(!visited[j]&&G.arcs[i][j].adj)
			DFS(G,j);
}
void DFSTrav(MGraph G)
{
	char m;
	int i,j;
	for(i=0;i<G.vexnum;i++)
		visited[i]=0;
	 printf("�����뿪ʼ�����ĵ�һ������:");
	 getchar();
     scanf("%c",&m);
	 j=LocateVex(G,m);
	for(i=0;i<G.vexnum;i++)
	{
		if(!visited[i])
			DFS(G,j);
	}
}
int OperatMenu()
{
	int i;
	printf("\n********���������ѡ��********\n");
	printf("-0 �˳�\n");
		printf("-1 ��ͼ \n"); printf("-2  ��ӡ�������ڽӾ��� \n");
	    printf("-3 ��ȱ������㼯��ӡ���\n");printf("������ѡ��:");
		scanf("%d",&i);
		return i;
}
void main()
{
	int k;
    MGraph G;
	char Flag=false;
	while(1)
	{
		 k=OperatMenu(); 
		 switch(k)
		 {
		 case 0:
			  exit(0);
			  break;
		 case 1:
               CreateAN(G);
			   Flag=true;
			   break;
		 case 2:
			 if(Flag)
               Print1(G);
			 else
				 printf("ͼδ��,���Ƚ�����ͼ��\n");
			   break; 
		 case 3:
			 if(Flag)
               DFSTrav(G);
			 else
				 printf("ͼδ��,���Ƚ�����ͼ��\n");
			   break;
   		 default:
			 printf("�����������������룺");
			 break;
		 }
	}
}








			





	
