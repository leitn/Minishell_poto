/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 08:56:42 by blax              #+#    #+#             */
/*   Updated: 2024/01/16 20:25:19 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* Initialise la structure 'data' avec la chaîne de caractères donnée. */
void init_data(t_data *data, char *str)
{
    data->node = NULL;
    data->str = str;
    // data->str = ft_substr(str, data->start, ft_end_string(str));
}

// int compt_args(t_node *node)
// {
//     int i;

//     i = 0;
//     while (node->tab_exec[i] != NULL)
//         i++;
//     return (i);
// }

// Fonction pour afficher le contenu de tous les nodes
void print_nodes(t_node *node)
{
    int i;

    i = 0;
    while (node != NULL)
	{
        printf("Token %d:\n", node->id);
        while (node->tab_exec[i])
        {
            printf("arg %d: %s\n", i, node->tab_exec[i]);
            i++;
        }
        i = 0;
        printf("\n");
        node = node->next;
    }
}