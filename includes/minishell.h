/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:43:57 by rlucas-d          #+#    #+#             */
/*   Updated: 2019/02/22 10:52:15 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "../libft/includes/libft.h"
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <fcntl.h>


typedef				void (*sig_t)(int);

typedef struct s_msh	t_msh;
struct				s_msh
{
	char		*line;
	char		**argm;
	char		**path;
	char		*pwd;
	char		**env;
	char		*home_path;
};

/*
**  minishell.c
*/
void				ft_sig(int i);
void				prompt(int i, char *pwd);

/*
**  msh_message.c
*/
void				msh_message(t_msh *msh, char *line);

/*
** msh_echo.
*/

void				msh_echo(char *line);
char				*rm_quotes(char *line);
void				msh_env(t_msh msh);
/*
** msh_get_env.c
*/
void				get_env(t_msh *msh);
void				create_env(char **env, t_msh *msh);

void				msh_cd(char **argv, t_msh *msh);



void				set_env_var(char *key, t_msh *msh, char *value);
int					find_env_var(char *var, t_msh msh);
char				**realloc_env(int new_size, t_msh msh);
#endif
