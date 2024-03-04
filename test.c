/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:14:49 by asemsey           #+#    #+#             */
/*   Updated: 2024/03/04 20:08:20 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*replace_var(t_mini *shell, char *str)
{
	char	*new;

	new = add_variables(shell, str);
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
	new_s = malloc (sizeof(char) * (i - count + 1));
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

void	ft_print_env(t_mini *shell)
{
	char	**env;
	int		i;

	env = shell->env;
	i = 0;
	while (env && env[i])
	{
		printf("%d || %s\n", i, env[i]);
		i++;
	}
}

char	**remove_quotes(char **args)
{
	int		i;

	i = 0;
	while (args && args[i])
	{
		args[i] = remove_char(args[i], '\"');
		args[i] = remove_char(args[i], '\'');
		i++;
	}
	return (args);
}

int	prompt(t_mini *shell)
{
	char	**args;
	char	*str;

	str = readline("minishell> ");
	if (!str)
		return (0);
	if (!*str)
		return (1);
	add_history(str);
	str = replace_var(shell, str);
	args = ft_argv(str);
	args = remove_quotes(args);
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

void	leak(void)
{
	system("leaks minishell");
}

int	main(int argc, char **argv, char **ev)
{
	t_mini	shell;
	
	(void)argc;
	(void)argv;
	atexit(leak);
	get_ev(&shell, ev);
	write(1, "Welcome to minishell :)\n", 24);
	while (prompt(&shell))
		;
	rl_clear_history();
	return (0);
}
