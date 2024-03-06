/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:35:27 by asemsey           #+#    #+#             */
/*   Updated: 2024/03/06 18:43:47 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	replace_var(t_mini *shell)
{
	char	*new;
	int		i;

	i = 0;
	while (shell->argv[i])
	{
		if (shell->arg_type[i] == 0)
		{
			i++;
			continue ;
		}
		new = add_variables(shell, shell->argv[i]);
		if (new)
		{
			free(shell->argv[i]);
			shell->argv[i] = new;
		}
		i++;
	}
}

void	remove_quotes(t_mini *shell)
{
	int		i;
	char	*tmp;

	i = 0;
	while (shell->argv && shell->argv[i])
	{
		// shell->argv[i] = remove_char(shell->argv[i], '\"');
		// shell->argv[i] = remove_char(shell->argv[i], '\'');
		if (shell->arg_type[i] == 2)
		{
			i++;
			continue ;
		}
		if (shell->arg_type[i] == 0)
			tmp = ft_strtrim(shell->argv[i], "\'");
		if (shell->arg_type[i] == 1)
			tmp = ft_strtrim(shell->argv[i], "\"");
		free(shell->argv[i]);
		shell->argv[i++] = tmp;
	}
}

// types: 0-do not interpret | 1-change variables | 2-all metachars
int	get_arg_types(t_mini *shell)
{
	int		i;
	char	**args;

	i = 0;
	args = shell->argv;
	shell->arg_type = (int *)malloc(sizeof(int) * len_str_arr(args));
	if (!shell->arg_type)
		return (0);
	while (args[i])
	{
		if (args[i][0] == '\'' && args[i][ft_strlen(args[i]) - 1] == '\'')
			shell->arg_type[i] = 0;
		else if (args[i][0] == '\"' && args[i][ft_strlen(args[i]) - 1] == '\"')
			shell->arg_type[i] = 1;
		else if (!(args[i][0] == '\"' || args[i][0] == '\''))
			shell->arg_type[i] = 2;
		else
			return (0);
		i++;
	}
	return (1);
}
