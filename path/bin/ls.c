#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

int custom_ls(int argc, char *argv[]);

int main(int argc, char *argv[]) {
    return custom_ls(argc, argv);
}

int custom_ls(int argc, char *argv[]) {
    /* Check if a directory is provided as an argument, if not, use the current directory.*/ 
    const char *directory = (argc > 1) ? argv[1] : ".";

    struct dirent *entry;

    /*Open the directory*/ 
    DIR *dir = opendir(directory);
    if (dir == NULL) {
        fprintf(stderr, "Error opening directory '%s': %s\n", directory, strerror(errno));

        return 1;
    }

    /* Read and print directory contents */ 
    while ((entry = readdir(dir))) {
        printf("%s\n", entry->d_name);
    }

    /*Close the directory*/ 
    closedir(dir);

    return 0;
}
