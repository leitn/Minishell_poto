/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnguyen <wnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:21:48 by wnguyen           #+#    #+#             */
/*   Updated: 2023/11/21 21:12:27 by wnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	is_valid_env_char(char c, int first_char)
{
	if (first_char)
		return (ft_isalpha(c) || c == '_');
	else
		return (ft_isalnum(c) || c == '_');
}

int	is_valid_env_name(char *name)
{
	int	i;

	if (!name || !is_valid_env_char(name[0], 1))
		return (0);
	i = 1;
	while (name[i])
	{
		if (!is_valid_env_char(name[i], 0))
			return (0);
		i++;
	}
	return (1);
}

static int	env_cmp(const char *env_var, const char *var)
{
	int	i;

	i = 0;
	while (env_var[i] && var[i] && env_var[i] == var[i])
		i++;
	if (var[i] == '\0' && (env_var[i] == '=' || env_var[i] == '\0'))
		return (0);
	return (1);
}

static void	unset_env_var(t_list **env, char *var)
{
	t_list	*prev;
	t_list	*current;

	prev = NULL;
	current = *env;
	while (current)
	{
		if (env_cmp(current->content, var) == 0)
		{
			if (prev)
				prev->next = current->next;
			else
				*env = current->next;
			ft_lstdelone(current, free);
			break ;
		}
		prev = current;
		current = current->next;
	}
}

void	ft_unset(char **args, t_list **env)
{
	int	i;

	if (!args || !*env)
		return ;
	i = 1;
	while (args[1])
	{
		if (is_valid_env_name(args[i]))
			unset_env_var(env, args[i]);
		else
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(args[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
		}
		i++;
	}
}
