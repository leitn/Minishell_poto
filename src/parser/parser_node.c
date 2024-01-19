/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:04:42 by edesaint          #+#    #+#             */
/*   Updated: 2024/01/19 11:34:56 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_node *create_node(t_data *data)
{
    t_node *node;
    
    node = malloc(sizeof(t_node));
    if (!node)
        return (NULL);
    node->id = data->nb_nodes;
    node->type = N_CMD;
    node->tab_exec = NULL;
    node->redir_in = NULL;
    node->redir_out = NULL;
    node->redir_append = NULL;
    node->redir_heredoc = NULL;
    node->next = NULL;
    return (node);
}

void add_node(t_data *data)
{
    t_node *new_node;
    t_node *temp;

    new_node = create_node(data);
    if (new_node)
    {
        if (data->node == NULL)
            data->node = new_node;
        else
        {
            temp = data->node;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = new_node;
        }
    }
}