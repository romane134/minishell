/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_unsetenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:46:41 by rlucas-d          #+#    #+#             */
/*   Updated: 2019/03/04 17:04:23 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char			**msh_unsetenv(char *argm, t_msh msh)
{
	int		i;
	char	*ar;
	int		j;

	j = 0;
	i = 0;
	while (msh.env[i])
	{
		if (ft_strnequ(msh.env[i], argm, ft_strlen(ar)) == 1)
			j = i;
		i++;
	}
	printf ("%d\n", j);
	return (msh.env);
}
