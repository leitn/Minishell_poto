/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:22:11 by edesaint          #+#    #+#             */
/*   Updated: 2024/01/20 15:23:54 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token *get_end_token(t_data *data, t_token *token)
{
    if (!token)
        return (NULL);
    while (token && token->id != data->end)
        token = token->next;
    if (token && token->id == data->end)
        return (token);
    return (NULL);
}

t_token *get_first_token(t_data *data, t_token *token)
{
    if (!token)
        return (NULL);
    if (data->end == 0)
        return (token);
    else
        token = get_end_token(data, token);
    if (token->next && token->next->type_token == T_PIPE)
        token = token->next->next;
    if (!token)
        return (NULL);
    return (token);
}

char *get_command(t_token *token)
{
    if (token == NULL)
        return (NULL);
    if (token->type_token == T_COMMAND)
        return (token->str);
    return (NULL);
}

t_token *next_arg(t_data *data, t_token *token)
{
    if (!token)
        return (NULL);
    while (token != NULL && token->id <= data->end)
    {
        if (token->type_token == T_ARGUMENT)
        {
            return (token);
        }
        token = token->next;
    }
    return (NULL);
}

char *get_argument(t_data *data, t_token *token)
{
    token = next_arg(data, token);
    if (!token)
        return (NULL);
    return (token->str);
}