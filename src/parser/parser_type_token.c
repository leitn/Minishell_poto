/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_type_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:06:18 by blax              #+#    #+#             */
/*   Updated: 2024/01/20 21:36:17 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void update_token_type(t_token *token, bool is_cmd, t_state *current_state)
{
	if (is_redirection(token->str))
	{
        token->type_token = what_redirection(token->str);
        *current_state = T_FILE;
    }
    else if (is_command(token))
        token->type_token = T_COMMAND;
    else if (is_pipe(token->str))
	{
        token->type_token = T_PIPE;
        is_cmd = 0;
    }
	else
		update_token_type_suite(token, current_state);
}

void update_token_type_suite(t_token *token, t_state *current_state)
{
	if (*current_state == T_FILE)
        token->type_token = T_FILE;
	else if (is_option(token->str))
    {
        token->type_token = T_OPTION;
    	*current_state = T_ARGUMENT;
	}
	else
        token->type_token = *current_state;
}

void determine_token_types(t_data *data)
{
    t_token *current_token;
    t_state current_state;
    bool is_cmd;

    is_cmd = 0;
	current_token = data->token;
	current_state = T_NULL;
    while (current_token != NULL)
	{
        if (current_token->type_token == T_NULL)
            update_token_type(current_token, is_cmd, &current_state);
        current_token = current_token->next;
    }
}