#include "minishell.h"

void run_pwd()
{
	char 	buffer[1000];
	if (getcwd(buffer, 200) == 0)
		exit(0);
	printf("%s\n", buffer);
}
