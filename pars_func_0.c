/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_func_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeffere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:22:06 by pjeffere          #+#    #+#             */
/*   Updated: 2021/11/19 16:22:08 by pjeffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rewriting_str(t_list *tmp, char *str, int j)
{
	free(tmp->cmd[j]);
	tmp->cmd[j] = NULL;
	tmp->cmd[j] = str;
}

int	check_char(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	skip_quotes(t_msh *msh, char *str, int *i)
{
	(void)msh;
	if (str[*i] == '\"')
	{
		while (str[++(*i)] != '\"')
		{
			if (str[*i] == '\0')
			{
				error_msg(1, ' ');
				return (1);
			}
		}
	}
	if (str[*i] == '\'')
	{
		while (str[++(*i)] != '\'')
		{
			if (str[*i] == '\0')
			{
				error_msg(1, ' ');
				return (1);
			}
		}
	}
	return (0);
}

int	creat_list(char *str, t_msh *msh, int *i)
{
	t_list	*new;

	new = ft_lstnew(str);
	new->red_inp = -1;
	new->red_outp = -1;
	new->pipe_or_word = NULL;
	msh->start = *i;
	new->pipe_h[0] = -1;
	new->pipe_h[1] = -1;
	while (check_char(msh->str_name[*i], "<>") && msh->str_name[*i])
		(*i)++;
	if (redirect(msh, new, i))
		return (1);
	ft_lstadd_back(&msh->g_cmd, new);
	return (0);
}

int	list_cmd(t_msh *msh)
{
	int		i;
	char	*tmp;

	i = 0;
	msh->start = 0;
	msh->g_cmd = NULL;
	while (msh->str_name[i])
	{
		while (!check_char(msh->str_name[i], "|<>") && \
							msh->str_name[i] != '\0')
		{
			if (check_char(msh->str_name[i], "'\""))
				if (skip_quotes(msh, msh->str_name, &i))
					return (1);
			i++;
		}
		tmp = ft_substr(msh->str_name, msh->start, i - msh->start);
		if (creat_list(tmp, msh, &i))
			return (1);
	}
	return (0);
}
