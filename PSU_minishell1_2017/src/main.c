/*
** EPITECH PROJECT, 2018
** Project mysh
** File description:
** Main file.
*/

#include "main.h"

int check_env(char **envp, char **boot)
{
	int a = 0;

	if (my_strcmp(boot[0], "env") == 1) {
		while (envp[a] != NULL) {
			my_putstr(envp[a]);
			my_putstr("\n");
			a++;
		}
	}
	return (0);
}

int check(char **envp, char **boot)
{
	int i = 0;

	i = check_exit(boot);
	i += check_cd(envp, boot);
	i += check_env(envp, boot);

	return (0);
}

char **program(char **boot, char *str, char *buff, char **envp)
{
	int a = 0;

	a = spacelen(buff);
	boot = malloc(sizeof(char *) * (a + 2));
	for (int i = 0; i < a + 2; i += 1)
		boot[i] = NULL;
	str = pathfinder(envp, str);
	buff = create(buff, str, boot);
	envp = check_setenv(envp, boot);
	check(envp, boot);
	boot = prompt(boot, envp, buff);
	return (envp);
}

int main(int argc, char *argv[], char *env[])
{
	char **boot = '\0';
	char *str = '\0';
	char **envp = copy_env(env);
	char *buff = malloc(sizeof(char) * 300);
	int s = 0;

	(void)argc;
	(void)argv;
	while (!s) {
		if (isatty(0)) {
			my_firstline(envp);
		}
		buff = get_next_line(0);
		if (buff)
			envp = program(boot, str, buff, envp);
		else
			s = !s;
	}
	return (0);
}
