#include "minishell.h"

void export(t_msh *msh)
{
	char *tmp;
	int i;
	int tmp3;
	int tmp4;


	i = 0;
	tmp3 = ft_strlen(msh->string_name);
	tmp4 = ft_strlen("export");
	if(tmp3 > tmp4)
	{
		if(!ft_strncmp(msh->string_name, "export ", ft_strlen("export ")))
		{
			tmp = msh->string_name;
			tmp = ft_substr(tmp, 7, ft_strlen(msh->string_name) - 7);
			msh->g_env[i] = tmp;
		}
	}
	else
	{
		if(!ft_strncmp(msh->string_name, "export", ft_strlen("export")))
		{
			printf("КОД, ЧТОБЫ EXPORT СОРТИРОВАЛ АЛФАВИТУ (key)!!!!!\n");
		}
	}
}

