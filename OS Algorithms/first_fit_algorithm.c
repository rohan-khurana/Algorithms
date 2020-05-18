#include<stdio.h>
void main()
{
int fragment[20],b[20],p[20],i,j,bno,pno,temp,lowest=9999;
static int barray[20],parray[20];
printf("Enter the No. of Blocks:");
scanf("%d",&bno);
printf("Enter the Size of each Blocks:\n");
for(i=1;i<=bno;i++)
{
scanf("%d",&b[i]);
}
printf("Enter the No. of Processes:");
scanf("%d",&pno);
printf("Enter the Size of each Process:\n");
for(i=1;i<=pno;i++)
{
scanf("%d",&p[i]);
}
for(i=1;i<=pno;i++)
{
for(j=1;j<=bno;j++)
{
if(barray[j]!=1)
{
temp=b[j]-p[i];
if(temp>=0)
if(lowest>temp)
{
parray[i]=j;
lowest=temp;
}
}
}
fragment[i]=lowest;
barray[parray[i]]=1;
lowest=10000;
}
printf("\nProcess No\tProcess size\tBlock No\tBlock
Size\tFragment");
for(i=1;i<=pno && parray[i]!=0;i++)
printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,p[i],parray[i],b[parra
y[i]],fragment[i]);
}
