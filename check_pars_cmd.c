/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pars_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeffere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:19:33 by pjeffere          #+#    #+#             */
/*   Updated: 2021/11/19 16:19:35 by pjeffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**search_path(char **arr)
{
	int		i;
	size_t	c;
	char	*str;
	char	**arr_path;

	i = -1;
	c = -1;
	while (arr[++i] && ft_strncmp(arr[i], "PATH", ft_strlen("PATH")));
	while (++c < (ft_strlen("PATH") + 1));
	str = ft_strdup(&arr[i][c]);
	arr_path = ft_split(str, ':');
	free(str);
	return (arr_path);
}

char	*ft_access(char *str, char **arr)
{
	int		i;
	char	*string;

	i = -1;
	while (arr[++i])
	{
		string = ft_strjoin(arr[i], "/");
		string = ft_strjoin(string, str);
		if (access(string, 1) == 0)
			return(string);
	}
	return(NULL);
}

char	*check_cmd(t_msh *msh, char *str)
{
	char	**arr;
	char	*string;

	arr = search_path(msh->a_env);
	string = ft_access(str, arr);
	if (string == NULL)
	{
		error_msg(5, 0);
		exit(1);
	}
	else
		return (string);
}
