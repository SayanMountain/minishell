#include "minishell.h"

//https://github.com/Avchar/minishell/blob/develop/srcs/own_progc.c

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	all_command(t_msh *msh)
{
	char *cmd_ls[3] = {"/bin/ls", NULL}; /// execve
	char *cmd_cat[3] = {"/bin/cat", "-e"}; /// execve
	int i;
	int j;
	int pid;


	t_list *tmp;
	tmp = msh->g_cmd;
	msh->num_of_cmd = ft_lstsize(msh->g_cmd);
//	printf("num_of_cmd = %d\n", msh->num_of_cmd);
	msh->pipe_fd = malloc(sizeof(int *) * (msh->num_of_cmd));

	i = 0;
	while (i < msh->num_of_cmd)
	{
		msh->pipe_fd[i] = malloc(sizeof (int) * 2);
		i++;
	}
	i = 0;
	while (i < msh->num_of_cmd)
	{
		pipe(msh->pipe_fd[i]);
		i++;
	}

	i = 0;
	while(tmp)
	{
		pid = fork();
		if (pid == 0)
		{
//			if (msh->numof_cmd == 2)
			if (i == 0)
			{
				j = -1;
				while (++j < msh->num_of_cmd)
//				while (msh->num_of_cmd == 2)
				{
//					printf("for_1\n");
					 if (msh->pipe_fd[j][1] == msh->pipe_fd[i + 1][1])
						 continue;
					 close(msh->pipe_fd[j][1]);
				}
				j = -1;
				while (++j < msh->num_of_cmd)
				{
					close(msh->pipe_fd[j][0]);
				}
				dup2(msh->pipe_fd[i + 1][1], 1);
				close(msh->pipe_fd[i + 1][1]);
//				execve("/bin/ls", cmd_ls, msh->g_env);
			}
			if (i != 0 && tmp->next != NULL)
//			if (msh->num_of_cmd > 2 && tmp->next != NULL)
			{
//				printf("for_2\n");
				j = -1;
				while(++j < msh->num_of_cmd)
				{
					if(msh->pipe_fd[j][1] == msh->pipe_fd[i + 1][1])
						continue;
					close(msh->pipe_fd[j][1]);
				}
				j = -1;
				while(++j < msh->num_of_cmd)
				{
					if(msh->pipe_fd[j][0] == msh->pipe_fd[i][0])
						continue;
					close(msh->pipe_fd[j][0]);
				}
				dup2(msh->pipe_fd[i][0], 0);
				dup2(msh->pipe_fd[i + 1][1], 1);
				close(msh->pipe_fd[i][0]);
				close(msh->pipe_fd[i + 1][1]);
//				execve("/bin/cat", cmd_ls, msh->g_env);
			}
			if (tmp->next == NULL)  /* pipe count */
			{
//				printf("for_3\n");
				j = -1;
				while(++j < msh->num_of_cmd)
				{
					if(msh->pipe_fd[j][0] == msh->pipe_fd[i][0])
						continue;
					close(msh->pipe_fd[j][0]);
				}
				j = -1;
				while(++j < msh->num_of_cmd)
				{
					close(msh->pipe_fd[j][1]);
				}
				dup2(msh->pipe_fd[i][0], 0);
				close(msh->pipe_fd[i][0]);
//				execve("/bin/cat", cmd_cat, msh->g_env);
			}

			int y = 0;
			while(tmp->cmd[y])
			{
				if (!ft_strncmp(tmp->cmd[y], "cd", ft_strlen("cd")))
					run_cd_standart(msh);
				if (!ft_strncmp(tmp->cmd[y], "pwd", ft_strlen("pwd")))
					run_pwd();
				if (!ft_strncmp(tmp->cmd[y], "echo", ft_strlen("echo")))
					run_echo(msh);
				if (!ft_strncmp(tmp->cmd[y], "export", ft_strlen("export")))
					run_export(msh, msh->g_cmd);
				if (!ft_strncmp(tmp->cmd[y], "unset", ft_strlen("unset")))
					run_unset(msh, msh->g_cmd);
				if (!ft_strncmp(tmp->cmd[y], "exit", ft_strlen("exit")))
					run_exit(msh);
				if (!ft_strncmp(tmp->cmd[y], "env", ft_strlen("env")))
					run_env(msh);
				if (!ft_strncmp(tmp->cmd[y], "cat", ft_strlen("cat")))
					execve("/bin/cat", cmd_cat, tmp->cmd);
				if (!ft_strncmp(tmp->cmd[y], "ls", ft_strlen("ls")))
					execve("/bin/ls", cmd_ls, tmp->cmd);
				y++;
			}
			exit(0);
		}
		i++;
		tmp = tmp->next;
	}
	j = -1;
	while(++j < msh->num_of_cmd)
	{
		close(msh->pipe_fd[j][0]);
		close(msh->pipe_fd[j][1]);
	}
	i = -1;
	while (++i < msh->num_of_cmd)
		waitpid(-1, 0, 0);
	return 1;
}



//int	all_command(t_msh *msh, char **argv, char **env)
//int	all_command(t_msh *msh)
////int	all_command(t_msh *msh, t_list **cmd)
//{
//	t_list *tmp;
//	int y = 0;
//	tmp = msh->g_cmd;
//	while(tmp)
//	{
//		while(tmp->cmd[y])
//		{
//		if (!ft_strncmp(tmp->cmd[y], "cd", ft_strlen("cd")))
//		{
//			run_cd_standart(msh);
//			printf("сd_complete\n");
//		}
//			if (!ft_strncmp(tmp->cmd[y], "pwd", ft_strlen("pwd")))
//				run_pwd();
//			if (!ft_strncmp(tmp->cmd[y], "export", ft_strlen("export")))
//				run_export(msh, msh->g_cmd);
//			if (!ft_strncmp(tmp->cmd[y], "exit", ft_strlen("exit")))
//				run_exit(msh);
//			if (!ft_strncmp(tmp->cmd[y], "echo", ft_strlen("echo")))
//				run_echo(msh);
//			if (!ft_strncmp(tmp->cmd[y], "env", ft_strlen("env")))
//				run_env(msh);
//			y++;
//		}
//		tmp = tmp->next;
//	}
//	return 1;
//}