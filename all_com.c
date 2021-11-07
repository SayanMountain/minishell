#include "minishell.h"

//https://github.com/Avchar/minishell/blob/develop/srcs/own_progc.c

void	all_command(t_msh *msh)
{
	if(!ft_strncmp(msh->string_name, "cd", ft_strlen("cd")))
		cd(msh);
	if(!ft_strncmp(msh->string_name, "export", ft_strlen("export")))
		export(msh);
	if(!ft_strncmp(msh->string_name, "pwd", ft_strlen("pwd")))
		pwd();
	if(!ft_strncmp(msh->string_name, "echo", ft_strlen("echo")))
		run_echo(msh);
	if(!ft_strncmp(msh->string_name, "exit", ft_strlen("exit")))
		cmd_exit(msh);
	if(!ft_strncmp(msh->string_name, "env", ft_strlen("env")))
		run_env(msh);
//	if(!ft_strncmp(msh->string_name, "unset", ft_strlen("unset")))
//		unset(msh);
//	else
//		not_found(msh);
	return;
}
//	if(ft_strncmp(argv[0], "cd"))
//		cd();
//	else if(argv[0] != NULL)
//	{
//		printf("err");
//		exit(0);
//	}
//	else if(ft_strncmp(argv[0], "pwd"))
//		pwd();
//	else if(ft_strncmp(argv[0], "uncet"))
//		uncet();
//	else if(ft_strncmp(argv[0], "export"))
//		export();
//	else if(ft_strncmp(argv[0], "env"))
//		env();
//	else if(ft_strncmp(argv[0], "echo"))
//		echo();
//}