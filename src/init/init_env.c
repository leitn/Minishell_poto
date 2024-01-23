/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:01:14 by letnitan          #+#    #+#             */
/*   Updated: 2024/01/23 15:22:12 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Creates a new t_env_link node by dividing a str from the env at the '=' sign and filles the *name and *content
t_env_link *env_new_link(char *str)
{
	char		*tmp;
	t_env_link	*new_link;

	if (!str)
		return (NULL);
	new_link = memset_malloc(0, sizeof(t_env_link));
	if (!new_link)
		return (NULL);
	tmp = ft_strchr(str, '=');
	if (tmp == 0)
		new_link->name = ft_strdup(str);
	else
	{
		new_link->name = ft_strndup(str, (tmp - &str[0]));
		new_link->content = ft_strdup(&tmp[1]);
	}
	return (new_link);
}

//connects the nodes in the t_env struct
void	env_connect_links(t_env_link *prev, t_env_link *now)
{
	if (prev)
		prev->next = now;
	if (now)
		now->prev = prev;
}

// If env is unset, we create a basic env structure : _/, SHLVL, PWD + cur_path, PATH + execve paths
t_env *init_mini_env()
{
	t_env	*mini_env;
	t_env_link	*temp;
	char	*pwd;
	char	*path;

	mini_env = malloc(sizeof(t_env));
	pwd = getcwd(NULL, 0);
	if (!mini_env || !pwd)
		return (NULL);
	mini_env->first = env_new_link("_=/usr/bin/env");
	env_connect_links(mini_env->first, env_new_link("SHLVL=1"));
	path = ft_strjoin("PWD=", pwd);
	mini_env->last = env_new_link(path);
	env_connect_links(mini_env->first->next,mini_env->last);
	free(path);
	path = ft_strjoin("PATH=",
			"/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin");
	temp = env_new_link(path);
	free (path);
	env_connect_links(mini_env->last, temp);
	mini_env->last = temp;
	mini_env->lst_exit = 0;
	mini_env->len = 4;
	return (mini_env);
}

// Pener a free env correctement, on a malloc CHAQUE t_env_link + une structure t_env


t_env *init_env(char **system_env);
