/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_message.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:44:49 by rlucas-d          #+#    #+#             */
/*   Updated: 2019/03/06 15:03:40 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>

char			*rm_quotes(char *line)
{
	int		i;
	char	*str;
	int		size;

	i = 0;
	size = 0;
	while (line[i])
	{
		if (line[i] == '\"')
			size++;
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (i - size))))
		return (NULL);
	i = 0;
	size = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\"')
			i++;
		else
		{
			str[size] = line[i];
			size++;
			i++;
		}
	}
	return (str);
}

void			msh_message(t_msh *msh, char *line)
{
	int			i;
	char		**tmp;

	i = 1;
	if (ft_strequ(line, "\0") == 1)
		return ;
	if ((ft_strequ((*msh).argm[0], "echo") == 1))
		msh_echo(line);
	else if ((ft_strequ((*msh).argm[0], "cd") == 1))
		msh_cd((*msh).argm, msh);
	else if ((ft_strequ((*msh).argm[0], "setenv") == 1))
	{
		if (!(*msh).argm[1])
			msh_env((*msh));
		else if ((*msh).argm[3])
			st_printf("setenv: Too many arguments.\n");
		else
		{
			tmp = msh_setenv(msh->argm, (*msh));
			free ((*msh).env);
			msh->env = tmp;
		}
	}
	else if ((ft_strequ((*msh).argm[0], "env") == 1))
		msh_env((*msh));
	else if ((ft_strequ((*msh).argm[0], "unsetenv") == 1))
	{
		if (!(*msh).argm[1])
			st_printf("unsetenv: Too few arguments.\n");
		while ((*msh).argm[i])
		{
			msh->env = msh_unsetenv(msh->argm[i], (*msh));
			i++;
		}
	}
	else
	{
		if (ft_bulletin(msh->path, msh->argm, *msh) == 1)
			NULL;
		else
			st_printf ("zsh: command not found: %s\n", line);
	}
}
