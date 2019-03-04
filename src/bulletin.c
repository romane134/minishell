/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bulletin_ls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 09:00:58 by rlucas-d          #+#    #+#             */
/*   Updated: 2019/02/28 16:35:32 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <sys/stat.h>
#include <dirent.h>

static int	ft_bulletin_1(char *path, char **argm, t_msh msh)
{
	pid_t		pid;

	pid = fork();
	if (pid == 0)
		execve(path, argm, msh.env);
	else if (pid < 0)
	{
		free(path);
		ft_putendl("Fork failed to create a new process.");
		return (-1);
	}
	wait(&pid);
	if (path)
		free(path);
	return (1);
}

int		ft_bulletin(char **path, char **argm, t_msh msh)
{

	int		i;
	DIR		*dirp;
	struct stat	f;
	struct dirent *dp;
	char	*tmp;


	i = 0;
	tmp = NULL;
	while (path[i])
	{
		if (lstat(path[i], &f) != -1)
		{
			if (f.st_mode & S_IXUSR)
			{
				dirp = opendir(path[i]);
				while ((dp = readdir(dirp)) != NULL)
				{
					if (ft_strequ(dp->d_name, argm[0]) == 1)
					{
						tmp = ft_strjoin (path[i], "/");
						tmp = ft_strjoin (tmp, dp->d_name);
						if (ft_bulletin_1(tmp, argm, msh) == 1)
							return (1);
					}
				}
			}
		}
		i++;
	}
	return (0);
}
