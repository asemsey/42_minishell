/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnikzad <fnikzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:14:49 by asemsey           #+#    #+#             */
/*   Updated: 2024/02/29 17:12:32 by fnikzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*replace_var(char *str)
{
	char	*new;

	new = add_variables(str);
	if (!new)
		return (str);
	free(str);
	return (new);
}

int	dosomething(char **argv, char **ev)
{
	execute_all(argv, ev);
	return (1);
}

int	prompt(int argc, char **argv, char **ev)
{
	char	**args;
	char	*str;

	(void) argc;
	(void) argv;
	str = readline("minishell> ");
	if (!str)
		return (0);
	if (!*str)
		return (1);
	add_history(str);
	str = replace_var(str);
	args = ft_argv(str);
	if (!dosomething(args, ev))
	{
		free(str);
		free_all(args);
		return (0);
	}
	free(str);
	free_all(args);
	return (1);
}

void	leak(void)
{
	system("leaks minishell");
}

int	main(int argc, char **argv, char **ev)
{
	atexit(leak);
	write(1, "Welcome to minishell :)\n", 24);
	while (prompt(argc, argv, ev))
		;
	rl_clear_history();
	return (0);
}
