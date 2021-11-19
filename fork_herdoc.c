#include "minishell.h"

void	ft_signal_cltr_c_2(int sig)
{
	(void)sig;
	write(2, "\n", 1);
//	g_status = "-101";
}

void	redirect_child(t_list *tmp, char *file)
{
	char	*line;

//	ctrl_ign();
//	ft_signal_main();
	while (1)
	{
		line = readline("> ");
		if (!line)
			exit(0);
		if (ft_strcmp1(line, file) == 0)
		{
			free(file);
			break ;
		}
		write(tmp->pipe_h[1], line, ft_strlen(line));
		write(tmp->pipe_h[1], "\n", 1);
	}
	free(line);
	close(tmp->pipe_h[1]);
	exit(1);
}

void	redirect_parent(t_list *tmp, t_msh *msh, pid_t pid)
{
	int	he;
	(void )msh;
//	g_status = "0";
	signal(SIGINT, ft_signal_cltr_c_2);
	close(tmp->pipe_h[1]);
	waitpid(pid, &he, WUNTRACED);
	ft_signal_main();
	if (he / 256 == 5)
	{
//		tmp->pipe_h = 0;
		write(1, "\n", 1);
//		mini->count_cmd = 0;
	}
}