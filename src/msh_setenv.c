/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_setenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 11:18:52 by rlucas-d          #+#    #+#             */
/*   Updated: 2019/03/06 18:10:56 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char			**ft_setenv(char *argm, t_msh msh)
{
	int len;
	char **tmp;
	int k;

	len = 0;
	while (msh.env[len] != '\0')
		len++;
	tmp = ft_memalloc(len + 2);
	k = 0;
	while (k < len)
	{
		tmp[k] = ft_strdup(msh.env[k]);
		k++;
	}
	tmp[k] = ft_strdup(argm);
	return (tmp);
}

char				*ft_join_argm(char **argm)
{
	char	*tmp;

	tmp = ft_strjoin(argm[1], "=");
	if (argm[2])
		tmp = ft_strjoin(tmp, argm[2]);
	return (tmp);
}

char				**msh_setenv(char **argm, t_msh msh)
{
	int		i;
	int		j;
	char	**tmp;
	char	*ar;

	j = 0;
	i = 0;
	while (argm[i])
		i++;
	if (i != 1)
	{
		ar = ft_join_argm(argm);
		tmp = ft_setenv(ar, msh);
		free (ar);
		return (tmp);
	}
	tmp = msh.env;
	return (tmp);
}
