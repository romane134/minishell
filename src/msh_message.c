/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_message.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:44:49 by rlucas-d          #+#    #+#             */
/*   Updated: 2019/02/18 15:56:59 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void			msh_message(char *line, char **argv)
{
	if ((ft_strnequ(line, "echo", ft_strlen("echo")) == 1))
		msh_echo(line);
	else if ((ft_strnequ(line, "ls", 2) == 1))
	{
		st_printf ("sdfsdf\n");
		execve("/bin/ls", argv, NULL);
	}
	else
		st_printf ("zsh: command not found: %s\n", line);
}
