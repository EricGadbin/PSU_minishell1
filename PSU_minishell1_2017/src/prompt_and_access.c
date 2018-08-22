/*
** EPITECH PROJECT, 2018
** Project mysh
** File description:
** prompt_and_access
*/

#include "main.h"

char *bootmalloc(char *buff, char **boot)
{
	int k = 0;
	int j = 0;
	int a = 0;

	boot[j] = my_calloc(my_strlen(buff));
	buff = cleaner(buff);
	while (buff[a] != '\0') {
		if (buff[a] == ' ') {
			boot[j][k] = '\0';
			k = 0;
			j++;
			a++;
			boot[j] = my_calloc(my_strlen(buff));
		}
		boot[j][k] = buff[a];
		a++;
		k++;
	}
	boot[j][k] = '\0';
	return (buff);
}

int check_access(char *finalbuff, char *buff, char *str, char **boot)
{
	int i = 0;
	int a = 0;

	finalbuff = my_strcat(buff, str, &i);
	while (access(finalbuff, F_OK) != 0 && finalbuff != NULL) {
		finalbuff = my_strcat(buff, str, &i);
	}
	a += my_strcmp(buff, "exit");
	a += my_strcmp(buff, "cd");
	a += my_strcmp(buff, "env");
	a += my_strcmp(buff, "setenv");
	if (a > 0)
		return (0);
	else if (finalbuff == NULL) {
		my_putstr(buff);
		my_putstr(": Command not found.\n");
	} else {
		boot[0] = finalbuff;
	}
	return (0);
}
char *create(char *buff, char *str, char **boot)
{
	char *finalbuff = '\0';
	int a = 0;

	buff = bootmalloc(buff, boot);

	while (buff[a] != '\0') {
		if (buff[a] == ' ')
			break;
		a++;
	}
	buff[a] = '\0';
	if (access(buff, F_OK) != 0)
		check_access(finalbuff, buff, str, boot);
	else {
		boot[0] = buff;
	}
	return (buff);
}

void my_firstline(char **envp)
{
	int i = 0;
	char *str = findenv(envp, "PWD=");
	char str2[] = "/home/";

	while (i < 6) {
		if (str[i] != str2[i]) {
			i = 0;
			break;
		}
		i++;
	}
	if (i != 0) {
		while (str[i] && str[i] != '/')
			i++;
		str += i;
		write(1, "~", 1);
	}
	while (str[i++]);
	write(1, str, i);
	write(1, "> ", 2);
}
