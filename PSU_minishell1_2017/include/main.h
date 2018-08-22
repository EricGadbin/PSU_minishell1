/*
** EPITECH PROJECT, 2018
** Project mysh
** File description:
** Header file
*/

#ifndef MAIN_H_
	#define MAIN_H_
	#include <stdlib.h>
	#include <stdio.h>
	#include <unistd.h>
	#include <string.h>
	#include <sys/types.h>
	#include <sys/wait.h>

	char *my_calloc(int);
	int my_putstr(char *str);
	int my_strlen(char *);
	int my_strcat2(char *buff, char *, int, int);
	char *my_strcat(char *, char *, int *);
	char *get_next_line(int);
	char *findenv(char **, char *);
	int my_strcmp(char *, char *);
	char *cleaner(char *);
	int my_getnbr(char *);
	char ** prompt(char **, char **, char *);
	char *create(char *, char *, char **);
	char *pathfinder(char **, char *);
	int spacelen(char *);
	void my_firstline(char **);
	int check_cd(char **, char **);
	int check_exit(char **);
	char **my_calloc2d(int, char **);
	char **check_setenv(char **, char **);
	int my_tablen(char **);
	int check_same(char **, char *);
	char *my_concat(char *, char *);
	char **copy_env(char **);
	int update_env(char **, char *, char *);
	int update_envold(char **, char *, char *);
	void update(char **, char *, char *);

#endif
