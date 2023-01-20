#include <stdio.h>


// at = {0,1,3,3} and bt = {1,9,1,9}  , time quantum = 1

int main()
{
    int i, n, time, remain, flag = 0, time_quantum = 1;
    int wait_time = 0, turnaround_time = 0, finish_time[10], rt[10];
    int at[] = {0,1,3,3};
    int bt[] = {1,9,1,9};
    n = sizeof at / sizeof at[0];
    remain = n;

    for (int i = 0; i < n; i++){
        rt[i] = bt[i];
    }
    
    printf("AT\t BT\t FT\t TAT\t WT");
    for (time = 0, i = 0; remain != 0;){
        if (rt[i] <= time_quantum && rt[i] > 0){
            time += rt[i];
            rt[i] = 0;
            flag = 1;
        }else if (rt[i] > 0){
            rt[i] -= time_quantum;
            time += time_quantum;
        }
        if (rt[i] == 0 && flag == 1){
            remain--;
            finish_time[i] = time;
            printf("\n%d\t %d\t %d\t %d\t %d", at[i],bt[i], finish_time[i], finish_time[i] - at[i], finish_time[i] - at[i] - bt[i]);

            wait_time += finish_time[i] - at[i] - bt[i];
            turnaround_time += finish_time[i] - at[i];
            flag = 0;
        }
        if (i == n - 1){
            i = 0; 
        } else if (at[i + 1] <= time){
            i++;
        } else{ i = 0; }
    }

    printf("\n\nAverage WT:  %0.2f", (wait_time * 1.0 / n));
    printf("\nAverage TAT: %0.2f\n", (turnaround_time * 1.0 / n));

    return 0;
}
