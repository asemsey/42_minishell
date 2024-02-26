/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:34:45 by asemsey           #+#    #+#             */
/*   Updated: 2024/02/26 14:26:12 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*var_name(char *str)
{
	char	*name;
	int		i;

	i = 0;
	while (str[i] && 'A' <= str[i] && str[i] <= 'Z')
		i++;
	i++;
	name = (char *)malloc(sizeof(char) * (i));
	if (!name)
		return (NULL);
	ft_strlcpy(name, str, i);
	return (name);
}

int	var_len(char *str)
{
	char	*env;
	char	*name;
	int		len;

	len = 0;
	while (str && *str)
	{
		if (*str == '$')
		{
			name = var_name(++str);
			env = getenv(name);
			free(name);
			len += ft_strlen(env);
			while (*str && 'A' <= *str && *str <= 'Z')
				str++;
		}
		else
		{
			str++;
			len++;
		}
	}
	return (len);
}

char	*get_var(char *str)
{
	char	*env;
	char	*name;
	char	*new;
	int		i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = var_len(str) + 1;
	new = (char *)malloc(sizeof(char) * (i[2]));
	if (!new)
		return (str);
	while (str && str[i[1]])
	{
		if (*str == '$')
		{
			name = var_name(&str[++i[1]]);
			env = getenv(name);
			free(name);
			i[0] = ft_strlcat(new, (const char *)env, i[2]);
			while ('A' <= str[i[1]] && str[i[1]] <= 'Z')
				i[1]++;
		}
		else
			new[i[0]++] = str[i[1]]++;
	}
	return (new);
}

// echo $PATH$HOME

char	**add_variables(char **argv)
{
	int	i;

	i = 0;
	while (argv && argv[i])
	{
		if (ft_strchr(argv[i], '$'))
			argv[i] = get_var(argv[i]);
		i++;
	}
	return (argv);
}
