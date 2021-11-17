#include "minishell.h"

//char	*dollar(char *str, int *i, char **env)
//{
//	int j = *i;
//	char *tmp;
//	char *tmp2;
//	char *tmp3;
//
//	while(str[++(*i)])
//	{
//		if(str[*i] == '\'')
//			break ;
//	}
//	tmp = ft_substr(str, 0, j);
//	tmp2 = ft_substr(str, j + 1, *i - j - 1);
//	tmp3 = ft_strdup(str + *i + 1);
//	tmp = ft_strjoin(tmp, tmp2);
//	tmp = ft_strjoin(tmp, tmp3);
//	printf("tmp = %s\n", tmp);
//	free(str);
//	return (tmp);
//}