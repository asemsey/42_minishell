/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:14:49 by asemsey           #+#    #+#             */
/*   Updated: 2024/03/06 18:36:30 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//  0-end  1-next_prompt
int	free_memory(t_mini *shell, char *str, int ret)
{
	if (str)
		free(str);
	if (shell)
	{
		free_all(shell->argv);
		free(shell->arg_type);
		if (ret == 0)
			free_all(shell->env);
	}
	return (ret);
}

int	prompt(t_mini *shell)
{
	char	*str;

	str = readline("minishell> ");
	if (!str)
		return (free_memory(shell, NULL, 0));
	if (!*str)
		return (free(str), 1);
	add_history(str);
	shell->argv = ft_argv(str);
	if (!get_arg_types(shell))
	{
		write(1, "Error: unclosed quotes\n", 23);
		return (free_memory(shell, str, 1));
	}
	get_arg_types(shell);
	remove_quotes(shell);
	replace_var(shell);
	if (!execute_all(shell))
		return (free_memory(shell, str, 1));// 0?
	return (free_memory(shell, str, 1));
}

void	leak(void)
{
	system("leaks minishell");
}

int	main(int argc, char **argv, char **ev)
{
	t_mini	shell;
	
	(void)argc;
	(void)argv;
	atexit(leak);
	get_ev(&shell, ev);
	write(1, "Welcome to minishell :)\n", 24);
	while (prompt(&shell))
		;
	rl_clear_history();
	return (0);
}
