#include <stdio.h>
struct Process {
    int id;
    int executionTime;
};

int main() {
    int numProcesses;
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);
    struct Process processes[numProcesses];
    for (int i = 0; i < numProcesses; i++) {
        processes[i].id = i + 1;
        printf("Enter execution time for Process %d: ", i + 1);
        scanf("%d", &processes[i].executionTime);
    }
    for (int i = 0; i < numProcesses - 1; i++) {
        for (int j = 0; j < numProcesses - i - 1; j++) {
            if (processes[j].executionTime > processes[j + 1].executionTime) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    printf("\nExecution Order:\n");
    int totalTime = 0;
    for (int i = 0; i < numProcesses; i++) {
        printf("Executing Process %d for %d units of time\n", processes[i].id, processes[i].executionTime);
        totalTime += processes[i].executionTime;
    }
    float averageWaitingTime = (float)totalTime / numProcesses;
    printf("\nAverage Waiting Time: %.2f\n", averageWaitingTime);

    return 0;
}
