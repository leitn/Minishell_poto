/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:33:07 by blax              #+#    #+#             */
/*   Updated: 2024/01/16 21:30:50 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// void free_tab_exec(t_node *node)
// {
//     // demander a chatgpt
// }

void free_nodes(t_node *node)
{
    t_node *tmp;

    while (node)
    {
        tmp = node;
        node = node->next;
        // free_tab_exec(node);
        free(tmp);
    }
}

void free_data(t_data *data)
{
    if (data)
    {
        free_nodes(data->node);
        free(data);
    }
}