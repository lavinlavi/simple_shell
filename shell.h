#ifndef __MAIN__
#define __MAIN__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>

extern char **environ;

/* path finder */
char *find_path();

/* parser */
char **parse_command(char *input, char *command);
size_t get_token_size(char *buf);
char *get_command(char *path, char *buf);

/* memory tools */
void p_free(char **ptr);
void _memset(char **s, size_t n);
void t_free(char *s, char *p);

/* signal handler */
/* exit handler */
/* commandeer */

/* loop */
void inter_shell(char **av);
void prompt_user(void);
void n_inter_shell(char **av);

/* exec */
void execution(char **argv);

/* String manipulators*/
char *_strdup(char *s1);
char *str_maker(char *s1, char *s2);
int _strlen(char *s);
void _strcpy(char *s1, char *s2);

#endif

