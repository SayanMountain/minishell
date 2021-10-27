#ifndef MINISHELL_MINISHELL_H
#define MINISHELL_MINISHELL_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <fcntl.h>
# include <stdbool.h>
# include "./libft/libft.h"
# include "./GNL/get_next_line.h"
# include "struct.h"
# include <readline/readline.h>
# include <readline/history.h>

//char **com_str;

typedef struct 			s_cmd
{
	int a;
} 						t_cmd;


typedef struct 			s_env
{
	char 				*line_env;
	char 				*key;
	char				*value;
	int					code;
	int					visible;
}						t_env;


typedef struct 			s_msh
{
	t_list				*g_env;
	t_list				*g_cmd;
	char				*string_name;
	char				*res;
}						t_msh;

//utils1
int ft_len_arr(char **arr);
int fill_key(t_env *g_env, const char *str);
void	fill_value(t_list *g_env, char *str, int *i);
void	fill_line_env(char *env, t_env *new);


//parser
void parser(t_msh *msh);

//menu
void 	invitation(t_msh *msh);
void	fill_hist(char *str);
void	record_hist(t_list *g_env, char *str);

#endif