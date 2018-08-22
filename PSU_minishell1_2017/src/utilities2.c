/*
** EPITECH PROJECT, 2018
** Project mysh
** File description:
** Utilities2
*/

#include "main.h"

int my_putstr(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		write(1, &str[i], 1);
		i++;
	}
	return (0);
}

int my_strcmp(char *boot, char *check)
{
	int i = 0;

	if (boot[i] == '\0')
		return (0);
	while (boot[i] != '\0') {
		if (boot[i] != check[i])
			return (0);
		i++;
	}
	return (1);
}

int nbr_maker(char *str, int i)
{
	int nb = 0;

	while (str[i] >= '0' && str[i] <= '9') {
		nb = nb * 10;
		nb = nb + str[i] - '0';
		i++;
	}
	return (nb);
}

int my_getnbr(char *str)
{
	int nb = 0;
	int j = 0;
	int i = 0;

	while (str[i] != '\0' && nb == 0) {
		if (str[i] == '-')
			j++;
		if (str[i] >= '0' && str[i] <= '9')
			nb = nbr_maker(str, i);
		i++;
	}
	if (j % 2 == 1)
		nb = - nb;
	return (nb);
}

void update(char **envp, char *pwd, char *old_pwd)
{
	update_env(envp, pwd, "PWD=");
	update_envold(envp, old_pwd, "OLDPWD=");
}
