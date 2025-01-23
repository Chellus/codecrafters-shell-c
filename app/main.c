#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define EXIT 0
#define ECHO 1

#define INVALID_CMD -1

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
        char* input_copy = (char*)malloc(strlen(input + 1) * sizeof(char));
        strcpy(input_copy, input);
        int command = get_command(input);
        int should_break = 0;

        switch (command)
        {
        case EXIT:
            should_break = 1;    
            break;
        case ECHO:
            printf("%s\n", input + 5);
            break;
        default:
            printf("%s: command not found\n", input_copy);
            break;
        }

        free(input_copy);

        if (should_break)
            break;
    
    }
  
    return 0;
}

int get_command(char input[]) {
    // extract the command using strtok
    char* command = strtok(input, " ");

    // if the command equals to exit 0
    if (strcmp(command, "exit") == 0) 
        return EXIT;

    if (strcmp(command, "echo") == 0)
        return ECHO; 

    // if not a valid command, return -1
    return -1;
}
