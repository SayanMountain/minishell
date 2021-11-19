NAME		= 	minishell

HEADER		= 	minishell.h

LIBS		= -L ./libft -lft -lreadline

LIST		=  	main.c 						\
				menu.c   					\
				./GNL/get_next_line.c		\
				pars_func_0.c 				\
				pars_func_1.c				\
				preparser.c					\
				parser.c 					\
				check_pars_cmd.c			\
				lst_functions.c				\
				lst_func_env.c				\
				all_com.c					\
				cd.c						\
				pwd.c						\
				echo.c						\
				export.c					\
				exit.c						\
				unset.c						\
				env.c						\
				baks.c						\
				addit_func.c				\
				fork_herdoc.c				\
				signal.c					\
				redirects.c					\
				pipes.c						\
				pipes_utils.c				\


GCC			= gcc

OBJ			= $(LIST:.c=.o)

FLAGS       = -Wall -Wextra -Werror -I ~/.brew/opt/readline/include

RDL_MAC		=	-lreadline -L ~/.brew/opt/readline/lib

%.o:%.c		$(HEADER)
		    gcc $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME) :	$(OBJ) $(HEADER)
			$(MAKE) -C ./libft
			$(GCC) -o $(NAME) $(FLAGS) $(OBJ) $(LIBS) $(RDL_MAC) Libft/libft.a

all :		$(NAME)

clean:
			$(MAKE) clean -C ./libft
			$(RM) $(OBJ)

fclean:          clean
			$(MAKE) fclean -C ./libft
			$(RM) $(NAME)

debug:
	gcc -g ./*.c ./GNL/*.c ./libft/*.c -o $(NAME) -lreadline -I

re :		fclean all

.PHONY :	all clean fclean re
