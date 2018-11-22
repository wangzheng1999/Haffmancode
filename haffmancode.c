#include<stdio.h>
#include<limits.h>
#include<string.h>
typedef struct node
{
	char data;
	int fre;
	int lchild;
	int rchild;
	int parent;
}TreeNode;
TreeNode TreeArray[200];
int alp[200],count=0,l=0,min,nmin,length=0;
char ch[200],code[200];
void Init()
{
	int i;
	for(i=0;i<200;i++)
	alp[i]=0;
}
void Count()
{
	int i;
	char m=getchar();
	Init();
	while(m!='#')
	{
		alp[m]++;
		ch[l]=m;
		l++;
		m=getchar();
	}
	for(i=32;i<=122;i++)
	{
		if(alp[i]!=0)
		count++;
	}
}
void Select(int i)
{
	int j;
	min=nmin=150;
	TreeArray[150].fre=INT_MAX;
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
	int i,j=0,m;
	for (i = 0; i <count; i++)
	{
	    while(alp[j]==0)
	    j++;
		TreeArray[i].data=j;
		TreeArray[i].fre=alp[j];
		TreeArray[i].parent = -1;
		TreeArray[i].lchild=-1;
		TreeArray[i].rchild=-1;
		j++;
	}
	for (j = count; j <2*count-1;j++)
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
	int s,j,k=99;
	char m[100];
	for(s=0;s<l;s++)
	{
		for(j=0;j<count;j++)
		{
			if(ch[s]==TreeArray[j].data)
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
	              length++;
	            }
	            break;
			}
		}
	}
}
void Decode()
{
	int i,j;
	j=2*count-2;
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
	    	j=2*count-2;
		}
	}
}
int main()
{
	Count();
	CreatTree();
	scanf("%s",code);
	Coden();
	printf("\n");
	Decode();
	printf("\n%.2f",(float)length/l);

}
