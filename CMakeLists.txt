cmake_minimum_required(VERSION 3.20)
project(minishell C)

set(CMAKE_C_STANDARD 99)

add_executable(minishell main.c minishell.h utils1.c parser.c
        libft/ft_strdup.c
        libft/ft_substr.c
        libft/ft_strjoin.c
        libft/ft_strlen.c)

