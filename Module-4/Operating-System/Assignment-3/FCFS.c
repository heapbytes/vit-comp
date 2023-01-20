#include <stdio.h>
#include <stdlib.h>

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

  printf("\nAT\t\tBT\t\tFT\t\tTT\t\tWT\n");
  for(int i=0; i<n; i++){
    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, bt[i], ft[i], tt[i], wt[i]);
  }

  return 0;
}
