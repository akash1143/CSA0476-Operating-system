#include <stdio.h>
#include <stdlib.h>
struct Process {
    int processID;
    int arrivalTime;
    int burstTime;
    int remainingTime;
};
void roundRobinScheduling(struct Process processes[], int n, int timeQuantum) {
    int time = 0; 
    int completed = 0;
    int waitingTime[n], turnaroundTime[n];
    for (int i = 0; i < n; i++) {
        processes[i].remainingTime = processes[i].burstTime;
    }
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remainingTime > 0) {
                int executionTime = (processes[i].remainingTime < timeQuantum) ? processes[i].remainingTime : timeQuantum;
                processes[i].remainingTime -= executionTime;
                time += executionTime;

                if (processes[i].remainingTime == 0) {
                    completed++;
                    waitingTime[i] = time - processes[i].arrivalTime - processes[i].burstTime;
                    turnaroundTime[i] = waitingTime[i] + processes[i].burstTime;
                }
            }
        }
    }
    float avgWaitingTime = 0, avgTurnaroundTime = 0;
    for (int i = 0; i < n; i++) {
        avgWaitingTime += waitingTime[i];
        avgTurnaroundTime += turnaroundTime[i];
    }
    avgWaitingTime /= n;
    avgTurnaroundTime /= n;
    printf("Average Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
}
int main() {
    int n;
    int timeQuantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time quantum: ");
    scanf("%d", &timeQuantum);

    struct Process processes[n];
    for (int i = 0; i < n; i++) {
        processes[i].processID = i + 1;

        printf("Enter arrival time for Process %d: ", i + 1);
        scanf("%d", &processes[i].arrivalTime);

        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
    }
    roundRobinScheduling(processes, n, timeQuantum);

    return 0;
}
