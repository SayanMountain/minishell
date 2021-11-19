#include "minishell.h"

void	printnl_exit(void)
{
	write(2, "\n", 1);
//	g_status = 1;
	exit(1);
}

void	heredoc_signal(void)
{
	signal(SIGTERM, SIG_DFL);
	signal(SIGINT, (void *)printnl_exit);
	signal(SIGQUIT, SIG_DFL);
}

void	double_left_red(t_list *tmp, t_msh *msh, char *file)
{
	int	pid;
//	int	i;
	(void )msh;
	(void )tmp;
	(void )file;
	int status;

	pipe(tmp->pipe_h);
	pid = fork();
	if (pid == 0)
	{
		heredoc_signal();
		redirect_child(tmp, file);
	}
	else
		waitpid(pid, &status, 0);
	close(tmp->pipe_h[1]);
	status = WEXITSTATUS(status);
	if (status == 1)
	{
//		g_status = 1;
		close(tmp->pipe_h[0]);
		return ;
	}

}

void	right_redir(t_list *tmp, char *spec_ch, char *file)
{
	if (!ft_strncmp(spec_ch, ">>", 2))
		tmp->red_outp = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (!ft_strncmp(spec_ch, ">", 1))
		tmp->red_outp = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
}

int		one_left_red(t_list *tmp, char *file)
{
	tmp->red_inp = open(file, O_RDONLY);
	if (!tmp->red_inp)
	{
		error_msg(4, 0);
		return(1);
	}
	return (0);
}

int 	open_redirect(t_list *tmp, t_msh *msh, char *spec_ch, char *file)
{
//	(void )msh;
	if (!ft_strncmp(spec_ch, "<<", 2))
		double_left_red(tmp, msh, file);
	else if (!ft_strncmp(spec_ch, ">>", 2) || !ft_strncmp(spec_ch, ">", 1))
		right_redir(tmp, spec_ch, file);
	else if (!ft_strncmp(spec_ch, "<", 1))
		if (one_left_red(tmp, file))
			return (1);
	return (0);
}

int 	redirect(t_msh *msh, t_list *tmp, int *i)
{
	char	*spec_ch;
	char	*file;
	(void )tmp;
	spec_ch = ft_substr(msh->str_name, msh->start, *i - msh->start);
//	printf("spec - %s\n", spec_ch);
	check_space(msh, msh->str_name, i);
	while (msh->str_name[*i] && msh->str_name[*i] != ' ')
	{
		if (check_char(msh->str_name[*i], "'\""))
			skip_quotes(msh, msh->str_name, i);
		(*i)++;
	}
	file = ft_substr(msh->str_name, msh->start, *i - msh->start);
//	printf("File - %s\n", file);
//	printf("spec - %s\n", file);
	check_space(msh, msh->str_name, i);
	if (open_redirect(tmp, msh, spec_ch, file))
		return (1);
	return (0);
}