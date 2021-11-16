#include "minishell.h"

void run_unset(t_msh *msh, t_list *tmp)
{
	t_env		*list_unset;
//	t_env		*list_unset_cmd;
//	int 		i;
	char 		*str;

	list_unset = msh->g_env;
	str = tmp->cmd[1];

	while(list_unset)
	{
		if(ft_strcmp(list_unset->str, str))
			printf("unset удалить = %s\n", str);
		list_unset = list_unset->next;
	}

//	if(ft_strchr(list_unset->cmd[1]))
}