#include "minishell.h"

static void quotes_u(char *argv)
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
//парсер error
// parser_error
static void quotes_d(char *argv)
{
	int g;

	g = -1;
	while(argv[++g])
		if(argv[g] == '\"')
			break ;
		if(argv[g] == '\"')

//		else
//			parser_error();
}

void parser(int argc, char **argv)
{
	int i;
	int j;
	int x;

	i = 1;
	j = 0;
	x = 0;
	com_str = malloc(sizeof(char*) * argc);

	while(argv[i])
	{
		while(argv[i][j])
		{
			if(argv[i][j] == '\'')
				quotes_u(argv[i]);
			if(argv[i][j] == '\"')
				quotes_d(argv[i]);
			else
				com_str[x][j] = argv[i][j];
			j++;
		}
		x++;
		i++;
	}
}