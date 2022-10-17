#include <stdio.h>

int main()
{
  int i, j, n, wt[30], bt[30], tat[30];
  float avwt = 0, avtat = 0;
  printf("Enter the no of process: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    printf("Burst time of P[%d]: ", i + 1);
    scanf("%d", &bt[i]);
  }
  wt[0] = 0;
  for (i = 1; i < n; i++)
  {
    wt[i] = bt[i - 1] + wt[i - 1];
    avwt = avwt + wt[i];
  }

  for (i = 0; i < n; i++)
  {
    tat[i] = bt[i] + wt[i];
    avtat = avtat + tat[i];
  }

  printf("\nProcesses\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for (i = 0; i < n; i++)
  {
    printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
  }
  printf("Average Waiting Time = %f\n", avwt / n);
  printf("Average turn around time = %f", avtat / n);
}
