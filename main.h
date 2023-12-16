#ifndef MAIN_H
#define MAIN_H

#include <math.h>
#include <errno.h>
#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

#define OR_FLAG 1
#define NEG_ONE -1
#define RED_FLAG 0
#define AND_FLAG 2
#define CHAIN_FLAG 3
#define USE_STRTOK 0
#define USE_GETLINE 0
#define MAX_INPUT_SIZE 1024
#define MAX_ARG_COUNT 32
#define MAX_PATH_LENGTH 1024
#define MAX_WORD_COUNT 120
#define BAS_CHANGE_LOWER 1
#define BAS_CHANGE_UNSIG 2
#define BUFFER_SIZE_READ 1024
#define BUFFER_SIZE_WRITE 1024

extern char **environ;

void _exec(char *input);
void _exec_args(char *cmd);
void child_exit(char **argv);
int arg_array(char *cmd, char **argv);

int existing_cmd(const char *cmd);
int _strlen(const char *s);
void _strncat(char *dest, const char *src, size_t n);

int _strcmp(char *s1, char *s2);
void print_env(void);
const char *_getenv(const char *name);
const char *_strchr(const char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(const char *s);
char *_strcpy(char *dest, const char *src);
void _memcpy(void *dest, const void *src, size_t n);
int make_fullpath(char *cmd, char *pathcpy, char *fullpath, int *fullpath_len);

void _exec_cmd(char *fullpath, char **argv);

void trial_mode(void);
void batch_mode(char *filename);
int main(void);
void remove_str(char *input);

#endif
