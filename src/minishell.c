/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:47:40 by rlucas-d          #+#    #+#             */
/*   Updated: 2019/03/06 18:11:04 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* faire la ~ ? !!!!!!!!!!!!!!!!!! */
#include "../includes/minishell.h"

void		ft_sig(int i)
{
	i = 2;
	prompt(i, "path");
}

void		prompt(int i, char *pwd)
{
	if (i == 2)
		st_printf("\nrlucas-d/minishell$>");
	else
		st_printf("%s$>", pwd);
}

int			main(int argc, char **argv, char **env)
{
	t_msh		msh;
	int			ret;
	int i;

	i = 0;
	signal(SIGINT, ft_sig);
	create_env(env, &msh);
	if (argc == 1 && argv)
		while (1)
		{
			prompt(0, (msh.env[6] + 4));
			ret = get_next_line(0, &msh.line);
			if (ret == 0)
				break ;
			if ((ft_strcmp(msh.line, "exit") == 0))
				break ;
			msh.line = ft_strtrim(msh.line);
			msh.argm = ft_mshstrsplit(msh.line, ' ');
			msh_message(&msh, msh.line);
			free(msh.line);
		}
	return (0);
}

