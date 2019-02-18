/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:43:57 by rlucas-d          #+#    #+#             */
/*   Updated: 2019/02/18 13:54:23 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "../libft/includes/libft.h"
#include <sys/wait.h>
#include <unistd.h>
#include "../../gnl/get_next_line.h"


typedef				void (*sig_t)(int);

/*
**  minishell.c
*/
void				ft_sig(int i);
void				prompt(int i);

/*
**  msh_message.c
*/
void				msh_message(char *line, char **argv);

/*
** msh_echo.
*/

void				msh_echo(char *line);
#endif
