/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 08:56:42 by blax              #+#    #+#             */
/*   Updated: 2024/01/17 22:37:13 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void init_data(t_data *data, char *str)
{
    data->node = NULL;
    data->nb_tokens = 0;
    data->token = NULL;
    data->type_quote = '\0';
    data->in_quote = 0;
    data->str = trim_str(str);
}

bool in_node(t_data *data, t_token *token)
{
    return (token->id > data->start && token->id < data->end);
}

int compt_args(t_data *data, t_token *token)
{
    int i;

    i = 0;
    while (token != NULL && in_node(data, token))
    {
        if (token->type_token == T_ARGUMENT)
            i++;
        token = token->next;
    }
    return (i);
}

// Fonction pour afficher le contenu de tous les nodes
void print_nodes(t_node *node)
{
    int i;

    i = 0;
    while (node != NULL)
	{
        printf("Token %d:\n", node->id);
        while (node->tab_exec[i])
        {
            printf("arg %d: %s\n", i, node->tab_exec[i]);
            i++;
        }
        i = 0;
        printf("\n");
        node = node->next;
    }
}