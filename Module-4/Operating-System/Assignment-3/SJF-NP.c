#include <stdio.h>

int main(){
    int at[] = {0, 1, 3, 3};
    int bt[] = {1, 9, 1, 9};
    int n = sizeof(at)/ sizeof(at[0]);

    int ft[n], tat[n], wt[n];
    int total_wt = 0, total_tat = 0;

    int i, j, min, temp;
    for (i = 0; i < n; i++){
        min = i;
        for (j = i + 1; j < n; j++){
            if (at[j] < at[min]){
                min = j;
            }
        }
        temp = at[i];
        at[i] = at[min];
        at[min] = temp;

        temp = bt[i];
        bt[i] = bt[min];
        bt[min] = temp;
    }

    ft[0] = at[0] + bt[0];
    tat[0] = ft[0] - at[0];
    wt[0] = tat[0] - bt[0];

    for (i = 1; i < n; i++){
        ft[i] = ft[i - 1] + bt[i];
        tat[i] = ft[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    printf("AT\t BT\t FT\t TAT\t WT");
    for (i = 0; i < n; i++){
        printf("\n%d\t %d\t %d\t %d\t %d", at[i], bt[i], ft[i], tat[i], wt[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\n\nAverage WT:  %0.2f", (total_wt * 1.0 / n));
    printf("\nAverage TAT: %0.2f\n", (total_tat * 1.0 / n));

    return 0;
}