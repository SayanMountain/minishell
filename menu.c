//#include "minishell.h"
//
//void	fill_hist(char *str)
//{
//	int		fd;
//	char	*line;
//
//	fd = open(str, O_CREAT | O_RDWR | O_APPEND, 0777);
//
//	while (get_next_line(fd, &line) > 0)
//	{
//		add_history(str);
//		free(line);
//	}
//	free(str);
//	close(fd);
//}
//
//char	*env_search(char *str)
//{
//	int	i;
//	int j;
//	int k;
//	char	*way;
//
//	i = 0;
//	j = 0;
//	k = 0;
//	while (ft_memcmp(g_env.envp[i], str, ft_strlen(str)) != 0)
//		i++;
//	while (g_env.envp[i][j] != '=')
//		j++;
//	way = malloc(sizeof (char ) * (ft_strlen(g_env.envp[i]) - (ft_strlen(str) + 1)));
//	while (g_env.envp[i][j++])
//	{
//		way[k] = g_env.envp[i][j];
//		k++;
//	}
//	way = ft_strjoin(way, "/.minishell_history");
//	return (way);
//}
//
//void	record_hist(char *str)
//{
//	int	fd;
//	char	*way;
//
//	way = env_search(str);
//	fd = open(way, O_CREAT | O_RDWR | O_APPEND, 0777);
//	ft_putstr_fd(str, fd);
//	ft_putstr_fd("\n", fd);
//	add_history(str);
//	free(way);
//	close(fd);
//}
//
//void invitation(void)
//{
//	char	*way_hist;
//	char	*string_invite;
//	char	*string_name;
//
//	way_hist = env_search("HOME");
//	fill_hist(way_hist);
//	while(1)
//	{
//		string_invite = ft_strdup("minishell> ");
//		string_name = readline(string_invite);
//		if (string_name[0])
//			record_hist(string_name);
//
//
//	}
//}
