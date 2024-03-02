/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnikzad <fnikzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:14:49 by asemsey           #+#    #+#             */
/*   Updated: 2024/03/02 17:22:12 by fnikzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*replace_var(char *str)
{
	char	*new;

	new = add_variables(str);
	if (!new)
		return (str);
	free(str);
	return (new);
}

int	dosomething(char **argv, t_mini *shell)
{
	execute_all(argv, shell);
	return (1);
}

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
	if (count == 2)
	{
		new_s = malloc (sizeof(char) * (i + 1));
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
		return (new_s);
	}
	return (s);
}


int	prompt(int argc, char **argv, t_mini *shell)
{
	char	**args;
	char	*str;

	(void) argc;
	(void) argv;
	str = readline("minishell> ");
	if (!str)
		return (0);
	if (!*str)
		return (1);
	add_history(str);
	str = replace_var(str);
	str = remove_char(str, '"');
	args = ft_argv(str);
	if (!dosomething(args, shell))
	{
		free(str);
		free_all(args);
		return (0);
	}
	free(str);
	free_all(args);
	return (1);
}

// void	leak(void)
// {
// 	system("leaks minishell");
// }

int	main(int argc, char **argv, char **ev)
{
	t_mini	shell;
	
	// atexit(leak);
	get_ev(&shell, ev);
	write(1, "Welcome to minishell :)\n", 24);
	while (prompt(argc, argv, &shell))
		;
	rl_clear_history();
	return (0);
}
