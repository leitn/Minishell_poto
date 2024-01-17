/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:36:42 by edesaint          #+#    #+#             */
/*   Updated: 2024/01/17 21:05:46 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void delimit_node(t_data *data, int *i)
{
    data->start_node = *i;
    while (data->str[*i] && data->str[*i] != '|')
        (*i)++;
    data->end_node = *i;
}

void lexer(t_data *data)
{
    
    lexer_node(data, node);
}

void parser(t_data *data)
{
    char letter;
    int i;
    int j;
    int k;
    int start_token;
    int end_token;

    start_token = 0;
    end_token = 0;
    i = 0;
    j = 0;
    k = 0;
    delimit_node(data, &i);
    skip_spaces(data, &j);
    while (data->str[j])
    {
        start = i;
        letter = data->str[j];
        if (letter == ' ' || letter == '\'' || letter == '"' || letter == '>' || letter == '<' || letter == '|')
        {
            end = j;
            data->node = malloc(sizeof(t_node));
            // data->node = malloc(sizeof(char) * (end - start + 1));
            data->node->tab_exec[k] = ft_substr(data->str, start, end);
            k++;
        }
        j++;
    }
}