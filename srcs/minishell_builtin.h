/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtin.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruiz <seruiz@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:02:51 by fgalaup           #+#    #+#             */
/*   Updated: 2021/03/15 13:39:49 by seruiz           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_BUILTIN_H
# define MINISHELL_BUILTIN_H

# include "libft.h"

# include "minishell_type.h"
# include "minishell_error.h"
# include "minishell_utilities.h"

# define BUILTIN_ECHO	"echo"
# define BUILTIN_ENV	"env"
# define BUILTIN_EXPORT	"export"
# define BUILTIN_UNSET	"unset"

# define BUILTIN_PWD	"pwd"
# define BUILTIN_CD		"cd"

# define BUILTIN_EXIT	"exit"

void	ft_test(t_shell_context *context, t_shell_command *command);

int		builtin_echo(t_shell_context *context, int argc, char **args);
int		builtin_echo_option_n(char *arg);

int		builtin_env(t_shell_context *context, int argc, char **args);

int		builtin_export(t_shell_context *context, int argc, char **args);
void	builtin_export_var(t_shell_context *context, char **args);
void	builtin_export_print(t_shell_context *context);

int		builtin_unset(t_shell_context *context, int argc, char **args);

int		builtin_pwd(t_shell_context *context, int argc, char **args);

int		builtin_cd(t_shell_context *context, int argc, char **args);

int		builtin_exit(t_shell_context *context, int argc, char **args);
int		exit_error_invalid_argument(t_shell_context *context, const char *arg);
int		exit_error_too_many_argument(t_shell_context *context);

#endif
