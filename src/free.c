/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:33:07 by blax              #+#    #+#             */
/*   Updated: 2024/01/22 11:14:28 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// void free_tab_exec(t_node *node)
// {
//     // demander a chatgpt
// }

void free_nodes(t_node *node)
{
    t_node *tmp;

    while (node)
    {
        tmp = node;
        node = node->next;
        // free_tab_exec(node);
        free(tmp);
    }
}

void free_data(t_data *data)
{
    if (data)
    {
        free_nodes(data->node);
        free(data);
    }
}

// free les doubles tableau de char (comme tab_exec)
void	ft_free_tab(char **s, int i)
{
	while (i-- > 0)
	{
		if (s[i])
		{
			free (s[i]);
			s[i] = NULL;
		}
	}
	free (s);
}

void free_tokens(t_token *token)
{
    t_token *tmp_token;

    while (token)
    {
        tmp_token = token->next;
        if (token->str)
            free(token->str);
        free(token); // voir peut etre un double free
        token = tmp_token;
    }
}