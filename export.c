/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnikzad <fnikzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:29:00 by fnikzad           #+#    #+#             */
/*   Updated: 2024/03/04 10:48:09 by fnikzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_str_arr(char **s)
{
	int i;
	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

void	ft_free (char **s)
{
	int i = 0;
	while (s && s[i])
	{
		free (s[i++]);
	}
	free (s);
}


int	ex_export(char **args, t_mini *shell)
{
	int i = 0;
	int j = 1;
	int l;
	char **new_ev;

	if (ft_strcmp(args[0], "export") == 0 && args[j])
	{
		if(valid_export(args) == 1)
		{
			write (1, "wrong\n", 6);
			return (0);
		}
		i = 0;
		while (shell->env[i] != NULL)
		{
			j = 1;
			while (args[j])
			{
				l = 0;
				while (shell->env[l])
				{
					if (ft_strncmp(shell->env[l], args[j], ft_strchr(args[j], '=') - args[j]) == 0)
					{
						free (shell->env[l]);
						shell->env[l] = ft_strdup(args[j++]);
						if (!args[j])
							return (0);
					}
					l++;
				}
				j++;
			}
			i++;
		}
		i = 0;
		while (shell->env[i])
		{
			j = 1;
			while (args[j])
			{
				l = 0;
				while (shell->env[l])
				{
					
					if (ft_strncmp(shell->env[l], args[j], ft_strchr(args[j], '=') - args[j]) == 0)
					{
						free (shell->env[l]);
						shell->env[l] = ft_strdup(args[j++]);
						l = 0;
						if (!args[j])
							return (0);
					}
					l++;
				}
				int k = ft_str_arr(shell->env);
				new_ev = (char **) malloc (sizeof(char *) * (k + 2));
				if (!new_ev)
					return (-1);
				k = 0;
				while (shell->env[k])
				{
					new_ev[k] = ft_strdup(shell->env[k]);
					k++;
				}
				new_ev[k++] = ft_strdup(args[j++]);
				new_ev[k] = NULL;
				shell->env = new_ev;
				if (!args[j])
					return (0);
			}
			i++;
		}
	}
	if (ft_strcmp(args[0], "export") == 0 && !args[1])
	{
		while (shell->env[i])
		{
			printf ("declare -x %s\n", shell->env[i++]);
		}
		return (0);
	}
	return (0);
}

int	valid_export(char **args)
{
	int i = 1;
	int eq = 0;
	if (ft_strcmp(args[0], "export") == 0)
	{
		while (args[i])
		{
			int j = 0;
			while (args[i][j])
			{
				if (!((args[i][0] >= 'a' && args[i][0] <= 'z') || 
					(args[i][0] >= 'A' && args[i][0] <= 'Z') || 
					args[i][0] == '_' ))
					return (1);
				if (!((args[i][j] >= 'a' && args[i][j] <= 'z') || 
					(args[i][j] >= 'A' && args[i][j] <= 'Z') || 
					(args[i][j] >= '0' && args[i][j] <= '9') || 
					args[i][j] == '_' || 
					(j > 0 && args[i][j] == '='))) 
					{
						return (1);
					}
				if (args[i][j] == '=')
					eq++;
				j++;
			}
			i++;
		}
		i--;
		if (eq != i)
			return (1);
		
	}
	return (0);
}

void	get_ev(t_mini *shell, char **ev)
{
	int i;
	i = 0;
	while (ev[i])
		i++;
	shell->env = malloc (sizeof(char * ) * (i + 1));
	if(!shell->env)
		return;
	i = 0;
	while (ev[i])
	{
		shell->env[i] = ft_strdup(ev[i]);
		i++;
	}
	shell->env[i] = NULL;
}

void	search_var(t_mini *shell, char *s)
{
	int i = 0;
	(void)s;
	char **vars = NULL;
	if (s)
		s++;
	while (shell->env[i])
	{
		if (vars)
			ft_free (vars);
		vars = ft_split(shell->env[i], '=');
		if (ft_strcmp(vars[0], s) == 0)
		{
			printf ("%s", vars[1]);
		}
		i++;
	}
}
