/*
** EPITECH PROJECT, 2018
** Project mysh
** File description:
** check_setenv
*/

#include "main.h"

int env_noarg(char **envp, char **boot)
{
	int a = 0;

	if (my_strcmp(boot[0], "setenv") == 1  && boot[1] == NULL) {
		while (envp[a] != NULL) {
			my_putstr(envp[a]);
			my_putstr("\n");
			a++;
		}
	}
	return (0);
}

void create_new_env(char **new_env, char **envp, int *i, int *j)
{
	if (envp[*i][*j] == '\0') {
		*j = 0;
		(*i)++;
		if (envp[*i] != NULL)
			new_env[*i] = my_calloc(my_strlen(envp[*i]));
	}
	if (envp[*i] != NULL) {
		new_env[*i][*j] = envp[*i][*j];
		(*j)++;
	}
}

void concat_new_env(char **new_env, char **boot, int *i, int *o)
{
	if (*o > 0) {
		new_env[*o] = my_concat(boot[1], "=");
		if (boot[2] != NULL)
			new_env[*o] = my_concat(new_env[*o], boot[2]);
	} else {
		new_env[*i] = my_concat(boot[1], "=");
		if (boot[2] != NULL)
			new_env[*i] = my_concat(new_env[*i], boot[2]);
	}
}

char **env_witharg(char **envp, char **boot)
{
	int i = 0;
	int j = 0;
	int o = 0;
	char **new_env = malloc(sizeof(char *) * (my_tablen(envp) + 2));
	char *str = malloc(sizeof(char) * (300 + 2));
	new_env[i] = malloc(sizeof(char *) * (my_strlen(envp[i]) + 300));
	if (my_strcmp(boot[0], "setenv") == 1  && boot[1] != '\0') {
		while (envp[i] != NULL)
			create_new_env(new_env, envp, &i, &j);
		str = my_concat(boot[1], "=");
		o = check_same(envp, str);
		concat_new_env(new_env, boot, &i, &o);
		return (new_env);
	}
	return (envp);
}

char **check_setenv(char **envp, char **boot)
{
	env_noarg(envp, boot);
	envp = env_witharg(envp, boot);
	return (envp);
}
