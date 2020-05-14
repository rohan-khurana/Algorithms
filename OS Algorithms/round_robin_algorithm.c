#include<stdio.h> 
#include<conio.h>
void main() 
{ 
 
  int i,j,n,time,left,flag=0,q; 
  int wait=0,at[10],bt[10],wt[10]; 
  clrscr();
  printf("Enter Total Process: "); 
  scanf("%d",&n); 
  left=n; 
  for(i=0;i<n;i++) 
  { 
    printf("Enter Arrival Time for Process Number %d: ",i+1); 
    scanf("%d",&at[i]); 
  } 
  
  for(i=0;i<n;i++) 
  { 
    printf("Enter Burst Time for Process Number %d: ",i+1); 
    scanf("%d",&bt[i]); 
    wt[i]=bt[i]; 
  } 
  
  printf("Enter Time Quantum: "); 
  scanf("%d",&q); 
  printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\n"); 
  for(time=0,i=0;left!=0;) 
  { 
    if(wt[i]<=q && wt[i]>0) 
    { 
      time+=wt[i]; 
      wt[i]=0; 
      flag=1; 
    } 
    else if(wt[i]>0) 
    { 
      wt[i]-=q; 
      time+=q; 
    } 
    if(wt[i]==0 && flag==1) 
    { 
      left--; 
      printf("P%d\t\t%d\t\t%d\t\t%d\n",i+1,at[i],bt[i],time-at[i]-bt[i]); 
      wait+=time-at[i]-bt[i]; 
      flag=0; 
    } 
    if(i==n-1) 
      i=0; 
    else if(at[i+1]<=time) 
      i++; 
    else 
      i=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",wait*1.0/n);
getch();
}
