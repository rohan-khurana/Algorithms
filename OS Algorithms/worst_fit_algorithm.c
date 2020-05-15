#include<stdio.h>
#include<conio.h>
void main()
{
	int fragment[10],b[10],f[10],i,j,bno,pno,temp,top=0;
	static int barray[10],parray[10];
	printf("Enter Number of Blocks:");
	scanf("%d",&bno);
	printf("Enter Size of each Block:\n");
	for(i=1;i<=bno;i++)
	{
		scanf("%d",&b[i]);
	}
	printf("Enter Number of Processes:");
	scanf("%d",&pno);
	printf("Enter the Size of each Process:\n");
	for(i=1;i<=pno;i++)
	{
		scanf("%d",&f[i]);
	}
	for(i=1;i<=pno;i++)
	{
		for(j=1;j<=bno;j++)
		{
			if(barray[j]!=1)
			{
				temp=b[j]-f[i];
				if(temp>=0)
					if(top<temp)
					{
						parray[i]=j;
						top=temp;
					}
			}
		}
		fragment[i]=top;
		barray[parray[i]]=1;
		top=0;
	}
	printf("\nProcess No.\tProcess Size\tBlock No.\tBlock Size\tFragment");
	for(i=1;i<=pno;i++)
	printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,f[i],parray[i],b[parray[i]],fragment[i]);
	getch();
}
