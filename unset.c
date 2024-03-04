/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnikzad <fnikzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:16:33 by fnikzad           #+#    #+#             */
/*   Updated: 2024/03/04 17:29:54 by fnikzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ex_unset(char **args, t_mini *shell)
{
	int i = -1;
	int j = 1;
	while (args[j])
	{
		i = -1;
		while (shell->env[++i])
		{
			if (ft_strncmp(shell->env[i], args[j], ft_strchr(shell->env[i], '=') - shell->env[i]) == 0)
			{
				while (shell->env[i])
				{
					shell->env[i] = shell->env[i + 1];
					i++;
				}
			}
		}
		j++;
	}
	return (0);
}
