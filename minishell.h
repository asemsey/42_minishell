/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:09:31 by asemsey           #+#    #+#             */
/*   Updated: 2024/03/05 09:40:55 by asemsey          ###   ########.fr       */
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

// enum	e_cmd{
// 	CD=0,
// 	PWD=1,
// 	ECHO=2,
// 	EXPORT=3,
// 	UNSET=4,
// 	ENV=5,
// 	EXIT=6
// };

typedef struct s_mini
{
	char		**env;
	int			var_num;
	char		**argv;
	int			argc;
	int			*arg_type;
} t_mini;

void	get_ev(t_mini *shell, char **ev);
char	*add_variables(t_mini *shell, char *str);
int		valid_export(char **args);
char	*search_var(t_mini *shell, char *s);

// builtins

int		execute_all(t_mini *shell);
int		ex_env(t_mini *shell);
int		ex_exit(char **args);
int		ex_pwd(char **args);
int		ex_echo(t_mini *shell);
int		ex_cd(char **args);
int		ex_export(t_mini *shell);
int		ex_unset(t_mini *shell);

// helpers

void	*free_ints(int **ints, int size);

// void	execute_pwd(char **args);
// void	ft_free (char **s);
// ft_free is identical to free_all which has the optional return value NULL :) (->libft)

#endif