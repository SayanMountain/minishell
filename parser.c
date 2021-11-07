#include "minishell.h"

void parser(t_msh *msh)
{

	list_cmd(msh);
	split_str_cmd(msh);
	print_list(msh->g_cmd);
}

