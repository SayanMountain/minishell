//
// Created by Patton Jefferey on 10/19/21.
//

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

//utils1
int ft_len_arr(char **arr);
void	fill_key(t_list *tmp);
void	fill_value(t_list *tmp, int i);

//parser
void parser(char *argv);

//menu
void 	invitation(void);
void	fill_hist(char *str);

#endif