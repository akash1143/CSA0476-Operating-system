#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sysipc.h>
#include <sysshm.h>

int main() {
    // Create a key for shared memory
    key_t key = 1234;

    // Create a shared memory segment
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Fork a child process
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        // Child process (Consumer)
        char* shared_memory = shmat(shmid, NULL, 0);
        printf("Consumer received: %s\n", shared_memory);
        shmdt(shared_memory);
    } else {
        // Parent process (Producer)
        char* shared_memory = shmat(shmid, NULL, 0);
        strcpy(shared_memory, "Hello from the Producer!");
        shmdt(shared_memory);

        // Wait for the child process to finish
        wait(NULL);

        // Delete the shared memory segment
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}
