#include "minishell.h"

void	fill_hist(char *str)
{
	int		fd;
	char	*line;

	fd = open(str, O_CREAT | O_RDWR | O_APPEND, 0777);

	while (get_next_line(fd, &line) > 0)
	{
		add_history(str);
		free(line);
	}
	free(str);
	close(fd);
}

char	*env_search(t_list **g_env, char *str)
{
	int	i;
	int k;
	char	*way;
	t_list	*tmp;

	i = 0;
	k = 0;
	tmp = *g_env;
	while (ft_memcmp(tmp->key, str, ft_strlen(str)) != 0)
		tmp = tmp->next;
	way = malloc(sizeof (char ) * (ft_strlen(tmp->value) + 1));
	while (tmp->value[i])
		way[k++] = tmp->value[i++];
	way[k] = '\0';
	way = ft_strjoin(way, "/.minishell_history");
//	printf("%s\n", way);
	return (way);
}

void	record_hist(t_list **g_env, char *str)
{
	int	fd;
	char	*way;

	way = env_search(g_env, str);
	fd = open(way, O_CREAT | O_RDWR | O_APPEND, 0777);
	ft_putstr_fd(str, fd);
	ft_putstr_fd("\n", fd);
	add_history(str);
	free(way);
	close(fd);
}

void invitation(t_list **g_env)
{
	char	*way_hist;
	char	*string_invite;
	char	*string_name;

//	printf("%s\n", (*g_env)->value);
	way_hist = env_search(g_env, "HOME");
	fill_hist(way_hist);
	while(1)
	{
		string_invite = ft_strdup("minishell> ");
		string_name = readline(string_invite);
		if (string_name[0])
			record_hist(g_env, string_name);
	}
}
