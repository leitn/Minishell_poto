/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blax <blax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 23:04:42 by blax              #+#    #+#             */
/*   Updated: 2023/12/18 09:29:15 by blax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int g_last_exit_status = 0;

// // Fonction pour obtenir le dernier statut de sortie
// int get_last_exit_status(void)
// {
//     // Supposons que vous avez une variable globale ou une structure qui stocke cette information
//     return (g_last_exit_status); // Remplacez par votre propre mécanisme de stockage
// }

void expand_tokens(t_data *data)
{
    t_token *current_token;
    char *expanded_value;

    current_token = data->token;
    while (current_token != NULL)
    {
        while (current_token && is_empty_token(current_token))
            current_token = current_token->next;
        if (current_token
            && (current_token->type_str == D_QUOTE
            || current_token->type_str == S_CHAR))
        {
            expanded_value = expand_variables(current_token->str);
            if (expanded_value)
            {
                replace_token_str(current_token, expanded_value);
                free(expanded_value); // Je ne pense pas qu'il doit etre free
            }
        }
        if (current_token)
            current_token = current_token->next;
    }
}

void replace_token_str(t_token *token, char *new_value)
{
    free(token->str);
    token->str = ft_strdup(new_value);
}

// void print_expanded_tokens(t_token *tokens)
// {
//     while (tokens != NULL)
// 	{
//         if (is_empty_token(tokens))
//             printf("%s", tokens->str);
//         else
//             printf(" %s", tokens->str);
//         tokens = tokens->next;
//     }
// }