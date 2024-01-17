/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:04:32 by blax              #+#    #+#             */
/*   Updated: 2024/01/17 21:16:12 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Si c'est le premier token ou après un pipe, c'est une commande
bool is_command(t_token *token)
{
   	if (token->id == 0)
		return (true);
	if (token->id > 0)
	{
		if (token->prev->type_token == T_PIPE)
			return (true);
	}
	return (false);
}

// Détermine si le token est un pipe.
bool is_pipe(const char *str)
{
    return (ft_strcmp(str, "|") == 0);
}

// Détermine si le token est une option d'une commande.
bool is_option(const char *str)
{
    return (str[0] == '-');
}

// Détermine si le token est une redirection.
bool is_redirection(const char *str)
{
    return (ft_strcmp(str, ">") == 0 || \
			ft_strcmp(str, "<") == 0 || \
			ft_strcmp(str, ">>") == 0 || \
			ft_strcmp(str, "<<") == 0);
}

t_state what_redirection(char *str)
{
	if (ft_strcmp(str, ">") == 0)
		return (T_REDIR_OUT);
	else if (ft_strcmp(str, "<") == 0)
		return (T_REDIR_IN);
	else if (ft_strcmp(str, ">>") == 0)
		return (T_REDIR_APPEND);
	else if (ft_strcmp(str, "<<") == 0)
		return (T_REDIR_HEREDOC);
	return (T_NOREDIR);
}