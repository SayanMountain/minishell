#include "minishell.h"

//void invitation(t_msh *msh, char **argv, char **env)
void invitation(t_msh *msh)
{
//	t_env	*new_list;
	while(1)
	{
		msh->string_name = readline("minishell> ");
		add_history(msh->string_name);
		if (preparser(msh))
			continue;
		if (parser(msh))
			continue;
//		check_cmd(msh);
		all_command(msh);
//		new_list = ft_lstlast_env(msh->g_env);
//		printf("%s\n", new_list->str);
		clean_lists(msh);

	}
}
