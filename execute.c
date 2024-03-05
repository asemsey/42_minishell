/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:21:56 by fnikzad           #+#    #+#             */
/*   Updated: 2024/03/05 09:45:33 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// valid_command() executes fayezas builins
// else other functions from bash (anna?)

int	valid_command(t_mini *shell);

int	execute_all(t_mini *shell)
{
	if (valid_command(shell) < 0)
	{
		perror("command not valid");
		return (0);
	}
	return (1);
}

int	valid_command(t_mini *shell)
{
	if (ft_strcmp(shell->argv[0], "cd") == 0)
		return (ex_cd(shell->argv));
	else if (ft_strcmp(shell->argv[0], "pwd") == 0)
		return (ex_pwd(shell->argv));
	else if (ft_strcmp(shell->argv[0], "echo") == 0)
		return (ex_echo(shell));
	else if (ft_strcmp(shell->argv[0], "export") == 0)
		return (ex_export(shell));
	else if (ft_strcmp(shell->argv[0], "unset") == 0)
		return (ex_unset(shell));
	else if (ft_strcmp(shell->argv[0], "env") == 0)
		return (ex_env(shell));
	else if (ft_strcmp(shell->argv[0], "exit") == 0)
		return (ex_exit(shell->argv));
	return (-1);
}
