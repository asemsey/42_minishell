/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:14:49 by asemsey           #+#    #+#             */
/*   Updated: 2024/02/26 12:53:02 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"




int	dosomething(char **argv)
{
	argv = add_variables(argv);
	// write(1, "--ok--\n", 7);
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
