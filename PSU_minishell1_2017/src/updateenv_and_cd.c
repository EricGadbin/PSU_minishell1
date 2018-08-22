/*
** EPITECH PROJECT, 2018
** Project mysh
** File description:
** update_and_cd
*/

#include "main.h"

void end_update(char *pwd, char **envp, int *a, int *i)
{
	int j = 0;

	while (pwd[j] !=  '\0') {
		envp[*i][*a] = pwd[j];
		j++;
		(*a)++;
	}
	envp[*i][*a] = '\0';
}

int update_env(char **envp, char *pwd, char *str)
{
	int i = 0;
	int a = (my_strlen(str));

	while (envp[i] != NULL && pwd != NULL) {
		if (envp[i][0] == str[0] && envp[i][3] == str[3]) {
			end_update(pwd, envp, &a, &i);
			return (0);
		}
		i++;
	}
	return (0);
}

int update_envold(char **envp, char *pwd, char *str)
{
	int i = 0;
	int a = (my_strlen(str));

	while (envp[i] != NULL && pwd != NULL) {
		if (envp[i][0] == str[0] && envp[i][6] == str[6]) {
			end_update(pwd, envp, &a, &i);
			return (0);
		}
		i++;
	}
	return (0);
}

int check_cd2(char **boot, char **pwd, char **old_pwd)
{
	if (boot[1][0] == '-' && boot[1][1] == '\0') {
		*old_pwd = getcwd(NULL, 255);
		chdir(*pwd);
		return (1);
	}
	if (boot[1] != NULL) {
		*old_pwd = getcwd(NULL, 255);
		if (chdir(boot[1])) {
			my_putstr(boot[1]);
			my_putstr(": No such file or directory.\n");
			return (0);
		}
		*pwd = getcwd(NULL, 255);
		return (1);
	}
	return (0);
}

int check_cd(char **envp, char **boot)
{
	char *cd = '\0';
	static char *pwd;
	static char *old_pwd;

	if (my_strcmp(boot[0], "cd")) {
		if (boot[1] == NULL || (boot[1][0] == '~' && \
		boot[1][1] == '\0') || (boot[1][0] == '-' && \
		boot[1][1] == '-' && boot[1][2] == '\0')) {
			pwd = getcwd(NULL, 255);
			cd = findenv(envp, "HOME=");
			chdir(cd);
			update_env(envp, cd, "PWD=");
			update_envold(envp, pwd, "OLDPWD=");
			return (0);
		}
		if (check_cd2(boot, &pwd, &old_pwd) == 1)
			update(envp, pwd, old_pwd);
	}
	pwd = old_pwd;
	return (0);
}
