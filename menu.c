#include "minishell.h"

void invitation(t_msh *msh)
{
//	char	*string_invite;

	while(1)
	{
//		string_invite = ft_strdup("minishell> ");
		msh->string_name = readline("minishell> ");
		add_history(msh->string_name);
		parser(msh);
		all_command(msh);
	}
}
