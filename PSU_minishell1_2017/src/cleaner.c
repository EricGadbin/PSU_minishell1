/*
** EPITECH PROJECT, 2018
** Project mysh
** File description:
** cleaner
*/

#include "main.h"

int my_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int my_clean(char *str, char *result, int *i, int *j)
{
	if (str[*i] != ' ' && str[*i] != '\t') {
		result[*j] = str[*i];
		if (str[(*i)] == '\0')
			result[*j] = '\0';
	}
	else if (str[*i] == ' ' || str[*i] == '\t') {
		while (str[*i] == ' ' || str[*i] == '\t')
			(*i)++;
		if (str[*i] == '\0') {
			result[*j] = '\0';
			return (1);
		} else {
			result[*j] = ' ';
			(*i)--;
		}
	}
	return (0);
}

char *cleaner(char *str)
{
	int i = 0;
	int j = 0;
	char *result = malloc(sizeof(char) * (my_strlen(str) + 1));

	if (str[0] == ' ' || str[0] == '\t') {
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] == '\0')
			result[j] = '\0';
	}
	while (str[i] != '\0') {
		if (my_clean(str, result, &i, &j) == 1) {
			j++;
			result[j] = '\0';
			return (result);
		}
		i++;
		j++;
	}
	result[j] = '\0';
	return (result);
}
