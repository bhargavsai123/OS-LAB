#include <stdio.h>

struct Process {
    int at,bt,ct,tat,wt,rt;
};

int main(){
    int n, i, j, time=0, count=0, tq;
    struct Process p[10], temp;
    float avg_tat=0, avg_wt=0;

    printf("Enter Number of Processes : ");
    scanf("%d",&n);
    printf("Enter Arrival Time, Burst Time for each process:\n");
    for(i=0;i<n;i++){
        printf("Process %d : ",i+1);
        scanf(" %d %d", &p[i].at, &p[i].bt);
        p[i].rt = p[i].bt;
    }
    printf("Enter Time Quantum : ");
    scanf("%d",&tq);

    int queue[50], front=0, rear=0;
    int inQueue[n];
    for(i=0;i<n;i++) inQueue[i] = 0;

    printf("Gantt Chart:\n");
    while(count < n){
        for(i=0; i < n; i++){
            if(!inQueue[i] && p[i].at <= time && p[i].rt > 0){
                queue[rear++] = i;
                inQueue[i] = 1;
            }
        }
        if(front == rear){
            time++;
            continue;
        }
        int i = queue[front++];
        inQueue[i] = 0;
        int run = p[i].rt < tq ? p[i].rt : tq;
        time += run;
        p[i].rt -= run;
        printf("| P%d ", i+1);
        for(j=0; j < n; j++){
            if(!inQueue[j] && p[j].at <= time && p[j].rt > 0 && j != i){
                queue[rear++] = j;
                inQueue[j] = 1;
            }
        }
        if(p[i].rt > 0){
            queue[rear++] = i;
            inQueue[i] = 1;
        } else {
            p[i].ct = time;
            count++;
        }
    }
    printf("|\n");
    printf("RR Scheduling:\n");
    for(i=0;i<n;i++){
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        avg_tat += p[i].tat;
        avg_wt += p[i].wt;
    }
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i+1, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    avg_tat /= n;
    avg_wt /= n;
    printf("Average Turnaround Time: %.2f\n", avg_tat);
    printf("Average Waiting Time: %.2f\n", avg_wt);
}