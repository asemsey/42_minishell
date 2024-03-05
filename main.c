/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:14:49 by asemsey           #+#    #+#             */
/*   Updated: 2024/03/05 09:46:27 by asemsey          ###   ########.fr       */
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

void	remove_quotes(t_mini *shell)
{
	int	i;

	i = 0;
	while (shell->argv && shell->argv[i])
	{
		shell->argv[i] = remove_char(shell->argv[i], '\"');
		shell->argv[i] = remove_char(shell->argv[i], '\'');
		i++;
	}
}

//  0-end  1-next_prompt
int	free_memory(t_mini *shell, char *str, int ret)
{
	if (str)
		free(str);
	if (shell)
	{
		free_all(shell->argv);
		free(shell->arg_type);
		if (ret == 0)
			free_all(shell->env);
	}
	return (ret);
}

int	prompt(t_mini *shell)
{
	char	*str;

	str = readline("minishell> ");
	if (!str)
		return (free_memory(shell, NULL, 0));
	if (!*str)
		return (free(str), 1);
	add_history(str);
	str = replace_var(shell, str);
	shell->argv = ft_argv(str);
	remove_quotes(shell);
	if (!execute_all(shell))
		return (free_memory(shell, str, 1));
	return (free_memory(shell, str, 1));
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
