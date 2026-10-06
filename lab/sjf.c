#include <stdio.h>

struct Process {
    int at, bt, ct, tat, wt, done;
};

int main(){
    int n, i, j, time=0, count=0;
    struct Process p[10], temp;
    float avg_tat=0, avg_wt=0;

    printf("Enter Number of Processes : ");
    scanf("%d",&n);
    printf("Enter Arrival Time, Burst Time for each process:\n");
    for(i=0;i<n;i++){
        printf("Process %d : ",i+1);
        scanf(" %d %d", &p[i].at, &p[i].bt);
        p[i].done = 0;
    }  

    while(count < n){
        int min = -1;
        for(i=0;i<n;i++){
            if(p[i].at <= time && !p[i].done){
                if(min == -1 || p[i].bt < p[min].bt)
                    min = i;
            }
        }
        if(min == -1){
            time++;
            continue;
        }
        time += p[min].bt;
        p[min].ct = time;
        p[min].tat = p[min].ct - p[min].at;
        p[min].wt = p[min].tat - p[min].bt;
        p[min].done = 1;
        avg_tat += p[min].tat;
        avg_wt += p[min].wt;
        count++;
    }
    printf("SJF Scheduling:\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i+1, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    avg_tat /= n;
    avg_wt /= n;
    printf("Average Turnaround Time: %.2f\n", avg_tat);
    printf("Average Waiting Time: %.2f\n", avg_wt);
}