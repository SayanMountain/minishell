/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmohamme <bmohamme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:01:23 by bmohamme          #+#    #+#             */
/*   Updated: 2021/11/09 14:01:34 by bmohamme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int parser(t_msh *msh)
{
	if (list_cmd(msh))
		return(1);
	split_str_cmd(msh);
	remove_quotes(msh);
//	print_list(msh->g_cmd);
	return(0);
}

