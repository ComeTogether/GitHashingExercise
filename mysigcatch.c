#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// Signal handler function
void sigint_handler(int signo) {
    if (signo == SIGINT) {
        printf("\nSIGINT signal caught!\n");
        exit(EXIT_SUCCESS);
    }
}

int main() {
    // Register the signal handler for SIGINT
    if (signal(SIGINT, sigint_handler) == SIG_ERR) {
        fprintf(stderr, "Error registering signal handler for SIGINT\n");
        exit(EXIT_FAILURE);
    }

    printf("Press Ctrl+C to send a SIGINT signal.\n");

    // Infinite loop to keep the program running
    while (1) {
        // The program will be terminated by the signal handler
    }

    return 0;  // This line is not reached due to the infinite loop
}