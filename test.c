/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:14:49 by asemsey           #+#    #+#             */
/*   Updated: 2024/02/27 10:29:53 by asemsey          ###   ########.fr       */
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

int	dosomething(char **argv)
{
	execute_all(argv);
	return (1);
}

int	prompt(void)
{
	char	**args;
	char	*str;

	str = readline("minishell> ");
	if (!str)
		return (0);
	if (!*str)
		return (1);
	add_history(str);
	str = replace_var(str);
	args = ft_argv(str);
	if (!dosomething(args))
	{
		free(str);
		free_all(args);
		return (0);
	}
	free(str);
	free_all(args);
	return (1);
}

void leak(void)
{
	system("leaks minishell");
}

int main(void)
{
	atexit(leak);
	write(1, "Welcome to minishell :)\n", 24);
	while (prompt())
		;
	rl_clear_history();
	return (0);
}
