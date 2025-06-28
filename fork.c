#include <stdio.h>    // for printf
#include <unistd.h>   // for fork, getpid
#include <sys/types.h> // for pid_t
#include <sys/wait.h> // for wait

int main() {
    pid_t pid;

    printf("Before fork: only one process. PID: %d\n", getpid());

    pid = fork();  // Create a new process

    if (pid < 0) {
        // Fork failed
        fprintf(stderr, "Fork failed!\n");
        return 1;
    }
    else if (pid == 0) {
        // Child process
        printf("Hello from the child process! PID: %d, Parent PID: %d\n", getpid(), getppid());
    }
    else {
        // Parent process
        printf("Hello from the parent process! Child PID: %d, My PID: %d\n", pid, getpid());

        // Wait for child to finish
        wait(NULL);
        printf("Child has finished. Parent exiting.\n");
    }

    // This runs in both processes
    printf("This line prints from both processes. PID: %d\n", getpid());

    return 0;
}
