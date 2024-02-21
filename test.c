/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnikzad <fnikzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:14:49 by asemsey           #+#    #+#             */
/*   Updated: 2024/02/21 12:09:36 by fnikzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



void	execute_cd(char **args)
{
	char cwd[1024];
	if (ft_strncmp(args[0], "pwd", 3) == 0)
	{
		if (getcwd(cwd, sizeof(cwd)) != 0)
			printf("%s\n", cwd);
	}
	if (args[0][0] == 's' && args[0][1] == 'd')
	{
		if (args[1] == NULL)
			chdir(getenv("HOME"));
		else 
			chdir("args[1]");
	}
}

int	dosomething(char **argv)
{
	// int		i;

	// i = 0;
	// while (argv[i])
	// {
	// 	ft_putstr_fd(argv[i++], 1);
	// }
	
	execute_cd(argv);
	return (1);
}

int	prompt(void)
{
	char	**args;
	char	*str;

	str = readline("minishell> ");
	if (!str)
		return (0);
	if (!*str)
		return (1);
	args = ft_split(str, ' ');
	if (!dosomething(args))
	{
		free(str);
		free_all(args);
		return (0);
	}
	free(str);
	free_all(args);
	// write(1, "\n", 1);
	return (1);
}

int main(void)
{
	write(1, "Welcome to minishell :)\n", 24);
	while (prompt())
		;
	return (0);
}
