//#include "minishell.h"
//
//void	create_and_launch_pipes(t_msh *msh)
//{
//	int i;
//
//	/**		маллок на количество команд(аргументов) в строке.
//	 **		уточнить/найти значение total_cmd (Евгений)
//	 **/
//	msh->num_of_cmd = 1;
//	msh->pipe_fd = malloc(sizeof(int *) * (msh->num_of_cmd));
//
//	i = 0;
//	while(i < msh->num_of_cmd)
//	{
//		msh->pipe_fd[i] = malloc(sizeof(int) * 2);
//		if(msh->pipe_fd[i])
//		{
//			if(pipe(msh->pipe_fd[i]))
//			{
//				print_msg(ERROR_in_pipes);
//				free(msh->pipe_fd[i]), msh->pipe_fd[i] = NULL;
//				return ;
//			}
//			else
//				print_msg(Error_in_malloc);
//			i++;
//		}
//		msh->pipe_fd[i] = NULL;
//	}
//}
//
//void	close_opened_pipes(int pipe_id, t_msh *msh, t_cmd)
//{
//	int i;
//
//	i = 0;
//	pipe_id -= 1;
//	while(msh->pipe_fd[i] && msh->pipe_fd[i + 1])
//	{
//		if(i != pipe_id)
//			close(msh->pipe_fd[i + 1] [1]), msh->pipe_fd[i + 1][1] = -1;
//		i++;
//	}
//	if(msh->pipe_fd[0] && pipe_id != -1)
//		close(msh->pipe_fd[0] [1]), msh->pipe_fd[0][1] = -1;
//	i = 0;
//	while(msh->pipe_fd[i])
//	{
//		if(i != pipe_id)
//			close(msh->pipe_fd[i][0]), msh->pipe_fd[i][0] = -1;
//		i++;
//	}
//	if(msh->pipe_fd[pipe_id] && msh->)
//}