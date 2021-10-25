cmake_minimum_required(VERSION 3.20)
project(minishell C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(libft)
add_executable (minishell
        main.c
        minishell.h
        utils1.c
        parser.c
        menu.c
        GNL/get_next_line.c)
target_link_libraries(minishell libft readline)