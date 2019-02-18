/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:47:40 by rlucas-d          #+#    #+#             */
/*   Updated: 2019/02/18 15:57:01 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>

/*static int			ft_stop_quote(char *line, int quote)
{
	st_printf ("%s\n", line);
	quote = 0;
	return (quote);
}
static int			ft_quotes(char *line)
{
	int count_simple;
	int count_double;
	int i;

	count_double = 0;
	count_simple = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\'')
			count_simple++;
		if (line[i] == '\"')
			count_double++;
		i++;
	}
	if (((count_double % 2) != 0) || (count_simple % 2) != 0)
	{
		st_printf(((count_double % 2) == 0) ? "dquote>\n" : "quote>\n");
		return (1);
	}

	return (0);
}*/

void		ft_sig(int i)
{
	i = 2;
	prompt(i);
}

void		prompt(int i)
{
	if (i == 2)
		st_printf("\n");
	st_printf("Romane$>");
}

int			main(int argc, char **argv)
{
	char		*line;
	int quote;

	quote = 0;
	signal(SIGINT, ft_sig);
	if (argc == 1 && argv)
		while (1)
		{
			prompt(0);
			get_next_line(0, &line);
			if ((ft_strcmp(line, "exit") == 0))
				break ;
		//	if (ft_quotes(line) == 1)
			msh_message(line, argv);
			free(line);
		}
	return (0);
}

