/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeffere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:14:46 by pjeffere          #+#    #+#             */
/*   Updated: 2021/11/19 23:58:34 by bmohamme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_malloc(t_msh *msh)
{
	int	i;

	msh->num_of_cmd = ft_lstsize(msh->g_cmd);
	msh->pipe_fd = malloc(sizeof(int *) * (msh->num_of_cmd));
	i = -1;
	while (++i < msh->num_of_cmd)
		msh->pipe_fd[i] = malloc(sizeof(int) * 2);
	i = -1;
	while (++i < msh->num_of_cmd)
		pipe(msh->pipe_fd[i]);
}

void	check(t_msh *msh, t_list *tmp, int i)
{
	if (tmp && tmp->next)
		many_pipe(msh, tmp, i);
	else
		without_pipe(msh, tmp);
}

void	without_pipe(t_msh *msh, t_list *tmp)
{
	int		pid;

	pid = fork();
	if (pid == 0)
		chose_builtin(tmp, msh);
	else
		wait(&pid);
}

void	many_pipe(t_msh *msh, t_list *tmp, int i)
{
	int	pid;

	while (tmp)
	{
		pid = fork();
		if (pid == 0)
		{
			if (i == 0)
				one_pipe(msh, i);
			if (i != 0 && tmp->next != NULL)
				more_than_2_pipe(msh, i);
			if (tmp->next == NULL)
				last_pipe(msh, i);
			chose_builtin(tmp, msh);
		}
		i++;
		tmp = tmp->next;
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}