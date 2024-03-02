/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnikzad <fnikzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:29:00 by fnikzad           #+#    #+#             */
/*   Updated: 2024/03/01 18:50:37 by fnikzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free (char **s)
{
	int i = 0;
	while (s && s[i])
	{
		free (s[i++]);
	}
	free (s);
}

int	ex_export(char **args, char **ev)
{
	int i = 0;
	char **new_ev;


	if (ft_strcmp(args[0], "export") == 0 && args[1])
	{
		
		i = 0;
		while ((ev)[i] != NULL)
		{
			i++;
		}
		new_ev = (char **) malloc (sizeof(char *) * (i + 2));
		if (!new_ev)
			return (-1);
		i = 0;
		while ((ev)[i])
		{
			new_ev[i] = ft_strdup((ev)[i]);
			i++;
		}
		new_ev[i++] = ft_strdup(args[1]);
		new_ev[i] = NULL;
		if (g_env)
			ft_free(g_env);
		g_env = (char **) malloc (sizeof(char *) * (i));
		g_env = new_ev;
	}
	if (!args[1])
	{
		if (!g_env)
			get_ev(ev);
		ev = g_env;
		while (ev[i])
		{
			printf ("declare -x %s\n", ev[i++]);
		}
		return (0);
	}
	return (0);
}

void	get_ev(char **ev)
{
	int i = 0;
	while (ev[i])
	{
		i++;
	}
	g_env = malloc (sizeof(char *) * (i + 1));
	i = 0;
	while (ev[i])
	{
		g_env[i] = ft_strdup(ev[i]);
		i++;
	}
	g_env[i] = NULL;
}