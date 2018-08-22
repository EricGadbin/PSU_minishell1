/*
** EPITECH PROJECT, 2018
** Project mysh
** File description:
** env
*/

#include "main.h"

int my_tablen(char **str)
{
	int i = 0;

	while (str[i] != NULL)
		i++;
	return (i);
}

char *my_concat(char *str, char *str2)
{
	int i = 0;
	int j = 0;
	int a = (my_strlen(str) + my_strlen(str2) + 300);
	char *result = malloc(sizeof(char) * (a + 1));

	while (str[i] != '\0') {
		result[i] = str[i];
		i++;
	}
	while (str2[j] != '\0') {
		result[i] = str2[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}

int check_same(char **envp, char *new_env)
{
	int i = 0;
	int j = 0;
	int a = (my_strlen(new_env) - 1);
	int b = 0;
	while (envp[i] != NULL) {
		while (envp[i][j] != '=') {
			envp[i][j] == new_env[j] ? b++ : b;
			j++;
		}
		if (a == b) {
			return (i);
		} else {
			b = 0;
			j = 0;
			i++;
		}
	}
	return (0);
}

void check_nullcopy(char **envp, char **new_env, int *i)
{
	if (envp[*i] != NULL)
		new_env[*i] = my_calloc(my_strlen(envp[*i]));

}

char **copy_env(char **envp)
{
	int i = 0;
	int j = 0;

	char **new_env = malloc(sizeof(char *) * (my_tablen(envp) + 1));

	new_env[i] = malloc(sizeof(char *) * my_strlen(envp[i]));
	while (envp[i] != NULL) {
		if (envp[i][j] == '\0') {
			j = 0;
			i++;
			check_nullcopy(envp, new_env, &i);
		}
		if (envp[i] != NULL)
			new_env[i][j] = envp[i][j];
		j++;
	}
	return (new_env);
}
