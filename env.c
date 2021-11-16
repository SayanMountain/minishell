#include "minishell.h"

void run_env(t_msh *msh)
{
	t_env	*env_env;

	env_env = msh->g_env;
	while(env_env) /* env_env->next */
	{
		printf("%s\n", env_env->str);
		env_env = env_env->next;
	}
}
