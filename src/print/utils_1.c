/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:38:08 by edesaint          #+#    #+#             */
/*   Updated: 2024/01/17 19:38:26 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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