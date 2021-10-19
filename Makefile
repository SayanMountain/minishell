NAME		= 	minishell
HEADER		= 	minishell.h

LIBS		= -L ./libft -lft -lreadline

LIST		=  	main.c 						\
				utils1.c

GCC			= gcc

OBJ			= $(LIST:.c=.o)

FLAGS       = -Wall -Wextra -Werror

%.o:%.c		$(HEADER)
		    gcc $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME) :	$(OBJ) $(HEADER)
			$(MAKE) -C ./libft
			$(GCC) $(FLAGS) $(OBJ) Libft/libft.a -o $(NAME)

all :		$(NAME)

clean:
			$(MAKE) clean -C ./libft
			$(RM) $(OBJ)

fclean:          clean
			$(MAKE) fclean -C ./libft
			$(RM) $(NAME)

debug:
	gcc -g $(LIST) -o $(NAME)

re :		fclean all

.PHONY :	all clean fclean re