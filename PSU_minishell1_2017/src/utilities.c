/*
** EPITECH PROJECT, 2018
** Project mysh
** File description:
** Utilities.
*/

#include "main.h"

char *my_calloc(int size)
{
	char *str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	for (int i = 0; i != size; i++)
		str[i] = '0';
	str[size] = '\0';
	return (str);
}

char **my_calloc2d(int size, char **str2)
{
	char **str = malloc(sizeof(char *) * (size + 1));
	if (str == NULL)
		return (NULL);
	for (int i = 0; i != size; i++)
		str[i] = my_calloc(my_strlen(str2[i]));
	str[size] = NULL;
	return (str);

}

int my_strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

int my_strcat2(char *buff, char *result, int j, int k)
{
	result[j] = '/';
	j++;
	while (buff[k] != '\0') {
		result[j] = buff[k];
		k++;
		j++;
	}
	result[j] = '\0';
	return (0);
}

char *my_strcat(char *buff, char *str, int * i)
{
	int j = 0;
	int k = 0;
	int len = (my_strlen(buff) + my_strlen(str));
	char *result = malloc(sizeof(char) * (len));

	if (str[*i] == '\0') {
		return (NULL);
	}
	while (str[*i] != '/' && str[*i] != '\0')
		(*i)++;
	while (str[*i] != ':' && str[*i] != '\0') {
		result[j] = str[*i];
		(*i)++;
		j++;
	}
	my_strcat2(buff, result, j, k);
	return (result);
}
