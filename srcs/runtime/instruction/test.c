/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruiz <seruiz@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:10:28 by seruiz            #+#    #+#             */
/*   Updated: 2021/03/15 15:01:55 by seruiz           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_runtime.h"
#include "minishell_builtin.h"
#include "minishell_utilities.h"

#include <unistd.h>

int		ft_is_valid_var_name(t_shell_context *context, t_shell_command *command, int i, char *str)
{
	int		j;
	int		k;
	char	*key;

	(void)str;
	j = i;
	k = 0;
	while ((ft_isalnum(command->command_string[i]) == 1 || command->command_string[i] == '_') && command->command_mask[i] == '0')
		i++;
	if	 (i - j > 0)
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
		printf("value = %s\n", env_get(context, key));
	}
	return (i - j);
}

int		ft_replace_env_variable(t_shell_context *context, t_shell_command *command, int i, char *str)
{
	int		var_len;
	//char	*key;

	var_len = ft_is_valid_var_name(context, command, i, str);
	return (var_len);
	/*
	while (j < i)
	{

	}
	env_get(t_shell_context *context, char *key)
	*/
}

int	ft_cpy_str(t_shell_context *context, t_shell_command *command, int i, char *str)
{
	int		j;
	int		k;
	int		backslash;
	char	*result;

	(void)context;
	(void)str;
	backslash = 0;
	k = 0;
	j = i;
	while (command->command_string[i] && command->command_string[i] != '$' && (command->command_string[i] != '>' || command->command_string[i] != '<'))
	{
		if (command->command_string[i] == '\\')
		{
			backslash++;
			i++;
		}
		i++;
	}
	result = malloc(sizeof(char) * (i - j - backslash + 1));
	printf("result len = %d\n", i - j - backslash + 1);
	result[i - j - backslash] = '\0';
	while (j < i)
	{
		if (command->command_string[j] == '\\')
			j++;
		result[k] = command->command_string[j];
		k++;
		j++;
	}
	printf("s = %s\n", result);
	return (i);
}

void	ft_test(t_shell_context *context, t_shell_command *command)
{
	int		i;
	//char	**str_tab;
	int		j;
	char	*str;

	(void)j;
	i = 0;
	str = NULL;
	printf("string = %s\n", command->command_string);
	printf("mask   = %s\n", command->command_mask);

	//Calculer la taille de chaque string et ensuite la copier dans argv



	while (command->command_string[i])
	{
		i = ft_cpy_str(context, command, i, str);
		if (command->command_string[i] == '$')
			i += ft_replace_env_variable(context, command, i + 1, str);


		/*
		if (command->command_string[i] == '\\')
		{
			
		}
		if (command->command_string[i] == '$')
		{
			ft_replace_env_variable(command, str);
		}
		*/
	}

}