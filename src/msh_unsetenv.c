/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_unsetenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:46:41 by rlucas-d          #+#    #+#             */
/*   Updated: 2019/03/06 18:11:42 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char			**ft_remove_one(int place, char **env, int len)
{
	int		i;
	char	**tmp;
	int		j;

	j = 0;
	i = 0;
	tmp = ft_memalloc(len);
	while (env[i])
	{
		if (i != place)
		{
			tmp[j] = ft_strdup(env[i]);
			j++;
		}
		i++;
	}
	return (tmp);
}

char			**msh_unsetenv(char *argm, t_msh msh)
{
	int		i;
	int		place;
	char	**tmp;

	place = 0;
	i = 0;
	while (msh.env[i])
	{
		if (ft_strnequ(msh.env[i], argm, ft_strlen(argm)) == 1)
			place = i;
		i++;
	}
	if (place == 0)
		return (msh.env);
	tmp = ft_remove_one(place, msh.env, i);
	free(msh.env);
	return (tmp);
}
