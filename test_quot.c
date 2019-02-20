/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_quot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:47:46 by rlucas-d          #+#    #+#             */
/*   Updated: 2019/02/20 13:47:50 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int			ft_stop_quote(char *line, int quote)
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
}
