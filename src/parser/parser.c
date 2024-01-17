/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:33:24 by blax              #+#    #+#             */
/*   Updated: 2024/01/17 22:37:08 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void delimit_node(t_data *data)
{
    t_token *token;

    token = data->token;
    data->start = token->id;
    while (token->next != NULL)
    {
        if (token->type_token != T_PIPE)
            token = token->next;
    }
    data->end = token->id;
}

void parse_input(t_data *data)
{
    parse_quote_tokens(data);
    determine_token_types(data);
}

void parser(t_data *data)
{
    t_token *token;
    int i;

    delimit_node(data);
    token = data->token; // a revoir, il faut prendre data->start->token ou similaire
    i = compt_args(data, token);
    while (token != NULL)
    {
        data->node = malloc(sizeof(t_node));
        data->node->tab_exec[i] = token;
        token = token->next;
    }
}

// void parser(t_data *data)
// {
//     char letter;
//     int i;
//     int j;
//     int k;
//     int start_token;
//     int end_token;

//     start_token = 0;
//     end_token = 0;
//     i = 0;
//     j = 0;
//     k = 0;
//     delimit_node(data, &i);
//     skip_spaces(data, &j);
//     while (data->str[j])
//     {
//         start = i;
//         letter = data->str[j];
//         if (letter == ' ' || letter == '\'' || letter == '"' || letter == '>' || letter == '<' || letter == '|')
//         {
//             end = j;
//             data->node = malloc(sizeof(t_node));
//             // data->node = malloc(sizeof(char) * (end - start + 1));
//             data->node->tab_exec[k] = ft_substr(data->str, start, end);
//             k++;
//         }
//         j++;
//     }
// }