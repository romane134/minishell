/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:15:38 by rlucas-d          #+#    #+#             */
/*   Updated: 2019/03/06 18:14:50 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void				msh_cd(char **argv, t_msh *msh)
{
	char	*path;
	char	*cwd;
	char	buff[4097];

	cwd = getcwd(buff, 4096);
	path = argv[1];
	if (argv[1][0] == '~')
		path = "/Users/rlucas-d/";
	if (!chdir(path))
	{
		if (cwd[1] == '/')
			set_env_var("PWD", msh, cwd);
		else
		{
			cwd = getcwd(buff, 4096);
			set_env_var("PWD", msh, cwd);
		}
	}
	else
	{
		ft_putstr("cd: ");
		if (access(path, F_OK) == -1)
			st_printf("no such file or directory: ");
		else if (access(path, R_OK) == -1)
			st_printf("permission denied: ");
		else
			st_printf("not a directory: ");
		ft_putendl(argv[1]);
	}
}
