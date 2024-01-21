/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnguyen <wnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:04:08 by blax              #+#    #+#             */
/*   Updated: 2024/01/21 15:17:55 by wnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	is_builtin(t_node *node)
{
	if (!node->tab_exec || !node->tab_exec[0])
		return (false);
	if (strcmp(node->tab_exec[0], "echo") == 0
		|| strcmp(node->tab_exec[0], "cd") == 0
		|| strcmp(node->tab_exec[0], "pwd") == 0
		|| strcmp(node->tab_exec[0], "export") == 0
		|| strcmp(node->tab_exec[0], "unset") == 0
		|| strcmp(node->tab_exec[0], "env") == 0
		|| strcmp(node->tab_exec[0], "exit") == 0)
		return (true);
	return (false);
}

void	execute_builtin(t_node *node, t_env *env)
{
	if (strcmp(node->tab_exec[0], "echo") == 0)
		ft_echo(node->tab_exec, env);
	else if (strcmp(node->tab_exec[0], "cd") == 0)
		ft_cd(node->tab_exec, env);
	else if (strcmp(node->tab_exec[0], "pwd") == 0)
		ft_pwd(node->tab_exec[0], env);
	else if (strcmp(node->tab_exec[0], "export") == 0)
		ft_export(node->tab_exec, env);
	else if (strcmp(node->tab_exec[0], "unset") == 0)
		ft_unset(node->tab_exec, env);
	else if (strcmp(node->tab_exec[0], "env") == 0)
		ft_env(node->tab_exec[0], env);
	else if (strcmp(node->tab_exec[0], "exit") == 0)
		ft_exit(node->tab_exec);
}

void	execute_command_node(t_node *node, t_env *env)
{
	char	*cmd;

	if (!node || !node->tab_exec)
		exit(EXIT_FAILURE);
	cmd = node->tab_exec[0];
	if (node->type == N_ERROR)
	{
		ft_putstr_fd("Tentative d'exécution d'un type non-commande",
			STDERR_FILENO);
		return ;
	}
	if (is_builtin(node))
		execute_builtin(node, env);
	else
	{
		if (fork() == 0)
		{
			execvp(cmd, node->tab_exec);
			perror("execvp");
			exit(EXIT_FAILURE);
		}
		else
			wait(NULL);
	}
}
