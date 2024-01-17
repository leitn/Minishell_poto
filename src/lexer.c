/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:08:04 by blax              #+#    #+#             */
/*   Updated: 2024/01/17 20:40:06 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

bool process_syntax(t_data *data, int *i)
{
    if (!is_syntax(data->str[*i]))
        return (false);
    if (is_syntax_char(data->str[*i]))
    {
        if (is_double_symbol(data, *i, '>') || \
            is_double_symbol(data, *i, '<'))
        {
            (*i)++;
        }
        (*i)++;
    }
    return (true);
}

bool process_string(t_data *data, int *i)
{
    if (is_syntax(data->str[*i]))
        return (false);
    while (data->str[*i] && !is_syntax(data->str[*i]))
        (*i)++;
    return (true);
}

/* Traite une séquence de guillemets dans la chaîne de caractères de 'data'. */
bool process_quote(t_data *data, int *i)
{
    char type_quote;

    if (!data->str[*i])
        return (false);
    if (!is_quote(data->str[*i]))
        return (false);
    type_quote = data->str[*i];
    (*i)++;
    while (data->str[*i])
    {
        if (data->str[*i] && is_quote(data->str[*i]))
        {
            if (data->str[*i] == type_quote)
            {
                (*i)++;
                return (true);
            }
        }
        (*i)++;
    }
    return (true);
}

bool is_empty_quotes(t_data *data, int *i)
{
    if (is_double_symbol(data, *i, '\'') || \
        is_double_symbol(data, *i, '"'))
    {
        *i = *i + 2;
        return (true);
    }
    return (false);
}

/* Analyse la chaîne de caractères 'str' et remplit 'data' avec les tokens. */
void ft_lexer(t_data *data)
{
    int i;
    
    i = 0;
    while (data->str[i])
    {
        if (skip_spaces(data, &i))
            data->is_space = true;
        data->start = i;
        if (!is_empty_quotes(data, &i))
        {
            if (!process_quote(data, &i))
                if (!process_string(data, &i))
                    process_syntax(data, &i);
            add_token(data, i);
        }
        data->nb_tokens++;
    }
}