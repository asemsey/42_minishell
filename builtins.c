/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:41:46 by asemsey           #+#    #+#             */
/*   Updated: 2024/03/05 09:43:32 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// env, exit, pwd, echo, cd

int	ex_env(t_mini *shell)
{
	int	i;

	i = 0;
	if (ft_strcmp(shell->argv[0], "env") == 0)
	{
		while (shell->env[i])
			printf("%s\n", shell->env[i++]);
	}
	return (0);
}

// wrong!!!
int	ex_exit(char **args)
{
	if (ft_strcmp(args[0], "exit") == 0)
		exit(EXIT_SUCCESS);
	return (0);
}

// ???
int	ex_pwd(char **args)
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

int	ex_echo(t_mini *shell)
{
	int	i;

	if (ft_strcmp(shell->argv[0], "echo") == 0)
	{
		if (shell->argv[1] && shell->argv[2] && ft_strcmp(shell->argv[1], "-n") == 0)
			i = 2;
		else
			i = 1;
		while (shell->argv[i])
		{
			printf("%s", shell->argv[i++]);
			if (shell->argv[i])
				printf(" ");
		}
	}
	if (shell->argv[1] && ft_strcmp(shell->argv[1], "-n") != 0)
		printf("\n");
	return (0);
}

// if (ft_strcmp(args[i], "$PWD") == 0)
// {
// 	char	cwd[1024]
// 	if (getcwd(cwd, sizeof(cwd)) != 0)
// 		printf("%s", cwd);
// 	else
// 		perror("failed");
// 	if (args[i + 1])
// 	{
// 		printf(" ");
// 		i++;
// 	}
// 	else
// 		return (0);
// }
// if (args[i][0] == '$' && shell != NULL)
// {
// 	search_var(shell, args[i]);
// 	i++;
// }
// else

// replace
int	ex_cd(char **args)
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
