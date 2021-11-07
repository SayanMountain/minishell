NAME		= 	minishell
HEADER		= 	minishell.h

LIBS		= -L ./libft -lft -lreadline

LIST		=  	main.c 						\
				pars_func_0.c 				\
				pars_func_1.c				\
				menu.c   					\
				./GNL/get_next_line.c		\
				parser.c 					\
				lst_functions.c				\


GCC			= gcc

OBJ			= $(LIST:.c=.o)

FLAGS       = -Wall -Wextra -Werror

%.o:%.c		$(HEADER)
		    gcc $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME) :	$(OBJ) $(HEADER)
			$(MAKE) -C ./libft
			$(GCC) $(FLAGS) $(OBJ) $(LIBS) Libft/libft.a -o $(NAME)

all :		$(NAME)

clean:
			$(MAKE) clean -C ./libft
			$(RM) $(OBJ)

fclean:          clean
			$(MAKE) fclean -C ./libft
			$(RM) $(NAME)

debug:
	gcc -g ./*.c ./GNL/*.c ./libft/*.c -o $(NAME) -lreadline

re :		fclean all

.PHONY :	all clean fclean re