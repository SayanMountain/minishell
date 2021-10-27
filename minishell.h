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
	char	**cmd;
} 						t_cmd;


//typedef struct 			s_env
//{
//	char 				*line_env;
//	char 				*key;
//	char				*value;
//	int					code;
//	int					visible;
//}						t_env;


typedef struct 			s_msh
{
	char				**g_env;
	t_list				*g_cmd;
	char				*string_name;
	char				*res;
}						t_msh;

//menu
void 	invitation(t_msh *msh);

//utils1


//parser
//void parser(t_msh *msh);


#endif