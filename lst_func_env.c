/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func_env.c                                      :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeffere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:14:46 by pjeffere          #+#    #+#             */
/*   Updated: 2021/11/19 17:14:47 by pjeffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_lstlast_env(t_env *lst)
{
	t_env	*tmp;

	tmp = lst;
	if (tmp == NULL)
		return (tmp);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

t_env	*ft_lstnew_env(char *content)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (new == NULL)
		return (NULL);
	new->str = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back_env(t_env **lst, t_env *new)
{
	t_env	*tmp;

	if (lst && new)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			tmp = ft_lstlast_env(*lst);
			tmp->next = new;
		}
	}
}


int	ft_lstsize1(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
