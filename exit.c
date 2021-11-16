#include "minishell.h"

//void run_exit (t_msh *msh)
//{
//	int i = 0;
//	t_list *tmp;
//
//	tmp = msh->g_cmd;
//	printf("%s\n", tmp->cmd[i]);
//		exit(0);
//}

void run_exit (t_msh *msh)
{
	(void)msh;
	printf("exit\n");
	exit(0);
}