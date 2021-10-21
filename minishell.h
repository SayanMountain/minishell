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

char **com_str;



//utils1
int ft_len_arr(char **arr);
void	fill_key(t_list **tmp, int *j);
void	fill_value(t_list **tmp, int i);

//parser
void parser(int argc, char **argv);

//menu
void 	invitation(t_list **g_env);
void	fill_hist(char *str);
void	record_hist(t_list **g_env, char *str);

#endif