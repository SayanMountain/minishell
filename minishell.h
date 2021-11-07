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

//typedef struct 			s_cmd
//{
//	char	*str;
//	char	**cmd;
//	int 	fd[2];
//} 						t_cmd;

typedef struct s_list
{
	char	*str;
	char	**cmd;
	int 	fd[2];
	struct s_list	*next;
}					t_list;

typedef struct 			s_msh
{
	char				**g_env;
	t_list				*g_cmd;
	char				*string_name;
//	int 				pipe;
//	int					c;
	int					len_arr;
	int 				start;
	int					finish;
//	char				*qwerty;
}						t_msh;

//menu
void 	invitation(t_msh *msh);

//pars_func_0
int	check_char(char c, char *str);
void	list_cmd(t_msh *msh);
//void	hand_quotes(const char *str, t_msh *msh);
void	 skip_quotes(const char *str, int *i);

//pars_func_1
void	split_str_cmd(t_msh *msh);
void	write_arr(t_msh *msh, t_list *tmp, int i);
void	check_space(t_msh *msh, t_list *tmp, int *i);

//parser
void parser(t_msh *msh);

//lst_functions
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(char *content);
int	ft_lstsize(t_list *lst);

void	print_list(t_list *g_cmd);

#endif