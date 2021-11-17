#include "minishell.h"

void invitation(t_msh *msh)
{

	while(1)
	{
		msh->str_name = readline("minishell> ");
		add_history(msh->str_name);
		if (preparser(msh))
			continue;
		if (parser(msh))
			continue;
		check_cmd(msh);
		all_command(msh);
		clean_lists(msh);
	}
}
