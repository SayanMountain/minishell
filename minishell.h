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

			/* pipes */
#define STDOUT					0
#define STDIN 					1
			/* redirects */
#define 			L_ARR		1
#define 			R_ARR 		2
#define 			R_D_ARR		3


typedef enum e_errors
{
	ERROR_in_pipes,
	Error_in_malloc,
	ERROR_3,
	ERROR_4,
	ERROR_5,
}	t_errors;

//typedef struct 			s_cmd
//{
//	char				*str;
//	char				**cmd;
//	int 				fd[2];
//	/* pipes */
//	int 				fl;
//	int 				num_of_arg;
//	int					**num_of_pipes;
//	/* redirect + hay que cambiar el nombre */
//	int					fd_inf;
//	int					fd_outf;
//	int					in;
//	int					out;
//	int 				is_fork;
//} 						t_cmd;

typedef struct 			s_env
{
	char 				*str;
	struct s_env        *next;
}						t_env;

typedef struct s_list
{
	char				*str;
	char				**cmd;
	int 				fd[2];
//	void				*content;
	struct s_list		*next;
//	t_redir 			*redir;
}						t_list;



typedef struct 			s_msh
{
	t_env				*g_env;
	t_list				*g_cmd;
    /* parser part */
	char				*string_name;
    int                 len_arr;
    int                 start;

    /* pipes part */
	int 				**pipe_fd;
	int 				num_of_cmd;

	/* implement and rename */
	int					in;
	int					out;

	/* redirect part */

}						t_msh;

//menu
void 	invitation(t_msh *msh);
void	clean_lists(t_msh *msh);

//parser
int 	parser(t_msh *msh);

//check_pars_cmd
void	check_cmd(t_msh *msh);
char	**search_path(char **arr);
int		ft_access(t_list *tmp, char **arr);

//preparser
int     preparser(t_msh *msh);
int     check_zero_i(char *str, int *i);

//pars_func_0
int		check_char(char c, char *str);
int		list_cmd(t_msh *msh);
int		skip_quotes(const char *str, int *i);
void	rewriting_str(t_list *tmp, char *str, int j);

//pars_func_1
void    split_str_cmd(t_msh *msh);
void    write_arr(t_msh *msh, t_list *tmp, int i);
void    check_space(t_msh *msh, t_list *tmp, int *i);
void	remove_quotes(t_msh *msh);

/* lst_func_env */
void	ft_lstadd_back_env(t_env **lst, t_env *new);
t_env	*ft_lstnew_env(char *content);
t_env	*ft_lstlast_env(t_env *lst);


/* pipes */
int 	pipes (char **envp, t_msh *msh);

//lst_functions
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(char *str);

/* builind.c */
int		all_command(t_msh *msh);
int		ft_strcmp(const char *s1, const char *s2);
void	run_pwd(void);
void 	run_echo(t_msh *msh);
void 	run_exit(t_msh *msh);
void	unset(t_msh *msh);
void 	run_env(t_msh *msh);
void	not_found(t_msh *msh);
void	run_export(t_msh *msh, t_list *tmp);
void	run_cd_standart(t_msh *msh);
void	run_cd_oldpwd(t_msh *msh);
void	run_cd_home(t_msh *msh);
void 	run_unset(t_msh  *msh, t_list *tmp);


/* print.c */
int     print_msg(t_errors err);
void    print_list(t_list *g_cmd);

//addit_func
void	error_msg(int i, char c);
void	clean_lists(t_msh *msh);

/* redirect */
void	redirect_detect(t_msh *msh);
//void	left_left_readarrow(t_msh *msh, t_cmd *cmd, char *stop);
//void	left_left_arrow(t_msh *msh, t_cmd *cmd, char *stop);
//void	open_file(t_cmd *cmd, char *fname, int mode);


#endif
