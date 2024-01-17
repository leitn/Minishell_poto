/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:11:36 by edesaint          #+#    #+#             */
/*   Updated: 2024/01/17 20:46:13 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* Crée un nouveau token avec les données fournies et le retourne. */
t_token *create_token(t_data *data, int end)
{
    t_token *token;
    int len;
    
    len = end - data->start;
    if (len <= 0)
        return (NULL);
    token = malloc(sizeof(t_token));
    if (!token)
        return (NULL);
    token->id = data->nb_tokens;
    token->type_token = T_NOREDIR;
    token->str = ft_substr(data->str, (unsigned int) data->start, (size_t) len);
    token->type_str = ft_type_char(data->str[--end]);
    token->type_rstick = ft_type_char(data->str[++end]);
    if (data->start > 0)
        token->type_lstick = ft_type_char(data->str[--data->start]);
    token->is_space = data->is_space;
    data->is_space = false;
    token->prev = NULL;
    token->next = NULL;
    
    return (token);
}

/* Ajoute un nouveau token à la liste chaînée de tokens dans 'data'. */
void add_token(t_data *data, int end)
{
    t_token *new_token;
    t_token *temp;

    new_token = create_token(data, end);
    if (new_token)
    {
        if (data->token == NULL)
        {
            new_token->prev = NULL;
            data->token = new_token;
        }
        else
        {
            temp = data->token;
            while (temp->next != NULL)
                temp = temp->next;
            new_token->prev = temp;
            temp->next = new_token;
        }
    }
}