#include<stdio.h>
int main()
{
  int n,i,j,p[90],pr[90],bt[90],wt[90],tat[90],min,temp;
  float avwt=0,avtat=0;
  printf("Enter the no of process: ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("Burst time of P[%d]: ",i+1);
    scanf("%d",&bt[i]);
    printf("Priority of P[%d]: ",i+1);
    scanf("%d",&pr[i]);
    p[i] = i+1;
  }
  
  for(i=0;i<n;i++)
  {
    min=i;
    for(j=i+1;j<n;j++)
    {
      if(pr[j]<pr[min])
      {
        min = j;
        
        temp=pr[i];
        pr[i]=pr[min];
        pr[min]=temp;
        
        temp=bt[i];
        bt[i]=bt[min];
        bt[min]=temp;
        
        temp=p[i];
        p[i]=p[min];
        p[min]=temp;
      }
    }
  }
  wt[0] = 0;
    for(i=1;i<n;i++)
    {
      wt[i] = wt[i-1]+bt[i-1];
      avwt = avwt + wt[i];
    }
    for(i=0;i<n;i++)
    {
      tat[i]= wt[i]+bt[i];
      avtat = avtat + tat[i];
    }
    printf("Processes\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i=0;i<n;i++)
    {
      printf("P[%d]\t\t%d\t\t%d\t\t%d\n",p[i],bt[i],wt[i],tat[i]);
    }
    printf("Average waiting time: %f",avwt/n);
    printf("\nAverage turnaround time: %f",avtat/n);
}




































