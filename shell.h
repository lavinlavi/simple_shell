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

/**
 * struct root -  central structure for the shelll
 * @buf: pointer to input
 * @commands: pointer to array of strings of comamnds.
 * @paths: a pointer to array of strings of paths.
 * @sig: used to control logic
 * @inter_shell: used to ontrol logic
 * @path: pointer to path environment variable.
 */

typedef struct root
{
	char *buf;
	char **commands;
	char **paths;
	char *path;
	int sig;
	int inter_shell;
	int n_free;
} rootkit;
void n_inter_shell(rootkit *kit, char **av);
size_t get_token_size(char *buf);
void init_struct(rootkit *kit);
extern char **environ;
char *find_path();
char **parse_input(char *buf);
char *find_command(char **path, char *o_command);
char *str_maker(char *str1, char *str2);
int _strlen(char *s);
char *_strchr(char *s, char c);
char *_memset(char *s, char b, unsigned int n);
void free_mem(char *ptr);
void free_dmem(char **ptr);
void prompt_user(void);
int shell_loop(rootkit *kit, char **av);
void inter_shell(rootkit *kit, char **av);
void cleanup(void);
void free_struct(rootkit *kit);
#endif

