/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeffere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:21:01 by pjeffere          #+#    #+#             */
/*   Updated: 2021/11/19 16:21:04 by pjeffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	invitation(t_msh *msh)
{
	while (1)
	{
		msh->str_name = readline("minishell> ");
		add_history(msh->str_name);
		if (msh->str_name == NULL)
		{
			printf("exit\n");
			exit(0);
		}
		if (!msh->str_name[0])
			continue;
		if (preparser(msh))
			continue ;
		if (parser(msh))
			continue ;
		all_command(msh);
		clean_lists(msh);
	}
}
