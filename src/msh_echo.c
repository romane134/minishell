/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:58:43 by rlucas-d          #+#    #+#             */
/*   Updated: 2019/02/22 11:32:57 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/includes/libft.h"
#include <stdio.h>

static void		msh_echo_2(char **echo, int len, int j)
{
	j = 1;
	while ((*echo) && (len > 2))
	{
		st_printf("%s ", echo[j++]);
		len--;
	}
	st_printf("%s\n", echo[j]);
}

void			msh_echo(char *line)
{
	char	**echo;
	int		flag;
	int		len;
	int		j;

	j = 2;
	flag = 0;
	len = 0;
	//echo = (ft_strcmp(line, "echo \"-n") == 0) ? ft_strsplit(line, '\"') : ft_strsplit(line, ' ');
	echo = ft_strsplit(line, ' ');
	while (echo[len])
	{
		echo[len] = rm_quotes(echo[len]);
		len++;
	}
	if ((echo[1] && (((echo[1][0] == '-') && (echo[1][1] == 'n'))))
			&& (ft_strlen(echo[1]) == 2))
	{
		while (len > 2)
		{
			st_printf("%s ", echo[j]);
			j++;
			len--;
		}
		st_printf("%s", echo[j]);
	}
	else
		msh_echo_2(echo, len, j);
}


void				msh_env(t_msh msh)
{
	int i;

	i = 0;
	while (msh.env[i])
		st_printf("%s\n", msh.env[i++]);
}
