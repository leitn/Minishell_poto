/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 08:55:05 by blax              #+#    #+#             */
/*   Updated: 2024/01/17 20:51:23 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* Détermine le type de caractère (guillemet, espace, etc.) pour le lexer. */
t_stick_token ft_type_char(char c)
{
    if (c == '\'')
        return (S_QUOTE);
    else if (c == '"')
        return (D_QUOTE);
    else if (is_space(c))
        return (S_SPACE);
    else if (is_syntax_char(c))
        return (S_SYNTAX);
    else if (c == '\0')
        return (S_NULL);
    else
        return (S_CHAR);
}

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

// num_c pour numéro du caractere
char *transform_enum_quote(t_stick_token num_c)
{
    if (num_c == S_QUOTE)
        return ("S_QUOTE");
    else if (num_c == D_QUOTE)
        return ("D_QUOTE");
    else if (num_c == S_SPACE)
        return ("S_SPACE");
    else if (num_c == S_SYNTAX)
        return ("S_SYNTAX");
    else if (num_c == S_NULL)
        return ("S_NULL");
    else
        return ("S_CHAR");
}

// Fonction pour afficher le contenu de tous les tokens
void print_tokens(t_token *tokens)
{
    while (tokens != NULL)
	{
        printf("Token %d:\n", tokens->id);
        printf("Token->str: %s\n", tokens->str);
        printf("Token->type_str: %s\n", transform_enum_quote(tokens->type_str));
        printf("Token->type_rstick: %s\n", transform_enum_quote(tokens->type_rstick));
        printf("Token->type_lstick: %s\n", transform_enum_quote(tokens->type_lstick));
        printf("Token->is_space: %i\n", tokens->is_space);
        printf("Token->type_token: %s\n", transform_enum_type_token(tokens->type_token));
        // printf("Token->prev: %p\n", tokens->prev);
        // printf("Token->current: %p\n", tokens);
        // printf("Token->next: %p\n", tokens->next);
        printf("\n");
        tokens = tokens->next;
    }
	// printf("Token: %p\n", tokens);
}