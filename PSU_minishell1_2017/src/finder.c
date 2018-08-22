/*
** EPITECH PROJECT, 2018
** Project mysh
** File description:
** finder
*/

#include "main.h"

void findenv2(char **envp, char *str, char *result, int *a)
{
	int i = 0;
	int j = 0;

	while (envp[*a][i] == str[i])
		i++;
	if (str[i] == '\0') {
		while (envp[*a][i] != '\0') {
			result[j] = envp[*a][i];
			i++;
			j++;
		}
	} else
		i = 0;
	result[i] = '\0';
}

char *findenv(char **envp, char *str)
{
	int a = 0;
	char *result = malloc(sizeof(char) * 300);

	while (envp[a] != NULL) {
		if (envp[a][0] == str[0] && envp[a][3] == str[3]) {
			findenv2(envp, str, result, &a);
		}
		a++;
	}
	return (result);
}

char *pathfinder(char **envp, char *str)
{
	int a = 0;

	while (envp[a] != NULL) {
		if (envp[a][0] == 'P' && envp[a][1] == 'A' && \
		envp[a][2] == 'T' && envp[a][3] == 'H' && envp[a][4] == '=')
			str = (envp[a]);
		a++;
	}
	return (str);
}

int spacelen(char *str)
{
	int i = 0;
	int j = 0;

	while (str[i] != '\0') {
		if (str[i] == ' ')
			j++;
		i++;
	}
	return (j);
}
