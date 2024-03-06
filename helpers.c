/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:28:28 by asemsey           #+#    #+#             */
/*   Updated: 2024/03/06 16:21:34 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	len_str_arr(char **s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

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
		printf("%s\n", env[i]);
		i++;
	}
}

// changed malloc size because it was too long (... - count)
char	*remove_char(char *s, char c)
{
	int i = 0;
	int j = 0;
	int count = 0;
	char *new_s;
	while (s && s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	if (count % 2 != 0)
		return (s);
	new_s = (char *)malloc(sizeof(char) * (i - count + 1));
	if (!new_s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			new_s[j++] = s[i];
		i++;
	}
	new_s[j] = '\0';
	free(s);
	return (new_s);
}

int	count_char(char *str, char c)
{
	int	count;

	count = 0;
	while (str && *str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}
