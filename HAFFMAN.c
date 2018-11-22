#include<string.h>
#include<limits.h>
#include<stdio.h>
typedef struct node
{
	char data;
	int fre;
	int lchild;
	int rchild;
	int parent;
}TreeNode;
TreeNode TreeArray[12];
TreeNode p;
int min,nmin=0;
char ch[10],code[50];
void Select(int i)
{
	min=nmin= 11;
	int j;
	for (j = 0; j <i; j++)
	{
		if (TreeArray[j].parent == -1)
		{
			if (TreeArray[j].fre < TreeArray[min].fre)
			{
				nmin = min;
				min = j;
			}
			else if (TreeArray[j].fre < TreeArray[nmin].fre)
			{
				nmin = j;
			}
		}
	}
}
void CreatTree()
{
	TreeArray[11].fre =INT_MAX;
	int i,j,m;
	for (i = 0; i < 6; i++)
	{
		scanf("%d", &m);
		TreeArray[i].fre = m;
		TreeArray[i].data = 'A' + i;
		TreeArray[i].parent = -1;
		TreeArray[i].lchild=-1;
		TreeArray[i].rchild=-1;
	}
	for (j = 6; j <11; j++)
	{
		TreeArray[j].parent = -1;
		Select(j);
		TreeArray[j].lchild = min;
		TreeArray[j].rchild = nmin;
		TreeArray[j].fre = TreeArray[min].fre + TreeArray[nmin].fre;
		TreeArray[min].parent = j;
		TreeArray[nmin].parent = j;
	}
}
void Coden()
{
	int i,j,k=99;
	char m[100];
	for(j=0;j<6;j++)
	{
		i=j;
		printf("%c:",TreeArray[i].data);
		while(TreeArray[i].parent!=-1)
	    {
		if(TreeArray[TreeArray[i].parent].lchild==i)
		m[k]='0';		
		else
		m[k]='1';
		k--;
		i=TreeArray[i].parent;
	    }
	    while(k<99)
	    {
	    	k++;
	    printf("%c",m[k]);
	    }
	    printf("\n");
	}
	for(i=0;i<strlen(ch);i++)
	{
		for(j=0;j<6;j++)
		{
			if(ch[i]==TreeArray[j].data)
			{
				while(TreeArray[j].parent!=-1)
	            {
		         if(TreeArray[TreeArray[j].parent].lchild==j)
		          m[k]='0';		
		        else
		          m[k]='1';
		          k--;
		          j=TreeArray[j].parent;
	            }
	            while(k<99)
	            {
	    	      k++;
	              printf("%c",m[k]);
	            }
	            break;
			}
		}
	}
}
void Decode()
{
	int i,j;
	j=10;
	for(i=0;i<strlen(code);i++)
	{
		if(TreeArray[j].lchild!=-1)
		{
		if(code[i]=='0')
		j=TreeArray[j].lchild;
	    }
	   if(TreeArray[j].rchild!=-1)
		{
			if(code[i]=='1')
			j=TreeArray[j].rchild;
		}
	    if(TreeArray[j].lchild==-1&&TreeArray[j].rchild==-1)
	    {
	    	printf("%c",TreeArray[j].data);
	    	j=10;
		}
	}
}
int main()
{
	int i;
	CreatTree();
	scanf("%s",ch);
	scanf("%s",code);
	Coden();
	printf("\n");
	Decode();
	fflush(stdin);
}
