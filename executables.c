/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executables.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnikzad <fnikzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:21:56 by fnikzad           #+#    #+#             */
/*   Updated: 2024/03/01 18:42:06 by fnikzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_exit(char **args);
int	execute_pwd(char **args);
int	execute_echo(char **args);
int	execute_cd(char **args);

int	valid_command(char **args, char **ev)
{
	if (ft_strcmp(args[0], "cd") == 0)
		return (execute_cd(args));
	else if (ft_strcmp(args[0], "pwd") == 0)
		return (execute_pwd(args));
	else if (ft_strcmp(args[0], "echo") == 0)
		return (execute_echo(args));
	else if (ft_strcmp(args[0], "export") == 0)
		return (ex_export(args, ev));
	else if (ft_strcmp(args[0], "unset") == 0)
		return (UNSET);
	else if (ft_strcmp(args[0], "env") == 0)
		return (execute_env(args, ev));
	else if (ft_strcmp(args[0], "exit") == 0)
		return (execute_exit(args));
	return (-1);
}

int	execute_env(char **args, char **ev)
{
	if (!g_env)
		get_ev(ev);
	ev = g_env;
	int i = 0;
	if (ft_strcmp(args[0], "env") == 0)
	{
		while (ev[i])
		{
			printf("%s\n", ev[i++]);
		}
	}
	return (0);
}

// int	valid_command(char **args)
// {
// 	if (ft_strcmp(args[0], "cd") == 0 || ft_strcmp(args[0], "pwd") == 0
// 		|| ft_strcmp(args[0], "echo") == 0 || ft_strcmp(args[0], "export") == 0)
//		return 1;
//	if (ft_strcmp(args[0], "unset") == 0 || ft_strcmp(args[0], "env") == 0 ||
// 	ft_strcmp(args[0], "exit") == 0 || ft_strcmp(args[0], "ls") == 0)
// 		return 1;
// 	return 0;
// }

// wrong!!!
int	execute_exit(char **args)
{
	if (ft_strcmp(args[0], "exit") == 0)
		exit(EXIT_SUCCESS);
	return (0);
}

// ???
int	execute_pwd(char **args)
{
	char	cwd[1024];

	if (ft_strncmp(args[0], "pwd", 3) == 0)
	{
		if (getcwd(cwd, sizeof(cwd)) != 0)
			printf("%s\n", cwd);
		else
			perror("failed");
	}
	return (0);
}

// done?
int	execute_echo(char **args)
{
	int	i;

	if (ft_strcmp(args[0], "echo") != 0)
		return (0);
	if (args[1] && ft_strcmp(args[1], "-n") == 0)
		i = 2;
	else
		i = 1;
	while (args[i])
	{
		printf("%s", args[i++]);
		if (args[i])
			printf(" ");
	}
	if (args[1] && ft_strcmp(args[1], "-n") != 0)
		printf("\n");
	return (0);
}

// replace???
int	execute_cd(char **args)
{
	if (ft_strcmp(args[0], "cd") != 0)
		return (0);
	if (!args[1])
		chdir(getenv("HOME"));
	else
	{
		if (chdir(args[1]) != 0)
			perror("cd");
	}
	return (0);
}

void	execute_all(char **args, char **ev)
{
	if (valid_command(args, ev) < 0)
	{
		perror("command not valid");
		return ;
	}
}
	// valid_command() executes fayezas builins
	// else other functions from bash (anna?)