/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:29:00 by fnikzad           #+#    #+#             */
/*   Updated: 2024/03/06 15:17:07 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ex_export(t_mini *shell)
{
	int		i;
	int		j;
	int		l;
	char	**new_ev;

	if (ft_strcmp(shell->argv[0], "export") == 0 && !shell->argv[1])
	{
		// while (shell->env[i])
		// 	printf ("declare -x %s\n", shell->env[i++]);
		ft_print_env(shell);
		return (0);
	}
	if (valid_export(shell->argv) == 1)
	{
		write(1, "wrong\n", 6);
		return (0);
	}
	i = 0;
	while (shell->env[i] != NULL)
	{
		j = 1;
		while (shell->argv[j])
		{
			l = 0;
			while (shell->env[l])
			{
				if (ft_strncmp(shell->env[l], shell->argv[j], ft_strchr(shell->argv[j], '=') - shell->argv[j]) == 0)
				{
					free (shell->env[l]);
					shell->env[l] = ft_strdup(shell->argv[j++]);
					if (!shell->argv[j])
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
		while (shell->argv[j])
		{
			l = 0;
			while (shell->env[l])
			{
				
				if (ft_strncmp(shell->env[l], shell->argv[j], ft_strchr(shell->argv[j], '=') - shell->argv[j]) == 0)
				{
					free (shell->env[l]);
					shell->env[l] = ft_strdup(shell->argv[j++]);
					l = 0;
					if (!shell->argv[j])
						return (0);
				}
				l++;
			}
			int k = len_str_arr(shell->env);
			new_ev = (char **) malloc (sizeof(char *) * (k + 2));
			if (!new_ev)
				return (-1);
			k = 0;
			while (shell->env[k])
			{
				new_ev[k] = ft_strdup(shell->env[k]);
				k++;
			}
			new_ev[k++] = ft_strdup(shell->argv[j++]);
			new_ev[k] = NULL;
			shell->env = new_ev;
			if (!shell->argv[j])
				return (0);
		}
		i++;
	}
	return (0);
}

// maybe easier with valid_var_name()?
int	valid_export(char **args)
{
	int	i;
	int	eq;
	int	j;

	i = 1;
	eq = 0;
	if (ft_strcmp(args[0], "export") != 0)
		return (0);
	while (args[i])
	{
		j = 1;
		if (!valid_var_name(args[i][0], 0))
			return (0);
		while (args[i][j])
		{
			// if (!(ft_isalpha(args[i][0]) || args[i][0] == '_' ))
			// 	return (0);
			// if (!(ft_isalnum(args[i][j]) || args[i][j] == '_' || (j > 0 && args[i][j] == '=')))
			// 	return (0);
			if (!(valid_var_name(args[i][j], j) || args[i][j] == '='))
				return (0);
			if (args[i][j] == '=')
				eq++;
			j++;
		}
		i++;
	}
	// if (eq != i - 1) what is this???
	// 	return (1);
	return (1);
}

// save all env variables in t_mini
void	get_ev(t_mini *shell, char **ev)
{
	int i;
	i = 0;
	while (ev[i])
		i++;
	shell->env = malloc(sizeof(char *) * (i + 1));
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

// s now needs to be the name without '$' !!!
// use var_name() to get s
char	*search_var(t_mini *shell, char *s)
{
	int		i;
	char	**vars;
	char	*content;
	
	// if (s)
	// 	s++;
	i = 0;
	vars = NULL;
	while (shell->env[i])
	{
		vars = ft_split(shell->env[i], '=');
		if (ft_strcmp(vars[0], s) == 0)
		{
			shell->var_num = i;
			content = ft_strdup(vars[1]);
			free_all(vars);
			return (content);
		}
		free_all(vars);
		i++;
	}
	return (NULL);
}


// void	ft_free(char **s)
// {
// 	int i = 0;
// 	while (s && s[i])
// 	{
// 		free (s[i++]);
// 	}
// 	free (s);
// }