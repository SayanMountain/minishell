#include "minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

static void one_pipe(t_msh *msh, int i)
{
	int j;

	j = -1;
	while (++j < msh->num_of_cmd)
	{
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
}

static void more_than_2_pipe(t_msh *msh, int i)
{
	int j ;

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
}


static void	last_pipe(t_msh *msh, int i)
{
	int j;

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
}

static void pipe_close(t_msh *msh)
{
	int j;

	j = -1;
	while(++j < msh->num_of_cmd)
	{
		close(msh->pipe_fd[j][0]);
		close(msh->pipe_fd[j][1]);
	}
}

static void pipe_waitpid(t_msh *msh)
{
	int i;
	i = -1;
	while (++i < msh->num_of_cmd)
		waitpid(-1, 0, 0);
}

static void	pipe_malloc(t_msh *msh)
{
	int i;

	msh->num_of_cmd = ft_lstsize(msh->g_cmd);
	msh->pipe_fd = malloc(sizeof(int *) * (msh->num_of_cmd));
	i = -1;
	while (++i < msh->num_of_cmd)
		msh->pipe_fd[i] = malloc(sizeof(int) * 2);
	i = -1;
	while (++i < msh->num_of_cmd)
		pipe(msh->pipe_fd[i]);
}

static void chose_builtin(t_list *tmp, t_msh *msh)
{
//	signal_pipes_cmd();
//	char *cmd_ls[3] = {"/bin/ls", NULL}; /// execve
//	char *cmd_cat[3] = {"/bin/cat", "-e"}; /// execve
	int y;

	y = 0;
	while (tmp->cmd[y])
	{
		if (!ft_strncmp(tmp->cmd[y], "cd", ft_strlen("cd")))
			run_cd_standart(msh);
		else if (!ft_strncmp(tmp->cmd[y], "pwd", ft_strlen("pwd")))
			run_pwd();
		else if (!ft_strncmp(tmp->cmd[y], "echo", ft_strlen("echo")))
			run_echo(msh);
		else if (!ft_strncmp(tmp->cmd[y], "export", ft_strlen("export")))
			run_export(msh, msh->g_cmd);
		else if (!ft_strncmp(tmp->cmd[y], "unset", ft_strlen("unset")))
			run_unset(msh, msh->g_cmd);
		else if (!ft_strncmp(tmp->cmd[y], "exit", ft_strlen("exit")))
			run_exit(msh);
		else if (!ft_strncmp(tmp->cmd[y], "env", ft_strlen("env")))
			run_env(msh);
		else if (!ft_strncmp(tmp->cmd[y], "cat", ft_strlen("cat")))
			execve("/bin/cat", tmp->cmd, msh->a_env);
		else if (!ft_strncmp(tmp->cmd[y], "ls", ft_strlen("ls")))
			execve("/bin/ls", tmp->cmd, msh->a_env);
		y++;

	}
	exit(0);
}

int	all_command(t_msh *msh)
{
	int i;
	int pid;

//	signal_pipes_cmd();
	pipe_malloc(msh);
	t_list *tmp;
	tmp = msh->g_cmd;
	i = 0;
	if(tmp->next)
	{
		while (tmp)
		{
			pid = fork();
			if (pid == 0)
			{
				if (i == 0)                                             /* 1 pipe */
					one_pipe(msh, i);
				if (i != 0 && tmp->next != NULL)                       	/* more than 1 pipe */
					more_than_2_pipe(msh, i);
				if (tmp->next == NULL)                                  /* last pipe */
					last_pipe(msh, i);
				chose_builtin(tmp, msh);
			}
			i++;
			tmp = tmp->next;
		}
	}
	else
	{
		pid = fork();
		if(pid == 0)
			chose_builtin(tmp, msh);
		else
			wait(&pid);
	}
	pipe_close(msh);
	pipe_waitpid(msh);
	return 1;
}


//	str = ft_strtrim(tmp->cmd[1], "123");
//	str = ft_substr(tmp->cmd[1], 4, ft_strlen(tmp->cmd[1] + 4));
//	str = ft_substr(tmp->cmd[1], 3, );