/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:15:38 by rlucas-d          #+#    #+#             */
/*   Updated: 2019/02/20 15:28:04 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void				msh_cd(char **argv, t_msh *msh)
{
	char	*path;
	char	*old_path;

	old_path = msh->home_path;
	if (argv[1])
	{
		path = argv[1];
		if (chdir(path) == -1)
			st_printf("Error: Can't change dir\n");
		else
		{
			prompt (0, path);
			old_path = ft_strjoin(old_path, "/");
			(*msh).home_path = ft_strjoin(old_path, path);
		}
	}
}
