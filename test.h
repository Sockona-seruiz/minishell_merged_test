#include <stdio.h>
#include <unistd.h>

typedef struct s_shell_command
{
	char	instruction_type;
	char	*str;
	char	*mask;
	char	*path;
	char	**argv;
	char	redirection_type;
	char	*redirection_file;
}				t_shell_command;