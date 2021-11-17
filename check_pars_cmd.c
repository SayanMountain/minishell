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

int	ft_access(t_list *tmp, char **arr)
{
	int		i;
	char	*str;

	i = -1;
	while (arr[++i])
	{
		str = ft_strjoin(arr[i], "/");
		str = ft_strjoin(str, tmp->cmd[0]);
		if (access(str, 1) == 0)
			return(1);
	}
	return(0);
}

void	check_cmd(t_msh *msh)
{
	char	**arr;
	t_list	*tmp;
	tmp = msh->g_cmd;
	arr = search_path(msh->a_env);
	while (tmp)
	{
		if (!ft_access(tmp, arr))
			printf("%s: %s\n", tmp->cmd[0], "command not found");
		tmp = tmp->next;
	}
}
