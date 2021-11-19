/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeffere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:19:59 by pjeffere          #+#    #+#             */
/*   Updated: 2021/11/19 16:20:03 by pjeffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_env(t_msh *msh)
{
	t_env	*env_env;

	env_env = msh->g_env;
	while (env_env)
	{
		printf("%s\n", env_env->str);
		env_env = env_env->next;
	}
}
