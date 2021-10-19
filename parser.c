#include "minishell.h"

static void quotes_u(char *argv, int *i)
{
	int g;
	char *tmp1;
	char *tmp2;
	char *tmp3;

	g = *i;
	while(argv[++(*i)])
		if(argv[*i] == '\'')
			break ;
	tmp1 = ft_substr(argv, 0, g);
	tmp2 = ft_substr(argv, g + 1, *i - g - 1);
	tmp3 = ft_strdup(argv + *i + 1);
	tmp1 = ft_strjoin(tmp1, tmp2);
	tmp1 = ft_strjoin(tmp1, tmp3);

	printf("%s\n", tmp1);
}

static void quotes_d(char *argv, int *i)
{
	int g;
	char *tmp1;
	char *tmp2;
	char *tmp3;

	g = *i;
	while(argv[++(*i)])
		if(argv[*i] == '\"')

			break ;
	tmp1 = ft_substr(argv, 0, g);
	tmp2 = ft_substr(argv, g + 1, *i - g - 1);
	tmp3 = ft_strdup(argv + *i + 1);
	tmp1 = ft_strjoin(tmp1, tmp2);
	tmp1 = ft_strjoin(tmp1, tmp3);

	printf("%s\n", tmp1);
}

void parser(char *argv)
{
	int i;

	i = 0;
	while(argv[i])
	{
		if(argv[i] == '\'')
				quotes_u(argv, &i);
		if(argv[i] == '\"')
				quotes_d(argv, &i);
		i++;
	}
}