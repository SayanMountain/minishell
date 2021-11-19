/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addit_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmohamme <bmohamme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 00:34:21 by bmohamme          #+#    #+#             */
/*   Updated: 2021/11/20 00:34:21 by bmohamme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_msg(int i, char c)
{
	if (i == 1)
		printf("No closing quote\n");
	if (i == 2)
		printf("syntax error near unexpected token `%c'\n", c);
	if (i == 3)
		printf("syntax error near unexpected token `||'\n");
	if (i == 4)
		printf("file read error\n");
	if (i == 5)
	{
		printf("127: command not found\n");
//		g_status = "127: command not found";
	}

	//	exit(1);
}

void	clean_lists(t_msh *msh)
{
	int		i;
	t_list	*tmp;

	tmp = msh->g_cmd;
	while (tmp)
	{
		i = 0;
		while (tmp->cmd[i])
		{
			//			printf("строка - %s\n", tmp->cmd[i - 1]);
			free(tmp->cmd[i]);
			tmp->cmd[i] = NULL;
			i++;
		}
		if (tmp->str)
			free(tmp->str);
		tmp->str = NULL;
		free(tmp->cmd);
		tmp->cmd = NULL;
		tmp = tmp->next;
		free(msh->g_cmd);
		msh->g_cmd = tmp;
	}
}

void	check_space(t_msh *msh, char *str, int *i)
{
	while (str[*i] && str[*i] == ' ')
		(*i)++;
	msh->start = *i;
}

int	ft_strcmp1(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}
