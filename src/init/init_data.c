/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:25:07 by letnitan          #+#    #+#             */
/*   Updated: 2024/01/23 15:20:23 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void init_data(t_data *data, char *str, char **env)
{
    t_env *my_env;

    if (!env || !env[0])
        my_env = init_mini_env();
    // else
    //     my_env = init_env(env);
    data->start = 0;
    data->end = 0;
    data->node = NULL;
    data->nb_tokens = 0;
    data->nb_nodes = 0;
    data->token = NULL;
    data->is_space = false;
    data->type_quote = '\0';
    data->in_quote = 0;
    data->str = trim_str(str);
    data->env = my_env;
}
