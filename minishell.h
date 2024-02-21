/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:09:31 by asemsey           #+#    #+#             */
/*   Updated: 2024/02/21 15:05:19 by asemsey          ###   ########.fr       */
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
// # include <include/readline-8.2/readline.h>

void	execute_all(char **args);
void	execute_pwd(char **args);
int		valid_command(char **args);
void	execute_echo(char **args);
#endif