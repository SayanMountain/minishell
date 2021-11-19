/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeffere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:19:33 by pjeffere          #+#    #+#             */
/*   Updated: 2021/11/19 16:19:35 by pjeffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	skip_space(char *str, int *i)
{
	if (str[*i] == ' ')
		while (str[++(*i)] == ' ' && str[*i]);
}

int	check_zero_i(char *str, int *i)
{
	if (str[*i] == '|')
	{
		(*i)++;
		skip_space(str, i);
		if (str[*i] == '|')
		{
			error_msg(3, ' ');
			return (1);
		}
		else
		{
			error_msg(2, '|');
			return (1);
		}
	}
	if (str[*i] == '>' || str[*i] == '<')
	{
		(*i)++;
		skip_space(str, i);
		if (check_char(str[*i], "<>|"))
		{
			error_msg(2, str[*i]);
			return (1);
		}
	}
	return (0);
}

int	preparser(t_msh *msh)
{
	int		i;
	char	*str;

	i = 0;
	str = msh->str_name;
	skip_space(str, &i);
	if (check_zero_i(str, &i))
		return (1);
//	while (str[++i])
//	{
//
//	}
	return (0);
}
