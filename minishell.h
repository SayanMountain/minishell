/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmohamme <bmohamme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 23:47:53 by bmohamme          #+#    #+#             */
/*   Updated: 2021/11/19 23:47:53 by bmohamme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

//char	*g_status;

typedef enum e_errors
{
	ERROR_in_pipes,
	Error_in_malloc,
	ERROR_3,
	ERROR_4,
	ERROR_5,
}	t_errors;

typedef struct		s_env
{
	char			*str;
	struct s_env	*next;
}					t_env;

typedef struct s_list
{
	char			*str;
	char			**cmd;
	int 			red_inp;
	int 			red_outp;
	char			*pipe_or_word;
	int				pipe_h[2];
	int 			fd[2];
//	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct 			s_msh
{
	t_env				*g_env;
	t_list				*g_cmd;
	char				**a_env;
    /* parser part */
	char				*str_name;
    int                 len_arr;
    int                 start;
	char				*val_baks;
	/* pipes part */
	int 				**pipe_fd;
	int 				num_of_cmd;
}						t_msh;

//main
void	ctrl_ign(void);


//menu
void 	invitation(t_msh *msh);

//check_pars_cmd
char	*check_cmd(t_msh *msh, char *str);
char	**search_path(char **arr);
char	*ft_access(char *str, char **arr);

//preparser
int	preparser(t_msh *msh);
int	check_zero_i(char *str, int *i);

//parser
//int		check_red_quotes(t_list *tmp, int *i);
//void	redirect_init(t_list *g_cmd);
int		parser(t_msh *msh);

//pars_func_0
int		check_char(char c, char *str);
int		list_cmd(t_msh *msh);
int		skip_quotes(t_msh *msh, char *str, int *i);
void	rewriting_str(t_list *tmp, char *str, int j);
int 	creat_list(char *str, t_msh *msh, int *i);

//pars_func_1
int		split_str_cmd(t_msh *msh);
int 	split_str(t_msh *msh, t_list *tmp);
void    write_arr(t_msh *msh, t_list *tmp, int *i);
void	remove_quotes(t_msh *msh);
char	*join_str(t_msh *msh, char *str, int *i);

//redirects
int 	redirect(t_msh *msh, t_list *tmp, int *i);
int 	open_redirect(t_list *tmp, t_msh *msh, char *spec_ch, char *file);
void	double_left_red(t_list *tmp, t_msh *msh, char *file);
int		one_left_red(t_list *tmp, char *file);
void	right_redir(t_list *tmp, char *spec_ch, char *file);

//fork_herdoc
void	redirect_parent(t_list *tmp, t_msh *msh, pid_t pid);
void	redirect_child(t_list *tmp, char *file);
void	ft_signal_hd(void);

//lst_functions
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(char *content);

//lst_func_env
t_env	*ft_lstlast_env(t_env *lst);
t_env	*ft_lstnew_env(char *content);
void	ft_lstadd_back_env(t_env **lst, t_env *new);
//int		ft_lstsize1(t_list *lst);
//int		ft_lstsize_2_env(t_env *lst);

//baks
int		check_baks(t_msh *msh, char *str, int *i);
char	*baks(t_msh *msh, char *str, int *i);
char	*value(char *str);

/* pipes */
int 	pipes (char **envp, t_msh *msh);

//addit_func
void	error_msg(int i, char c);
void	clean_lists(t_msh *msh);
void    check_space(t_msh *msh, char *str, int *i);
int		ft_strcmp1(const char *s1, const char *s2);
void	ft_signal_cltr_c_2(int sig);

/* builind.c */
int		all_command(t_msh *msh);
void	chose_builtin(t_list *tmp, t_msh *msh);
int		ft_strcmp(const char *s1, const char *s2);
void	run_pwd(void);
void 	run_echo(t_msh *msh);
void 	run_exit(t_msh *msh);
void 	run_env(t_msh *msh);
void	not_found(t_msh *msh);
void	run_export(t_msh *msh, t_list *tmp);
void 	run_unset(t_msh  *msh, t_list *tmp);
void	run_cd_standart(t_msh *msh);


/* print.c */
int     print_msg(t_errors err);
void    print_list(t_list *g_cmd);

//signal
void	ft_signal_pipes(int sig);
void	ft_signal_run_pipes(void);
void	ft_signal_cltr_c(int sig);
void	ft_signal_in_child(void);
void	ft_signal_main(void);

//pipes
void	many_pipe(t_msh *msh, t_list *tmp, int i);
void	without_pipe(t_msh *msh, t_list *tmp);
void	check(t_msh *msh, t_list *tmp, int i);
void	pipe_close(t_msh *msh);
void	pipe_waitpid(t_msh *msh);
void	pipe_malloc(t_msh *msh);
void	one_pipe(t_msh *msh, int i);
void	more_than_2_pipe(t_msh *msh, int i);
void	last_pipe(t_msh *msh, int i);
int		ft_strcmp(const char *s1, const char *s2);

#endif
