/*
** EPITECH PROJECT, 2018
** Project mysh
** File description:
** fork_and_exit
*/

#include "main.h"

int my_fork(char **envp, char **boot, char *buff)
{
	int i = 0;
	int j = 0;
	char *path = malloc(sizeof(char) * (my_strlen(boot[0]) + 1));

	while (boot[0][i] != '\0') {
		path[i] = boot[0][i];
		i++;
	}
	path[i] = '\0';
	while (buff[j] != ' ' && buff[j] != '\0') {
		boot[0][j] = buff[j];
		j++;
	}
	boot[0][j] = '\0';
	execve(path, boot, envp);
	return (0);
}

char ** prompt(char **boot, char **envp, char *buff)
{
	int stop = 0;
	int cpt = 0;

	if (fork() == 0) {
		my_fork(envp, boot, buff);
		exit (0);
	}
	wait(&stop);
	cpt = WTERMSIG(stop);
	if (cpt == 11)
		write(2, "Segmentation fault\n", 19);
	return (boot);
}

int diffexit(char **boot)
{
	int i = 0;
	int a = 0;

	while (boot[1][i] != '\0') {
		if (boot[1][i] > '0' &&  boot[1][i] < '9')
			a = 1;
		if ((boot[1][i] < '0' ||  boot[1][i] > '9') && a == 1) {
			my_putstr("exit: Badly formed number.\n");
			return (1);
		}
		else if ((boot[1][i] < '0' ||  boot[1][i] > '9') && a != 1) {
			my_putstr("exit: Expression Syntax.\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int check_exit(char **boot)
{
	int n = 0;
	int i = 0;

	if (my_strcmp(boot[0], "exit")) {
		if (boot[1] != NULL) {
			i = diffexit(boot);
			n = my_getnbr(boot[1]);
		}
		if (i == 1)
			return (0);
		if (boot[2] != NULL) {
			my_putstr("exit: Expression Syntax.\n");
			return (0);
		}
		my_putstr("exit\n");
		exit(n);
	}
	return (1);
}
