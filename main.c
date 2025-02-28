#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Arbitrary constants to limit input sizes
# define MAX_INPUT 1024
# define MAX_ARGS 50

void run_shell_loop();
void execute_command(char *input);

int main() {
    run_shell_loop();
    return 0;
}

void run_shell_loop() {
    char input[MAX_INPUT];
    while (true) {
        printf("shell> ");
        if (fgets(input, MAX_INPUT, stdin) == NULL) {
            break;
        }

        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            break;
        }

        execute_command(input);
    }
}

void execute_command(char *input) {
}
