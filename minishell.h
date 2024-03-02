/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnikzad <fnikzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:09:31 by asemsey           #+#    #+#             */
/*   Updated: 2024/03/02 10:01:54 by fnikzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <dirent.h> 
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "include/libft/libft.h"

char **g_env;

enum	e_cmd{
	CD=0,
	PWD=1,
	ECHO=2,
	EXPORT=3,
	UNSET=4,
	ENV=5,
	EXIT=6
};

typedef struct s_mini
{
	char **env;
} t_mini;

// typedef struct s_mini
// {
// 	char **env;
// } t_mini;

// void	execute_pwd(char **args);
// int		valid_command(char **args);
// void	execute_echo(char **args);

char	*add_variables(char *str);
void	execute_all(char **args, char **ev);
int		execute_env(char **args, char **ev);
int	ex_export(char **args, char **ev);
void	get_ev(char **ev);
void	ft_free (char **s);



#endif