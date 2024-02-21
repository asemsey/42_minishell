/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:14:49 by asemsey           #+#    #+#             */
/*   Updated: 2024/02/21 11:02:17 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	dosomething(char **argv)
{
	int		i;

	i = 0;
	while (argv[i])
		ft_putstr_fd(argv[i++], 1);
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
	args = ft_split(str, ' ');
	if (!dosomething(args))
	{
		free(str);
		free_all(args);
		return (0);
	}
	free(str);
	free_all(args);
	write(1, "\n", 1);
	return (1);
}

int main(void)
{
	write(1, "Welcome to minishell :)\n", 24);
	while (prompt())
		;
	return (0);
}