cmake_minimum_required(VERSION 3.20)
project(minishell C)

set(CMAKE_C_STANDARD 99)

include_directories(. libft)

add_subdirectory(libft)
add_executable (minishell
        main.c
        menu.c
        ./GNL/get_next_line.c
        check_pars_cmd.c
        pars_func_0.c
        pars_func_1.c
        addit_func.c
        preparser.c
        parser.c
        lst_functions.c
        lst_func_env.c
        all_com.c
        cd.c
        pwd.c
        echo.c
        export.c
        exit.c
        redirect.c
        unset.c						
        env.c)
target_link_libraries(minishell libft readline)