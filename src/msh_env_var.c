/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:47:02 by rlucas-d          #+#    #+#             */
/*   Updated: 2019/03/04 15:36:38 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**realloc_env(int new_size, t_msh msh)
{
	char	**new;
	int		i;

	new = (char **)ft_memalloc(sizeof(char *) * (new_size + 1));
	i = 0;
	while (msh.env[i] && i < new_size)
	{
		new[i] = ft_strdup(msh.env[i]);
		free(msh.env[i]);
		i++;
	}
	free(msh.env);
	return (new);
}

int		find_env_var(char *var, t_msh msh)
{
	int		i;
	char	*tmp;

	i = 0;
	while (msh.env[i])
	{
		tmp = ft_strjoin(var, "=");
		if (ft_strnequ(msh.env[i], tmp, ft_strlen(tmp)))
		{
			free(tmp);
			return (i);
		}
		free(tmp);
		i++;
	}
	return (i);
}

void	set_env_var(char *key, t_msh *msh, char *value)
{
	int		pos;
	char	*tmp;

	pos = find_env_var(key, *msh);
	tmp = ft_strjoin("=", value);
	if (msh->env[pos])
	{
		free(msh->env[pos]);
		if (value)
			msh->env[pos] = ft_strjoin(key, tmp);
		else
			msh->env[pos] = ft_strjoin(key, "=");
	}
	else
	{
		msh->env = realloc_env(pos + 1, *msh);
		if (value)
			msh->env[pos] = ft_strjoin(key, tmp);
		else
			msh->env[pos] = ft_strjoin(key, "=");
	}
	free(tmp);
}
