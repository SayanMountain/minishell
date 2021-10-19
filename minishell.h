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

typedef	struct	s_env
{
	char		**envp;
	int 		code;
}				t_env;

t_env			g_env;


int ft_len_arr(char **arr);
void parser(char *argv);


#endif