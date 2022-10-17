#include <stdio.h>

int main()
{
  int a[100][4], i, j, temp, min, n;
  float avwt = 0, avtat = 0, total1 = 0, total2 = 0;
  printf("Enter the no of process: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    printf("Burst Time of P[%d]: ", i + 1);
    scanf("%d", &a[i][1]);
    a[i][0] = i + 1;
  }
  for (i = 0; i < n; i++)
  {
    min = i;
    for (j = i + 1; j < n; j++)
    {
      if (a[j][1] < a[min][1])
      {
        min = j;
        temp = a[i][1];
        a[i][1] = a[min][1];
        a[min][1] = temp;

        temp = a[i][0];
        a[i][0] = a[min][0];
        a[min][0] = temp;
      }
    }
  }
  a[0][2] = 0;
  for (i = 1; i < n; i++)
  {
    a[i][2] = a[i - 1][1] + a[i - 1][2];
    avwt = avwt + a[i][2];
  }
  for (i = 0; i < n; i++)
  {
    a[i][3] = a[i][1] + a[i][2];
    avtat = avtat + a[i][3];
  }

  printf("Processes\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for (i = 0; i < n; i++)
  {
    printf("%d\t\t%d\t\t%d\t\t%d\n", a[i][0], a[i][1], a[i][2], a[i][3]);
  }
  printf("Average Waiting Time = %f\n", avwt / n);
  printf("Average turn around time = %f", avtat / n);
}
