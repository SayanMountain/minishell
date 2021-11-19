#include "minishell.h"

int print_msg(t_errors err)
{
	if(err == ERROR_in_pipes)
		printf("Error_in_pipes\n");
	return (err);
}