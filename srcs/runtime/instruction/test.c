/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruiz <seruiz@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:10:28 by seruiz            #+#    #+#             */
/*   Updated: 2021/03/15 14:02:29 by seruiz           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_runtime.h"
#include "minishell_builtin.h"
#include "minishell_utilities.h"

#include <unistd.h>

int		ft_is_valid_var_name(t_shell_context *context, t_shell_command *command, int i)
{
	int		j;
	int		k;
	char	*key;

	j = i;
	k = 0;
	while ((ft_isalnum(command->command_string[i]) == 1 || command->command_string[i] == '_') && command->command_mask[i] == '0')
		i++;
	if (i - j > 0)
	{
		key = malloc(sizeof(char) * (i - j + 1));
		key[i - j] = '\0';
		i = j;
		while ((ft_isalnum(command->command_string[i]) == 1 || command->command_string[i] == '_') && command->command_mask[i] == '0')
		{
			key[k] = command->command_string[i];
			k++;
			i++;
		}
		printf("key = %s\n", key);
		env_get(context, key);
	}
	return (i - j);
}

int		ft_replace_env_variable(t_shell_context *context, t_shell_command *command, int i, char *str)
{
	int		var_len;
	//char	*key;

	(void)str;
	var_len = ft_is_valid_var_name(context, command, i);
	return (1);
	/*
	while (j < i)
	{

	}
	env_get(t_shell_context *context, char *key)
	*/
}

void	ft_test(t_shell_context *context, t_shell_command *command)
{
	int		i;
	//char	**str_tab;
	char	*str;

	i = 0;
	str = NULL;
	printf("string = %s\n", command->command_string);
	printf("mask = %s\n", command->command_mask);

	//Calculer la taille de chaque string et ensuite la copier dans argv



	while (command->command_string[i])
	{
		if (command->command_string[i] == '$')
			ft_replace_env_variable(context, command, i + 1, str);


		/*
		if (command->command_string[i] == '\\')
		{
			
		}
		if (command->command_string[i] == '$')
		{
			ft_replace_env_variable(command, str);
		}
		*/
		i++;
	}

}