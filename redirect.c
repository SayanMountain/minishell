//#include "minishell.h"
//
//void	redirect_detect(t_msh *msh)
//{
//	t_redir *tmp;
//
//	tmp = msh->g_cmd->redir;
//
//	while(tmp)
//	{
//		if(!ft_strncmp(tmp->value, "<<", 2))
//			left_left_arrow(msh, + 2);
//		if(!ft_strncmp(tmp->value, "<", 1))
//			open_file(msh, L_ARR);
//		if(!ft_strncmp(tmp->value, ">>", 2))
//			open_file(msh, R_D_ARR);
//		if(!ft_strncmp(tmp->value, ">", 1))
//			open_file(msh, R_ARR);
//	}
//}
//
//void	left_left_arrow(t_msh *msh, t_cmd *cmd, char *stop)
//{
//	int	fd[2];
//	int	pid;
//
//	if (cmd->in)
//	close(cmd->in);
//	if (pipe(fd) < 0)
//	{
//		if (cmd->is_fork)
//			printf("open_file, if (cmnd->is_fork)\n");
//			exit(0);
////			ft_critical_error(0, 0, 0);
//		else
//			printf("open_file, if (cmnd->is_fork)\n");
//			exit(0);
////			ft_raise_error(NULL, NULL);
//	}
//	pid = fork();
//	if (pid)
//	{
//		waitpid(pid, 0, 0);
//		cmd->in = fd[0];
//		close(fd[1]);
//	}
//	else
//	{
//		close(fd[0]);
//		cmd->out = fd[1];
//		left_left_readarrow(msh, cmd, stop);
//	}
//}
//
//void	left_left_readarrow(t_msh *msh, t_cmd *cmd, char *stop)
//{
//	char	*line;
//
//	(void)msh;
//	while(true)
//	{
//		line = readline("> ");
//		if (!ft_strncmp(line, stop, ft_strlen(stop) + 1))
//			break ;
//		ft_putendl_fd(line, cmd->out);
//		free(line);
//	}
//	close(cmd->out);
//	exit(0);
//}
//
//
///* rename */
//void	open_file(t_cmd *cmd, char *fname, int mode)
//{
//	if (mode == L_ARR)
//	{
//		if (cmd->in != STDIN)
//			close(cmd->in);
//		cmd->in = open(fname, O_RDONLY);
//	}
//	else
//	{
//		if (cmd->out != STDOUT)
//			close(cmd->out);
//		if (mode == R_ARR)
//			cmd->out = open(fname, O_RDWR | O_CREAT | O_TRUNC, 00774);
//		else if (mode == R_D_ARR)
//			cmd->out = open(fname, O_WRONLY | O_APPEND | O_CREAT, 00774);
//	}
//	if (cmd->in < 0 || cmnd->out < 0)
//	{
//		if (cmd->is_fork)
//			printf("open_file, if (cmnd->is_fork)\n");
//			exit(0);
////			ft_critical_error(NULL, fname, 1);
//		else
//			printf("open_file, else\n");
//			exit(0);
////			ft_raise_error(NULL, fname);
//	}
//}



//- какие файлы есть и какие создать, считать, записать + дать права
//- может быть два редиректа на один пайп
//	специальный ли это файл
//
//
//
//
//
//get_redirects
//	double_left_arrow
//	redirect_open_file
//	redirect_open_file
//	redirect_open_file