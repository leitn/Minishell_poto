/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:48:38 by edesaint          #+#    #+#             */
/*   Updated: 2024/01/16 21:30:43 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool check_syntax_before(t_data *data, int i)
{
    i--;
    while (i >= 0 && is_space(data->str[i]))
        i--;
    if (i < 0 || is_syntax_char(data->str[i]))
        return (true);
    return (false);
}

bool check_syntax_after(t_data *data, int i)
{
    i++;
    while (data->str[i] && is_space(data->str[i]))
        i++;
    if (!data->str[i])
        return (true);
    if (is_syntax_char(data->str[i]))
        return (true);
    return (false);
}

void update_is_quote(t_data *data, char letter)
{
    if (is_quote(letter) && !data->in_quote)
    {
        data->type_quote = letter;
        data->in_quote = 1;
    }
    else if (is_quote(letter) && data->in_quote)
    {
        if (letter == data->type_quote)
        {
            data->type_quote = '\0';
            data->in_quote = 0;
        }
    }   
}

void verif_syntax(t_data *data)
{
    char letter;
    int i;

    i = 0;
    while (data->str[i])
    {
        letter = data->str[i];
        update_is_quote(data, letter);
        if (is_syntax_char(data->str[i]) && !data->in_quote)
        {
            if (check_syntax_before(data, i))
                ft_error_2("Syntax error before");
            if (is_double_symbol(data, i, '<') || \
                is_double_symbol(data, i, '>'))
            {
                i++;
            }
            if (check_syntax_after(data, i))
                ft_error_2("Syntaxb error after");
        }
        i++;
    }
}
