#include<stdio.h>

struct Process {
    int at, bt, ct, tat, wt;
};

int main(){
    int n, i, j;
    struct Process p[10], temp;
    float avg_tat=0, avg_wt=0;

    printf("Enter Number of Processes : ");
    scanf("%d",&n);
    printf("Enter Arrival Time, Burst Time for each process:\n");
    for(i=0;i<n;i++){
        printf("Process %d : ",i+1);
        scanf(" %d %d", &p[i].at, &p[i].bt);
    }

    for(i = 0; i < n; i++){
        for(j = i+1; j < n; j++){
            if(p[i].at > p[j].at){
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    p[0].ct = p[0].at + p[0].bt;
    for(i=1;i <n; i++){
        if(p[i-1].ct < p[i].at)
            p[i].ct = p[i].at + p[i].bt;
        else
            p[i].ct = p[i-1].ct + p[i].bt;
    }

    printf("FCFS Scheduling:\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++){
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        avg_tat += p[i].tat;
        avg_wt += p[i].wt;
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i+1, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    avg_tat /= n;
    avg_wt /= n;
    printf("Average Turnaround Time: %.2f\n", avg_tat);
    printf("Average Waiting Time: %.2f\n", avg_wt); 

}
