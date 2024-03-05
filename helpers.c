/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:28:28 by asemsey           #+#    #+#             */
/*   Updated: 2024/03/05 09:34:56 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*free_ints(int **ints, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(ints[i]);
		ints[i++] = NULL;
	}
	free(ints);
	return (NULL);
}

void	ft_print_env(t_mini *shell)
{
	char	**env;
	int		i;

	env = shell->env;
	i = 0;
	while (env && env[i])
	{
		printf("%d || %s\n", i, env[i]);
		i++;
	}
}
