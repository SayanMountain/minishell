#include "minishell.h"

void cmd_exit (t_msh *msh)
{
	ft_putstr_fd(msh->string_name, 1);
	ft_putendl_fd("\n", 1);
	exit(0);
}