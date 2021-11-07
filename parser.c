/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmohamme <bmohamme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:01:23 by bmohamme          #+#    #+#             */
/*   Updated: 2021/11/07 21:14:15 by bmohamme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void parser(t_msh *msh)
{

	list_cmd(msh);
	split_str_cmd(msh);
	remove_quotes(msh);

	print_list(msh->g_cmd);
}

