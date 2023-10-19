#include <stdio.h>
#include <stdlib.h>

int main() {
    int ReadyQueue[100];  // An array to store the disk request queue
    int n, TotalHeadMov = 0, initial;

    // Read the number of requests (n)
    scanf("%d", &n);

    // Read the disk request queue
    for (int i = 0; i < n; i++) {
        scanf("%d", &ReadyQueue[i]);
    }

    // Read the initial head position
    scanf("%d", &initial);

    // Calculate the total head movement
    for (int i = 0; i < n; i++) {
        // Calculate the absolute difference between the current request and the initial head position
        int headMovement = abs(ReadyQueue[i] - initial);
        TotalHeadMov += headMovement;

        // Update the initial head position
        initial = ReadyQueue[i];
    }

    // Print the total head movement
    printf("Total Head Movement = %d\n", TotalHeadMov);

    return 0;
}

