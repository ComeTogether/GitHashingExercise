#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// Counter for the number of times SIGINT is caught
int sigint_count = 0;

// Custom signal handler function for SIGINT
void custom_sigint_handler(int signo) {
    if (signo == SIGINT) {
        printf("\nCustom SIGINT handler: Signal %d (SIGINT) caught!\n", signo);

        // Increment the count
        sigint_count++;

        // Check if SIGINT has been caught twice
        if (sigint_count == 2) {
            // Restore the default behavior for SIGINT
            signal(SIGINT, SIG_DFL);
            printf("Restored default behavior for SIGINT.\n");
        }
    }
}

int main() {
    // Register the custom signal handler for SIGINT
    if (signal(SIGINT, custom_sigint_handler) == SIG_ERR) {
        fprintf(stderr, "Error registering signal handler for SIGINT\n");
        exit(EXIT_FAILURE);
    }

    printf("Press Ctrl+C to send a SIGINT signal.\n");

    // Infinite loop to keep the program running
    while (1) {
        // The program will be terminated by the signal handler
    }
}