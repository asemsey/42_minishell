/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:34:45 by asemsey           #+#    #+#             */
/*   Updated: 2024/02/27 10:24:44 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_var(char *name);
char	*var_name(char *str);
int		var_len(char *str);

// add all $ variables to a str
char	*add_variables(char *str)
{
	char	*new;
	char	*name;
	int		len[2];

	len[0] = var_len(str) + 1;
	if (len[0] - 1 < 1)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (len[0]));
	if (!new)
		return (NULL);
	len[1] = 0;
	while (str && *str)
	{
		if (*str == '$')
		{
			name = var_name(++str);
			new[len[1]] = '\0';
			len[1] = ft_strlcat(new, getenv(name), len[0]);
			str += ft_strlen(name);
			free(name);
		}
		else
			new[len[1]++] = *str++;
	}
	return (new);
}

// check if name exists in env, return the length
int	check_var(char *name)
{
	char	*env;

	env = getenv(name);
	if (!env)
		return (-1);
	return (ft_strlen(env));
}

// get the name of the next var in str
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

// get the total len after replacing all $
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
			if (check_var(name) < 1)
				return (free(name), -1);
			env = getenv(name);
			len += ft_strlen(env);
			str += ft_strlen(name);
			env = NULL;
			free(name);
		}
		else
		{
			str++;
			len++;
		}
	}
	return (len);
}

// int	main(void)
// {
// 	char *str = "echo $HOME$PATH	$USER";
// 	char *new = add_variables(str);
// 	printf("%s\n", new);
// 	free(new);
// 	system("leaks minishell");
// 	return (0);
// }

// test var_name():
// while (str && *str)
// {
// 	if (*str == '$')
// 		printf("%s\n", var_name(++str));
// 	str++;
// }

// test var_len():
// printf("%s | %d\n", str, var_len(str));