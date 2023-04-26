#ifndef _MYSHELL_H_
#define _MYSHELL_H_

/* all libreries will be needed */
#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<limits.h>
#include <fcntl.h>
#include<errno.h>

/*here define read/write for buffers */
#define READ_BUFFER_SIZE 1024
#define WRITE_BUFFER_SIZE 1024
#define BUFFER_FLUSH -1

/*define for  command chaining */
#define CMD_NORM   0
#define CMD_OR     1
#define CMD_AND    2
#define CMD_CHAIN  3

/* define for convert_number */
#define CONVERT_LOWERCASE   1
#define CONVERT_UNSIGNED    2

/*define 1 if using system getline */
#define USE_GETLINE 0
#define USE_STRTOK  0

#define HIST_FILE  ".mysimple_shell_history"
#define HIST_MAX   4096

extern char **environ;

/**
 * struct liststr - singly linked list
 * @n : the number field
 * @str : a string
 * @next : points to the next node
 */
typedef struct liststr
{
	int n;
	char *str;
	struct liststr *next;
} list_t;
/**
 * struct passinfo - contains pseudo-arguments
 * @arg : a string generated from getline
 * @argv : an array of strings
 * @path: a string path
 * @argc : the argument count
 * @line_count: the error count
 * @err_num: the error code for exits
 * @linecount_flag: if on count this
 * @fname : the program filename
 * @env : linked list local copy of environoment
 * @environ: custom modified copy of
 * @history: the history node
 * @alias : the alias node
 * @env_changed: on if environ was changed
 * @status: the return status of the last exec'd command
 * @cmd_buf:address of pointer to cmd_buff,
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd : the fd from which to read line input
 * @histcount : the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd */
	int cmd_buf_type; /* for CMD_type || , &&, ;*/
	int readfd;
	int histcount;
} info_t;
#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}
/**
 *struct builtin - contains a builtin string
 *@type: the builtin command flag
 *@func : the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

/* declare for_exit.c */
int _putchar(char c);
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* declare for_shell_loops.c */
int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

/* declare for_parse.c */
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

/* declare for_lphsh.c */
int lphsh(char **);

/* declare for_error.c */
void _eputs(char *);
int  _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/*declare for_strng.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* declare for_string01.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
/*int _putchar(char);*/

/*declare for_token */
char **strtow(char *, char *);
char **strtow02(char *, char);

/* declare for_lloc.c */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* declare for_address.c */
int bfree(void **);

/*declare for_strng-intgr.c */
int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

/* declare for_error01.c */
int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* declare for_bltn.c */
int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);

/*declare for_bltn01.c */
int _myhistory(info_t *);
int _myalias(info_t *);

/* declare for gtln.c */
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

/*declare for_gtnf.c */
/*void clear_info(info_t *, const char *);*/
void set_info(info_t *, char **);
void free_info(info_t *, int);

/* declare for_envrn.c */
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);

/* declera for_gtnv.c */
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

/* declare for_hstry.c */
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);

/* declare for_lst.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

/* declare for_lst01.c */
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/* declare for_vrs.c */
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

#endif /* a NIYIBIZI Bonaventure codes */

