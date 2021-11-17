#include "minishell.h"

void	run_echo(t_msh *msh)
{
	t_list	*tmp;
	int		i;
	int		logic;

	tmp = msh->g_cmd;
	i = 1;
	logic = 1;
	if (tmp->cmd[0] && !tmp->cmd[1])
		printf("\n");
	if (tmp->cmd[1])
	{
		if (ft_strcmp(tmp->cmd[i], "-n") == 0)
			logic = 0;
		while (tmp->cmd[i])
		{
			if (ft_strcmp(tmp->cmd[i], "-n"))
			{
				ft_putstr_fd(tmp->cmd[i], 1);
				if (tmp->cmd[i + 1] && ft_strlen(tmp->cmd[i + 1]))
					write(1, " ", 1);
			}
			i++;
		}
		if (logic)
			write (1, "\n", 1);
	}
}
