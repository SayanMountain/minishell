/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeffere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:01:24 by pjeffere          #+#    #+#             */
/*   Updated: 2021/11/19 16:01:26 by pjeffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//static char	*go_env(t_env *env, char *key)
//{
//	while (env)
//	{
//		if (!ft_strncmp(env->str, key, ft_strlen(key)))
//		{
//			return (env->str);
//		}
//		env = env->next;
//	}
//	return (NULL);
//}

static void	ft_lstdelone(t_env *start, t_env *del)
{
	t_env	*tmp;
	t_env	*env;
	int		i;

	i = 0;
	if (!del)
		return ;
	env = start;
	while (env)
	{
		if (env->next == del)
			break ;
		env = env->next;
		i++;
	}
	if (env == NULL)
		return ;
	tmp = del->next;
	free(del->str);
	free(del);
	env->next = tmp;
}

void	run_unset(t_msh *msh, t_list *tmp)
{
	t_env		*list_unset;
	char		*str;

	list_unset = msh->g_env;
	str = tmp->cmd[1];
	while (list_unset)
	{
		if (!ft_strncmp(list_unset->str, str, 3))
			ft_lstdelone(msh->g_env, list_unset);
		list_unset = list_unset->next;
	}
}
