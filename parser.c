/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmohamme <bmohamme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:01:23 by bmohamme          #+#    #+#             */
/*   Updated: 2021/11/19 17:03:39 by bmohamme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//int		check_red_quotes(t_list *tmp, int *i)
//{
//	if (tmp->str[*i] == '\"')
//		while (tmp->str[++(*i)] != '\"')
//		{
//			if (tmp->str[*i] == '<' || tmp->str[*i] == '>')
//			{
//				tmp->redirect = 0;
//			}
//			if (tmp->str[*i] == '\0')
//				return (0);
//		}
//	if (tmp->str[*i] == '\'')
//		while (tmp->str[++(*i)] != '\'')
//		{
//			if (tmp->str[*i] == '<' || tmp->str[*i] == '>')
//			{
//				tmp->redirect = 0;
//			}
//			if (tmp->str[*i] == '\0')
//				return (0);
//		}
//	return (0);
//}
//
//void	redirect_init(t_list *g_cmd)
//{
//	int		i;
//	t_list	*tmp;
//
//	tmp = g_cmd;
//	tmp->redirect = -1;
//	while (tmp)
//	{
//		i = -1;
//		while (tmp->str[++i])
//		{
//			if (tmp->str[i] == '>' || tmp->str[i] == '<')
//			{
//				tmp->redirect = 1;
//				break;
//			}
//			if (tmp->str[i] == '\"' || tmp->str[i] == '\'')
//				if (!check_red_quotes(tmp, &i))
//					break;
//		}
//		printf("redirect - %d\n", tmp->redirect);
//		tmp = tmp->next;
//	}
//}

int parser(t_msh *msh)
{
	if (list_cmd(msh))
		return(1);
//	signal_pipes_cmd();
	if (split_str_cmd(msh))
		return (1);
	remove_quotes(msh);
//	main_signals();
//	print_list(msh->g_cmd);
	return(0);
}

