/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_get_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 09:05:21 by rlucas-d          #+#    #+#             */
/*   Updated: 2019/02/22 10:49:08 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void			create_env(char **env, t_msh *msh)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((env[i++]))
		NULL;
	(*msh).env = ft_memalloc(i + 1);
	i = 0;
	while (env[i])
	{
		(*msh).env[i] = ft_memalloc(ft_strlen(env[i]) + 1);
		j = 0;
		while (env[i][j])
		{
			(*msh).env[i][j] = env[i][j];
			j++;
		}
		(*msh).env[i][j] = '\0';
		i++;
	}
	get_env(msh);
}

void				get_env(t_msh *msh)
{
	int i;

	i = 0;
	while (msh->env[i])
	{
		if (ft_strnequ((*msh).env[i], "PATH", 4) == 1)
			if (!(msh->path = ft_strsplit((msh->env[i] + 5), ':')))
				return ;
		if (ft_strnequ((*msh).env[i], "PWD", 3) == 1)
		{
			msh->pwd = ((*msh).env[i] + 4);
			msh->home_path = ((*msh).env[i] + 4);
		}
		i++;
	}
}
