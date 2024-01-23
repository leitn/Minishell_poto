/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:00:04 by wnguyen           #+#    #+#             */
/*   Updated: 2024/01/23 12:23:30 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	print_env_var(t_env *env)
{
	t_env_link	*current;

	current = env->first;
	while (current)
	{
		ft_putstr_fd(current->name, STDOUT_FILENO);
		ft_putchar_fd('=', STDOUT_FILENO);
		ft_putstr_fd(current->content, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		current = current->next;
	}
}

void	ft_export(t_node *node, t_env *env)
{
	int			i;
	char		*name;
	char		*content;

	i = 1;
	if (!node->tab_exec[1])
		print_env_var(env);
	while (node->tab_exec[i])
	{
		if (is_valid_env_name(node->tab_exec[i]))
		{
			name = get_env_name(env, node->tab_exec[i]);
			content = get_env_content(node->tab_exec[i]);
			update_env_var(env, name, content);
			free(name);
			free(content);
		}
		else
			unset_error(node->tab_exec[i]);
		i++;
	}
}

