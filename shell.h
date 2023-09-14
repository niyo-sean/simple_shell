#ifndef SHELL_H
#define  SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>
#include <stdarg.h>
#include <stdlib.h>
#include <errno.h>
#include <dirent.h>


void niyo_play(const char *message, const char *color);
void dis_prompt(void);
void env_to_path(const char *path);
void read_command(char *command, size_t size);
void exec_command(const char *command);






#endif /*My shell header  Done by niyo-sean */
