/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeffere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:02:23 by pjeffere          #+#    #+#             */
/*   Updated: 2021/11/19 16:02:27 by pjeffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_pwd(void)
{
	char	buffer[1000];

	if (getcwd(buffer, 200) == 0)
		exit(0);
	printf("%s\n", buffer);
}
