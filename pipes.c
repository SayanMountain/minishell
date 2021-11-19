/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeffere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:14:14 by pjeffere          #+#    #+#             */
/*   Updated: 2021/11/20 00:04:08 by bmohamme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	one_pipe(t_msh *msh, int i)
{
	int	j;

	j = -1;
	while (++j < msh->num_of_cmd)
	{
		if (msh->pipe_fd[j][1] == msh->pipe_fd[i + 1][1])
			continue ;
		close(msh->pipe_fd[j][1]);
	}
	j = -1;
	while (++j < msh->num_of_cmd)
	{
		close(msh->pipe_fd[j][0]);
	}
	dup2(msh->pipe_fd[i + 1][1], 1);
	close(msh->pipe_fd[i + 1][1]);
}

void	more_than_2_pipe(t_msh *msh, int i)
{
	int	j;

	j = -1;
	while (++j < msh->num_of_cmd)
	{
		if (msh->pipe_fd[j][1] == msh->pipe_fd[i + 1][1])
			continue ;
		close(msh->pipe_fd[j][1]);
	}
	j = -1;
	while (++j < msh->num_of_cmd)
	{
		if (msh->pipe_fd[j][0] == msh->pipe_fd[i][0])
			continue ;
		close(msh->pipe_fd[j][0]);
	}
	dup2(msh->pipe_fd[i][0], 0);
	dup2(msh->pipe_fd[i + 1][1], 1);
	close(msh->pipe_fd[i][0]);
	close(msh->pipe_fd[i + 1][1]);
}

void	last_pipe(t_msh *msh, int i)
{
	int	j;

	j = -1;
	while (++j < msh->num_of_cmd)
	{
		if (msh->pipe_fd[j][0] == msh->pipe_fd[i][0])
			continue ;
		close(msh->pipe_fd[j][0]);
	}
	j = -1;
	while (++j < msh->num_of_cmd)
	{
		close(msh->pipe_fd[j][1]);
	}
	dup2(msh->pipe_fd[i][0], 0);
	close(msh->pipe_fd[i][0]);
}

void	pipe_close(t_msh *msh)
{
	int	j;

	j = -1;
	while (++j < msh->num_of_cmd)
	{
		close(msh->pipe_fd[j][0]);
		close(msh->pipe_fd[j][1]);
		free(msh->pipe_fd[j]);
	}
	free(msh->pipe_fd);
}

void	pipe_waitpid(t_msh *msh)
{
	int		i;

	i = -1;
	while (++i < msh->num_of_cmd)
		waitpid(-1, 0, 0);
}
