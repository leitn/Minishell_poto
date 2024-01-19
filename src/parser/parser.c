/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:33:24 by blax              #+#    #+#             */
/*   Updated: 2024/01/19 15:17:24 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token *get_end_token(t_data *data)
{
    t_token *token;

    token = data->token;
    if (!token)
        return (NULL);
    while (token && token->id != data->end)
        token = token->next;
    if (token && token->id == data->end)
        return (token);
    return (NULL);
}

// t_token *get_first_token(t_data *data)
// {
//     t_token *token;

//     token = data->token;
//     if (!token)
//         return (NULL);
//     while (token->next && token->id != data->end)
//         token = token->next;
//     if (!token->next)
//         return (NULL);
//     if (token->id == data->end)
//         return (token->next);
// }

bool delimit_node(t_data *data, t_token *token)
{
    if (token == NULL)
        return (false);
    data->start = token->id;
    while (token != NULL)
    {
        if (token->type_token == T_PIPE)
        {
            data->end = token->id;
            return (true);
        }
        token = token->next;
    }
    return (true);
}

void init_nodes(t_data *data)
{
    int nb_pipes;
    int i;

    i = 0;
    nb_pipes = compt_pipes(data);
    if (nb_pipes < 0)
        ft_error("Il n'y a pas de pipes..");
    while (i < nb_pipes)
    {
        add_node(data);
        i++;
    }
}

bool fill_nodes(t_data *data)
{
    t_node *node;
    t_token *token;

    node = data->node;
    while (node)
    {
        token = get_end_token(data);
        if (token->id != 0)
            token = token->next;
        if (!delimit_node(data, token))
            return ("erreur");
        init_tab_exec(data);
        // init_redir(data);
        // node_suiv(data);
        // token = token->next;
        node = node->next;
    }
    return (true);
}

void parser(t_data *data)
{
    parse_quote_tokens(data);
    determine_token_types(data);
    init_nodes(data);
    fill_nodes(data);
}