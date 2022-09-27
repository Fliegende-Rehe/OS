#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

char *shell_read_line(void);
char **shell_split(char *line);
int shell_execute(char **args);

int main() {
    char *line;
    char **args;
    int status;

    do {
        printf("> ");
        line = shell_read_line();
        args = shell_split(line);
        status = shell_execute(args);

        free(line);
        free(args);
    } while (status);
    return EXIT_SUCCESS;
}

char *shell_read_line(void) {
    char *line = NULL;
    size_t bufsize = 0;
    if (getline(&line, &bufsize, stdin) != -1) return line;
    if (!feof(stdin)) {
        perror("readline");
        exit(EXIT_FAILURE);
    } else exit(EXIT_SUCCESS);
}

char **shell_split(char *line) {
    const int token_size = 64;
    const char token_delim[] = " \t\r\n\a";
    int bufsize = token_size, position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token = strtok(line, token_delim);

    if (!tokens)
        exit(EXIT_FAILURE);

    tokens[position] = token;
    for (; token != NULL; position++) {
        if (position >= bufsize) {
            bufsize += token_size;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens)
                exit(EXIT_FAILURE);
        }
        token = strtok(NULL, token_delim);
        tokens[position] = token;
    }
    tokens[position] = NULL;
    return tokens;
}

int shell_launch(char **args);
int shell_cd(char **args);
char *command_list[];
int (*commands[])(char **);
int shell_num_builtins();

int shell_launch(char **args) {
    int status;
    pid_t pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1)
            perror("shell");
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("shell");
    } else {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return 1;
}

char *command_list[] = {
    "cd"
};

int (*commands[])(char **) = {
    &shell_cd
};

int shell_num_builtins() {
    return sizeof(command_list) / sizeof(char *);
}

int shell_execute(char **args) {
    if (args[0] == NULL) return 1;
    for (int i = 0; i < shell_num_builtins(); i++) {
        if (strcmp(args[0], command_list[i]) == 0)
            return (*commands[i])(args);
    }
    return shell_launch(args);
}

int shell_cd(char **args) {
    if (args[1] != NULL) {
        fprintf(stderr, "shell: expected argument to \"cd\"\n");
        if (chdir(args[1]) != 0)
            perror("shell");
    } else fprintf(stderr, "shell: expected argument to \"cd\"\n");
    return 1;
}