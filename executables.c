/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executables.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:21:56 by fnikzad           #+#    #+#             */
/*   Updated: 2024/02/21 15:13:20 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int valid_command(char **args)
{
	if (ft_strcmp(args[0], "cd") == 0 || ft_strcmp(args[0], "pwd") == 0 || ft_strcmp(args[0], "echo") == 0 || ft_strcmp(args[0], "export") == 0)
        return 1;
    if (ft_strcmp(args[0], "unset") == 0 || ft_strcmp(args[0], "env") == 0 || ft_strcmp(args[0], "exit") == 0 || ft_strcmp(args[0], "ls") == 0)
        return 1;
    return 0;
}

void	execute_ls(char **args)
{
	DIR *d;

	if (ft_strcmp(args[0], "ls") == 0)
	{
		if (!args[1])
		{
			d = opendir(".");
			// stuff
		}
	}
}

void	execute_exit(char **args)
{
	if (ft_strcmp(args[0], "exit") == 0)
		exit(EXIT_SUCCESS);
}

void	execute_pwd(char **args)
{
	char cwd[1024];
	if (ft_strncmp(args[0], "pwd", 3) == 0)
	{
		if (getcwd(cwd, sizeof(cwd)) != 0)
			printf("%s\n", cwd);
		else
			perror("failed");
	}
}

void	execute_echo(char **args)
{
	int i;
	if (args[1] && ft_strcmp(args[1], "-n") == 0)
	{
		if (ft_strcmp(args[0], "echo") == 0)
		{
			i = 2;
			while (args && args[i])
			{
				printf("%s", args[i++]);
				if (args[i])
					printf(" ");
			}
		}
	}
	else if (ft_strcmp(args[0], "echo") == 0)
	{
		i = 1;
		while (args && args[i])
		{
			printf("%s", args[i++]);
			if (args[i])
				printf(" ");
		}
		printf ("\n");
	}
}

void	execute_cd(char **args)
{
	if (ft_strcmp(args[0], "cd") == 0)
	{
		if (args[1] == NULL)
			chdir(getenv("HOME"));
		else 
		{
			if (chdir(args[1]) != 0)
			{
				perror("cd");
			}
		}
	}
}

void	execute_all(char **args)
{
	struct stat *s;
	if (!valid_command(args))
	{
		perror("command not valid");
		return ;
	}
	execute_exit(args);
	execute_pwd(args);
	execute_cd(args);
	execute_echo(args);
}
