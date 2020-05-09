#include<stdio.h> 
#include<conio.h>
int main() 
{
int n=5, m=3, i, j, k;
int alloc[5][3] = { { 0, 1, 0 },{ 3, 0, 0 },{2, 0, 2 },{ 2, 1, 1 },{ 0, 0, 2 } };
int max[5][3] = { { 7, 5, 3 },{ 3, 2, 2 },{9, 0, 2 },{ 2, 2, 2 },{4, 3, 3 } };
int avail[3] = { 3, 3, 2 };
int f[n], ans[n], x= 0; 
for (k = 0; k < n; k++) 
{
  f[k] = 0; 
} 
    	int need[n][m]; 
    	for (i = 0; i < n; i++) 
      { 
        		for (j = 0; j < m; j++) 
            		need[i][j] = max[i][j] - alloc[i][j]; 
    	}
int y = 0; 
for (k = 0; k < 5; k++) 
{ 
  for (i = 0; i < n; i++) 
  { 
    if (f[i] == 0) 
    { 
      int flag = 0; 
      for (j = 0; j < m; j++) 
      { 	if (need[i][j] > avail[j])
          { flag = 1;
            break; 
          } 
      }
     if (flag == 0) 
      { ans[x++] = i; 
        for (y = 0; y < m; y++) 
        avail[y]+=alloc[i][y];
        f[i] = 1; 
      } 
    } 
  } 
} 
printf("Allocation Matrix:\n   A B C\n");
for(i=0;i<5;i++)
{
printf("P%d ",i);
    	for(j=0;j<3;j++)
      {
        printf("%d ",alloc[i][j]);
      }
	printf("\n");
}
printf("Max Matrix:\n   A B C\n");
for(i=0;i<5;i++)
{	
printf("P%d ",i);
    	for(j=0;j<3;j++)
    	{
    		printf("%d ",max[i][j]);
	}
	printf("\n");
}
printf("\n\nNeed Matrix:\n   A B C\n");
for(i=0;i<5;i++)
{
printf("P%d ",i);
    	for(j=0;j<3;j++)
    	{
    		printf("%d ",need[i][j]);
	}
	printf("\n");
}
  printf("\nSafe Sequence: \n"); 
for (i=0;i<n-1;i++) 
{
  printf(" P%d ->", ans[i]);
}
printf(" P%d", ans[n-1]); 
}
