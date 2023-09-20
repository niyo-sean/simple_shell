
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    char *current_directory = NULL;
    size_t size = pathconf(".", _PC_PATH_MAX);

    if ((current_directory = (char *)malloc((size_t)size)) != NULL) {
        if (getcwd(current_directory, (size_t)size) != NULL) {
            printf("Current working directory: %s\n", current_directory);
        } else {
            perror("getcwd");
        }
        free(current_directory);
    } else {
        perror("malloc");
    }

    return 0;
}
