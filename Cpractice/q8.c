#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <fcntl.h> // For O_CREAT

int main() {
    // Create named semaphores for synchronization
    sem_t *sem_p1 = sem_open("/sem_p1", O_CREAT, 0644, 1); // Initially unlocked for P1
    sem_t *sem_p2 = sem_open("/sem_p2", O_CREAT, 0644, 0);
    sem_t *sem_p3 = sem_open("/sem_p3", O_CREAT, 0644, 0);
    sem_t *sem_p4 = sem_open("/sem_p4", O_CREAT, 0644, 0);
    sem_t *sem_p5 = sem_open("/sem_p5", O_CREAT, 0644, 0);

    pid_t pid1, pid2, pid3, pid4, pid5;

    // Create first child (P1)
    pid1 = fork();
    if (pid1 == 0) {
        sem_wait(sem_p1); // Wait for permission
        fprintf(stderr, "Coronavirus ");
        sem_post(sem_p2); // Signal P2
        exit(0);
    }

    // Create second child (P2)
    pid2 = fork();
    if (pid2 == 0) {
        sem_wait(sem_p2); // Wait for permission
        fprintf(stderr, "WHO: ");
        sem_post(sem_p3); // Signal P3
        exit(0);
    }

    // Create third child (P3)
    pid3 = fork();
    if (pid3 == 0) {
        sem_wait(sem_p3); // Wait for permission
        fprintf(stderr, "COVID-19 ");
        sem_post(sem_p4); // Signal P4
        exit(0);
    }

    // Create fourth child (P4)
    pid4 = fork();
    if (pid4 == 0) {
        sem_wait(sem_p4); // Wait for permission
        fprintf(stderr, "disease ");
        sem_post(sem_p5); // Signal P5
        exit(0);
    }

    // Create fifth child (P5)
    pid5 = fork();
    if (pid5 == 0) {
        sem_wait(sem_p5); // Wait for permission
        fprintf(stderr, "pandemic.\n");
        exit(0);
    }

    // Parent process waits for all children to complete
    for (int i = 0; i < 5; i++) {
        wait(NULL);
    }

    // Close and unlink semaphores
    sem_close(sem_p1);
    sem_close(sem_p2);
    sem_close(sem_p3);
    sem_close(sem_p4);
    sem_close(sem_p5);
    sem_unlink("/sem_p1");
    sem_unlink("/sem_p2");
    sem_unlink("/sem_p3");
    sem_unlink("/sem_p4");
    sem_unlink("/sem_p5");

    return 0;
}
