/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_com.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeffere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:25:18 by pjeffere          #+#    #+#             */
/*   Updated: 2021/11/19 16:25:29 by pjeffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	chose_builtin(t_list *tmp, t_msh *msh)
{
	if (!ft_strncmp(tmp->cmd[0], "cd", ft_strlen("cd")))
		run_cd_standart(msh);
	else if (!ft_strncmp(tmp->cmd[0], "pwd", ft_strlen("pwd")))
		run_pwd();
	else if (!ft_strncmp(tmp->cmd[0], "echo", ft_strlen("echo")))
		run_echo(msh);
	else if (!ft_strncmp(tmp->cmd[0], "export", ft_strlen("export")))
		run_export(msh, msh->g_cmd);
	else if (!ft_strncmp(tmp->cmd[0], "unset", ft_strlen("unset")))
		run_unset(msh, msh->g_cmd);
	else if (!ft_strncmp(tmp->cmd[0], "exit", ft_strlen("exit")))
		run_exit(msh);
	else if (!ft_strncmp(tmp->cmd[0], "env", ft_strlen("env")))
		run_env(msh);
	else
		execve(check_cmd(msh, tmp->cmd[0]), tmp->cmd, msh->a_env);
}

int	all_command(t_msh *msh)
{
	int			i;
	t_list		*tmp;

	tmp = msh->g_cmd;
	pipe_malloc(msh);
	i = 0;
	check(msh, tmp, i);
	pipe_close(msh);
	pipe_waitpid(msh);
	return (1);
}
