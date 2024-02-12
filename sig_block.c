#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handler(int signum) {
    printf("Signal %d received.\n", signum);
}

int main() {
    // Registering a signal handler for SIGINT (Ctrl+C)
    signal(SIGKILL, handler);

    // Blocking SIGINT
    sigset_t new_mask, old_mask;
    sigemptyset(&new_mask);
    sigaddset(&new_mask, SIGKILL);

    if (sigprocmask(SIG_BLOCK, &new_mask, &old_mask) < 0) {
        perror("sigprocmask");
        exit(EXIT_FAILURE);
    }

    printf("SIGINT is blocked. You can't interrupt with Ctrl+C now.\n");

    // Wait for a few seconds to simulate a long-running task
    sleep(5);

    printf("Unblocking SIGINT. You can now interrupt with Ctrl+C.\n");

    // Unblocking SIGINT
    if (sigprocmask(SIG_SETMASK, &old_mask, NULL) < 0) {
        perror("sigprocmask");
        exit(EXIT_FAILURE);
    }

    // Wait indefinitely
    while (1) {
        sleep(1);
    }

    return 0;
}

