#include "minishell.h"

//static char *quotes_u(char *argv, int i)
//{
//	int g;
//	char *tmp1;
//	char *tmp2;
//	char *tmp3;
//
//	g = i;
//	while(argv[++i])
//		if(argv[i] == '\'')
//			break ;
//	tmp1 = ft_substr(argv, 0, g);
//	tmp2 = ft_substr(argv, g + 1, i - g - 1);
//	tmp3 = ft_strdup(argv + i + 1);
//	tmp1 = ft_strjoin(tmp1, tmp2);
//	tmp1 = ft_strjoin(tmp1, tmp3);
//	printf("%s\n", tmp1);
//	printf("%s", tmp1);
//	return (tmp1);
//}
////парсер error
//// parser_error
//
//
//static char *quotes_d(char *argv, int i)
//{
//	int g;
//	char *tmp1;
//	char *tmp2;
//	char *tmp3;
//
//	g = i;
//	while(argv[++i])
//		if(argv[i] == '\"')
//			break ;
//	tmp1 = ft_substr(argv, 0, g);
//	tmp2 = ft_substr(argv, g + 1, i - g - 1);
//	tmp3 = ft_strdup(argv + i + 1);
//	tmp1 = ft_strjoin(tmp1, tmp2);
//	tmp1 = ft_strjoin(tmp1, tmp3);
//	printf("%s\n", tmp1);
//	printf("%s", tmp1);
//	return (tmp1);
//}
//
//char	*check_quotes(char *argv)
//{
//	int j;
//	char *str;
//	str = NULL;
//
//	j = 0;
//	while(argv[j])
//	{
//		if(argv[j] == '\"')
//		{
//			str = quotes_d(&argv[j], j);
//			break;
//		}
//		if(argv[j] == '\'')
//		{
//			str = quotes_u(&argv[j], j);
//			break;
//		}
//		j++;
//	}
//	return (str);
//}

void parser(t_msh *msh)
{
	int i;
//	int x;
//	int j;
//	char	*str;

	i = 0;
//	x = 0;
//	str = NULL;
	while(msh->string_name[i++])
	{
		printf("%c\n", msh->string_name[i]);
//		j = 0;
//		str = check_quotes(argv[i]);
//		if (str != NULL)
//			while (*str)
//			{
//				com_str[x][j++] = (*str)++;
//			}
//		else
//			while (argv[i][j])
//			{
//				com_str[x][j] = argv[i][j];
//				j++;
//			}
////		free(str);
//		x++;
//		i++;
	}
}