#ifndef MINISHELL_MINISHELL_H
#define MINISHELL_MINISHELL_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <dirent.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include "./libft/libft.h"
# include "./GNL/get_next_line.h"
# include "struct.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <errno.h>
# include <curses.h>
# include <term.h>

// понять как использовать
#define STDOUT					0
#define STDIN 					1

typedef enum e_errors
{
	ERROR_in_pipes,
	Error_in_malloc,
	ERROR_3,
	ERROR_4,
	ERROR_5,
}	t_errors;

typedef struct 			s_cmd
{
	char	*str;
	char	**cmd;
	int 	fd[2];

	// pipes
	int 				fl;
	int 				num_of_arg;
	int					**num_of_pipes;
	// cmd
} 						t_cmd;

typedef struct s_list
{
	char			*str;
	char			**cmd;
	int 			fd[2];
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct 			s_msh
{
	char				**g_env;
	t_list				*g_cmd;
    /* parser part */
	char				*string_name;
    int                 len_arr;
    int                 start;
    int                 finish;
	/* pipes part */
	int 				**pipe_fd;
	int 				num_of_cmd;
	char				*qwerty;
}						t_msh;

//menu
void 	invitation(t_msh *msh);

//parser
void parser(t_msh *msh);

//pars_func_0
int     check_char(char c, char *str);
void    list_cmd(t_msh *msh);
void    skip_quotes(const char *str, int *i);

//pars_func_1
void    split_str_cmd(t_msh *msh);
void    write_arr(t_msh *msh, t_list *tmp, int i);
void    check_space(t_msh *msh, t_list *tmp, int *i);


//lst_functions
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(char *content);

/* builind.c */
void 	all_command(t_msh *msh);
void 	cd(t_msh *msh);
void	pwd(void);
void 	run_echo(t_msh *msh);
void 	cmd_exit(t_msh *msh);
void	unset(t_msh *msh);
void 	run_env(t_msh *msh);
void	not_found(t_msh *msh);
void	export(t_msh *msh);

/* print.c */
int     print_msg(t_errors err);
void    print_list(t_list *g_cmd);

#endif
