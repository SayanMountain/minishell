#include "minishell.h"


void	processing_arr(t_list *tmp)
{
	int	i;

	i = 0;
	if (!ft_strncmp(tmp->cmd[0], "<", 1) && !ft_strncmp(tmp->cmd[0], "<<", 2))

	while (tmp->cmd[i])
	{

	}
}

void	check_pars_cmd(t_msh *msh)
{
	t_list	*tmp;

	tmp = msh->g_cmd;
	while (tmp)
	{
		processing_arr(tmp);
		tmp = tmp->next;
	}
}
