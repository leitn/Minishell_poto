/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_type_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blax <blax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:06:18 by blax              #+#    #+#             */
/*   Updated: 2023/12/18 09:06:55 by blax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Met à jour le type de token suivant le contexte actuel.
void update_token_type(t_token *token, t_state *current_state)
{
    if (is_command(token))
	{
        token->type_token = T_COMMAND;
        *current_state = T_ARGUMENT; // Après une commande, on s'attend à des arguments
    }
	else if (is_pipe(token->str))
	{
        token->type_token = T_PIPE;
        *current_state = T_COMMAND; // Après un pipe, on s'attend à une nouvelle commande
    }
	else if (is_redirection(token->str))
	{
        token->type_token = what_redirection(token->str);
        *current_state = T_FILE; // Après une redirection, on s'attend à un nom de fichier
    }
	else
		update_token_type_suite(token, current_state);
}

// Met à jour le type de token suivant le contexte actuel.
void update_token_type_suite(t_token *token, t_state *current_state)
{
	if (*current_state == T_FILE)
    {
        token->type_token = T_FILE; // Le token est un nom de fichier après une redirection
        *current_state = T_ARGUMENT; // Après un nom de fichier, on s'attend à des arguments ou à une nouvelle commande
    }
	else if (is_option(token->str))
    {
        token->type_token = T_OPTION; // Le token est une option d'une commande
    	*current_state = T_ARGUMENT;
	}
	else
        token->type_token = *current_state; // Si le token n'est ni une commande, ni un pipe, ni une redirection, il est traité selon le contexte actuel
}

// Parcourt tous les tokens et détermine leur type.
void determine_token_types(t_data *data)
{
    t_token *current_token;
    t_state current_state; // Le premier token est probablement une commande

	current_token = data->token;
	current_state = T_COMMAND;
    while (current_token != NULL)
	{
        if (current_token->type_token == T_NOREDIR)
            update_token_type(current_token, &current_state);
        current_token = current_token->next;
    }
}