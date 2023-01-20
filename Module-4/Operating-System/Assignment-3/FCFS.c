#include <stdio.h>

int main(){

  int n = 4;
  int at[] = {0, 1, 3, 3};
  int bt[] = {1, 9, 1, 9};

  int ft[n];
  for(int i=0; i<n; i++){
    ft[i] = ft[i-1]+bt[i];
  }

  int tt[15];
  for(int i=0; i<n;i++){
    tt[i] = ft[i] - at[i];
  }

  int wt[15];
  for(int i=0;i<n;i++){
    wt[i] = tt[i] - bt[i];
  }

  printf("\nAT\t\tBT\t\tFT\t\tTAT\t\tWT\n");
  for(int i=0; i<n; i++){
    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, bt[i], ft[i], tt[i], wt[i]);
  }
  float avg_wt = 0.0, avg_tt = 0.0;
  for (int i = 0; i < n; i++) {
    avg_wt += wt[i];
    avg_tt += tt[i];
  }
  avg_wt /= n;
  avg_tt /= n;

  printf("\nAverage WT:  %0.2f", avg_wt);
  printf("\nAverage TAT: %0.2f\n", avg_tt);

  return 0;
}
