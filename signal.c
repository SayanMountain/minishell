/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeffere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:01:29 by pjeffere          #+#    #+#             */
/*   Updated: 2021/11/19 13:01:41 by pjeffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_signal_pipes(int sig)
{
	signal(SIGINT, SIG_IGN);
	(void)sig;
}

void	ft_signal_run_pipes(void)
{
	signal(SIGINT, ft_signal_pipes);
	signal(SIGQUIT, ft_signal_pipes);
}

void	ft_signal_cltr_c(int sig)
{
	(void)sig;
	write(2, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	g_status = "130";
}

void	ft_signal_in_child(void)
{
	signal(SIGTERM, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	ft_signal_main(void)
{
	signal(SIGTERM, SIG_IGN);
	signal(SIGINT, ft_signal_cltr_c);
	signal(SIGQUIT, SIG_IGN);
}
