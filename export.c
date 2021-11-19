/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeffere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:12:28 by pjeffere          #+#    #+#             */
/*   Updated: 2021/11/19 16:12:33 by pjeffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



static void alphabet_env(t_msh *msh)
{
	int 		i;
	int 		j;
	t_env		*list_unset;
	int 		x;
	char		*str;
	char		*str1;
	char		*tmp;

	i = 0;
	list_unset = msh->g_env;
	str = &msh->g_env->str[0];
	str1 = &msh->g_env->next->str[0];
	x = ft_lstsize_2_env(msh->g_env);

	while(i < x)
	{
		j = 0;
		while(j < x - 1)
		{
			if(ft_strcmp(&str[j], &str1[j + 1]) > 0)
			{
				tmp = &str[j];
				str[j] = str1[j + 1];
				str1[j + 1] = *tmp;
			}
			j++;
		}
		i++;
	}

//	run_env(msh);
}

void	run_export(t_msh *msh, t_list *tmp)
{
	if (tmp->cmd[0] && !tmp->cmd[1])
	{
//		printf("@@@@\n");
		alphabet_env(msh);

	}
	if (!ft_strchr(tmp->cmd[1], '='))
	{
		printf("export: `%s': not a valid identifier\n", tmp->cmd[1]);
	}
	if (tmp->cmd[2])
		printf("export: `%s': not a valid identifier\n", tmp->cmd[2]);
	if (tmp->cmd[3])
		printf("export: `%s': not a valid identifier\n", tmp->cmd[3]);

}
