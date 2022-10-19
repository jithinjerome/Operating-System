#include <stdio.h>
int main()
{
  int i, n, total = 0, x, count = 0, ts;
  int wt = 0, tat = 0, at[10], bt[10], temp[10];
  float avwt, avtat;

  printf("Enter the no of process: ");
  scanf("%d", &n);
  x = n;
  for (i = 0; i < n; i++)
  {
    printf("\nArrival time of P[%d]: ", i + 1);
    scanf("%d", &at[i]);
    printf("Burst time of P[%d]: ", i + 1);
    scanf("%d", &bt[i]);
    temp[i] = bt[i];
  }
  printf("Enter the time slice: ");
  scanf("%d", &ts);

  printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for (total = 0, i = 0; x != 0;)
  {
    if (temp[i] <= ts && temp[i] > 0)
    {
      total = total + temp[i];
      temp[i] = 0;
      count = 1;
    }
    else if (temp[i] > 0)
    {
      temp[i] = temp[i] - ts;
      total = total + ts;
    }
    if (temp[i] == 0 && count == 1)
    {
      x--;
      printf("\nP[%d]\t\t%d\t\t%d\t\t%d", i + 1, bt[i], total - at[i] - bt[i], total - at[i]);
      wt = wt + total - at[i] - bt[i];
      tat = tat + total - at[i];
      count = 0;
    }
    if (i == n - 1)
    {
      i = 0;
    }
    else if (at[i + 1] <= total)
    {
      i++;
    }
    else
    {
      i = 0;
    }
  }
  return 0;
}
