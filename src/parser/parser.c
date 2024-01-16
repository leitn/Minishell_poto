/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blax <blax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:33:24 by blax              #+#    #+#             */
/*   Updated: 2024/01/15 22:47:21 by blax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool is_empty_token(t_token *token)
{
	if (!token)
		return (true);
	if (token && token->str[0] == '\0'
		&& (token->type_str == S_QUOTE
		|| token->type_str == D_QUOTE))
	{
		return (true);
	}
	return (false);
}
// Fonction principale pour démarrer le processus de parsing.
void parse_input(t_data *data)
{
    parse_quote_tokens(data);
    determine_token_types(data);
    // Ici, vous pouvez continuer le parsing, comme l'analyse syntaxique, l'exécution des commandes, etc.
}

// Pour l'affichage (print et debug)
char *transform_enum_type_token(t_state num_c)
{
	if (num_c == T_COMMAND)
		return ("T_COMMAND");
	else if (num_c == T_OPTION)
		return ("T_OPTION");
	else if (num_c == T_ARGUMENT)
		return ("T_ARGUMENT");
	else if (num_c == T_FILE)
		return ("T_FILE");
	else if (num_c == T_PIPE)
		return ("T_PIPE");
	else if (num_c == T_REDIR_IN)
		return ("T_REDIR_IN");
	else if (num_c == T_REDIR_OUT)
		return ("T_REDIR_OUT");
	else if (num_c == T_REDIR_APPEND)
		return ("T_REDIR_APPEND");
	else if (num_c == T_REDIR_HEREDOC)
		return ("T_REDIR_HEREDOC");
	else if (num_c == T_NULL)
		return ("T_NULL");
	return (NULL);
}