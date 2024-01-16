/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blax <blax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:00:04 by wnguyen           #+#    #+#             */
/*   Updated: 2023/12/25 08:18:37 by blax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	add_or_update_env_var(t_list **env, char *var)
{
	t_list	*current;
	char	*name;
	int		name_len;
	char	*equal_sign;

	equal_sign = ft_strchr(var, '=');
	if (equal_sign == NULL)
		ft_error_2("ft_strchr(var, '=) renvoie NULL");
	name_len = equal_sign - var;
	name = ft_substr(var, 0, name_len);
	current = *env;
	while (current)
	{
		if (ft_strncmp(current->content, name, name_len) == 0)
		{
			free(current->content);
			current->content = ft_strdup(var);
			free(name);
			return ;
		}
		current = current->next;
	}
	ft_lstadd_back(env, ft_lstnew(ft_strdup(var)));
	free(name);
}

void	ft_export(char **args, t_list **env)
{
	int	i;

	if (!args[1])
		ft_error_2("aucun argument fourni");
	i = 1;
	while (args[i])
	{
		if (is_valid_env_name(args[i]))
			add_or_update_env_var(env, args[i]);
		else
		{
			ft_putstr_fd("minishell: export: `", 2);
			ft_putstr_fd(args[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
		}
		i++;
	}
}
