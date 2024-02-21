/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:26:45 by fnikzad           #+#    #+#             */
/*   Updated: 2024/02/21 12:07:53 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// !!! undefined behaviour for unclosed quotes !!!

static int	count(const char *str)
{
	int	words;

	words = 0;
	while (str && *str)
	{
		while (*str && ft_isspace(*str))
			str++;
		if (*str && !ft_isspace(*str))
			words++;
		while (*str)
		{
			if (*str && *str == '\"')
			{
				str++;
				while (*str && *str != '\"')
					str++;
				str++;
			}
			if (*str && ft_isspace(*str))
				break ;
			str++;
		}
	}
	return (words);
}

static char	*ft_copy(const char *str, int *len)
{
	int		v[2];
	char	*s;

	v[0] = 0;
	while (str && str[v[0]])
	{
		if (str[v[0]] && str[v[0]] == '\"')
		{
			while (str[v[0]] && str[v[0] + 1] != '\"')
				v[0]++;
			v[0]++;
		}
		if (str[v[0]] && ft_isspace(str[v[0]]))
			break ;
		v[0]++;
	}
	s = (char *)malloc(sizeof(char) * (v[0] + 1));
	if (!s)
		return (NULL);
	v[1] = 0;
	while (*str && *str && v[1] < v[0])
		s[v[1]++] = *str++;
	s[v[1]] = '\0';
	*len = v[1];
	return (s);
}

char	**ft_argv(const char *str)
{
	char	**strs;
	int		v[3];

	(void)str;
	v[0] = count(str);
	strs = (char **)malloc(sizeof(char *) * (v[0] + 1));
	if (!strs)
		return (NULL);
	v[1] = 0;
	while (v[1] < v[0])
	{
		while (str && *str && ft_isspace(*str))
			str++;
		strs[v[1]++] = ft_copy(str, &v[2]);
		if (!strs[v[1] - 1])
			return ((char **)free_all(strs));
		str += v[2];
	}
	strs[v[1]] = NULL;
	return (strs);
	return (NULL);
}

// #include <stdio.h>
// int main()
// {
// 	int i = 0;
// 	const char *input = "";

// 	printf("-%d-\n", count(input));
// 	char **result = ft_argv(input);
// 	while (result && result[i])
// 		printf("%s\n", result[i++]);
// }