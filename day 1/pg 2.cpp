#include <stdio.h>

struct Process {
    int id;
    int arrival_time;
    int burst_time;
};

void calculateWaitingTime(struct Process processes[], int n, int waitingTime[]) {
    waitingTime[0] = 0; // First process has 0 waiting time

    // Calculate waiting time for the rest of the processes
    for (int i = 1; i < n; i++) {
        waitingTime[i] = waitingTime[i - 1] + processes[i - 1].burst_time;
    }
}

void calculateTurnaroundTime(struct Process processes[], int n, int waitingTime[], int turnaroundTime[]) {
    for (int i = 0; i < n; i++) {
        turnaroundTime[i] = waitingTime[i] + processes[i].burst_time;
    }
}

void calculateAverageTime(struct Process processes[], int n) {
    int waitingTime[n], turnaroundTime[n];

    calculateWaitingTime(processes, n, waitingTime);
    calculateTurnaroundTime(processes, n, waitingTime, turnaroundTime);

    float totalWaitingTime = 0, totalTurnaroundTime = 0;
 printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time, waitingTime[i], turnaroundTime[i]);
    }

    float averageWaitingTime = totalWaitingTime / n;
    float averageTurnaroundTime = totalTurnaroundTime / n;

    printf("\nAverage Waiting Time: %.2f\n", averageWaitingTime);
    printf("Average Turnaround Time: %.2f\n", averageTurnaroundTime);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        processes[i].arrival_time = 0; // All processes start at time 0
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }
	calculateAverageTime(processes, n);

}
