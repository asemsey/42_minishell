/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:09:31 by asemsey           #+#    #+#             */
/*   Updated: 2024/03/06 18:43:41 by asemsey          ###   ########.fr       */
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

// parsing

void	replace_var(t_mini *shell);
void	remove_quotes(t_mini *shell);
int		get_arg_types(t_mini *shell);
char	*add_variables(t_mini *shell, char *str);
int		valid_var_name(char c, int index);
int		valid_export(char **args);

void	get_ev(t_mini *shell, char **ev);
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

int		len_str_arr(char **s);
void	*free_ints(int **ints, int size);
char	*remove_char(char *s, char c);
void	ft_print_env(t_mini *shell);

// void	execute_pwd(char **args);
// void	ft_free (char **s);
// ft_free is identical to free_all which has the optional return value NULL :) (->libft)

#endif