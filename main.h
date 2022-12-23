#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>

int _strcmp(const char *s1, const char *s2);
char *_which(const char *command);
char *read_line(void);
void loop(void);
char **split_line(char *str);
int start_process(char **args);
int cd(char **args);
int exit_process(char **args);
int execute_line(char **args);
int pipe_sh(char *argv[]);
char *_strtok(char *str, const char *delim);
int set_env(char **args);
int unset_env(char **args);
int and_sh(char **args);
int or_sh(char **args);
int var_rep(char **args);
int _setenv(const char *name, const char *value, int overwrite);
int _putenv(char *string);
char *_getenv(const char *name);
char *_strcpy(char *dst, const char *src);
int _atoi(const char *str);
int _strlen(const char *str);
char *_strcat(char *dest, const char *src);
char *_strdup(const char *src);
int _unsetenv(const char *name);
int _putchar(int c);
void write_int(int num);

#endif
