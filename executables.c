/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executables.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:21:56 by fnikzad           #+#    #+#             */
/*   Updated: 2024/02/26 12:28:16 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	valid_command(char **args)
{
	if (ft_strcmp(args[0], "cd") == 0)
		return (CD);
	else if (ft_strcmp(args[0], "pwd") == 0)
		return (PWD);
	else if (ft_strcmp(args[0], "echo") == 0)
		return (ECHO);
	else if (ft_strcmp(args[0], "export") == 0)
		return (EXPORT);
	else if (ft_strcmp(args[0], "unset") == 0)
		return (UNSET);
	else if (ft_strcmp(args[0], "env") == 0)
		return (ENV);
	else if (ft_strcmp(args[0], "exit") == 0)
		return (EXIT);
	return (-1);
}

// int valid_command(char **args)
// {
// 	if (ft_strcmp(args[0], "cd") == 0 || ft_strcmp(args[0], "pwd") == 0 || ft_strcmp(args[0], "echo") == 0 || ft_strcmp(args[0], "export") == 0)
//         return 1;
//     if (ft_strcmp(args[0], "unset") == 0 || ft_strcmp(args[0], "env") == 0 || ft_strcmp(args[0], "exit") == 0 || ft_strcmp(args[0], "ls") == 0)
//         return 1;
//     return 0;
// }


// wrong!!!
void	execute_exit(char **args)
{
	if (ft_strcmp(args[0], "exit") == 0)
		exit(EXIT_SUCCESS);
}

// ???
int	execute_pwd(char **args)
{
	char cwd[1024];
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
void	execute_echo(char **args)
{
	int i;

	if (ft_strcmp(args[0], "echo") != 0)
		return ;
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
}

// replace???
void	execute_cd(char **args)
{
	if (ft_strcmp(args[0], "cd") != 0)
		return ;
	if (!args[1])
		chdir(getenv("HOME"));
	else
	{
		if (chdir(args[1]) != 0)
			perror("cd");
	}
}

void	execute_all(char **args)
{
	if (valid_command(args) < 0)
	{
		perror("command not valid");
		return ;
	}
	// valid_command() executes fayezas builins
	// else other functions from bash (anna?)
}
