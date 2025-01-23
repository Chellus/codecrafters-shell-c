#include <stdio.h>
#include <string.h>

int get_command(char[]);

int main() {
  
  
    while (1) {// Flush after every printf
        setbuf(stdout, NULL);
  
        // Uncomment this block to pass the first stage
        printf("$ ");
  
        // Wait for user input
        char input[100];
        fgets(input, 100, stdin);
  
        // remove the trailing newline
        input[strlen(input) - 1] = '\0';

        int command = get_command(input);

        if (command == -1)
            printf("%s: command not found\n", input);
        
        if (command == 0)
            break;
    
    }
  
    return 0;
}

int get_command(char input[]) {
    // if the command equals to exit 0
    if (strcmp(input, "exit 0") == 0) {
        return 0;
    }

    // if not a valid command, return -1
    return -1;
}
