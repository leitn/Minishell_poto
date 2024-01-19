/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:50:34 by edesaint          #+#    #+#             */
/*   Updated: 2024/01/19 11:58:55 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool skip_spaces(t_data *data, int *i)
{
    int tmp_i;

    tmp_i = *i;
    while (data->str[*i] && is_space(data->str[*i]))
        (*i)++;
    if (*i > tmp_i)
        return (true);
    return (false);
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